#include "Menu.h"

Menu::Menu(std::string fileName)
{
	File = fileName;
}

std::vector<::Item*> Menu::LoadMenu(std::string File)
{
	std::string line;
	std::vector<std::string> menuItems;
	std::ifstream file(File);
	std::vector<std::string> Listofitems;
	

	//Opens the file and reads the file line by line into an array 
	while (getline(file, line))
	{
		std::string delimiter = ",";
		std::string token;
		size_t pos = 0;

		line.push_back(',');

		//splits the line into the indidvidual cells of data which are stored in a vector
		while ((pos = line.find(delimiter)) != std:: string::npos) {
			token = line.substr(0, pos);
			Listofitems.push_back(token);
			line.erase(0, pos + delimiter.length());
		}
	}
	file.close();
	
	//creates the objects and assigns each to a pointer of type Item and pushes each back to a vector of pointers 
	Item* Nachos = new Appetiser(Listofitems[1], 4.99 , 600, true, false);
	items.push_back(Nachos);
	Item* BuffWings = new Appetiser(Listofitems[9], 3.99, 450, false, true);
	items.push_back(BuffWings);
	Item* GarlicBread = new Appetiser(Listofitems[17], 3.99, 500, false, true);
	items.push_back(GarlicBread);
	Item* Burger = new MainCourse(Listofitems[25], 9.99, 950);
	items.push_back(Burger);
	Item* MacCheese = new MainCourse(Listofitems[33], 7.99, 850);
	items.push_back(MacCheese);
	Item* FishChips = new MainCourse(Listofitems[41], 8.99, 1000);
	items.push_back(FishChips);
	Item* ChickenTikka = new MainCourse(Listofitems[49], 6.99, 700);
	items.push_back(ChickenTikka);
	Item* Lager = new Beverage(Listofitems[57], 3.50, 200, 568, 4.5);
	items.push_back(Lager);
	Item* WhiteWine = new Beverage(Listofitems[65], 4, 150, 175, 11.5);
	items.push_back(WhiteWine);
	Item* RedWine = new Beverage(Listofitems[73], 4, 170, 175, 12.5);
	items.push_back(RedWine);
	Item* Coke = new Beverage(Listofitems[81], 2.5, 140, 330, 0);
	items.push_back(Coke);
	Item* Water = new Beverage(Listofitems[89], 1.5, 0, 330, 0);
	items.push_back(Water);

	return items;
}

std:: string Menu::toString()
{
	std:: string Final;
	std::string Appetiser = "-------------Appetisers------------- \n(1) Nachos: " "\x9C" "4.99, 600 cal (shareable) \n(2) Buffalo Wings: " "\x9C" "3.99, 450 cal (2-4-1) \n(3) Garlic Bread: " "\x9C" "3.99, 450 cal (2-4-1) \n";
	std::string Main = "-------------Main Dishes------------- \n(4) Burger: " "\x9C" "9.99, 950cal \n(5) Mac & Cheese: " "\x9C" "7.99, 850cal \n(6) Fish & chips: " "\x9C" "8.99, 1000cal \n(7) Chicken Tikka Masalla: " "\x9C" "8.99, 700cal \n";
	std::string Beverages = "-------------Beverages------------- \n(8) Lager: " "\x9C" "3.50, 200 cal (568ml, 4.5% abv)  \n(9) White Wine: " "\x9C" "4.00, 150 cal (175ml, 11.5% abv)\n(10) Red Wine: " "\x9C" "4.00, 170 cal (175ml, 12.5% abv) \n(11) Coke: " "\x9C" "2.50, 140 cal (330ml) \n(12) Water: " "\x9C" "1.50, 0 cal (330ml) \n";
	Final = Appetiser + Main + Beverages;

	return Final;
}

std::string Menu::help()
{
	std::string help = "These commands are available to you: \n menu - Display the Menu. \n add [index] - add an item to your order. \n remove [index] - remove an item from your order \n checkout - displays your order and the price\n exit - exits the program \n"; 
	return help;
}