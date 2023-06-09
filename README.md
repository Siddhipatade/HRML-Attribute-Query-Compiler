
# HRML Attribute Query Compiler

This is a C++ program that works with a custom-designed markup language called HRML. HRML is a language where each element consists of a starting and ending tag, with attributes associated with each tag. This program allows you to parse HRML source code and perform attribute queries to retrieve attribute values.

## How it works

The program takes HRML source code as input and builds a hierarchical structure of tags and attributes. It then processes queries to retrieve attribute values based on the provided tags and attribute names.

The opening tags in HRML follow the format:

<tag-name attribute1-name="value1" attribute2-name="value2" ...>

The closing tags follow the format:

</tag-name>

Attributes are referenced using the tag name followed by a tilde (~) and the attribute name:

tag1~value
tag1.tag2~name

## Usage
1. Compile the code using a C++ compiler:

        g++ -o compiler compiler.cpp

2. Run the compiled program:

        ./compiler


3. Enter the number of tags in the HRML source code and press Enter.

4. Enter the number of queries and press Enter.

5. Enter the HRML source code line by line.

6. Enter the queries line by line.

7. The program will output the attribute values based on the queries. If an attribute does not exist, it will display "Not Found!".

## Example

Here's an example to demonstrate the usage:

**Input:**

        4 2
        <tag1>
        <tag2 attr1="value1" attr2="value2">
        <tag3 attr3="value3">
        </tag3>
        </tag2>
        <tag4 attr4="value4">
        </tag4>
        tag1value
        tag2.attr1value


**Output:**

        Not Found!
        value1


In the above example, there are four tags in the HRML source code. The first query is `tag1~value`, which retrieves the value of the attribute `value` from `tag1`. Since `tag1` does not have that attribute, the output is "Not Found!". The second query is `tag2.attr1~value`, which retrieves the value of the attribute `value` from `tag2` with the attribute name `attr1`. The output is `value1`.

## Limitations

- The program assumes the correctness of the HRML input format and doesn't include extensive error handling. Invalid HRML code may lead to unexpected behavior.
- The program supports a limited set of operations and doesn't provide full HRML functionality.

Feel free to modify the code and add error handling or additional features based on your requirements.

