#include <iostream>
#include <string>
#include <vector>
#include "methods.h"
#include "stdlib.h"
#include "SignSet.h"
int main()
{
	SignSet lower_case("abcdefghijklmnopqrstuvwxyz");
	SignSet upper_case("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	SignSet special_signs("!@#$%^&*(),./;'[]?<>:");
	SignSet numbers("1234567890");
	SignSet signSet[4] = {lower_case, upper_case, special_signs, numbers};
	string ammount_of_passwords, length_of_password;

	srand(time(NULL));
	
	std::cout << "MENU\n"; 
	//while the ammount_of_passwords is not a number, make the user input a number that's bigger than 0
	while (!isNumber(ammount_of_passwords)) {
		std::cout << "Provide the ammount of passwords: ";
		std::cin.clear();
		std::cin >> ammount_of_passwords;
	}
	//while the length_of_password is not a number, make the user input a number that's bigger than 0
	while (!isNumber(length_of_password) && length_of_password!="0") {
		std::cout << "Provide the desired length of the passwords: ";
		std::cin.clear();
		std::cin >> length_of_password;	
	}
	std::cout << "Answer T for true or F for flase:\n";
	//get which requirements should work for the passwords
	lower_case.setAllowed(dataIn("Lower case"));
	upper_case.setAllowed(dataIn("Upper case"));
	special_signs.setAllowed(dataIn("Special signs"));
	numbers.setAllowed(dataIn("Numbers"));

	SignSet gates[4] = {lower_case, upper_case, special_signs, numbers};

	std::vector<SignSet> allowedGates(0);
	for(SignSet gate:gates){
		if(gate.getAllowed()) {
			allowedGates.push_back(gate);
		}
	}

	if (allowedGates.size()==0) {
		std::cout << "The password cannot be created without any signs.";
		exit(0);
	}

	std::cout << "Generated passwords: \n";
	//for each password
	for(int i=1;i<=stoi(ammount_of_passwords);i++) {
		string password = "";
		//for each letter 
		int ilength = stoi(length_of_password);
		for(int j=1;j<=ilength;j++) {
			//choose from which set should i pick a letter
			int pickOfGate = generateRandomNumber(allowedGates.size());
			SignSet pickedSignSet = allowedGates.at(pickOfGate); 
			//pick a sign from given set and put it into the password
			int pickOfLetter = generateRandomNumber(pickedSignSet.size());
			char pickedLetter = pickedSignSet.getLetterAt(pickOfLetter);
			password = password + pickedLetter;
		}
		std::cout << i << ". " << password << "\n"; 
	}

	//click something for app to close
	char holder;
	std::cin >> holder;
}