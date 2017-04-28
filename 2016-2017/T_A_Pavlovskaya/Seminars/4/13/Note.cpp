#include <string>
#include "Note.h"

using namespace std;

string Note::getName(){
	return name;
}

string Note::getFamilyName(){
	return familyName;
}

int* Note::getDate(){
	return date;
}

int Note::getPhoneNumber(){
	return phone;
}

void Note::setName(string name){
	this->name = name;
}

void Note::setFamilyName(string name){
	this->familyName = name;
}

void Note::setDate(int* date){
	this->date = date;
}

void Note::setPhoneNumber(int number){
	this->phone = number;
}

