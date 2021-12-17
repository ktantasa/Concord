// Name: Kant Tantasathien

// Table.cpp  Table class implementation

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;

// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"

//*************************************************************************

/*/
Table default constructor
/*/
Table::Table()
{
   listArray = new ListType[HASH_SIZE];
   hashSize = HASH_SIZE;
   numberOfEntries = 0;
   initialize();
   assert(isValid());
}

/*/
Table Parameterized constructor
@param hSize - Size of the hash array
/*/
Table::Table(unsigned int hSize)
{
   listArray = new ListType[hSize];
   hashSize = hSize;
   numberOfEntries = 0;
   initialize();
   assert(isValid());
}
/*/
Table destructor
/*/
Table::~Table()
{
   if (listArray != nullptr)
   {
      for (int i = 0; i < hashSize; i++)
      {
         list_clear(listArray[i]);
      }
      delete[] listArray;
      listArray = nullptr;
   }
}
/*/
Table Lookup Method
Retrieves item from the table based off their index
@param key - index of the item in which we want to lookup
@return the value at the index or null
/*/
int *Table::lookup(const string &key)
{
   assert(isValid());
   int hash = hashCode(key);
   ListType node = list_lookup(listArray[hash], key);
   if (node == nullptr)
   {
      return nullptr;
   }
   return &(node->value);
}

/*/
Table Remove Method
Removes item from the table based off their index
@param key - index of the item in which we want to lookup
@return whether the value is removed or not
/*/
bool Table::remove(const string &key)
{
   assert(isValid());
   int hash = hashCode(key);
   bool didRemove = false;
   listArray[hash] = list_remove(listArray[hash], key, didRemove);
   if (didRemove)
   {
      numberOfEntries--;
   }
   return didRemove;
}

/*/
Table Insert Method
Insert item from the table based off their index
@param key - index of the item in which we want to lookup
@return whether the value was inserted or not
/*/
bool Table::insert(const string &key, int value)
{
   assert(isValid());
   int hash = hashCode(key);
   listArray[hash] = list_insert(listArray[hash], key, value);
   numberOfEntries++;
   return true;
}

/*/
Table Return NumEntries Method
Returns the number of entries that has been inserted to the table
@return number of entries
/*/
int Table::numEntries() const
{
   return numberOfEntries;
}

/*/
Print method
prints all of the values in the table
/*/
void Table::printAll() const
{
   assert(isValid());
   for (int i = 0; i < hashSize; ++i)
   {
      list_print(listArray[i]);
   }
}

/*/
Methods to tell how many value in a chain.
@param output stream to write to
/*/
void Table::hashStats(ostream &out) const
{
   assert(isValid());
   int count = 0;
   int chain = 0;
   for (int i = 0; i < hashSize; ++i)
   { //loop through all of the hash items.
      if (listArray[i] != nullptr)
      { //if something exists at that item
         count++;
         int tmp = list_size(listArray[i]);
         if (tmp > chain)
         {
            chain = tmp;
         }
      }
   }
   out << "number of buckets: " << hashSize << endl;
   out << "number of entries: " << numberOfEntries << endl;
   out << "number of non-empty buckets: " << count << endl;
   out << "longest chain: " << chain << endl;
}

// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const
{

   // Note: calls a std library hash function for string (it uses the good hash
   //   algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashSize;
}

// add definitions for your private methods here
void Table::initialize()
{
   for (int i = 0; i < hashSize; ++i)
   {
      listArray[i] = nullptr;
   }
}

//Make sure if listArray isn't null
//Make sure that
bool Table::isValid() const
{
   return (listArray != nullptr) && (hashSize > 0);
}
