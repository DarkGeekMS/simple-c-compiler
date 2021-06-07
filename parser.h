#pragma once
#include <stdbool.h>

// we have 4 available nodes: constants , identifiers, operations, data types
typedef enum { typeCon, typeId, typeOpr, typeDef } nodeEnum;
// any variable cn have (or function can return) : constant/- int, float, string, char, boolen or something other ( not defined for any missed case)
typedef enum { typeInt, typeFloat, typeString, typeChar, typeBool, typeConst, typeND } conEnum; 

/* constants */

struct conNodeType{
    conEnum type;        // type of the constant value ( used to assign value for the identifiers)

    /* constant values */
    union 
    {
        int iValue; 
        float fValue;
        char* sValue;
        char cValue;
    };
    
};

/* identifiers */
struct idNodeType{
    // pointer to the identifiers table
    char* id; 

};


/* operators */
struct oprNodeType {
    int oper;                   /* operator */
    int nops;                   /* number of operands */
    struct nodeTypeTag *op[1];	/* operands, extended at runtime */
};

/* types */
struct typeNodeType {
    conEnum type;                     
} ;


typedef struct nodeTypeTag {
    nodeEnum type;              /* type of node */

    union {
        struct conNodeType con;        /* constants */
        struct idNodeType id;          /* identifiers */
        struct oprNodeType opr;        /* operators */
        struct typeNodeType typ;       /* types */
    };
} nodeType;