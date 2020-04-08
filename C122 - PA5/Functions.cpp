#include "Stack.h"
#include "Queue.h"
#include "Header.h"

//displays main menu
int main_menu(void)
{
    int choice = 0;

    do
    {
        system("cls");
        cout << "(1) Create Players\n(2) Add Specific Cards\n(3) Trade Between Players\n(4) Duel\n(5) Exit\n";

        cin >> choice;

    } while (choice < 1 || choice > 5);

    return choice;
}

//code to replace a specific card within a specific deck
void replace_specific(card deck1[30], card deck2[30])
{
    int choice, c_choice;
    system("cls");
    do {
        cout << "Which player wants to add a specific card?\n";
        cin >> choice;
        if (choice != 1 && choice != 2)
        {
            cout << "\nPlayer doesnt exist.\n\n";
        }
    } while (choice != 1 && choice != 2);


    system("cls");
    do {
        cout << "Which card do you wish to replace?:\n\n";
        if (choice == 1)
            display_deck(deck1);
        else
            display_deck(deck2);

        cin >> c_choice;
    } while (c_choice < 1 || c_choice > 30);
    c_choice--;

    string name, type;
    int attack, defense;

    cout << "\nEnter name of card:\n";
    cin >> name;
    cout << "\nEnter monster type of card:\n";
    cin >> type;
    cout << "\nEnter attack power of card:\n";
    cin >> attack;
    cout << "\nEnter defense power of card:\n";
    cin >> defense;

    if (choice == 1)
    {
        strcpy(deck1[c_choice].name, name.c_str());
        strcpy(deck1[c_choice].type, type.c_str());
        deck1[c_choice].attack = attack;
        deck1[c_choice].defense = defense;
    }
    else
    {
        strcpy(deck2[c_choice].name, name.c_str());
        strcpy(deck2[c_choice].type, type.c_str());
        deck2[c_choice].attack = attack;
        deck2[c_choice].defense = defense;
    }
}

//displays entire deck
void display_deck(card deck[30])
{
    for (int i = 0; i < 30; i++)
    {
        cout << left << (i + 1) << setw(2) << ". " << setw(40) << deck[i].name << "ATK: " << setw(20) << deck[i].attack << "DEF: " << setw(15) << deck[i].defense << "Type: " << deck[i].type << endl;
    }
}

//displays hand
void display_hand(card hand[5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << left << (i + 1) << setw(2) << ". " << setw(40) << hand[i].name << "ATK: " << setw(20) << hand[i].attack << "DEF: " << setw(15) << hand[i].defense << "Type: " << hand[i].type << endl;
    }
}

//code to trade a card. prompts a card to trade from both players, and then prompts both players to agree to the trade to successfully trade
void trade_card(card deck1[30], card deck2[30])
{
    int c_choice1, c_choice2;
    char p_choice1, p_choice2;

    system("cls");
    do {
        cout << "What does Player 1 wish to trade?:\n\n";
        display_deck(deck1);
        cin >> c_choice1;
    } while (c_choice1 < 1 || c_choice1 > 30);
    c_choice1--;

    system("cls");
    do {
        cout << "What does Player 2 wish to trade?:\n\n";
        display_deck(deck2);
        cin >> c_choice2;
    } while (c_choice2 < 1 || c_choice2 > 30);
    c_choice2--;

    system("cls");

    do {
        cout << "Does Player 1 agree?\n";
        cin >> p_choice1;
        cout << "\nDoes Player 2 agree?\n";
        cin >> p_choice2;
    } while (p_choice1 != 'y' && p_choice1 != 'n' && p_choice1 != 'Y' && p_choice1 != 'N' && p_choice2 != 'y' && p_choice2 != 'n' && p_choice2 != 'Y' && p_choice2 != 'N');

    if (p_choice1 == 'n' || p_choice1 == 'N' || p_choice2 == 'n' || p_choice2 == 'N')
    {
        system("cls");
        cout << "Trade Refused";
        system("pause");
        return;
    }
    else
    {
        card temp;
        temp = deck1[c_choice1];
        deck1[c_choice1] = deck2[c_choice2];
        deck2[c_choice2] = temp;
    }

    system("cls");
    cout << "Card Traded Successfully!";
    system("pause");
}

