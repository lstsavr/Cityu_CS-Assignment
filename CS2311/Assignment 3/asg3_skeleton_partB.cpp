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

void initSequence(Card* cardSeq, char colorName[][10], int* color, int* num);
void printSequence(Card* cardSeq);
// Add your code here.
int main() {
	// Add your code here.
	initSequence(cardSeq, colorName, color, num);
	cout << "Your card sequence: ";
	printSequence(cardSeq);
	
	// Add your code here for computer operation.
	initSequence(ComcardSeq, colorName, colorc, numc);
	cout << "Computer's card sequence: ";
	printSequence(ComcardSeq);
	// Add your code here.
	return 0;
}

// Add your code here.
// You need to implement initSequence(Card* cardSeq, char colorName[][10], int* j, int* num) function.

// Add your code here.
// You need to implement printSequence(Card* cardSeq) function.