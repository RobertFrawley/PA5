#ifndef Lib
#define Lib

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <fstream>
#include <istream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct card
{
    int attack;            // Value in a node
    int defense;
    char name[40] = { '\0' };
    char type[20] = { '\0' };
};

#endif

#ifndef Stack_H
#define Stack_H

//our class for the deck
class DynamicStack
{
private:
    struct StackNode
    {
        int attack;            // Value in a node
        int defense;
        char name[40] = { "\0" };
        char type[20] = { "\0" };
        StackNode* next;	// Pointer to the next node
    };

    StackNode* top;  // The Top of the Stack
    int numItems;
public:
    // Constructor
    DynamicStack();

    // Destructor
   ~DynamicStack();

    // Stack operations
    void push(int attack, int defense, char name[40], char type[20]);
    void pop(card hand[5], int ele);
    bool StackisEmpty() const;
    bool StackisFull() const;
};

#endif