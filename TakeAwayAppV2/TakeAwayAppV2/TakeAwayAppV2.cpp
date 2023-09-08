// TakeAwayAppV2.cpp : This file contains the 'main' function. Program execution begins and ends there.

/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "Takeaway" assignment
Autumn 2020

Written by James Brown

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Item.h"
#include "List.h"
#include "Menu.h"
#include "Order.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;
	vector <Item*> Objects;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Loads the menu from the file, creates the objects and returns an array of pointers
	Objects = menu.LoadMenu(menu.File);

	Order order = Order();

	while (userCommand != "exit")
	{
		cout << "Please input a command: ";
		//takes a user input and converts it from a string to tokens (individual words)
		getline(cin, userCommand); //takes an input from the user 
		char* cstr = new char[userCommand.length() + 1]; //defines an array of characters and creates a pointer to it 
		strcpy(cstr, userCommand.c_str()); //makes a copy of the characters in usercommand to a c-string 

		char* token; //creates a pointer of type char 
		token = strtok(cstr, " "); //converts the c-string to tokens

		//when the token isn't empty, its content will get pushed back into the vector "parameters" 
		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) {

			cout << menu.toString();
		}
		else if (command.compare("add") == 0)
		{
			int index = stoi(parameters[1]);			
			Item* choice = Objects[index - 1]; 
			order.add(choice);
		}
		else if (command.compare("remove") == 0)
		{
			int index = stoi(parameters[1]);
			index--;
			order.remove(index);
		}
		else if (command.compare("checkout") == 0)
		{
			string input;
			string UserOrder;
			order.calculateTotal();
			UserOrder = order.toString();
			cout << UserOrder;
			cout << "Do you want to place your order: \n Type 'y' to confirm, or 'n' to go back and modify it. \n";
			getline(cin, input);
			if (input == "y") 
			{
				cout << "A receipt has been printed, Thabk you for your order \n";
				order.toFile(UserOrder);
			}
			
			else {}

		}
		else if (command.compare("help") == 0)
		{
			cout << menu.help();
		}
		else if (command.compare("exit") == 0) 
		{
			cout << "Program Exiting......." << endl;
		}
		else 
		{
			cout << "This command is incorrect, Please Type help to see the available commands." << endl;
		}
		//clears the user input taken previously
		parameters.clear();
		
		//deletes the pointers 
		delete[] cstr; 
		delete token;  
	}

	cout << "Press any key to quit...";

	//destroys the objects
	menu.~Menu();
	order.~Order();

	int input = getchar();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
