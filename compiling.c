
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "symbolTable.h"
#include "y.tab.h"

static int line_num = 1;

// initializations
char* var;                                                      // identifier name
char* error = "";                                               // any semantic error
int prev_line, current_line;

void execute(nodeType *p);
void yyerror(char *);

void addMOV( char* var, struct conNodeType value,  FILE* outFile) {
    switch (value.type){
        case typeInt: {
                fprintf(outFile, "MOV\t%s\t%d\n", var, value.iValue );
                break;
            }
        case typeFloat: {

            fprintf(outFile, "MOV\t%s\t%f\n", var, value.fValue );
            break;
        }
        case typeBool: {
            fprintf(outFile, "MOV\t%s\t%d\n", var, value.iValue );
            break;
        }
        case typeChar: {
            fprintf(outFile, "MOV\t%s\t\'%c\'\n", var, value.cValue );
            break;
        }
        case typeString: {
            fprintf(outFile, "MOV\t%s\t\"%s\"\t", var, value.sValue );
            break;
        }
        default:
            break;
    }
}

// TODO: all operations logic converted into assemble
struct conNodeType* ex(nodeType *p, int oper, FILE* outFile) {

    struct conNodeType* pt = malloc(sizeof(struct conNodeType*));   // to loop over the program expressions
    pt->type = typeND;
    struct conNodeType* pt2;
    conEnum type;
    //if no program exists return
    if (!p) return NULL;

    // loop over the possible expressions in the program
    switch(p->type) {
        
        // in case of constants , assigning any identifier a value
        case typeCon: {
            printf("inside con\n");
            printf(var);
            printf("\n");
            //pt2 = getsymbol(var, &error);
            if(oper != ASSIGNMENT) return NULL;
            // for any type assignment it follows : MOV var_name Value
            switch (p->con.type){
                case typeInt: {
                    printf(" INTEGER \n");
                    pt->iValue = p->con.iValue;
                    pt->type = p->con.type;
                    break;
                }
                case typeFloat: {
                    printf(" FLOAT \n");
                    pt->fValue = p->con.fValue;
                    pt->type = p->con.type;
                    break;
                }
                case typeBool: {
                    printf(" BOOL \n");
                    pt->iValue = p->con.iValue;
                    pt->type = p->con.type;
                    break;
                }
                case typeChar: {
                    printf(" CHAR \n");
                    pt->cValue = p->con.cValue;
                    pt->type = p->con.type;
                    break;
                }
                case typeString: {
                    printf(" STRING \n");
                    printf(p->con.sValue );                // problem in sValue 
                    printf("\n");
                    pt->sValue = p->con.sValue;
                    pt->type = p->con.type;
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
            printf("inside id\n");
            pt2 = getsymbol(p->id.id, &error);
            if (pt2 && error == "") {
                fprintf(outFile, "MOV\t%s\t\"%s\"\t", var, p->id.id );
                return pt2;
            }
            error = "";
            break;
        }
        // in case of operation
        case typeOpr: {
            printf("inside operation \n");
            switch (p->opr.oper)
            {
                // for variable declaration without initialization
                case 'd' :{
                    pt = ex(p->opr.op[0], 0 , outFile);
                    type =  pt->type;                 // variable type
                    var =  p->opr.op[1]->id.id;      // variable name
                    pt2 = insert(var, type, *pt, 0, 0, &error);
                    if(pt2 && error == "") {
                        return pt2;
                    }
                    printf(error);
                    printf("\n");
                    error = "";
                    return NULL;
                }
                case ASSIGNMENT:{
                    switch (p->opr.nops) {
                        // var Assignment value
                        case 2: {
                            // get the vriable name
                            var =  p->opr.op[0]->id.id;
                            //printf(var);
                            //printf("\n");
                            // get the assigned value object
                            pt = ex(p->opr.op[1], ASSIGNMENT, outFile);
                            //fprintf(outFile, "\n");
                            if(pt){
                                //printf("value exists \n");
                                // update the variable value
                                pt2 = insert(var, typeND, *pt, 0, 1, &error);
                                // if update done successfully add the quadruples to the file
                                if (pt2 && error == ""){
                                    addMOV(var, *pt2, outFile );
                                    return pt2;
                                }
                                printf(error);
                                printf("\n");
                            }
                            error = "";
                            return NULL;
                        }
                        // type var Assignment value 
                        case 3: {
                            //printf("inside type variable = value \n");
                            // first get the variable type , name
                            pt = ex(p->opr.op[0],0, outFile);
                            type =  pt->type;                 // variable type
                            var =  p->opr.op[1]->id.id;      // variable name
                            //printf(var);
                            //printf("\n");
                            // get the assigned value node (type and value)
                            pt = ex(p->opr.op[2], ASSIGNMENT, outFile);
                            //fprintf(outFile, "\n");
                            // for any error in the value
                            if(!pt) return NULL;

                            if(pt){
                                // try to insert the variable in the symbol table 
                                pt2 = insert(var, type, *pt, 0, 1, &error);
                                if (pt2 && error == "") {
                                    //printf("insertion done ! \n");
                                    addMOV(var, *pt2, outFile );
                                    return pt2;
                                } 
                                printf(error);
                                printf("\n");
                            } 
                            error = "";
                            return NULL;                          
                        }
                            
                        // type const Assignment value
                        case 4: {
                            //printf("inside const type variable = value \n");
                            // first get the variable type , name
                            pt = ex(p->opr.op[1],0, outFile);
                            type =  pt->type;                 // variable type
                            var =  p->opr.op[2]->id.id;      // variable name
                            //printf(var);
                            //printf("\n");
                            // get the assigned value node (type and value)
                            pt = ex(p->opr.op[3], ASSIGNMENT, outFile);
                            // for any error in the value
                            if(!pt) return NULL;

                            if(pt){
                                // try to insert the variable in the symbol table 
                                pt2 = insert(var, type, *pt, 1, 1, &error);
                                if (pt2 && error == "") {
                                    //printf("insertion done ! \n");
                                    addMOV(var, *pt2, outFile );
                                    return pt2;
                                } 
                                printf(error);
                                printf("\n");
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
            printf("inside type defining \n");
            pt->type = p->typ.type; 
            return pt;
        }

    }
return 0;
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
