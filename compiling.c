
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "symbolTable.h"
#include "ops.h"
#include "y.tab.h"

static int line_num = 1;

// initializations
char* var;                                                      // identifier name
char* error = "";                                               // any semantic error
int prev_line, current_line;

void execute(nodeType *p);
void yyerror(char *);
struct conNodeType* biOP(nodeType *operand, struct conNodeType* pt, FILE* outFile);
struct conNodeType* castCon (nodeType *p);
struct conNodeType* plus(struct conNodeType* operand1, struct conNodeType* operand2);
struct conNodeType* ex(nodeType *p, int oper, FILE* outFile);

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
            fprintf(outFile, "MOV\t%s\t\"%s\"\n", var, value.sValue );
            break;
        }
        default:
            break;
    }
}

struct conNodeType* castCon (nodeType *p){
    struct conNodeType* pt = malloc(sizeof(struct conNodeType*));
    pt->type = typeND;

    switch (p->con.type){
        case typeInt: {
            pt->iValue = p->con.iValue;
            pt->type = p->con.type;
            break;
        }
        case typeFloat: {
            pt->fValue = p->con.fValue;
            pt->type = p->con.type;
            break;
        }
        case typeBool: {
            pt->iValue = p->con.iValue;
            pt->type = p->con.type;
            break;
        }
        case typeChar: {
            pt->cValue = p->con.cValue;
            pt->type = p->con.type;
            break;
        }
        case typeString: {
            pt->sValue = p->con.sValue;
            pt->type = p->con.type;
            break;
        }
        default:
            break;
    }
    return pt;
}

struct conNodeType* biOP(nodeType *operand, struct conNodeType* pt, FILE* outFile){
    switch(operand->type) { 

        case typeId:{
            // TODO: check if exists in symbol table 
            struct conNodeType* pt2;
            pt2 = getsymbol(operand->id.id, &error);
            if (pt2 && error == "") {
                printf("push %s \n", operand->id.id); 
                return pt2;
            }
            // ERROR
            printf("ERROR: Variable %s not defined.\n", operand->id.id);
            return NULL;
        }


        case typeOpr: {
            pt = ex(operand, 0, outFile);
            return pt;
        }

        case typeCon: {
            switch(operand->con.type){
                // (2 * 4) + (5)
                case typeInt: {
                    // TODO: print push opr.op[0]->con.iValue
                    printf("push %d \n", operand->con.iValue);
                    break;
                }
                case typeFloat: {
                    // TODO: print push opr.op[0]->con.fValue
                    printf("push %f\n", operand->con.fValue);
                    break;
                }
                case typeBool: {
                    // TODO: print push opr.op[0]->con.iValue
                    printf("push %d\n", operand->con.iValue);
                    break;
                }
                case typeChar: {
                    // TODO: print push opr.op[0]->con.cValue
                    printf("push %c\n", operand->con.cValue);
                    break;
                }
                case typeString: {
                    // TODO: print push opr.op[0]->con.sValue
                    printf("push %s\n", operand->con.sValue);
                    break;
                }
                default:{
                    break;
                }

            }
            return castCon(operand);
        }
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
                    fprintf(outFile, "\tPUSH\t%d\n", p->con.iValue );
                    break;
                }
                case typeFloat: {
                    printf(" FLOAT \n");
                    pt->fValue = p->con.fValue;
                    pt->type = p->con.type;
                    fprintf(outFile, "\tpush\t%f\n", p->con.fValue );
                    break;
                }
                case typeBool: {
                    printf(" BOOL \n");
                    pt->iValue = p->con.iValue;
                    pt->type = p->con.type;
                    fprintf(outFile, "\tpush\t%d\n", p->con.iValue );
                    break;
                }
                case typeChar: {
                    printf(" CHAR \n");
                    pt->cValue = p->con.cValue;
                    pt->type = p->con.type;
                    fprintf(outFile, "\tpush\t\'%c\'\n", p->con.cValue );
                    break;
                }
                case typeString: {
                    printf(" STRING \n");
                    printf(p->con.sValue );                // problem in sValue 
                    printf("\n");
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
            printf("inside id\n");
            pt2 = getsymbol(p->id.id, &error);
            if (pt2 && error == "") {
                fprintf(outFile, "\tpush\t%s\n", p->id.id ); 
                return pt2;
            }
            printf(error);
            printf("\n");
            error = "";
            break;
        }
        // in case of operation
        case typeOpr: {
            printf("inside operation \n");
            switch (p->opr.oper)
            {


                // bi-ops
                case PLUS :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = plus(operand1, operand2);
                        printf("plus\n");
                        printf("result = %d\n", result->iValue);
                        
                        return result;
                    }
                case MINUS :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = minus(operand1, operand2);
                        printf("minus\n");
                        printf("result = %d\n", result->iValue);
                        
                        return result;
                    }
                case MUL :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = mul(operand1, operand2);
                        printf("mul\n");
                        printf("result = %d\n", result->iValue);
                        return result;
                    }
                case DIV :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = divide(operand1, operand2);
                        printf("div\n");
                        printf("result = %f\n", result->fValue);
                        return result;
                    }
                case MOD :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = mod(operand1, operand2);
                        printf("mod\n");
                        printf("result = %d\n", result->iValue);
                        return result;
                    }
                case G :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = greater(operand1, operand2);
                        printf("compGT\n");
                        printf("result = %d\n", result->iValue);
                        return result;
                    }
                case L :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = less(operand1, operand2);
                        printf("compLT\n");
                        printf("result = %d\n", result->iValue);
                        return result;
                    }
                case GE :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = greaterEqual(operand1, operand2);
                        printf("compGE\n");
                        printf("result = %d\n", result->iValue);
                        return result;
                    }
                case LE :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = lessEqual(operand1, operand2);
                        printf("compLE\n");
                        printf("result = %d\n", result->iValue);
                        return result;
                    }
                case EQEQ :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = eqEq(operand1, operand2);
                        printf("compEQ\n");
                        printf("result = %d\n", result->iValue);
                        return result;
                    }
                case NOTEQ :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = notEq(operand1, operand2);
                        printf("compNOTEQ\n");
                        printf("result = %d\n", result->iValue);
                        return result;
                    }
                case AND :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = and(operand1, operand2);
                        printf("and\n");
                        printf("result = %d\n", result->iValue);
                        return result;
                    }
                case OR :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = or(operand1, operand2);
                        printf("or\n");
                        printf("result = %d\n", result->iValue);
                        return result;
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
                    printf(error);
                    printf("\n");
                    error = "";
                    return NULL;
                }
                case ASSIGNMENT:{
                    switch (p->opr.nops) {
                        // var Assignment value
                        case 2: {
                            //printf("inside 2\n");
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
                                    // Assign variable with value of another variable
                                    fprintf(outFile, "\tpop\t%s\n", var);
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
                                    // Assign variable with value of another variable
                                    //if (p->opr.op[2]->type == typeId) {
                                    fprintf(outFile, "\tpop\t%s\n", var );
                                        //fprintf(outFile, "MOV\t%s\t%s\n", var, p->opr.op[2]->id.id);
                                    //    return pt2;
                                    //}
                                    //printf("insertion done ! \n");
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
                                    fprintf(outFile, "\tpop\t%s\n", var);
                                    //printf("insertion done ! \n");
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
