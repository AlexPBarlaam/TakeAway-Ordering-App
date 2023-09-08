#ifndef ORDER_H
#define ORDER_H

#include "Item.h"
#include "List.h"

#include <iostream>
#include <fstream>


class Order : 
	public itemList
{
public:
	double OrderPrice = 0;
	bool discout = false;

	void add(::Item* choice);
	void remove(int index);
	void calculateTotal();
	std::string toString();
	void toFile(std::string Order);
};

#endif
