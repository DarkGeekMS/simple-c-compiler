#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "parser.h"
#include "y.tab.h"

struct conNodeType* plus(struct conNodeType* operand1, struct conNodeType* operand2) {
    if ((operand1->type == typeInt || operand1->type == typeFloat) && (operand2->type == typeInt || operand2->type == typeFloat)) {
        struct conNodeType* result = malloc(sizeof(struct conNodeType*));
        if(operand1->type == typeInt) {
            if(operand2->type == typeInt) {
                result->type = typeInt;
                result->iValue = operand1->iValue + operand2->iValue;
            } else {
                result->type = typeFloat;
                result->fValue = operand1->iValue + operand2->fValue;
            }
        }
        if(operand1->type == typeFloat) {
            result->type = typeFloat;
            if(operand2->type == typeInt) {
                result->iValue = operand1->fValue + operand2->iValue;
            } else {
                result->fValue = operand1->fValue + operand2->fValue;
            }
        }
        return result;
    }
    // ERROR
    printf("ERROR: Type mismatch!\n");
    return NULL;
}

struct conNodeType* minus(struct conNodeType* operand1, struct conNodeType* operand2) {
    if ((operand1->type == typeInt || operand1->type == typeFloat) && (operand2->type == typeInt || operand2->type == typeFloat)) {
        struct conNodeType* result = malloc(sizeof(struct conNodeType*));
        if(operand1->type == typeInt) {
            if(operand2->type == typeInt) {
                result->type = typeInt;
                result->iValue = operand1->iValue - operand2->iValue;
            } else {
                result->type = typeFloat;
                result->fValue = operand1->iValue - operand2->fValue;
            }
        }
        if(operand1->type == typeFloat) {
            result->type = typeFloat;
            if(operand2->type == typeInt) {
                result->iValue = operand1->fValue - operand2->iValue;
            } else {
                result->fValue = operand1->fValue - operand2->fValue;
            }
        }
        return result;
    }
    // ERROR
    printf("ERROR: Type mismatch!\n");
    return NULL;
}

struct conNodeType* mul(struct conNodeType* operand1, struct conNodeType* operand2) {
    if ((operand1->type == typeInt || operand1->type == typeFloat) && (operand2->type == typeInt || operand2->type == typeFloat)) {
        struct conNodeType* result = malloc(sizeof(struct conNodeType*));
        if(operand1->type == typeInt) {
            if(operand2->type == typeInt) {
                result->type = typeInt;
                result->iValue = operand1->iValue * operand2->iValue;
            } else {
                result->type = typeFloat;
                result->fValue = operand1->iValue * operand2->fValue;
            }
        }
        if(operand1->type == typeFloat) {
            result->type = typeFloat;
            if(operand2->type == typeInt) {
                result->iValue = operand1->fValue * operand2->iValue;
            } else {
                result->fValue = operand1->fValue * operand2->fValue;
            }
        }
        return result;
    }
    // ERROR
    printf("ERROR: Type mismatch!\n");
    return NULL;
}

struct conNodeType* divide(struct conNodeType* operand1, struct conNodeType* operand2) {
    if ((operand1->type == typeInt || operand1->type == typeFloat) && (operand2->type == typeInt || operand2->type == typeFloat)) {
        struct conNodeType* result = malloc(sizeof(struct conNodeType*));
        result->type = typeFloat;
        if(operand1->type == typeInt) {
            if(operand2->type == typeInt) {
                if(operand2->iValue == 0){
                    //ERROR
                    printf("ERROR: Division by zero!");
                    return NULL;
                }
                result->fValue = operand1->iValue / operand2->iValue;
            } else {
                if(operand2->fValue == 0){
                    //ERROR
                    printf("ERROR: Division by zero!");
                    return NULL;
                }
                result->fValue = operand1->iValue / operand2->fValue;
            }
        }
        if(operand1->type == typeFloat) {
            if(operand2->type == typeInt) {
                if(operand2->iValue == 0){
                    //ERROR
                    printf("ERROR: Division by zero!");
                    return NULL;
                }
                result->fValue = operand1->fValue / operand2->iValue;
            } else {
                if(operand2->fValue == 0){
                    //ERROR
                    printf("ERROR: Division by zero!");
                    return NULL;
                }
                result->fValue = operand1->fValue / operand2->fValue;
            }
        }
        return result;
    }
    // ERROR
    printf("ERROR: Type mismatch!\n");
    return NULL;
}

