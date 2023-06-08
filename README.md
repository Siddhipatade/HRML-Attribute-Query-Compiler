
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

