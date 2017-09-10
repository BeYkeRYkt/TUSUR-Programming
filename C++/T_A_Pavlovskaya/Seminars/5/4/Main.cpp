#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

bool isVowel(char c)
{
	if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'Y' || c == 'y' || c == 'U' || c == 'u' || c == 'I' || c == 'i' || c == 'O' || c == 'o'){
		return true;
	}
	return false;
}

// 194
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream in("english_text.txt");
	if (!in.good()){
		cout << "Error while reading file." << endl;
		return 0;
	}

	char* word = new char[10]();
	int count = 0;
	cout << "Слова, начинающиес¤ с гласных английских букв: " << endl;
	while (in >> word) {
		if (isVowel(word[0])) { //get first char
			cout << "-> " << word << endl;
			++count;
		}
	}
	if (count == 0){
		cout << "Слов, начинающихс¤ на гласные английские буквы, нет" << endl;
	}
	return 0;
}