struct conNodeType* mod(struct conNodeType* operand1, struct conNodeType* operand2) {
    if ((operand1->type == typeInt) && (operand2->type == typeInt)) {
        struct conNodeType* result = malloc(sizeof(struct conNodeType*));
        result->type = typeInt;
        if(operand2->iValue == 0){
            //ERROR
            printf("ERROR: Division by zero!");
            return NULL;
        }
        result->iValue = operand1->iValue % operand2->iValue;
        return result;
    }
    // ERROR
    printf("ERROR: Type mismatch!\n");
    return NULL;
}

struct conNodeType* greater(struct conNodeType* operand1, struct conNodeType* operand2) {
    if ((operand1->type == typeInt || operand1->type == typeFloat) && (operand2->type == typeInt || operand2->type == typeFloat)) {
        struct conNodeType* result = malloc(sizeof(struct conNodeType*));
        result->type = typeBool;
        if(operand1->type == typeInt) {
            if(operand2->type == typeInt) {
                result->iValue = operand1->iValue > operand2->iValue;
            } else {
                result->iValue = operand1->iValue > operand2->fValue;
            }
        }
        if(operand1->type == typeFloat) {
            if(operand2->type == typeInt) {
                result->iValue = operand1->fValue > operand2->iValue;
            } else {
                result->iValue = operand1->fValue > operand2->fValue;
            }
        }
        return result;
    }
    // ERROR
    printf("ERROR: Type mismatch!\n");
    return NULL;
}

struct conNodeType* less(struct conNodeType* operand1, struct conNodeType* operand2) {
    if ((operand1->type == typeInt || operand1->type == typeFloat) && (operand2->type == typeInt || operand2->type == typeFloat)) {
        struct conNodeType* result = malloc(sizeof(struct conNodeType*));
        result->type = typeBool;
        if(operand1->type == typeInt) {
            if(operand2->type == typeInt) {
                result->iValue = operand1->iValue < operand2->iValue;
            } else {
                result->iValue = operand1->iValue < operand2->fValue;
            }
        }
        if(operand1->type == typeFloat) {
            if(operand2->type == typeInt) {
                result->iValue = operand1->fValue < operand2->iValue;
            } else {
                result->iValue = operand1->fValue < operand2->fValue;
            }
        }
        return result;
    }
    // ERROR
    printf("ERROR: Type mismatch!\n");
    return NULL;
}

struct conNodeType* greaterEqual(struct conNodeType* operand1, struct conNodeType* operand2) {
    if ((operand1->type == typeInt || operand1->type == typeFloat) && (operand2->type == typeInt || operand2->type == typeFloat)) {
        struct conNodeType* result = malloc(sizeof(struct conNodeType*));
        result->type = typeBool;
        if(operand1->type == typeInt) {
            if(operand2->type == typeInt) {
                result->iValue = operand1->iValue >= operand2->iValue;
            } else {
                result->iValue = operand1->iValue >= operand2->fValue;
            }
        }
        if(operand1->type == typeFloat) {
            if(operand2->type == typeInt) {
                result->iValue = operand1->fValue >= operand2->iValue;
            } else {
                result->iValue = operand1->fValue >= operand2->fValue;
            }
        }
        return result;
    }
    // ERROR
    printf("ERROR: Type mismatch!\n");
    return NULL;
}

