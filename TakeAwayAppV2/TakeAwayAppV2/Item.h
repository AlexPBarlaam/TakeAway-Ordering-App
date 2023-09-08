#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

class Item
{
public:
	std::string name;
	float calories;
	float price;
	int ItemNumber;

	std::string toString();
};

class Appetiser :
	public Item
{
public:
	bool shareable;
	bool twoForOne;

	Appetiser(std::string n, float p, int cal, bool share, bool two4one);
};

class MainCourse :
	public Item
{
public:
	MainCourse(std::string n, float p, int cal);
};

class Beverage :
	public Item
{
public:
	int volume;
	double abv;

	Beverage(std::string n, float p, int cal, int vol, float alc);
};

#endif