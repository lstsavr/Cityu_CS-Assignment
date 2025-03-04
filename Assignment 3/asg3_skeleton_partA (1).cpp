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
private:
	char* color;
	int value;
	int number;
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

// color is an pointer to color array, while num is an pointer to number array
void initSequence(Card* cardSeq, char colorName[][10], int* color, int* num);
void printSequence(Card* cardSeq);
int main() {
	// Add your code here.
	//Create arrays
	Card* cardSeq = new Card[6];
	char colorName[][10] = { "","Red","Yellow","Blue","Green" };
	int* color = new int[6];
	int* num = new int[6];
	int seed = 1;
	//Ask the user to input a random number seed
	cout << "Enter the seed for random number generation:" << endl;
	cin >> seed;

	//Randomly generate color and num sequences
	genSeq(seed, color, num);
	//Create card sequence
	initSequence(cardSeq, colorName, color, num);
	//Print card sequence
	printSequence(cardSeq);
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
		cout << cardSeq[i].getColor() << cardSeq[i].getNum() << ' ';
	}
}