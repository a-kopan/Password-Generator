#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
//get the information whether 
bool dataIn(string requirement) {
	char answer;
	cout << requirement + ": ";
	cin >> answer;
	while (!(answer == 'T' || answer == 't' || answer == 'F' || answer == 'f')) {
		cout << "Please answer with T or F.\n";
		cout << requirement + ": ";
		cin >> answer;
	}
	//answer is T/t/F/f
	if(answer=='f' || answer=='F') {
		return false;
	} else {
		return true;
	}
}
//get the random number without the range included
int generateRandomNumber(int range) {
	int number = ((rand()+3)^2 * 8)%range;
	return number;
}
//if at least one sign in a string is a letter or if no input was given, return false
bool isNumber(string chain) {
	if(!chain.length()) {
		return false;
	}
	for(char number:chain) {
		if(!isdigit(number)) {
			return false;
		}
	}
	return true;
}