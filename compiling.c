#include "parser.h"
#include "y.tab.h"


void execute(nodeType *p);
void yyerror(char *);

// TODO: all operations logic converted into assemble
struct conNodeType* ex(nodeType *p, int oper) {
    return 0;
}
 
// parser connected by this function
void execute(nodeType *p){
   // ex(p, 0);
}
