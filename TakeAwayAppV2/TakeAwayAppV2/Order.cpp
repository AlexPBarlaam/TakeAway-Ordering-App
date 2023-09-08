#include "Order.h"
#include "Item.h"


void Order::add(::Item* choice)
{
	//pushes the Item back into a vector of pointers
	items.push_back(choice);
	std::cout << choice->name << " was added to your order!" << std::endl;
}

void Order::remove(int index)
{
	//deletes the item at the index supplied by the user
	std::cout << items[index]->name << " was removed from your order!" << std::endl;
	items.erase(items.begin() + index);	
}

void Order::calculateTotal()
{
	float total = 0;
	bool twoForOne = false;
	int TFOCounter = 0;

	//iterates through each Item in the order and adds the price to total
	for(int i = 0; i < items.size(); i++)
	{
		total += items[i]->price;
		std::cout << i;
		if (i == 2 || 3) {
			TFOCounter++;
			if (TFOCounter >= 2) { 
				twoForOne = true; 
			}
		}
	}	
	if (twoForOne == true) {
		total -= 3.99;
		discout = true;
	}

	OrderPrice = total;
}

std:: string Order::toString()
{
	std::string string = "======= Checkout ======= \n";
	int counter = 1;
	
	//Iterates through each Item and appends a string with the item's name, price and calories
	for (int i = 0; i < items.size(); i++) 
	{
		std::string item = "(" + std::to_string(counter) + ") " + items[i]->name + ", \x9C" + std::to_string(items[i]->price) + ", " + std::to_string(items[i]->calories) + "cal \n------------------------------ \n";
		string.append(item);
		counter++;
	}
	
	if (discout == true) {
		std::string savings = "2-4-1 Discount applied! Savings: " "\x9c" "3.99\n";
		string.append(savings);
	}

	//appends the string with the price of the Items
	std::string orderprice = "Total: \x9C" + std::to_string(OrderPrice) + "\n------------------------------ \n";
	string.append(orderprice);
	return string;
}

void Order::toFile(std::string Order) 
{
	//opens a file named receipt.txt and outputs the order into it
	std::ofstream file;
	file.open("receipt.txt");
	file << Order;
	file.close();
}