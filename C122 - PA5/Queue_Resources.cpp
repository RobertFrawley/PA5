#include "Queue.h"

//********************************************
// The constructor creates an empty queue.   *
//********************************************
DynamicQueue::DynamicQueue()
{
    front = nullptr;
    rear = nullptr;
    QueueItems = 0;
}

//********************************************
// Destructor                                *
//********************************************
DynamicQueue::~DynamicQueue()
{
    cout << "Queue Successfully Deleted";
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************

void DynamicQueue::enqueue(card hand[5], int ele)
{
    QueueNode* newNode;

    // Create a new node and store num there.
    newNode = new QueueNode;
    newNode->attack = hand[ele].attack;
    newNode->defense = hand[ele].defense;
    strcpy(newNode->name, hand[ele].name);
    strcpy(newNode->type, hand[ele].type);
    newNode->next = nullptr;

    // Adjust front and rear as necessary.
    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    // Update numItems.
    QueueItems++;
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
void DynamicQueue::dequeue()
{
    QueueNode* temp = nullptr;

    if (isEmpty())
    {
        cout << "The queue is empty.\n";
    }
    else
    {

        // Remove the front node and delete it.
        temp = front;
        front = front->next;
        delete temp;

        // Update numItems.
        QueueItems--;
    }
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
bool DynamicQueue::isEmpty() const
{
    bool status;

    if (QueueItems > 0)
        status = false;
    else
        status = true;
    return status;
}

//********************************************
// Function clear dequeues all the elements  *
// in the queue. Unused                            *
//********************************************
void DynamicQueue::clear()
{
    while (!isEmpty())
        dequeue();
}

//displays everything in the queue
void DynamicQueue::display()
{
    QueueNode* temp = front;

    while (temp != NULL)
    {
        cout << left << setw(40) << temp->name << "ATK: " << setw(20) << temp->attack << "DEF: " << setw(15) << temp->defense << "Type: " << temp->type << endl;
        temp = temp->next;
    }
}

//displays the "frontmost" (oldest node in the queue) node
string DynamicQueue::display_front()
{
    return front->name;
}

//getter for oldest node's attack value
int DynamicQueue::get_front_attack()
{
    return front->attack;
}

//getter for oldest node's defense value
int DynamicQueue::get_front_defense()
{
    return front->defense;
}

