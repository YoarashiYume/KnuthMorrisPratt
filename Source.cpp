#include "KnuthMorrisPratt.h"
#include <iostream>
int main(int argc, char* argv[])
{
	if (argc < 3) {
		std::cout << "usage: <prog-name> <sourceString> <templateString> \n";
		std::system("pause");
		return 1;
	}
	KnuthMorrisPratt kMP(argv[1]);
	kMP.setTemplateStr(argv[2]);
	int pos = kMP.find();
	std::cout << "index = " << pos << std::endl;
	return 0;
}