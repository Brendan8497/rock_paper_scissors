/**

Name: Brendan Ryan
Date: 10/30/2017
Program_name: rock_paper_scissors.cpp

Purpose: This is a program that allows the user to play rock, paper, scissors
	with the computer. The main() function calls the victor() function,
	which calls the userChoice() and computerChoice() functions and stores
	the returned values from each into separate functions. The
	computerChoice() function calls the randComputerNum() function to
	find a random number which will serve as the computer's choice. Once
	both players' choices are made, the victor() function then compares
	the choices to each other through if statements to see who is the
	victor. If a tie results, the victor() function is called within the
	victor() function, which starts the program from the beginning to allow
	both players to make a new choice. This repeats until a victor is
	determined.

**/

#include <iostream>
#include <cstdlib> // uses cstdlib for rand and srand
#include <ctime> // uses ctime for time

using std::cout;
using std::cin;
using std::endl;
using std::rand;
using std::srand;
using std::time;

int randComputerNum(); // header for randComputerNum() function
int computerChoice(); // header for computerChoice() function
int userChoice(); // header for userChoice() function
int victor(); // header for victor() function

int main() {

	// seeds rand with the current time
	srand(time(0));
	
	victor(); // calls the victor() function
	
	return 0;

}

// this function finds a random number between 1 and 3 and stores it in
// the random_num variable. returns the value of rand_num
int randComputerNum() {

	int random_num = rand() % 3 + 1;
	
	return random_num;

}

// function determines the computer's choice and returns said choice
int computerChoice() {

	// calls function randComputerNum() and stores it in computer_choice
	int computer_choice = randComputerNum();

	// if computer_choice is 1, computer selected rock
	if (computer_choice == 1) {
		
		cout << "The computer chose Rock" << endl;
	
	}
	
	// if computer_choice is 2, computer selected paper
	if (computer_choice == 2) {
	
		cout << "The computer chose Paper" << endl;
	
	}
	
	// if computer_choice is 3, computer selected scissors
	if (computer_choice == 3) {
	
		cout << "The computer chose Scissors" << endl;
	
	}
	
	// returns computer_choice
	return computer_choice;

}

// determines the user's choice and returns it
int userChoice() {

	// declares user_choice and initializes it to 0
	int user_choice = 0;

	// presents user with a menu and asks user to select rock, paper, or
	// scissors
	cout << "Please enter the number for the corresponding option you ";
	cout << "would like to select." << endl << endl;
	cout << "1. Rock" << endl;
	cout << "2. Paper" << endl;
	cout << "3. Scissors" << endl << endl;
	cin >> user_choice;
	
	// while user_choice is not 1, 2, or 3 (rock, paper, or scissors),
	// menu is printed again and user is asked to make another selection
	while ((user_choice != 1) && (user_choice != 2) && (user_choice != 3)) {
	
		cout << "Invalid option selected." << endl << endl;
		cout << "Please enter the number for the corresponding option you ";
		cout << "would like to select." << endl << endl;
		cout << "1. Rock" << endl;
		cout << "2. Paper" << endl;
		cout << "3. Scissors" << endl << endl;
		cin >> user_choice;
	
	}
	
	// if user_choice is 1, user chose rock
	if (user_choice == 1) {
	
		cout << "You chose Rock" << endl;
	
	}
	
	// if user_choice is 2, user chose paper
	if (user_choice == 2) {
	
		cout << "You chose Paper" << endl;
	
	}
	
	// if user_choice is 3, user chose scissors
	if (user_choice == 3) {
	
		cout << "You chose Scissors" << endl;
	
	}
	
	// returns user_choice
	return user_choice;

}

// calls userChoice and computerChoice, then compares the two player's
// selections to determine a victor. Calls itself to re run function if
// game resulted in a tie
int victor() {

	// declares u_choice and stores the value returned from userChoice()
	// function in it
	// declares comp_choice and stores the value returned from
	// computerChoice() function in it
	int u_choice = userChoice(), comp_choice = computerChoice();
	
	// if user chose scissors and computer chose rock
	if ((u_choice == 3) && (comp_choice == 1)) {
	
		cout << "You lose!" << endl;
	
	}
	
	// if user chose rock and computer chose scissors
	if ((u_choice == 1) && (comp_choice == 3)) {
	
		cout << "You win!" << endl;
	
	}
	
	// if user chose paper and computer chose scissors
	if ((u_choice == 2) && (comp_choice == 3)) {
	
		cout << "You lose!" << endl;
	
	}
	
	// if user chose scissors and computer chose paper
	if ((u_choice == 3) && (comp_choice == 2)) {
	
		cout << "You win!" << endl;
	
	}
	
	// if user chose rock and computer chose paper
	if ((u_choice == 1) && (comp_choice == 2)) {
	
		cout << "You lose!" << endl;
	
	}
	
	// if user chose paper and computer chose rock
	if ((u_choice == 2) && (comp_choice == 1)) {
	
		cout << "You win!" << endl;
	
	}
	
	// if user chose rock and computer chose rock
	if ((u_choice == 1) && (comp_choice == 1)) {
	
		cout << "Tie!" << endl << endl;
		
		victor(); // calls victor() function and re runs the function
			  // for another round
	
	}
	
	// if user chose paper and computer chose paper
	if ((u_choice == 2) && (comp_choice == 2)) {
	
		cout << "Tie!" << endl << endl;
		
		victor(); // calls victor() function and re runs the function
			  // for another round
	
	}
	
	// if user chose scissors and computer chose scissors
	if ((u_choice == 3) && (comp_choice == 3)) {
	
		cout << "Tie!" << endl << endl;
		
		victor(); // calls victor() function and re runs the function
			  // for another round
	
	}
	
	return 0;

}
