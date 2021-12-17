// Name: Kant Tantasathien


//*************************************************************************
// Node class definition
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to *not* put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <string>

struct Node
{
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};

typedef Node *ListType; //ListType now becomes Node*

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

//insert front method
ListType list_insert(ListType root, const std::string &theKey, int theValue);
//remove front method
ListType list_remove(ListType root, const std::string &theKey, bool &didRemove);
//lookup whether a value is inside the linked list
ListType list_lookup(ListType root, const std::string &theKey);
//print off all the nodes in the list
void list_print(ListType root);
//returns the size of the linked list
int list_size(ListType root);
//delete every node in the list
void list_clear(ListType root);

// keep the following line at the end of the file
#endif
