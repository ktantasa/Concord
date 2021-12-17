// Name: Kant Tantasathien

#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

/*/
Constuctor for an empty List
@param theKey - address of the key in the hashtable
@param &theKey - address of the key
@param theValue - value assigned to the node
/*/
Node::Node(const string &theKey, int theValue)
{
   key = theKey;
   value = theValue;
   next = NULL;
}
/*/
Constuctor for a non empty List
@param theKey - address of the key in the hashtable
@param &theKey - address of the key
@param theValue - value assigned to the node
@param *n - where next in the list should be pointing to
/*/
Node::Node(const string &theKey, int theValue, Node *n)
{
   key = theKey;
   value = theValue;
   next = n;
}

//*************************************************************************
// put the function definitions for your list functions below

/*/
Insert front method
@param root - current node
@param &theKey - address of the key
@param theValue - value assigned to the node
@param *n - where next in the list should be pointing to
@return node - the new node inserted
/*/
ListType list_insert(ListType root, const std::string &theKey, int theValue)
{
   ListType node = new Node(theKey, theValue, root);
   return node;
}
/*/
Remove front method
@param root - current node pointer
@param &theKey - address of the key
@param didRemove - Passed it didRemove as a reference. The varaible started off as .
@return root - the linked list after the removal
/*/
ListType list_remove(ListType root, const std::string &theKey, bool &didRemove)
{
   didRemove = false;
   if (root == nullptr)
   { //if the method reaches the end of the list, return nullpointer
      return nullptr;
   }
   if (root->key == theKey)
   {
      ListType toRemove = root;
      root = toRemove->next;
      delete toRemove;
      didRemove = true;
      return root;
   }
   ListType node = root;
   while (node->next != nullptr && node->next->key != theKey)
   {
      node = node->next;
   }
   if (node->next != nullptr)
   {
      ListType toRemove = node->next;
      node->next = toRemove->next;
      delete toRemove;
      didRemove = true;
   }
   return root;
}
/*/
Lookup method
@param root - the current node
@param &theKey - address of the key
return the node if it exists, if it doesn't, the method will return null.
/*/
ListType list_lookup(ListType root, const std::string &theKey)
{
   if (root == nullptr)
   { //if the method reaches the end of the list, return nullpointer
      return nullptr;
   }
   ListType node = root;
   while (node != nullptr && node->key != theKey)
   {
      node = node->next;
   }
   return node;
}
/*/
Print method
@param root - the current linked list
/*/
void list_print(ListType root)
{
   if (root == nullptr)
   {
      return;
   }
   ListType node = root;
   while (node != nullptr)
   {
      cout << node->key << " " << node->value << endl;
      node = node->next;
   }
}
/*/
Size method - returns the size of the list using recursion
@param root - the current node
@return - how many nodes are in the list
/*/
int list_size(ListType root)
{
   if (root == nullptr)
   {
      return 0;
   }
   int count = 0;
   ListType node = root;
   while (node != nullptr)
   {
      count++;
      node = node->next;
   }
   return count;
}
/*/
Clear mathod - uses recursion to delete all the nodes
@param root - the current node
/*/
void list_clear(ListType root)
{
   if (root == nullptr)
   {
      return;
   }
   ListType node = root;
   while (node != nullptr)
   {
      ListType toRemove = node;
      node = node->next;
      delete toRemove;
   }
}