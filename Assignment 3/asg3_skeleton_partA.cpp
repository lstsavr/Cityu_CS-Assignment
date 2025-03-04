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

// color is an pointer to color array, while num is an pointer to number array
void initSequence(Card* cardSeq, char colorName[][10], int* color, int* num);
void printSequence(Card* cardSeq);
int main() {
	// Add your code here.
	initSequence(cardSeq, colorName, color, num);
	printSequence(cardSeq);
	return 0;
}

// Add your code here.
// You need to implement initSequence(Card* cardSeq, char colorName[][10], int* color, int* num) function.

// Add your code here.
// You need to implement printSequence(Card* cardSeq) function.