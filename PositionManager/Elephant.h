#pragma once
#include"ElephantPosition.h"

class Elephant
{
	friend class ElephantPosition;
private:
	unsigned int value;
	std::shared_ptr<Elephant> pointer;
public:
	Elephant();
	virtual ~Elephant();
};

