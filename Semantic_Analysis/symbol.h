#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <stdbool.h>
typedef enum {
    TY_INT,    // integer
    TY_REAL,  // real
    TY_CHAR,   // char
    TY_BOOL    // boolean
}Type1;

// Enumeration for the types supported in Pascal

// Entry structure to hold information about identifiers
typedef struct entry {
    char *id;              // Identifier name
    int type;             // Type1 of the identifier
    bool isSet;    
} entry;

// Symbol table structure
typedef struct table {
    entry *entries[100];   // Fixed-size array of pointers to entries
    int numEntries;        // Number of entries in the table
} table;

// Function prototypes
table *createTable();
entry *createEntry(char *id, int type);
bool insertEntry(table *t, char *id, int type);
bool searchEntry(table *t, char *id);
int getEntryType(table *t, char *id);
void checkEntry(table *t, char *id);
void setEntry(table *t, char *id);
void checkSet(table *t, char *id);
unsigned int hash(char *str);
table *changeScope(table *cur);
void chainTable(table *parent, table *child);


#endif // SYMBOLTABLE_H
