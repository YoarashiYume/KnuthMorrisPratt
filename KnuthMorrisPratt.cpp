#include "KnuthMorrisPratt.h"

void KnuthMorrisPratt::prefixFunc(const char* str)
{
	prefixSize.clear();
	int stringSize = strlen(str);
	prefixSize.reserve(stringSize);
	prefixSize.push_back(0);
	for (size_t i = 1, j = 0; i < stringSize;)
	{
		if (*(str + i) != *(str + j))
		{
			if (j != 0)
			{
				j = prefixSize.at(j - 1);
				continue;
			}
			else
				prefixSize.push_back(0);
		}
		else
			prefixSize.push_back(++j);
		++i;
	}
}

KnuthMorrisPratt::KnuthMorrisPratt(const char* str)
{
	setSourceStr(str);
}


void KnuthMorrisPratt::setTemplateStr(const char* str)
{
	currentIndex = INT_MIN;
	templateSize = strlen(str);
	if (templateStr != nullptr)
		delete[] templateStr;
	templateStr = new char[sourceSize + 1];
	for (size_t i = 0; i < templateSize; i++)
		*(templateStr + i) = *(str + i);
	*(templateStr + templateSize) = '\0';
	prefixFunc(str);
}

void KnuthMorrisPratt::setSourceStr(const char* str)
{
	currentIndex = INT_MIN;
	sourceSize = strlen(str);
	if (source != nullptr)
		delete[] source;
	source = new char[sourceSize + 1];
	for (size_t i = 0; i < sourceSize; i++)
		*(source + i) = *(str + i);
	*(source + sourceSize) = '\0';
}

int KnuthMorrisPratt::find()
{
	if (currentIndex != INT_MIN)
		return currentIndex;
	bool isFind = false;
	currentIndex = 0;
	for (size_t i = 0,j = 0; i < sourceSize && !isFind;)
	{
		if (*(source + i) == *(templateStr + j))
		{
			++i;
			++j;
			if (j == templateSize)
			{
				isFind = true;
				currentIndex = i - templateSize;
			}
		}
		else
		{
			if (j == 0)
				++i;
			else
				j = prefixSize.at(j - 1);
		}
	}
	currentIndex = isFind ? currentIndex : -1;
	return currentIndex ;
}

KnuthMorrisPratt::~KnuthMorrisPratt()
{
	delete[] source;
	delete[] templateStr;
}
