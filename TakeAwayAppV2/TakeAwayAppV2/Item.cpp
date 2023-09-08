#include "Item.h"

std::string Item::toString()
{
	std::string string;
	return string;
}

Appetiser::Appetiser(std::string n, float p, int cal, bool share, bool two4one)
{
	name = n;
	calories = cal;
	price = p;
	shareable = share;
	twoForOne = two4one;
}

MainCourse::MainCourse(std::string n, float p, int cal)
{
	name = n;
	calories = cal;
	price = p;
}

Beverage::Beverage(std::string n, float p, int cal, int vol, float alc)
{
	name = n;
	calories = cal;
	price = p;
	volume = vol;
	abv = alc;
}