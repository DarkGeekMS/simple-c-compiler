#include "parser.h"
#ifdef __cplusplus
extern "C" {
#endif

/*
    functions used to access the symbol table which includes all program identifiers
*/

// semtanic analysis will be here as well !

// move the current symbol table up and down the tree
void changeScope(int scope_dir);
// insertion to a variable need : variable name , type , value , constant or not , declaretion or initialization
struct conNodeType* insert(char* var,conEnum var_type, struct conNodeType value, bool constant, bool with_value, char** error);
// get symbol value
struct conNodeType* getsymbol(char* var , char** error);
// print the whole symbol table
void printSymbolTable(char* table_path);

#ifdef __cplusplus
} //end extern "C"
#endif