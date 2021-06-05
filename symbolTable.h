#include "parser.h"
#ifdef __cplusplus
extern "C" {
#endif

/*
    functions used to access the symbol table which includes all program identifiers
*/

// semtanic analysis will be here as well !

  struct conNodeType* insert();
  struct conNodeType* getsymbolTable();
  void printSymbolTable();

#ifdef __cplusplus
} //end extern "C"
#endif