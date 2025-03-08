#include <iostream>
#include <cstring>

using namespace std;


void posToCode(int pos, char* code)
{
	pos += 1;
	
	int len = 1;
	int size = 2;
	int p = 0;
	while (p + size - 1 < pos)
	{
		len++;
		p += size - 1;
		size *= 2;
	}
	int num = pos - p;
	code[len] = '\0';

	for (int i = len - 1; i >= 0; i--)
	{
		code[i] = '0' + (num % 2);
		num /= 2;
	}
}
void codeToPos(char* code, int& pos)
{
	int len = strlen(code);
	int size = 2;
	
	pos = 0;
	for (int i = 0; i < len - 1; i++)
	{
		pos += size - 1;
		size *= 2;
	}

	int num = 0;
	size = 1;
	for (int i = len - 1; i >= 0; i--)
	{
		if (code[i] == '1')
		{
			num += size;
		}
		size *= 2;
	}
	pos += num;

	pos--;
}

int main()
{
	char header[247];
	cout << "Enter Header:" << endl;
	cin.getline(header, 247);
	char ch;
	cout << "Character?";
	cin.get(ch);
	for (int i = 0; i < strlen(header); i++)
	{
	
		if (header[i] == ch)
		{
			
			char code[8];
			posToCode(i, code);
			cout << code << endl;
		}
	}

	return 0;
}