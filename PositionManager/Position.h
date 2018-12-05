#pragma once
#include<vector>
#include<string>

class Position
{
public:
	virtual ~Position();
	Position(std::string& data);
	void setValues(const std::string& data);
	void setAmount(const std::string& data);
	void setInitialPositions(const std::string& data);
	void setFinalPositions(const std::string& data);
	virtual void showResult() = 0;
protected:
	unsigned int amount;
	std::vector<unsigned int> values;
	std::vector<unsigned int> finalPos;
	std::vector<unsigned int> initialPos;
	virtual void calculate() = 0;
private:
	void separDigits(const std::string& data, std::vector<unsigned int>& container);
};