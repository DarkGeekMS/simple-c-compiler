#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "symbolTable.h"
#include "ops.h"
#include "y.tab.h"


static int line_num = 1;
static int lbl;


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
                fprintf(outFile,"push %s \n", operand->id.id); 
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
                    fprintf(outFile,"push %d \n", operand->con.iValue);
                    break;
                }
                case typeFloat: {
                    // TODO: print push opr.op[0]->con.fValue
                    fprintf(outFile,"push %f\n", operand->con.fValue);
                    break;
                }
                case typeBool: {
                    // TODO: print push opr.op[0]->con.iValue
                    fprintf(outFile,"push %d\n", operand->con.iValue);
                    break;
                }
                case typeChar: {
                    // TODO: print push opr.op[0]->con.cValue
                    fprintf(outFile,"push %c\n", operand->con.cValue);
                    break;
                }
                case typeString: {
                    // TODO: print push opr.op[0]->con.sValue
                    fprintf(outFile,"push %s\n", operand->con.sValue);
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
    int lbl1, lbl2;
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
            if(oper != ASSIGNMENT) return NULL;
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
                    fprintf(outFile, "push\t%f\n", p->con.fValue );
                    break;
                }
                case typeBool: {
                    // printf(" BOOL \n");
                    pt->iValue = p->con.iValue;
                    pt->type = p->con.type;
                    fprintf(outFile, "push\t%d\n", p->con.iValue );
                    break;
                }
                case typeChar: {
                    // printf(" CHAR \n");
                    pt->cValue = p->con.cValue;
                    pt->type = p->con.type;
                    fprintf(outFile, "push\t\'%c\'\n", p->con.cValue );
                    break;
                }
                case typeString: {
                    // printf(" STRING \n");
                    pt->sValue = p->con.sValue;
                    pt->type = p->con.type;
                    fprintf(outFile, "push\t\"%s\"\n", p->con.sValue );
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
            if (pt2 && error == "") {
                fprintf(outFile, "push\t%s\n", p->id.id ); 
                return pt2;
            }
            yyerror(error);
            error = "";
            return NULL;
        }
        // in case of operation
        case typeOpr: {
            switch (p->opr.oper)
            {
                // bi-ops
                case PLUS :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = plus(operand1, operand2);
                        fprintf(outFile,"plus\n");                        
                        return result;
                    }
                case MINUS :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = minus(operand1, operand2);
                        fprintf(outFile,"minus\n");                        
                        return result;
                    }
                case MUL :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = mul(operand1, operand2);
                        fprintf(outFile,"mul\n");
                        return result;
                    }
                case DIV :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = divide(operand1, operand2);
                        fprintf(outFile,"div\n");
                        return result;
                    }
                case MOD :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = mod(operand1, operand2);
                        fprintf(outFile,"mod\n");
                        return result;
                    }
                case G :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = greater(operand1, operand2);
                        fprintf(outFile,"compGT\n");
                        return result;
                    }
                case L :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = less(operand1, operand2);
                        fprintf(outFile,"compLT\n");
                        return result;
                    }
                case GE :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = greaterEqual(operand1, operand2);
                        fprintf(outFile,"compGE\n");
                        return result;
                    }
                case LE :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = lessEqual(operand1, operand2);
                        fprintf(outFile,"compLE\n");
                        return result;
                    }
                case EQEQ :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = eqEq(operand1, operand2);
                        fprintf(outFile,"compEQ\n");
                        return result;
                    }
                case NOTEQ :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = notEq(operand1, operand2);
                        fprintf(outFile,"compNOTEQ\n");
                        return result;
                    }
                case AND :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = and(operand1, operand2);
                        fprintf(outFile,"and\n");
                        return result;
                    }
                case OR :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = or(operand1, operand2);
                        fprintf(outFile,"or\n");
                        return result;
                    }
                
                case WHILE:{
                    fprintf(outFile,"L%03d:\n", lbl1 = lbl++);
                    ex(p->opr.op[0], 0, outFile);
                    fprintf(outFile,"jz\tL%03d\n", lbl2 = lbl++);
                    ex(p->opr.op[1], 0, outFile);
                    fprintf(outFile,"jmp\tL%03d\n", lbl1);
                    fprintf(outFile,"L%03d:\n", lbl2);
                    break;
                }

                case IF:{
                    ex(p->opr.op[0], 0, outFile);
                    if (p->opr.nops > 2) {
                        /* if else */
                        fprintf(outFile,"jz\tL%03d\n", lbl1 = lbl++);
                        ex(p->opr.op[1], 0, outFile);
                        fprintf(outFile,"jmp\tL%03d\n", lbl2 = lbl++);
                        fprintf(outFile,"L%03d:\n", lbl1);
                        ex(p->opr.op[2], 0, outFile);
                        fprintf(outFile,"L%03d:\n", lbl2);
                    } else {
                        /* if */
                        fprintf(outFile,"jz\tL%03d\n", lbl1 = lbl++);
                        ex(p->opr.op[1], 0, outFile);
                        fprintf(outFile,"L%03d:\n", lbl1);
                    }
                    break;
                }
                
                case 'r' : {
                    pt = ex(p->opr.op[0], 0 , outFile);
                    type =  pt->type;                               // get the function parameter type
                    var =  p->opr.op[1]->id.id;                     // get the function parmeter name name
                    pt2 = insert(var, type, *pt, 0, 0, &error);
                    error = "";
                    return NULL;
                } 
                // in case of value returned function declaration
                case FUNCTION : {
                    // get the function type and name
                    pt = ex(p->opr.op[0], 0 , outFile);
                    type =  pt->type;                 // tunction return type
                    var =  p->opr.op[1]->id.id;      // function name
                    // add the function to the symbol table
                    pt2 = insert(var, type, *pt, 0,0, &error);
                    // crete scope to add functions parameters in
                    changeScope(1);
                    //printf ("new scope for function \n");
                    pt = ex(p->opr.op[2], 0, outFile);
                    //pt2 = insert(var, type, *pt, 0,0, &error);
                    changeScope(0);
                    return NULL; 
                }
                case VOIDFUNCTION : {
                    //printf("void function \n");
                    type = typeVoid;                // function type void
                    var = p->opr.op[0]->id.id;      // function name
                    // add the variable to the symbol table
                    pt2 = insert(var, type, *pt, 0,0, &error);
                    // crete scope to add functions parameters in
                    changeScope(1);
                    //printf ("new scope for function \n");
                    pt = ex(p->opr.op[1], 0, outFile);
                    changeScope(0);
                    return NULL; 

                }
                // in case of new scope 
                case ';' : {
                    switch (p->opr.nops) 
                    {
                    case 2:
                        ex(p->opr.op[0],0, outFile); 
                        return ex(p->opr.op[1],0, outFile);
                    case 3:
                        pt = ex(p->opr.op[0], 0 , outFile);
                        type =  pt->type;                               // get the function parameter type
                        var =  p->opr.op[1]->id.id;                     // get the function parmeter name name
                        pt2 = insert(var, type, *pt, 0, 0, &error);
                        error = "";
                        return ex(p->opr.op[2],0, outFile);          
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
                            var =  p->opr.op[0]->id.id;
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
                                    fprintf(outFile, "pop\t%s\n", var);
                                    return pt2;
                                }
                                yyerror(error);
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
                            // get the assigned value node (type and value)
                            pt = ex(p->opr.op[2], ASSIGNMENT, outFile);
                            //fprintf(outFile, "\n");
                            // for any error in the value
                            if(!pt) return NULL;
                            // try to insert the variable in the symbol table 
                            pt2 = insert(var, type, *pt, 0, 1, &error);
                            //printf("here we set variable %s \n" , var);
                            if (pt2 && error == "") {
                                // Assign variable with value of another variable
                                //if (p->opr.op[2]->type == typeId) {
                                fprintf(outFile, "\tpop\t%s\n", var );
                                //    return pt2;
                                //}
                                return pt2;
                            } 
                            yyerror(error);
                            error = "";
                            return NULL;                          
                        }
                            
                        // type const Assignment value
                        case 4: {
                            // printf("inside const type variable = value \n");
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
                                    fprintf(outFile, "pop\t%s\n", var);
                                    //printf("insertion done ! \n");
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
            // printf("inside type defining \n");
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
