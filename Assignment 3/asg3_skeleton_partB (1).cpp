#include<iostream>
#include<cstring>
using namespace std;
class Card
{
public:
	Card();
	void setColor(char* n);
	void setValue(int v);
	void setNum(int num);
	char* getColor();
	int getVal();
	int getNum();
	// Add your code here.
private:
	char* color;
	int value;
	int number;
	// Add your code here.
};

// Add your code here.
// You need to implement these access functions and the default constructor in order to complete the class definition of Card.
//default constructor
Card::Card()
{
	color = new char[10];
	value = 0;
	number = 0;
}

//access functions
void Card::setColor(char* n) { strcpy(color, n); }
void Card::setValue(int v) { value = v; }
void Card::setNum(int num) { number = num; }
char* Card::getColor() { return color; }
int Card::getVal() { return value; }
int Card::getNum() { return number; }

//Randomly generate color and num sequences
void genSeq(int seed, int* color, int* num)
{
	//Set random seed
	srand(seed);
	for (int i = 0; i < 6; i++)
	{
		color[i] = rand() % 4 + 1;
		num[i] = rand() % 9 + 1;
	}
}

//Search for a card that computer can play
bool getComputerPlay(Card* ComcardSeq, Card userPlayCard, Card* comPlayCard)
{
	for (int i = 0; i < 6; i++)
	{
		//Check unused cards
		if (ComcardSeq[i].getVal() != 0 && ComcardSeq[i].getNum() != 0)
		{
			//check has same color or same number
			if (userPlayCard.getVal() == 0 && userPlayCard.getNum() == 0 || 
				(userPlayCard.getVal() == ComcardSeq[i].getVal() || userPlayCard.getNum() == ComcardSeq[i].getNum()))
			{
				*comPlayCard = ComcardSeq[i];
				//remove the card
				ComcardSeq[i].setNum(0);
				ComcardSeq[i].setValue(0);
				return true;
			}
		}
	}
	return false;
}

bool checkUserInput(Card* cardSeq, int userVal, int userNum, Card* userPlayCard, Card comPlayCard)
{
	//input 0 0, return false
	if (userVal == 0 || userNum == 0)
	{
		return false;
	}
	//check input has same color or same number with computer card
	if (userVal != comPlayCard.getVal() && userNum != comPlayCard.getNum())
	{
		return false;
	}
	for (int i = 0; i < 6; i++)
	{
		//check has same color or same number
		if (cardSeq[i].getVal() == userVal && cardSeq[i].getNum() == userNum)
		{
			*userPlayCard = cardSeq[i];
			//remove the card
			cardSeq[i].setValue(0);
			cardSeq[i].setNum(0);
			return true;
		}
	}
	return false;
}

void initSequence(Card* cardSeq, char colorName[][10], int* color, int* num);
void printSequence(Card* cardSeq);
// Add your code here.
int main() {
	// Add your code here.
	//Create arrays
	Card* cardSeq = new Card[6];
	char colorName[][10] = { "","Red","Yellow","Blue","Green" };
	int* color = new int[6];
	int* num = new int[6];
	Card* ComcardSeq = new Card[6];
	int seed = 1;
	//Ask the user to input a random number seed
	cout << "Enter the seed for random number generation:" << endl;
	cin >> seed;

	//Randomly generate color and num sequences
	genSeq(seed, color, num);

	initSequence(cardSeq, colorName, color, num);
	cout << "Your card sequence: ";
	printSequence(cardSeq);

	// Add your code here for computer operation.
	//Set computer color and num sequences
	int colorc[6] = { 1,4,4,2,4,3 };
	int numc[6] = { 1,9,4,3,3,5 };
	initSequence(ComcardSeq, colorName, colorc, numc);
	cout << "Computer's card sequence: ";
	printSequence(ComcardSeq);
	// Add your code here.

	Card userPlayCard, comPlayCard;
	//get computer play card
	getComputerPlay(ComcardSeq, userPlayCard, &comPlayCard);
	while (true)
	{
		//output computer play card
		cout << "The computer plays " << comPlayCard.getColor() << comPlayCard.getNum();
		cout << ", please input two integers to represent the card you plan to play:" << endl;
		int useVal, useNum;
		cin >> useVal >> useNum;
		//Check and remove the card entered by the user
		if (!checkUserInput(cardSeq, useVal, useNum, &userPlayCard, comPlayCard))
		{
			//check failed, game lose
			cout << "Game ends. you lose" << endl;
			break;
		}
		//Check and remove the cards that can be played by computer
		if (!getComputerPlay(ComcardSeq, userPlayCard, &comPlayCard))
		{
			//check failed, game win
			cout << "Game ends. You win" << endl;
			break;
		}
		else
		{
			//output user cards and continue game
			cout << "Game continues. Your remaining card(s): ";
			printSequence(cardSeq);
		} 
	}
	return 0;
}

// Add your code here.
// You need to implement initSequence(Card* cardSeq, char colorName[][10], int* color, int* num) function.
void initSequence(Card* cardSeq, char colorName[][10], int* color, int* num)
{
	for (int i = 0; i < 6; i++)
	{
		cardSeq[i].setColor(colorName[color[i]]);
		cardSeq[i].setValue(color[i]);
		cardSeq[i].setNum(num[i]);
	}
}

// Add your code here.
// You need to implement printSequence(Card* cardSeq) function.
void printSequence(Card* cardSeq)
{
	for (int i = 0; i < 6; i++)
	{
		if (cardSeq[i].getNum() != 0 && cardSeq[i].getVal() != 0)
		{
			cout << cardSeq[i].getColor() << cardSeq[i].getNum() << ' ';
		}
	}
	cout << endl;
}