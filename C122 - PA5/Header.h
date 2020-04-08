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

//comments were mainly placed inside the Functions.cpp file

int main_menu(void);

void replace_specific(card deck1[30], card deck2[30]);

void display_deck(card deck[30]);

void display_hand(card hand[5]);

void trade_card(card deck1[30], card deck2[30]);

void duel(card deck1[30], card deck2[30]);

void shuffle(card deck1[30]);

int cointoss();
