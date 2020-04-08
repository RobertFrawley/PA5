#include "Stack.h"

//********************************************
// The constructor creates an empty Stack.   *
//********************************************
DynamicStack::DynamicStack()
{
    top = nullptr;
    numItems = 0;
}

DynamicStack::~DynamicStack()
{
    cout << "Stack Successfully Deleted";
}

//creates new node, enters struct data into node, and pushes it down into the stack
void DynamicStack::push(int attack, int defense, char name[40], char type[20])
{
    StackNode* newNode;

    // Create a new node and store values there.
    newNode = new StackNode;
    newNode->attack = attack;
    newNode->defense = defense;
    strcpy(newNode->name, name);
    strcpy(newNode->type, type);
    newNode->next = top;
    top = newNode;

    // Update numItems.
    numItems++;
}

//checks if empty
bool DynamicStack::StackisEmpty() const
{
    bool status;

    if (numItems > 0)
        status = false;
    else
        status = true;
    return status;
}

//wasnt used, but checks if stack is full (full as in a full "deck")
bool DynamicStack::StackisFull() const
{
    bool status;
    
    if (numItems == 30)
        status = true;
    else
        status = false;

    return status;
}

//pops the stack, or in this case, pops the data into the hand array at initial arguement element, and frees the top node
void DynamicStack::pop(card hand[5], int ele)
{
    if (DynamicStack::StackisEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    else {
        hand[ele].attack = top->attack;
        hand[ele].defense = top->defense;
        strcpy(hand[ele].type, top->type);
        strcpy(hand[ele].name, top->name);

        StackNode* temp = top->next;
        free(top);
        top = temp;
    }

    numItems--;
}
