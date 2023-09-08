#ifndef MENU_H
#define MENU_H

#include "List.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Menu :
	public itemList
{
public:

	std::string File;

	Menu(std::string fileName);
	std::vector<::Item*>LoadMenu(std::string File);
	std::string toString();
	std::string help();
};

#endif