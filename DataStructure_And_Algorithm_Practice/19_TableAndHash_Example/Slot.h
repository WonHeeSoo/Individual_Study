#pragma once
typedef struct _info
{
	int		serial;
	char	data[];
}Info;

typedef struct _slot
{
	int		key;
	Info	*value;
}Slot;