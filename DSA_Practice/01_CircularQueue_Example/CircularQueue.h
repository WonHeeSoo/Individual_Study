#pragma once
#include <stdio.h>

class CircularQueue
{
public:		// Public methods
	CircularQueue(bool verboseMode = false);
	~CircularQueue();

	char Pop();
	bool Push(char value);

	// void DebugDump();

public:		// Class constants
	static const char	EMPTY = -1;

private:	// Private properties
	static const int	ARRAY_SIZE = 5;
	
	bool		verboseMode;

	char		queue[ARRAY_SIZE] = { 0, };

	int			pushIndex;
	int			popIndex;
};

