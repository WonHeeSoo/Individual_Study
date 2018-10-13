#pragma once
#include <string>

#define INVALID_KEY	(-1)

struct Slot
{
	int		key;

	struct Info
	{
		std::string	name;
		int		phoneNumber;
		//Info() : name(), phoneNumber(0) {}
		//Info(std::string name, int phoneNumber) : name(name), phoneNumber(phoneNumber) {}
	}	value;

	//Slot() : key(INVALID_KEY), value() {}
	//Slot(int key, std::string name, int phoneNumber) : key(key), value(name, phoneNumber) {}
};