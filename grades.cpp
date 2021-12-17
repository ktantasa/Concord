// Name: Kant Tantasathien

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

vector<string> getUserInput();                                 //forward declaration of the userInput function
string handleUser(Table *grades);                              //forward declaration of the handleUser function
void handleInsert(Table *grades, const vector<string> &input); //forward declaration of the handleInsert function
void handleChange(Table *grades, const vector<string> &input); //forward declaration of the handleChange function
void handleLookup(Table *grades, const vector<string> &input); //forward declaration of the handleLookup function
void handleRemove(Table *grades, const vector<string> &input); //forward declaration of the handleRemove function
void showHelp();                                               //forward declaration of the showHelp function

int main(int argc, char *argv[])
{

   // gets the hash table size from the command line

   int hashSize = Table::HASH_SIZE;

   Table *grades; // Table is dynamically allocated below, so we can call
   // different constructors depending on input from the user.

   if (argc > 1)
   {
      hashSize = atoi(argv[1]); // atoi converts c-string to int

      if (hashSize < 1)
      {
         cout << "Command line argument (hashSize) must be a positive number"
              << endl;
         return 1;
      }

      grades = new Table(hashSize);
   }
   else
   { // no command line args given -- use default table size
      grades = new Table();
   }

   grades->hashStats(cout);

   // add more code here
   // Reminder: use -> when calling Table methods, since grades is type Table*
   while (handleUser(grades) != "quit")
      ;
   delete grades;
   return 0;
}

/*/
 *  Method that handle different type of user input
 *  @return the command that was given. Eg. insert/change..
/*/
string handleUser(Table *grades)
{
   vector<string> input = getUserInput();
   if (input.at(0) == "insert")
   {
      handleInsert(grades, input);
   }
   else if (input.at(0) == "change")
   {
      handleChange(grades, input);
   }
   else if (input.at(0) == "lookup")
   {
      handleLookup(grades, input);
   }
   else if (input.at(0) == "remove")
   {
      handleRemove(grades, input);
   }
   else if (input.at(0) == "print")
   {
      grades->printAll();
   }
   else if (input.at(0) == "size")
   {
      cout << "size: " << grades->numEntries() << " entries" << endl;
   }
   else if (input.at(0) == "stats")
   {
      grades->hashStats(cout);
   }
   else if (input.at(0) == "help")
   {
      showHelp();
   }
   return input.at(0);
}

/*/
 *  Method that user's insert request
/*/
void handleInsert(Table *grades, const vector<string> &input)
{
   int newScore = stoi(input.at(2)); //string to integer, table is set to hold integer
   grades->insert(input.at(1), newScore);
}
/*/
 *  Method that user's change request
/*/
void handleChange(Table *grades, const vector<string> &input)
{
   int newScore = stoi(input.at(2));
   if (!grades->remove(input.at(1)))
   {
      cout << "Student not found" << endl;
      return;
   }
   grades->insert(input.at(1), newScore);
}
/*/
 *  Method that user's handleLookup request
/*/
void handleLookup(Table *grades, const vector<string> &input)
{
   int *newScore = grades->lookup(input.at(1));
   if (newScore == nullptr)
   {
      cout << "Student not found" << endl;
      return;
   }
   cout << input.at(1) << ": " << *newScore << endl;
}
/*/
 *  Method that user's remove request
/*/
void handleRemove(Table *grades, const vector<string> &input)
{
   if (!grades->remove(input.at(1)))
   {
      cout << "Student not found" << endl;
   }
}
/*/
 *  Method that user's showHelp request
/*/
void showHelp()
{
   cout << "Usage functions" << endl;
   cout << "insert name score    : inserts student into grades" << endl;
   cout << "change name newscore : changes student grades inside system" << endl;
   cout << "lookup name          : displays student score" << endl;
   cout << "remove name          : removes student from grades" << endl;
   cout << "print                : print all student in system" << endl;
   cout << "size                 : print number of student in system" << endl;
   cout << "stats                : print system statistics" << endl;
   cout << "help                 : show this help" << endl;
   cout << "quit                 : exit the program" << endl;
}
/*/
 *  Method to help get UserInput
 *  @return a vector of string representing the word entered by the user
/*/
vector<string> getUserInput()
{
   cout << "cmd> ";
   vector<string> output;
   string token;
   string line;
   size_t position = 0;

   getline(cin, line);
   while ((position = line.find(" ")) != string::npos) //While there are still spaces
   {
      token = line.substr(0, position); //grab all the letters from the start of the string to the space I have found
      output.push_back(token);          //store those letters in the output vector
      line.erase(0, position + 1);      //erasing the letters and the space
   }
   output.push_back(line);
   transform(output.at(0).begin(), output.at(0).end(), output.at(0).begin(), [](unsigned char c)
             { return tolower(c); });
   return output;
}
