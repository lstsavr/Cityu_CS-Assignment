#include <iostream>
#include <cstring>

using namespace std;

int hAppY(char* code, int len)
{
	int p = 1;
	int ret = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (code[i] == '1')
		{
			ret += p;
		}
		p *= 2;
	}
	return ret;
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
	pos += hAppY(code, len);
	pos--;
}

void readCode(char* code, int count)
{
	for (int i = 0; i < count; i++)
	{
		cin.get(code[i]);
		if (code[i] == '\n')
		{
			code[i] = '\0';
			break;
		}
	}
	code[count] = '\0';
}

int main()
{
	char header[247];
	cout << "Enter Header:" << endl;
	cin.getline(header, 247);
	cout << "Enter code:" << endl;
	char res[247] = "";
	int resPos = 0;
	char code[8] = "";
	int segLen = -1;
	while (true)
	{
		readCode(code, 3);
		if (strlen(code) != 3) break;
		segLen = hAppY(code, 3);
		while (true)
		{
			readCode(code, segLen);
			if (hAppY(code, segLen) == 0) break;
			int pos = 0;
			codeToPos(code, pos);
			res[resPos++] = header[pos];
		}
		segLen = -1;
	}
	cout << res << endl;
	return 0;
}

