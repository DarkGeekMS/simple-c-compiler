#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "symbolTable.h"
#include "y.tab.h"

// functions will be represented as linked list
struct func
{
    char* func_name;
    struct func * next_function;               
};

struct func *head = NULL;
struct func *current = NULL;
static int line_num = 1;

// initializations
char* var;                                                      // identifier name
char* error = "";                                               // any semantic error
int prev_line, current_line;




void execute(nodeType *p);
void yyerror(char *);

// TODO: all operations logic converted into assemble
struct conNodeType* ex(nodeType *p, int oper, FILE* outFile) {

    struct conNodeType* pt = malloc(sizeof(struct conNodeType*));   // to loop over the program expressions
    pt->type = typeND;
    struct conNodeType* pt2;
    conEnum type;
    struct nodeTypeTag * line;
    struct nodeTypeTag * parms;
    //if no program exists return
    if (!p) return NULL;
    // loop over the possible expressions in the program
    switch(p->type) {
        // in case of constants , assigning any identifier a value
        case typeCon: {
            // for any type assignment it follows : MOV var_name Value
            switch (p->con.type){
                case typeInt: {
                    // printf(" INTEGER \n");
                    pt->iValue = p->con.iValue;
                    pt->type = p->con.type;
                    fprintf(outFile, "\tPush\t%d\n", p->con.iValue );
                    break;
                }
                case typeFloat: {
                    // printf(" FLOAT \n");
                    pt->fValue = p->con.fValue;
                    pt->type = p->con.type;
                    fprintf(outFile, "\tpush\t%f\n", p->con.fValue );
                    break;
                }
                case typeBool: {
                    // printf(" BOOL \n");
                    pt->iValue = p->con.iValue;
                    pt->type = p->con.type;
                    fprintf(outFile, "\tpush\t%d\n", p->con.iValue );
                    break;
                }
                case typeChar: {
                    // printf(" CHAR \n");
                    pt->cValue = p->con.cValue;
                    pt->type = p->con.type;
                    fprintf(outFile, "\tpush\t\'%c\'\n", p->con.cValue );
                    break;
                }
                case typeString: {
                    // printf(" STRING \n");
                    pt->sValue = p->con.sValue;
                    pt->type = p->con.type;
                    fprintf(outFile, "\tpush\t\"%s\"\n", p->con.sValue );
                    break;
                }
                default:
                    break;
            }
            // return the constant object
            return pt;
        }
        // in case of identifiers
        case typeId:{
            pt2 = getsymbol(p->id.id, &error);
            fprintf(outFile, "\tpush\t%s\n", p->id.id ); 
            if (pt2 && error == "") {
                return pt2;
            }
            yyerror(error);
            error = "";
            return pt2;
        }
        // in case of operation
        case typeOpr: {
            switch (p->opr.oper)
            {
                case RETURN : {
                    pt = ex(p->opr.op[0], 0, outFile);
                    return pt;
                }
                // in case of calling 
                case 'q' : {
                    pt = ex(p->opr.op[0], 0, outFile);
                    return pt;
                }
                case ':' : {
                        ex(p->opr.op[1],0, outFile); 
                        return ex(p->opr.op[0],0, outFile);
                }
                // in case of function call 
                case 't' : {
                    var = p->opr.op[0]->id.id;                      // get the function name 
                    strcat(var, ":");
                    // find the function from its name to execute it
                    current = head;
                    while (current) {
                        if (strcmp(current->func_name, var) == 0) {
                            break;
                        }
                        else
                            current = current->next_function;
                    }
                    if (current == NULL) {
                        error = "No function exists with that name ";
                        yyerror(error);
                        error = "";
                        return NULL;
                    }
                    // execute the function body
                    pt = ex(p->opr.op[1], 0, outFile);
                    char * label = var;
                    label[strlen(label) -1 ] = '\0';
                    fprintf(outFile, "\tJMP\t%s\n", label);
                    return pt;
                }
                // incase of parameters for functions
                case 'r' : {
                    pt = ex(p->opr.op[0], 0 , outFile);
                    type =  pt->type;                               // get the function parameter type
                    var =  p->opr.op[1]->id.id;                     // get the function parmeter name 
                    pt2 = insert(var, type, *pt, 0, 1, &error);
                    fprintf(outFile, "\tpop\t%s\n", var);
                    //head->parms_types[head->index]->type = type;
                    error = "";
                    return pt;
                } 
                // in case of value returned function declaration
                case FUNCTION : {
                    // get the function type and name
                    pt = ex(p->opr.op[0], 0 , outFile);
                    type =  pt->type;                 // tunction return type
                    var =  p->opr.op[1]->id.id;      // function name
                    // add the function to the symbol table
                    pt2 = insert(var, type, *pt, 0, 1 , &error);
                    // create the first function node
                    struct func * f = malloc(sizeof(struct func));
                    f->func_name = var;
                    //f->index = 0;
                    changeScope(1);
                    strcat(var, ":");
                    // declare the function parameters
                    fprintf(outFile, var);
                    ex(p->opr.op[2], 0, outFile);
                    // execute the function body
                    ex(p->opr.op[3], 0, outFile);
                    f->next_function = head;
                    head = f;
                    changeScope(0);
                    return NULL; 
                }
                // in case of void functions
                case VOIDFUNCTION : {
                    type = typeVoid;                // function type void
                    var = p->opr.op[0]->id.id;      // function name
                    // add the variable to the symbol table
                    pt2 = insert(var, type, *pt, 0, 1, &error);
                    // save the function needed data
                    struct func * f = malloc(sizeof(struct func));
                    f->func_name = var;
                    changeScope(1);
                    strcat(var, ":");
                    // declare the function parameters
                    fprintf(outFile, var);
                    ex(p->opr.op[1], 0, outFile);
                    ex(p->opr.op[2], 0, outFile);
                    f->next_function = head;
                    head = f;
                    changeScope(0);
                    return NULL; 

                }
                // in case of new scope 
                case ';' : {
                    switch (p->opr.nops) 
                    {
                        case 2: {
                            ex(p->opr.op[0],0, outFile); 
                            return ex(p->opr.op[1],0, outFile);
                        }
                        case 3: {
                            pt = ex(p->opr.op[0], 0 , outFile);
                            type =  pt->type;                                 // get the function parameter type
                            var =  p->opr.op[1]->id.id ;                     // get the function parmeter name name
                            pt2 = insert(var, type, *pt, 0, 1, &error);
                            fprintf(outFile, "\tpop\t%s\n", var);
                            error = "";
                            return ex(p->opr.op[2],0, outFile);    
                        }      
                        default:
                            break;
                    }
                    return pt;
                }
                case 's' : {
                    changeScope(1);
                    pt = ex(p->opr.op[0], 0, outFile);
                    changeScope(0);
                    return NULL;
                }
                // for variable declaration without initialization
                case 'd' :{
                    pt = ex(p->opr.op[0], 0 , outFile);
                    type =  pt->type;                 // variable type
                    var =  p->opr.op[1]->id.id;      // variable name
                    pt2 = insert(var, type, *pt, 0, 0, &error);
                    if(pt2 && error == "") {
                        return pt2;
                    }
                    yyerror(error);
                    error = "";
                    return NULL;
                }
                case ASSIGNMENT:{
                    switch (p->opr.nops) {
                        // var Assignment value
                        case 2: {
                            // get the variable name
                            char * var1 =  p->opr.op[0]->id.id;

                            // get the assigned value object
                            pt = ex(p->opr.op[1], 0, outFile);
                            if(pt){
                                // update the variable value
                                pt2 = insert(var1, typeND, *pt, 0, 1, &error);
                                fprintf(outFile, "\tpop\t%s\n", var1 );
                                // if update done successfully add the quadruples to the file
                                if (pt2 && error == ""){
                                    // Assign variable with value of another variable
                                    return pt2;
                                }
                                yyerror(error);
                            }
                            error = "";
                            return NULL;
                        }
                        // type var Assignment value 
                        case 3: {
                            // first get the variable type , name
                            pt = ex(p->opr.op[0],0, outFile);
                            type =  pt->type;                 // variable type
                            char * var1 =  p->opr.op[1]->id.id;      // variable name
                            // get the assigned value node (type and value)
                            pt = ex(p->opr.op[2], ASSIGNMENT, outFile);
                            // for any error in the value
                            if(!pt) return NULL;
                            // try to insert the variable in the symbol table 
                            pt2 = insert(var1, type, *pt, 0, 1, &error);
                            fprintf(outFile, "\tpop\t%s\n", var1 );
                            if (pt2 && error == "") {
                                return pt2;
                            } 
                            yyerror(error);
                            error = "";
                            return NULL;                          
                        }
                            
                        // type const Assignment value
                        case 4: {
                            // first get the variable type , name
                            pt = ex(p->opr.op[1],0, outFile);
                            type =  pt->type;                 // variable type
                            var =  p->opr.op[2]->id.id;      // variable name
                            // get the assigned value node (type and value)
                            pt = ex(p->opr.op[3], ASSIGNMENT, outFile);
                            // for any error in the value
                            if(!pt) return NULL;

                            if(pt){
                                // try to insert the variable in the symbol table 
                                pt2 = insert(var, type, *pt, 1, 1, &error);
                                if (pt2 && error == "") {
                                    fprintf(outFile, "\tpop\t%s\n", var);
                                    return pt2;
                                } 
                            } 
                            error = "";
                            return NULL;
                        }
                        default:
                            break;
                    }
                }
                default:
                    break;    
            }
        }
        // in case of data type defining
        case typeDef: {
            pt->type = p->typ.type; 
            return pt;
        }
    }
return NULL;
}
 
// parser connected by this function
void execute(nodeType *p){
    FILE* outFile;
    outFile = fopen("output/assembly.txt", "a");
    // first execute the program
    ex(p, 0, outFile);
    // print the symbol table after program execution
    printSymbolTable();
    fclose(outFile);
}
