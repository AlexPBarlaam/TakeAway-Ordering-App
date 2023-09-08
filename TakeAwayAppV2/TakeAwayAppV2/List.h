#ifndef LIST_H
#define LIST_H

#include "Item.h"

#include <string>
#include <vector>

class itemList
{
public:
	std::vector<Item*> items;

	virtual std::string toString() = 0;
};

#endif