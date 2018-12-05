#include "pch.h"
#include "ElephantPosition.h"
#include  <algorithm>
#include <iostream>
#include<ctime>


ElephantPosition::ElephantPosition(std::string& data) : Position(data)
{
}


ElephantPosition::~ElephantPosition()
{
	totalEffort = 0;
}

void ElephantPosition::showResult()
{
	calculate();
	std::cout << totalEffort;
}


void ElephantPosition::initObjects()
{
	for (unsigned int i = 0; i < amount; i++)
	{
		data[initialPos[i]] = { values[initialPos[i] - 1], finalPos[i] };
	}
}

void ElephantPosition::setSimpleCycles()
{
	Cycle simple;

	while (!data.empty())
	{
		auto it_first = data.begin();

		simple.minWeight = it_first->second.value;
		simple.totalWeight = it_first->second.value;
		simple.amount = 1;

		auto it_next = data.find(it_first->second.pointer);
		while (it_first != it_next) {
			if (simple.minWeight > it_next->second.value) simple.minWeight = it_next->second.value;
			simple.totalWeight += it_next->second.value;
			simple.amount++;

			auto temp = it_next->second.pointer;
			data.erase(it_next);
			it_next = data.find(temp);
		}
		data.erase(it_first);
		cycles.push_back(simple);
	}

	minGlobalWeight = cycles[0].minWeight;
	for (auto item : cycles) {
		if (minGlobalWeight > item.minWeight) minGlobalWeight = item.minWeight;
	}
}


unsigned int ElephantPosition::method1(const Cycle data) const
{
	auto score =  data.totalWeight + (data.amount - 2) * data.minWeight;
	return score;
}

unsigned int ElephantPosition::method2(const Cycle data, const size_t gmin) const
{
	auto score =  data.totalWeight + data.minWeight + (data.amount + 1) * gmin;
	return score;
}


void ElephantPosition::calculate()
{
	initObjects();
	setSimpleCycles();

	for (auto item : cycles) {
		totalEffort += std::min(method1(item), method2(item, minGlobalWeight));
	}
}
