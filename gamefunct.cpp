//Additional work for EA certification. Created a header file for a potential implementation in EA Sports.
//Expanded on the prompt and coded a draft of the implementation in basic C++ code.
//Based on expanding the feature "Wear and Tear" by adding "emotional impact" to the "physical impact" for player management.

#include "gamefunct.h"
#include <iostream>
#include <cstdlib>

Menu obj;
Camera ect;
EmotionalRegulation emo;
FacialChange cha;

int Menu::navigate()
{
	cout << endl << "Please enter a choice:" << endl << "x - Physical Impact" << endl << "y - Emotional Impact" << endl << "q - Quit" << endl;
	int ret_val = 0;
	cin >> obj.user_input;
	while (user_input != "x" or user_input != "y") {

		if (user_input == "x") {
			ret_val = Menu::physical_impact;
			break;
		}
		else if (user_input == "y") {
			ret_val = Menu::emotional_impact;
			break;
		}
		else if (user_input == "q") {
			ret_val = 4;
			break;
		}
		else {
			cout << "Invalid input" << endl;
			cin >> user_input;
			ret_val = 0;
			
		}

	}
	return ret_val;
}

int Camera::change_view(int z)
{
	string emotion = " ";
	while (z != 4) {

		ect.view_state = 0;
		if (z == 0) {
			cout << "Invalid input" << endl;
		}
		else if (z == ect.full_body_view) {
			cout << endl << "Viewing Physical Impact" << endl;
			cout << " ----- " << endl << "/     \\" << endl << "|     |" << endl << "\\     /" << endl << " ----- " << endl;
			cout << " \\ | / " << endl << "  \\|/  " << endl << "   |   " << endl;
			cout << "  | | " << endl << "  | | " << endl;
			z = obj.navigate();
		}
		else if (z == ect.face_view) {
			cout << endl << "Viewing Emotional Impact" << endl;
			emotion = cha.express(z);
			if (emotion == cha.sad){
				emo.act();
			}
			z = obj.navigate();
		}
		else if (z == 4) {
			exit(0);
		}
		else {
			cout << "System Error..." << endl;
			exit(0);
		}
	}

	return z;
}

int EmotionalRegulation::act()
{
	char opt;
	int choose;

	cout << "Would you like to improve this player's mood? Enter y or n." << endl;
	cin >> opt;
	if (opt == 'y') {
		cout << endl << "How would you like to improve the player's mood?" << endl;
		cout << endl << "1 - ..." << endl << "2 - ..." << endl << "3 - Pep Talk" << endl;
		cin >> choose;
		while (choose != 3) {
			cout << "Please choose 3 for sake of demo." << endl;
			cin >> choose;
		}
		if (choose == emo.pep_talk) {
			cout << endl << "Cheer Up!!" << endl;
		}

	}
	else if (opt == 'n') {
		cout << endl;
	}
	else {
		cout << endl << "Please choose valid option." << endl;
		cin >> opt;
	}
	return 0;
}
string FacialChange::express(int w)
{
	int emotion = 0;
	string current = " ";
	if (w == 2) {
		int randomNum = rand() % 3;
		emotion = randomNum;

		if (emotion == 0) {
			cout << " ----- " << endl << "/ ^ ^ \\" << endl << "|  o  |" << endl << "\\  v  /" << endl << " ----- " << endl;
			current = cha.happy;
		}
		else if (emotion == 1) {
			cout << " ----- " << endl << "/ . . \\" << endl << "|  o  |" << endl << "\\  -  /" << endl << " ----- " << endl;
			current = cha.neutral;
		}
		else if (emotion == 2) {
			cout << " ----- " << endl << "/ . . \\" << endl << "|  o  |" << endl << "\\  ^  /" << endl << " ----- " << endl;
			current = cha.sad;
		}
	}
	return current;
}

int main() {
	int z = obj.navigate();
	ect.change_view(z);

}