//The bulk of the scuff. Its hard to explain
void duel(card deck1[30], card deck2[30])
{
    DynamicStack Deck1, Deck2;
    DynamicQueue ATK1, DEF1, ATK2, DEF2;
    card temp;
    int LP1 = 8000, LP2 = 8000;

    system("cls");

    shuffle(deck1);
    shuffle(deck2);

    //pushes the deck into the nodes and then links them into the stack
    for (int i = 0; i < 30; i++)
    {
        Deck1.push(deck1[i].attack, deck1[i].defense, deck1[i].name, deck1[i].type);
        Deck2.push(deck2[i].attack, deck2[i].defense, deck2[i].name, deck2[i].type);
    }

    card hand1[5], hand2[5];

    //pops the hand out
    for (int i = 0; i < 5; i++)
    {
        Deck1.pop(hand1, i);
        Deck2.pop(hand2, i);
    }

    int face = cointoss(), oppoface = 0, round = 1;

    if (face == 1)
        cout << "Heads, Player 1 goes first!\n";
    else
        cout << "Tails, Player 2 goes first!\n";

    system("pause");

    //everything inside a big do while someone's LP is above 0
    do {

        int atk1 = 0, atk2 = 0, def1 = 0, def2 = 0;
        char ch1 = '\0', ch2 = '\0';

        //this allows the first turn player to choose the monsters to be placed in atk or def position
        //keeps looping until player chooses a monster for both positions that arent the same "element" within the hand array
        do {
            system("cls");

            cout << "Player " << face << ", which card do you place in attack position?:\n\n";

            if (face == 1)
                display_hand(hand1);
            else
                display_hand(hand2);

            if (face == 1)
                cin >> atk1;
            else
                cin >> atk2;

            cout << "\n\nPlayer " << face << ", which card do you place in defense position?:\n\n";

            if (face == 1)
                display_hand(hand1);
            else
                display_hand(hand2);

            if (face == 1)
                cin >> def1;
            else
                cin >> def2;

            if (atk1 == def1 && atk2 == def2)
                cout << "The cards chosen cannot be the same!\n";
            system("pause");

        } while (atk1 == def1 && atk2 == def2);

        //enqueues the chosen cards into the two queues for the positions
        if (face == 1)
        {
            ATK1.enqueue(hand1, (atk1 - 1));
            DEF1.enqueue(hand1, (def1 - 1));
        }
        else
        {
            ATK2.enqueue(hand2, (atk2 - 1));
            DEF2.enqueue(hand2, (def2 - 1));
        }

        if (face == 1)
            oppoface = 2;
        else
            oppoface = 1;

        //this allows the other player to do the same thing as above with minimal change in code
        //keeps looping to the same rules as above
        do {
            system("cls");

            cout << "Player " << oppoface << ", which card do you place in attack position?:\n\n";

            if (oppoface == 1)
                display_hand(hand1);
            else
                display_hand(hand2);

            if (oppoface == 1)
                cin >> atk1;
            else
                cin >> atk2;

            cout << "\n\nPlayer " << oppoface << ", which card do you place in defense position?:\n\n";

            if (oppoface == 1)
                display_hand(hand1);
            else
                display_hand(hand2);

            if (oppoface == 1)
                cin >> def1;
            else
                cin >> def2;

            if (atk1 == def1 && atk2 == def2)
                cout << "The cards chosen cannot be the same!\n";
            system("pause");

        } while (atk1 == def1 && atk2 == def2);

        //see: above
        if (oppoface == 1)
        {
            ATK1.enqueue(hand1, (atk1 - 1));
            DEF1.enqueue(hand1, (def1 - 1));
        }
        else
        {
            ATK2.enqueue(hand2, (atk2 - 1));
            DEF2.enqueue(hand2, (def2 - 1));
        }

        //allows player to choose the card they wish to use this round, which will be the frontmost, or oldest node within the queue.
        do {
            system("cls");

            cout << "Player " << face << ", Do you wish to attack or defend this round?:\n\n";

            if (face == 1)
            {
                cout << " Your Attack Position:\n\n";
                ATK1.display();
                cout << "\n\nYour Defense Position:\n\n";
                DEF1.display();
                cout << "\n\nOpponent's Attack Position:\n\n";
                ATK2.display();
                cout << "\n\nOpponent's Defense Position:\n\n";
                DEF2.display();
            }
            else
            {
                cout << "Your Attack Position:\n\n";
                ATK2.display();
                cout << "\n\nYour Defense Position:\n\n";
                DEF2.display();
                cout << "\n\nOpponent's Attack Position:\n\n";
                ATK1.display();
                cout << "\n\nOpponent's Defense Position:\n\n";
                DEF1.display();
            }

            if (face == 1)
                cin >> ch1;
            else
                cin >> ch2;

            if (ch1 != 'a' && ch1 != 'd' && ch1 != 'A' && ch1 != 'a' && ch1 != 'D' && ch2 != 'a' && ch2 != 'd' && ch2 != 'A' && ch2 != 'a' && ch2 != 'D')
                cout << "Incorrect Entry, characters only\n";
            system("pause");

        } while (ch1 != 'a' && ch1 != 'd' && ch1 != 'A' && ch1 != 'a' && ch1 != 'D' && ch2 != 'a' && ch2 != 'd' && ch2 != 'A' && ch2 != 'a' && ch2 != 'D');

        do {
            system("cls");

            cout << "Player " << oppoface << ", Do you wish to attack or defend this round?:\n\n";

            if (oppoface == 1)
            {
                cout << " Your Attack Position:\n\n";
                ATK1.display();
                cout << "\n\nYour Defense Position:\n\n";
                DEF1.display();
                cout << "\n\nOpponent's Attack Position:\n\n";
                ATK2.display();
                cout << "\n\nOpponent's Defense Position:\n\n";
                DEF2.display();
            }
            else
            {
                cout << "Your Attack Position:\n\n";
                ATK2.display();
                cout << "\n\nYour Defense Position:\n\n";
                DEF2.display();
                cout << "\n\nOpponent's Attack Position:\n\n";
                ATK1.display();
                cout << "\n\nOpponent's Defense Position:\n\n";
                DEF1.display();
            }

            if (oppoface == 1)
                cin >> ch1;
            else
                cin >> ch2;

            if (ch1 != 'a' && ch1 != 'd' && ch1 != 'A' && ch1 != 'a' && ch1 != 'D' && ch2 != 'a' && ch2 != 'd' && ch2 != 'A' && ch2 != 'a' && ch2 != 'D')
                cout << "Incorrect Entry, characters only\n";
            system("pause");

        } while (ch1 != 'a' && ch1 != 'd' && ch1 != 'A' && ch1 != 'a' && ch1 != 'D' && ch2 != 'a' && ch2 != 'd' && ch2 != 'A' && ch2 != 'a' && ch2 != 'D');

        system("cls");

        //using getters, calculates the post-battle changes to life points (if any)
        if ((ch1 == 'a' || ch1 == 'A') && (ch2 == 'a' || ch2 == 'A'))
        {
            cout << "Player 1's " << ATK1.display_front() << " vs " << "Player 2's " << ATK2.display_front() << endl;
            system("pause");

            if (ATK1.get_front_attack() > ATK2.get_front_attack()) // atk pos vs atk pos
            {
                LP2 = LP2 - (ATK1.get_front_attack() - ATK2.get_front_attack());
                cout << "Player 2 takes damage! Life points are now " << LP2 << endl;
            }
            else if (ATK1.get_front_attack() < ATK2.get_front_attack())
            {
                LP1 = LP1 - (ATK2.get_front_attack() - ATK1.get_front_attack());
                cout << "Player 1 takes damage! Life points are now " << LP1 << endl;
            }
            else
            {
                cout << "It does nothing..." << endl;
            }
            ATK1.dequeue();
            ATK2.dequeue();
        }
        else if ((ch1 == 'd' || ch1 == 'D') && (ch2 == 'd' || ch2 == 'D')) // def pos vs def pos
        {
            cout << "Player 1's " << DEF1.display_front() << " vs " << "Player 2's " << DEF2.display_front() << endl;
            system("pause");

            cout << "\nBoth monsters couldn't attack!\n";

            DEF1.dequeue();
            DEF2.dequeue();
        }
        else if ((ch1 == 'a' || ch1 == 'A') && (ch2 == 'd' || ch2 == 'D')) // player 1 atk pos vs player 2 def pos
        {
            cout << "Player 1's " << ATK1.display_front() << " vs " << "Player 2's " << DEF2.display_front() << endl;
            system("pause");
            if (ATK1.get_front_attack() > DEF2.get_front_defense())
            {
                LP2 = LP2 - (ATK1.get_front_attack() - DEF2.get_front_defense());
                cout << "Player 2 takes damage! Life points are now " << LP2 << endl;
            }
            else
                cout << "It does nothing..." << endl;

            ATK1.dequeue();
            DEF2.dequeue();
        }
        else if ((ch1 == 'd' || ch1 == 'D') && (ch2 == 'a' || ch2 == 'A')) // player 2 atk pos vs player 1 def pos
        {
            cout << "Player 1's " << DEF1.display_front() << " vs " << "Player 2's " << ATK2.display_front() << endl;
            system("pause");
            if (ATK2.get_front_attack() > DEF1.get_front_defense())
            {
                LP1 = LP1 - (ATK2.get_front_attack() - DEF1.get_front_defense());
                cout << "Player 1 takes damage! Life points are now " << LP1 << endl;
            } else
                cout << "It does nothing..." << endl;

            ATK2.dequeue();
            DEF1.dequeue();
        }

        system("pause");

        if (face == 1) // change sides on who starts the round first
            face = 2;
        else
            face = 1;

        system("cls");

        // checks if the amount of rounds is at 12, since 12*2 + 5 = 29 cards drawn by round 12, I would like to just end it there
        //before needing to do anymore coding for an empty deck situation. the function just ends itself and declares whoever has the
        //most LP as the winner.
        if (round < 12) 
        {
            Deck1.pop(hand1, atk1 - 1);
            Deck1.pop(hand1, def1 - 1);
            Deck2.pop(hand2, atk2 - 1);
            Deck2.pop(hand2, def2 - 1);
        }
        else
        {
            if (LP1 < LP2)
            {
                cout << "Player 2 has Won! Player 1 is banished to the shadow realm!\n";
            }
            else if (LP1 > LP2)
            {
                cout << "Player 1 has Won! Player 2 is banished to the shadow realm!\n";
            }
            else
            {
                cout << "Its a Tie!\n";
            }
            system("pause");
            return;
        }

        round++;
    } while (LP1 > 0 && LP2 > 0);

    //in the case someone actually loses 8000 LP
    if (LP1 < LP2)
    {
        cout << "Player 2 has Won! Player 1 is banished to the shadow realm!\n";
    }
    else if (LP1 > LP2)
    {
        cout << "Player 1 has Won! Player 2 is banished to the shadow realm!\n";
    }
    system("pause");
}

//shuffles the deck
void shuffle(card deck1[30])
{
    card temp;

    for (int i = 0; i < 30; i++)
    {
        int j = (rand() % ((30 - 1) + 1));
        temp = deck1[i];
        deck1[i] = deck1[j];
        deck1[j] = temp;
    }
}

//heads or tails (1 or 2)
int cointoss()
{
    int face;

    face = (rand() % ((2 - 1) + 1)) + 1;

    return face;
}