#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "symbolTable.h"
#include "ops.h"
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
static int lbl;
static int switch_lbl;
static int case_lbl;
static int reg;

// initializations
char* var;                                                      // identifier name
char* error = "";                                               // any semantic error
int prev_line, current_line;




void execute(nodeType *p, FILE * outFile);
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
                fprintf(outFile,"\tpush\t%s \n", operand->id.id); 
                return pt2;
            }
            // ERROR
            yyerror(error);
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
                    fprintf(outFile,"\tpush\t%d \n", operand->con.iValue);
                    break;
                }
                case typeFloat: {
                    // TODO: print push opr.op[0]->con.fValue
                    fprintf(outFile,"\tpush\t%f\n", operand->con.fValue);
                    break;
                }
                case typeBool: {
                    // TODO: print push opr.op[0]->con.iValue
                    fprintf(outFile,"\tpush\t%d\n", operand->con.iValue);
                    break;
                }
                case typeChar: {
                    // TODO: print push opr.op[0]->con.cValue
                    fprintf(outFile,"\tpush\t%c\n", operand->con.cValue);
                    break;
                }
                case typeString: {
                    // TODO: print push opr.op[0]->con.sValue
                    fprintf(outFile,"\tpush\t%s\n", operand->con.sValue);
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
    int lbl1, lbl2, lbl3, regist;
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
                    pt->iValue = p->con.iValue;
                    pt->type = p->con.type;
                    fprintf(outFile, "\tPush\t%d\n", p->con.iValue );
                    break;
                }
                case typeFloat: {
                    pt->fValue = p->con.fValue;
                    pt->type = p->con.type;
                    fprintf(outFile, "\tpush\t%f\n", p->con.fValue );
                    break;
                }
                case typeBool: {
                    pt->iValue = p->con.iValue;
                    pt->type = p->con.type;
                    fprintf(outFile, "\tpush\t%d\n", p->con.iValue );
                    break;
                }
                case typeChar: {
                    pt->cValue = p->con.cValue;
                    pt->type = p->con.type;
                    fprintf(outFile, "\tpush\t\'%c\'\n", p->con.cValue );
                    break;
                }
                case typeString: {
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
                // bi-ops
                case PLUS :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = plus(operand1, operand2);
                        fprintf(outFile,"\tplus\n");                        
                        return result;
                    }
                case MINUS :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = minus(operand1, operand2);
                        fprintf(outFile,"\tminus\n");                        
                        return result;
                    }
                case MUL :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = mul(operand1, operand2);
                        fprintf(outFile,"\tmul\n");
                        return result;
                    }
                case DIV :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = divide(operand1, operand2);
                        fprintf(outFile,"\tdiv\n");
                        return result;
                    }
                case MOD :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = mod(operand1, operand2);
                        fprintf(outFile,"\tmod\n");
                        return result;
                    }
                case G :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = greater(operand1, operand2);
                        fprintf(outFile,"\tcompGT\n");
                        return result;
                    }
                case L :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = less(operand1, operand2);
                        fprintf(outFile,"\tcompLT\n");
                        return result;
                    }
                case GE :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = greaterEqual(operand1, operand2);
                        fprintf(outFile,"\tcompGE\n");
                        return result;
                    }
                case LE :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = lessEqual(operand1, operand2);
                        fprintf(outFile,"\tcompLE\n");
                        return result;
                    }
                case EQEQ :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = eqEq(operand1, operand2);
                        fprintf(outFile,"\tcompEQ\n");
                        return result;
                    }
                case NOTEQ :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = notEq(operand1, operand2);
                        fprintf(outFile,"\tcompNOTEQ\n");
                        return result;
                    }
                case AND :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = and(operand1, operand2);
                        fprintf(outFile,"\tand\n");
                        return result;
                    }
                case OR :{
                        struct conNodeType* operand1 = biOP(p->opr.op[0], pt, outFile);
                        struct conNodeType* operand2 = biOP(p->opr.op[1], pt, outFile);
                        struct conNodeType* result = or(operand1, operand2);
                        fprintf(outFile,"\tor\n");
                        return result;
                    }
                
                case WHILE:{
                    fprintf(outFile,"L%03d:\n", lbl1 = lbl++);
                    ex(p->opr.op[0], 0, outFile);
                    fprintf(outFile,"\tjz\tL%03d\n", lbl2 = lbl++);
                    ex(p->opr.op[1], 0, outFile);
                    fprintf(outFile,"\tjmp\tL%03d\n", lbl1);
                    fprintf(outFile,"L%03d:\n", lbl2);
                    break;
                }

                case DO:{
                    fprintf(outFile,"L%03d:\n", lbl1 = lbl++);
                    ex(p->opr.op[0], 0, outFile);
                    ex(p->opr.op[1], 0, outFile);
                    fprintf(outFile,"\tjz\tL%03d\n", lbl2 = lbl++);
                    fprintf(outFile,"\tjmp\tL%03d\n", lbl1);
                    fprintf(outFile,"L%03d:\n", lbl2);
                    break;
                }

                case FOR:{
                    ex(p->opr.op[0], 0, outFile);
                    fprintf(outFile,"L%03d:\n", lbl1 = lbl++);
                    ex(p->opr.op[1], 0, outFile);
                    fprintf(outFile,"\tjz\tL%03d\n", lbl2 = lbl++);
                    ex(p->opr.op[3], 0, outFile);
                    ex(p->opr.op[2], 0, outFile);
                    fprintf(outFile,"\tjmp\tL%03d\n", lbl1);
                    fprintf(outFile,"L%03d:\n", lbl2);
                    break;
                }


                case IF:{
                    ex(p->opr.op[0], 0, outFile);
                    if (p->opr.nops > 2) {
                        /* if else */
                        fprintf(outFile,"\tjz\tL%03d\n", lbl1 = lbl++);
                        ex(p->opr.op[1], 0, outFile);
                        fprintf(outFile,"\tjmp\tL%03d\n", lbl2 = lbl++);
                        fprintf(outFile,"L%03d:\n", lbl1);
                        ex(p->opr.op[2], 0, outFile);
                        fprintf(outFile,"L%03d:\n", lbl2);
                    } else {
                        /* if */
                        fprintf(outFile,"\tjz\tL%03d\n", lbl1 = lbl++);
                        ex(p->opr.op[1], 0, outFile);
                        fprintf(outFile,"L%03d:\n", lbl1);
                    }
                    break;
                }

                case SWITCH:{
                    pt2 = getsymbol(p->opr.op[0]->id.id, &error);
                    if (pt2 && error == "") {
                        // fprintf(outFile,"L%03d: mov\tR%03d, %s\n", lbl1 = lbl++, regist = reg++, p->opr.op[0]->id.id); 
                        fprintf(outFile, "L%03d: \tpush\t%s\n",lbl1 = lbl++, p->opr.op[0]->id.id);
                        fprintf(outFile, "\tpop\tR%03d\n", regist = reg++);
                        ex(p->opr.op[1], 0, outFile);
                        ex(p->opr.op[2], 0, outFile);
                        fprintf(outFile, "S%03d:\n", lbl3 = switch_lbl++);
                        // add beyond++
                        return pt2;
                    }
                    printf(error);
                    printf("\n");
                    error = "";
                    break;
                }

                case CASE:{
                    ex(p->opr.op[0], 0, outFile);
                    caseHandler(p, outFile, reg);  
                    fprintf(outFile,"\tjz\tC%03d\n", lbl3 = case_lbl++);
                    // body
                    ex(p->opr.op[2], 0, outFile);
                    // jmp out
                    fprintf(outFile,"\tjmp\tS%03d\n", switch_lbl);
                    fprintf(outFile, "C%03d:\n", lbl3);

                    break;
                }

                case DEFAULT:{
                    ex(p->opr.op[0], 0, outFile);
                    break;
                }

                case BREAK:{
                    
                    break;
                }
                case UMINUS:{   
                    struct conNodeType* operand = ex(p->opr.op[0], 0, outFile);
                    struct conNodeType* result = uminus(operand);
                    fprintf(outFile,"\tneg\n");
                    return result;
                }
                
                case RETURN : {
                    pt = ex(p->opr.op[0], 0, outFile);
                    //fprintf(outFile,"\tRET\n");
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
                    char * v2 = malloc(strlen(var)*10);
                    strcpy(v2, var);
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
                    var[strlen(var) -1] = '\0';
                    fprintf(outFile, "\tEND\t%s\n", v2);
                    return NULL; 
                }
                // in case of void functions
                case VOIDFUNCTION : {
                    type = typeVoid;                // function type void
                    var = p->opr.op[0]->id.id;      // function name
                    char * v2 = malloc(strlen(var)*10);
                    strcpy(v2, var);
                    // add the variable to the symbol table
                    pt2 = insert(var, type, *pt, 0, 1, &error);
                    // save the function needed data
                    struct func * f = malloc(sizeof(struct func));
                    f->func_name = var;
                    if (strcmp(var, "main") != 0)  {
                        changeScope(1);
                        strcat(var, ":");
                        // declare the function parameters
                        fprintf(outFile, var);
                        ex(p->opr.op[1], 0, outFile);
                        ex(p->opr.op[2], 0, outFile);
                        f->next_function = head;
                        head = f;
                        changeScope(0);
                        var[strlen(var) -1] = '\0';
                        fprintf(outFile, "\tEND\t%s\n", v2);
                        return NULL; 
                    }
                    strcat(var, ":");
                    // declare the function parameters
                    fprintf(outFile, var);
                    f->next_function = head;
                    head = f;
                    ex(p->opr.op[1], 0, outFile);
                    ex(p->opr.op[2], 0, outFile);
                    fprintf(outFile, "\tHLT\n");
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
void execute(nodeType *p, FILE* outFile){
    
    //outFile = assembly;
    //FILE * f = fopen("test_cases/function/assembly.txt", "a");
    // first execute the program
    ex(p, 0, outFile);
}
