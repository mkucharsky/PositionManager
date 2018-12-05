#include "pch.h"
#include <iostream>
#include"ElephantPosition.h"
#include <ctime> 

int main()
{
	std::string data;
	std::getline(std::cin, data);

	ElephantPosition series1(data);
	std::getline(std::cin, data);
	series1.setValues(data);
	std::getline(std::cin, data);
	series1.setInitialPositions(data);
	std::getline(std::cin, data);
	series1.setFinalPositions(data);
	series1.showResult();
}
