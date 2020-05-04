#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <exception>
#include <fstream>
#include <sstream>
#include "Dictionary.h"

string get_word(char* temp_word, FILE* in);

int main() {
    Dictionary D;
    string str = "";
    FILE* in;
	try
	{
		if ((in = fopen("article.txt", "r")) == nullptr)
			cout << "Can't open.\n";

		while (!feof(in))
		{
			char temp_word[26] = { 0 };
			str = get_word(temp_word, in);
			D.insert(str);
		}
		D.preOrderPrint();

		cout << "== Enter string to remove:\n";
		string Str;
		cin >> Str;
		cout << " * Remove result:\n";
		D.remove(Str);
		//D.preOrderPrint();
		
		cout << "== Inserd a word:\n";
		cin >> Str;
		cout << " * Insert result:\n";
		D.insert(Str);
		cout << "Succeed.\n";

		cout << "== Search a word:\n";
		cin >> Str;
		D.search(Str);

		cout << "== Enter '#' print a list:\n";
		char ch;
		cin >> ch;

		while (ch != '#')
		{
			cout << ch;
			cin >> ch;
		}

		D.printList();
		
		cout << " *Sorted\n";
		D.interactiveGetModes();

	}

	catch (Exception& e)
	{
		std::cout<<e.what();
	}

    return 0;
}

string get_word(char* temp_word, FILE* in)
{
	int i = 0;
	char temp = '0';
	temp = fgetc(in);
	while (!isalpha(temp))
	{
		temp = fgetc(in);
		if (temp == EOF)
			return "";
	}

	while (isalpha(temp) && !isspace(temp))
	{
		temp = tolower(temp);
		temp_word[i] = temp;
		i++;
		temp = fgetc(in);
	}

	return temp_word;

}