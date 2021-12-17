// Name: Kant Tantasathien


// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {

   ListType node = nullptr;
   node = list_insert(node,"test1",1);
   cout<<"insert first node: test1 => " << list_lookup(node,"test1")->value << endl;

   node = list_insert(node,"test2",2);
   cout<<"insert second node: test2 => " << list_lookup(node,"test2")->value << endl;
   list_print(node);

   bool didRemove = false;
   node = list_remove(node, "test2", didRemove);
   cout<<"remove second node: test2 => " << boolalpha << didRemove << endl;
   list_print(node);
   cout << "list size: " << list_size(node) << endl;
   list_clear(node);
   node = nullptr;
   cout << "list size after clear: " << list_size(node) << endl;
   
   return 0;
}
