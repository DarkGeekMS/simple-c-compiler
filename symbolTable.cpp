#include <iostream>
#include <fstream>
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

// current symbol table
symbol_table cur_table;

void changeScope(int scope_dir) {
    // print symbol table upon scope switching
    //cout << "<---- UPON SWITCH ---->\n";
    //printSymbolTable();
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
        *error = (char*)malloc(128*sizeof(char)); 
        strcpy(*error, "Error: Void Functions have no return value ");
        return NULL;        
    }
    // intialize next table pointer
    symbol_table *next_table;
    next_table = &cur_table;
    // search for the variable
    while (next_table != NULL) {
        auto it = next_table->symtable.find(var);

        if(it != next_table->symtable.end()) {
            // ---------------------------------------------- the variable found
            // in case of constant variable
            if(next_table->symtable[var].second.first) {
                *error = (char*)malloc(128*sizeof(char)); 
                strcpy(*error, "Error: Can't update constant variable ");
                return NULL;
            }
            
            if (var_type != typeND) {
                *error = (char*)malloc(128*sizeof(char)); 
                strcpy(*error, "Error: Variable Re-declaration in the same scope is not allowed ");
                return NULL;                        
            }

            if (next_table->symtable[var].first.type != value.type) {
                *error = (char*)malloc(55*sizeof(char)); 
                strcpy(*error, "Error: Type Missmatch ");
                return NULL;          
            }
            
            next_table->symtable.at(var) = {value, {false, true}};
            return &next_table->symtable[var].first;

        }
        next_table = next_table->parent;
        
    } 
    // --------------------------------------------------- new identifier
    if (var_type == typeND) {
        *error = (char*)malloc(128*sizeof(char)); 
        strcpy(*error, "Error: Variable Must be declared before initialization ");
        return NULL;  

    }
    if (var_type != value.type && with_value == true && var_type != typeVoid) {
        *error = (char*)malloc(55*sizeof(char)); 
        strcpy(*error, "Error: Type Missmatch ");
        return NULL;        
        
    }
    
    // insert the identifer
    value.type =var_type;
    cur_table.symtable.insert( {var, {value, {constant, with_value}} });
    return &cur_table.symtable[var].first;
}

conNodeType* getsymbol(char* var , char** error){
    // intialize next table pointer
    symbol_table *next_table;
    next_table = &cur_table;
    // search for the variable
    while (next_table != NULL) {
        auto it = next_table->symtable.find(var);
        if(it != next_table->symtable.end()) {
            //the variable found and has value
            if (next_table->symtable[var].second.second) {
                return &next_table->symtable[var].first;
            }
            // variable found but has no value
            *error = (char*)malloc(55*sizeof(char)); 
            strcpy(*error, "Error: Non-initialized variable ");
            return &next_table->symtable[var].first;
        }
        next_table = next_table->parent;
    }
    *error = (char*)malloc(55*sizeof(char)); 
    strcpy(*error, "Error: undeclared variable ");
    return NULL;
}


void printSymbolTable(char* table_path){ 

    string path = string(table_path) + "/symbolTable.txt";
    ofstream table(path);
    table << "============================ TABLE ============================" << endl;
    //cout << " table size = " << cur_table.symtable.size()<<endl;
    for (auto& it: cur_table.symtable) {
        switch (it.second.first.type)
        {
            case typeInt:
                table << "variable Name: " << it.first << "      type: Integer     constant : " << it.second.second.first << " initialized " << it.second.second.second <<"\n";
                break;
            case typeFloat:
                table << "variable Name: " << it.first << "      type: Float       constant : " << it.second.second.first << " initialized " << it.second.second.second <<"\n";
                break;
            case typeBool:
                table << "variable Name: " << it.first << "      type: Boolean     constant : " << it.second.second.first << " initialized " << it.second.second.second <<"\n";
                break;

            case typeChar:
                table << "variable Name: " << it.first << "      type: Char        constant : " << it.second.second.first << " initialized " << it.second.second.second <<"\n";
                break;

            case typeString:
                table << "variable Name: " << it.first << "      type: String      constant : " << it.second.second.first << " initialized " << it.second.second.second <<"\n";
                break; 
            case typeVoid:
                if (it.first != "main")
                    table << "Function Name: " << it.first << "      type: Void   "  << " constant : " << it.second.second.first <<"\n";
                break;
            default:
                break;
        }
    }
    table << "===============================================================" << endl;
}