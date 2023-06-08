#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

static char c_bracket_open = '<';
static char c_bracket_close = '>';
static char c_tag_close = '/';
static char c_equal = '=';
static char c_space = ' ';
static char c_quotas = '"';
static char c_tilda = '~';
static const char *s_tag_closing = " >";
static const char *s_query_delimiters = ".~";
static const char *s_erase_simbols = " \t\n\r\f\v";
static const char *s_error_message = "Not Found!";

namespace HRML
{

    inline string &rtrim(string &s)
    {
        s.erase(s.find_last_not_of(s_erase_simbols) + 1);
        return s;
    }

    inline string &ltrim(string &s)
    {
        s.erase(0, s.find_first_not_of(s_erase_simbols));
        return s;
    }

    inline string &trim(string &s)
    {
        return ltrim(rtrim(s));
    }

    class Object
    {
    public:
        bool operator==(const string &name) const
        {
            return m_name == name;
        }

        string m_name;
    };

    class Attribute : public Object
    {
    public:
        string m_value;
    };

    class Tag : public Object
    {
    public:
        vector<Attribute> m_vAttr;
        vector<Tag> m_vTag;

        Tag *parent = nullptr;
    };
} // HRML

using namespace HRML;

int main()
{
    int tags = 0;
    cin >> tags;

    int queries = 0;
    cin >> queries;

    string str;
    std:: getline(cin, str);

    vector<Tag> doc;
    Tag *current_tag = nullptr;

    for (int i = 0; i < tags; i++)
    {
        std:: getline(cin, str);
        if (str.empty())
            continue;

        size_t n = 0;

        if (str[n] == c_bracket_open)
        {
            if (str[n + 1] == c_tag_close)
            {
                if (current_tag)
                    current_tag = current_tag->parent;
                continue;
            }
            else
            {
                Tag tag;
                if (current_tag == nullptr)
                {
                    doc.push_back(tag);
                    current_tag = &doc.back();
                }
                else
                {
                    tag.parent = current_tag;
                    current_tag->m_vTag.push_back(tag);
                    current_tag = &current_tag->m_vTag.back();
                }

                n++;
                auto pos = str.find_first_of(s_tag_closing, n);
                current_tag->m_name = str.substr(n, pos - n);

                if (str[pos] == c_bracket_close)
                {
                    continue;
                }
                else
                {
                    n = str.find_first_not_of(c_space, pos);

                    while (str[n] != c_bracket_close)
                    {
                        pos = str.find(c_equal, n);

                        Attribute attr;
                        attr.m_name = str.substr(n, pos - n);
                        attr.m_name = trim(attr.m_name);

                        n = pos;
                        pos = str.find(c_quotas, n);
                        n = pos + 1;
                        pos = str.find(c_quotas, n);

                        attr.m_value = str.substr(n, pos - n);
                        n = pos + 1;

                        current_tag->m_vAttr.push_back(attr);

                        n = str.find_first_not_of(c_space, n);
                    }
                }
            }
        }
    }

    for (int i = 0; i < queries; i++)
    {
        std:: getline(cin, str);
        size_t n = 0;
        current_tag = nullptr;

        auto pos = str.find_first_of(s_query_delimiters, n);

        while (pos != string::npos)
        {
            auto tag_name = str.substr(n, pos - n);
            n = pos + 1;

            auto &tags_vector = current_tag ? current_tag->m_vTag : doc;

            auto it = std::find(tags_vector.begin(), tags_vector.end(), tag_name);
            if (tags_vector.end() == it)
            {
                pos = string::npos;
                break;
            }
            else
            {
                current_tag = &(*it);
            }

            if (str[pos] == c_tilda)
                break;

            pos = str.find_first_of(s_query_delimiters, n);
        }

        if (pos == string::npos)
        {
            cout << s_error_message << endl;
        }
        else
        {
            n = pos + 1;

            auto attr_name = str.substr(n, pos - n);

            auto it = std::find(current_tag->m_vAttr.begin(), current_tag->m_vAttr.end(), attr_name);
            if (current_tag->m_vAttr.end() != it)
            {
                cout << (*it).m_value << endl;
            }
            else
            {
                cout << s_error_message << endl;
            }
        }
    }

    return 0;
}