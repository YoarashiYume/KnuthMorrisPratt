#pragma once
#include <vector>
class KnuthMorrisPratt
{
private:
	std::vector<unsigned int> prefixSize;
	void prefixFunc(const char* str);
	char* source = nullptr;
	unsigned int sourceSize;
	char* templateStr = nullptr;
	unsigned int templateSize;
	int currentIndex = INT_MIN;
public:
	KnuthMorrisPratt(const char* str);
	void setTemplateStr(const char* str);
	void setSourceStr(const char* str);
	int find();
	~KnuthMorrisPratt();
};

