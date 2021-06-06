#include <iostream>
#include <string.h>
#include "symbolTable.h"
#include <unordered_map>

using namespace std;

// variable name , variable(type/value) , constant or not , initialized or not.
unordered_map <string, pair<conNodeType, pair<bool,bool> >> symbol_table;

/* for insertion we need the following:
    1) check if the variable exists or not                                  -- Done
    2) if exists and constant raise error                                   -- Done
    3) if exists and the value for update is not its type raise error       -- DONE
    4) if not exists put it in the symbol table                             -- DONE
*/

conNodeType* insert(char* var,conEnum var_type, struct conNodeType value, bool constant, bool with_value, char** error) { 
    // search for the variable
    if (symbol_table.find(var)  != symbol_table.end()) {
         // ---------------------------------------------- the variable found
        // in case of constant variable
        if(symbol_table[var].second.first) {
            *error = (char*)malloc(55*sizeof(char)); 
            strcpy(*error, "Error: Can't update constant variable ");
            //cout << "Error : Can't update constant variable \n";
            return NULL;
        }

        if(var_type != typeND && var_type != value.type) {
            *error = (char*)malloc(55*sizeof(char)); 
            strcpy(*error, "Error: Type Missmatch ");
            //cout << "Error : Type Missmatch \n";
            return NULL;        
        }

        if (symbol_table[var].first.type != value.type) {
            *error = (char*)malloc(55*sizeof(char)); 
            strcpy(*error, "Error: Type Missmatch ");
            cout << "Error : Type Missmatch \n";
            return NULL;     
        }

        //cout << "normal update \n";
        // normal update
        symbol_table.at(var) = {value, {false, true}};
        return &symbol_table[var].first;

    } else {
        // --------------------------------------------------- new identifier
        if (var_type != value.type) {
            *error = (char*)malloc(55*sizeof(char)); 
            strcpy(*error, "Error: Type Missmatch ");
            //cout << "Error : Type Missmatch \n";
            return NULL;        
        }
        // insert the identifer
        symbol_table.insert( {var, {value, {constant, with_value}} });
        return &symbol_table[var].first;
    }

}

conNodeType* getsymbol(char* var , char** error){
    // search for the variable
    auto it = symbol_table.find(var);
    // if the variable not found add it 
    if(it == symbol_table.end()) {
        *error = (char*)malloc(55*sizeof(char)); 
        strcpy(*error, "Error: undeclared variable ");
        //cout << "Error : undeclared variable \n";
        return NULL;

    } else {
        // the variable found and has value
        if (symbol_table[var].second.second) {
            return &symbol_table[var].first;
        }
        // variable found but has no value
        *error = (char*)malloc(55*sizeof(char)); 
        strcpy(*error, "Error: Non-initialized variable ");
        return NULL;
    }
  }


void printSymbolTable(){ 
    for (auto& it: symbol_table) {
        switch (it.second.first.type)
        {
            case typeInt:
                cout << "variable Name: " << it.first << "      type: Integer     value : " << it.second.first.iValue << " constant : " << it.second.second.first <<"\n";
                break;
            case typeFloat:
                cout << "variable Name: " << it.first << "      type: Float       value : " << it.second.first.fValue <<  " constant : " << it.second.second.first <<"\n";
                break;
            case typeBool:
                cout << "variable Name: " << it.first << "      type: Boolean     value : " << it.second.first.iValue <<  " constant : " << it.second.second.first <<"\n";
                break;

            case typeChar:
                cout << "variable Name: " << it.first << "      type: Char        value : " << it.second.first.cValue <<  " constant : " << it.second.second.first <<"\n";
                break;

            case typeString:
                cout << "variable Name: " << it.first << "      type: String      value : " << it.second.first.sValue <<  " constant : " << it.second.second.first <<"\n";
                break;        
            default:
                break;
        }
    }
}