struct conNodeType* lessEqual(struct conNodeType* operand1, struct conNodeType* operand2) {
    if ((operand1->type == typeInt || operand1->type == typeFloat) && (operand2->type == typeInt || operand2->type == typeFloat)) {
        struct conNodeType* result = malloc(sizeof(struct conNodeType*));
        result->type = typeBool;
        if(operand1->type == typeInt) {
            if(operand2->type == typeInt) {
                result->iValue = operand1->iValue <= operand2->iValue;
            } else {
                result->iValue = operand1->iValue <= operand2->fValue;
            }
        }
        if(operand1->type == typeFloat) {
            if(operand2->type == typeInt) {
                result->iValue = operand1->fValue <= operand2->iValue;
            } else {
                result->iValue = operand1->fValue <= operand2->fValue;
            }
        }
        return result;
    }
    // ERROR
    printf("ERROR: Type mismatch!\n");
    return NULL;
}

struct conNodeType* eqEq(struct conNodeType* operand1, struct conNodeType* operand2) {
    if ((operand1->type == typeInt || operand1->type == typeFloat) && (operand2->type == typeInt || operand2->type == typeFloat)) {
        struct conNodeType* result = malloc(sizeof(struct conNodeType*));
        result->type = typeBool;
        if(operand1->type == typeInt) {
            if(operand2->type == typeInt) {
                result->iValue = operand1->iValue == operand2->iValue;
            } else {
                result->iValue = operand1->iValue == operand2->fValue;
            }
        }
        if(operand1->type == typeFloat) {
            if(operand2->type == typeInt) {
                result->iValue = operand1->fValue == operand2->iValue;
            } else {
                result->iValue = operand1->fValue == operand2->fValue;
            }
        }
        return result;
    }
    // ERROR
    printf("ERROR: Type mismatch!\n");
    return NULL;
}

struct conNodeType* notEq(struct conNodeType* operand1, struct conNodeType* operand2) {
    if ((operand1->type == typeInt || operand1->type == typeFloat) && (operand2->type == typeInt || operand2->type == typeFloat)) {
        struct conNodeType* result = malloc(sizeof(struct conNodeType*));
        result->type = typeBool;
        if(operand1->type == typeInt) {
            if(operand2->type == typeInt) {
                result->iValue = operand1->iValue != operand2->iValue;
            } else {
                result->iValue = operand1->iValue != operand2->fValue;
            }
        }
        if(operand1->type == typeFloat) {
            if(operand2->type == typeInt) {
                result->iValue = operand1->fValue != operand2->iValue;
            } else {
                result->iValue = operand1->fValue != operand2->fValue;
            }
        }
        return result;
    }
    // ERROR
    printf("ERROR: Type mismatch!\n");
    return NULL;
}

struct conNodeType* and(struct conNodeType* operand1, struct conNodeType* operand2) {
    printf("types = %d, %d\n", operand1->type, operand2->type);
    if ((operand1->type == typeBool) && (operand2->type == typeBool)) {
        struct conNodeType* result = malloc(sizeof(struct conNodeType*));
        result->type = typeBool;
        result->iValue = operand1->iValue && operand2->iValue;
        return result;
    }
    // ERROR
    printf("ERROR: Type mismatch!\n");
    return NULL;
}

struct conNodeType* or(struct conNodeType* operand1, struct conNodeType* operand2) {
    if ((operand1->type == typeBool) && (operand2->type == typeBool)) {
        struct conNodeType* result = malloc(sizeof(struct conNodeType*));
        result->type = typeBool;
        result->iValue = operand1->iValue || operand2->iValue;
        return result;
    }
    // ERROR
    printf("ERROR: Type mismatch!\n");
    return NULL;
}

struct conNodeType* uminus(struct conNodeType* operand) {
    if ((operand->type == typeFloat) || (operand->type == typeInt)) {
        struct conNodeType* result = malloc(sizeof(struct conNodeType*));
        result->type = operand->type;
        if (operand->type == typeInt){
            result->iValue = -1 * operand->iValue;
        }
        else{
            result->fValue = -1 * operand->fValue;
        }
        return result;
    }
    // ERROR
    printf("ERROR: Type mismatch!\n");
    return NULL;
}