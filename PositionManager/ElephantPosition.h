#pragma once
#include "Position.h"
#include <map>

class ElephantPosition : public Position
{
private:
	struct Elephant {
		unsigned int value;
		unsigned int pointer;
	};
	struct Cycle {
		size_t amount;
		size_t minWeight;
		size_t totalWeight;
	};
public:
	~ElephantPosition();
	virtual void showResult() override;
	ElephantPosition(std::string& data);
private:
	unsigned int totalEffort;
	size_t minGlobalWeight;
	std::vector<Cycle> cycles;
	std::map<unsigned int, Elephant>  data;
	void initObjects();
	void setSimpleCycles();
	unsigned int method1(const Cycle data) const;
	unsigned int method2(const Cycle data, const size_t gmin) const;
	virtual void calculate() override;
};

