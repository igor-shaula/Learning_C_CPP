/* names in C++ ca be:
 variables and constants
 functions (and methods)
 structures and classes
 templates
 type synonyms (typedefs)
 enums and unions
 namespaces
 */

// in C there is no way to make names unique - that's why people add prefixes to names:
struct XML_Parser;
int XML_GetCurrentLineNumber(XML_Parser *parser);

// the same in C++ code could look like this:
namespace XML {
    struct Parser;
    int GetCurrentLineNumber(Parser *parser);
}
// full names of this struct & function will be:
// XML::Parser;
// int XML::GetCurrentLineNumber(XML::Parser *parser);