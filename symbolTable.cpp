#include <iostream>
#include <string.h>
#include "symbolTable.h"
#include <unordered_map>
#include <list>

using namespace std;

// variable name , variable(type/value) , constant or not , initialized or not.
struct symbol_table {
    unordered_map <string, pair<conNodeType, pair<bool, bool>>> symtable;
    symbol_table* parent = NULL;
    list <symbol_table*> children;
};

symbol_table cur_table;

/* for insertion we need the following:
    1) check if the variable exists or not                                  -- Done
    2) if exists and constant raise error                                   -- Done
    3) if exists and the value for update is not its type raise error       -- DONE
    4) if not exists put it in the symbol table                             -- DONE
*/

void changeScope(int scope_dir) {
    // print symbol table upon scope switching
    cout << "<---- UPON SWITCH ---->\n";
    printSymbolTable();
    // check for scopes update (0=>UP, 1=>DOWN)
    if (scope_dir == 1) {
        // create a new child to the current table
        symbol_table *prev_table = new symbol_table{cur_table};

        symbol_table *new_table = new symbol_table;

        new_table->parent = prev_table;

        prev_table->children.push_back(new_table);

        cur_table = *new_table;
    }
    else if (scope_dir == 0) {
        // move to the parent of the current table
        cur_table = *cur_table.parent;
    }
}

conNodeType* insert(char* var,conEnum var_type, struct conNodeType value, bool constant, bool with_value, char** error) { 
    if (value.type == typeVoid) {
        *error = (char*)malloc(55*sizeof(char)); 
        strcpy(*error, "Error: Void Functions have no return value ");
        //cout << "Error : Void Functions have no return value \n";
        return NULL;        
    }
    // search for the variable
    if (cur_table.symtable.find(var)  != cur_table.symtable.end()) {
         // ---------------------------------------------- the variable found
        // in case of constant variable
        if(cur_table.symtable[var].second.first) {
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

        if (cur_table.symtable[var].first.type != value.type) {
            *error = (char*)malloc(55*sizeof(char)); 
            strcpy(*error, "Error: Type Missmatch ");
            cout << "Error : Type Missmatch \n";
            return NULL;     
        }

        //cout << "normal update \n";
        // normal update
        cur_table.symtable.at(var) = {value, {false, true}};
        return &cur_table.symtable[var].first;

    } else {
        // --------------------------------------------------- new identifier
        if (var_type != value.type) {
            *error = (char*)malloc(55*sizeof(char)); 
            strcpy(*error, "Error: Type Missmatch ");
            //cout << "Error : Type Missmatch \n";
            return NULL;        
        }
        // insert the identifer
        cur_table.symtable.insert( {var, {value, {constant, with_value}} });
        return &cur_table.symtable[var].first;
    }

}

conNodeType* getsymbol(char* var , char** error){
    // intialize next table pointer
    symbol_table *next_table;
    next_table = &cur_table;
    // search for the variable
    while (next_table != NULL) {
        auto it = next_table->symtable.find(var);
        if(it != next_table->symtable.end()) {
            // the variable found and has value
            if (next_table->symtable[var].second.second) {
                return &next_table->symtable[var].first;
            }
            // variable found but has no value
            *error = (char*)malloc(55*sizeof(char)); 
            strcpy(*error, "Error: Non-initialized variable ");
            return NULL;
        }
        next_table = next_table->parent;
    }
    *error = (char*)malloc(55*sizeof(char)); 
    strcpy(*error, "Error: undeclared variable ");
    return NULL;
}


void printSymbolTable(){ 
    cout << "==================== TABLE ============================" << endl;
    for (auto& it: cur_table.symtable) {
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
    cout << "========================================================" << endl;
}