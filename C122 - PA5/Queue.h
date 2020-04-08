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

#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H
#include <iostream>
using namespace std;

//Computer Science 122 Lecture copy-pasted code given to us in Lecture 9 attachment under Content in Blackboard

// DynamicQueue template
class DynamicQueue
{
private:
    // Structure for the queue nodes
    struct QueueNode
    {
        int attack;			// Value in a node
        int defense;
        char name[40];
        char type[20];
        QueueNode* next;	// Pointer to the next node
    };

    QueueNode* front;  // The front of the queue
    QueueNode* rear;   // The rear of the queue
    int QueueItems;      // Number of items in the queue
public:
    // Constructor
    DynamicQueue();

    // Destructor
    ~DynamicQueue();

    // Queue operations
    void enqueue(card hand[5], int ele);
    void dequeue();
    bool isEmpty() const;
    void clear();
    void display();
    string display_front();
    int get_front_attack();
    int get_front_defense();

};


#endif

