#pragma once
typedef struct _info
{
	const char	*name;
	int		phoneNumber;
	//_info(const char *infoName, int infoPhoneNumber) : name(infoName), phoneNumber(infoPhoneNumber) {}
}Info;

typedef struct _slot
{
	int		key;
	Info	*value;
	/*_slot(int key, const char *slotName, int slotPhoneNumber) : key(key)
	{
		value->name = slotName;
		value->phoneNumber = slotPhoneNumber;
		//(slotName, slotPhoneNumber);
	}*/
}Slot;