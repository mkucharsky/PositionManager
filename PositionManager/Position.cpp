#include "pch.h"
#include "Position.h"
#include <iostream>
#include <sstream>


Position::Position(std::string& data)
{
	amount = std::stoi(data);
}

Position::~Position()
{
}

void Position::setAmount(const std::string& data)
{
	amount = std::stoi(data);
}

void Position::setValues(const std::string& data)
{
	separDigits(data, values);
}

void Position::setInitialPositions(const std::string& data)
{
	separDigits(data, initialPos);
}

void Position::setFinalPositions(const std::string& data)
{
	separDigits(data, finalPos);
}

void Position::separDigits(const std::string& data, std::vector<unsigned int>& container)
{
	unsigned int n;
	std::stringstream stream(data);

	while (stream >>n) {
		container.push_back(n);
	}
}



