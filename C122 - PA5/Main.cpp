#include "Queue.h"
#include "Stack.h"
#include "Header.h"

/*******************************************************************************************
* Programmer: Robert Frawley *
* Class: CptS 122, Spring, 2020; Lab Section 5 *
* Programming Assignment: PA5 *
* Date: March 27, 2020 *
* Description: Yu Gi Oh with queues, stacks, and only monsters
* Note: Its kinda scuffed but works
*******************************************************************************************/

int main()
{
	srand(time(0));

	card List[200], Deck1[30], Deck2[30];
	string line;
	int count = 0, card, choice;
	int check = 1;

	ifstream Cardlist;
	Cardlist.open("Cardlist.csv", ios::in);

	do {
		//Displays main menu and gets user choice, keeps repeating until deck initialization is done first
		do {
			choice = main_menu();
			if (choice == 1 || choice == 5)
				check = 0;
			else if(check == 1)
			{
				system("cls");
				cout << "The Players must first create your Decks before initiating anything else!\n";
				system("pause");
			}
		} while (check != 0);
		switch (choice)
		{
		case 1:
			//pulls card data from a cardlist, and then randomizes the cards put into each deck from that card list
			while (getline(Cardlist, line, ','))
			{
				strcpy(List[count].name, line.c_str());
				getline(Cardlist, line, ',');
				strcpy(List[count].type, line.c_str());
				getline(Cardlist, line, ',');
				List[count].attack = stoi(line);
				getline(Cardlist, line, '\n');
				List[count].defense = stoi(line);
				count++;
			}

			Cardlist.close();

			for (int i = 0; i < 30; i++)
			{
				card = (rand() % (count - 1)) + 1;
				Deck1[i] = List[card];
				card = (rand() % (count - 1)) + 1;
				Deck2[i] = List[card];
			}

			cout << "\nDecks for Player 1 and Player 2 have been created.\n";
			system("pause");
			break;
		case 2:
			replace_specific(Deck1, Deck2);
			break;
		case 3:
			trade_card(Deck1, Deck2);
			break;
		case 4:
			duel(Deck1, Deck2);
			break;
		}

	} while (choice != 5);

	return 0;
}