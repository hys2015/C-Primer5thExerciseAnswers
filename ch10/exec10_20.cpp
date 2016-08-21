#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int exec10_20_main()
{
	std::vector<std::string> words;
	std::cout << "enter the words ^Z to end:";
	std::string input;
	while (std::cin >> input)
	{
		words.push_back(input);
	}
	std::cout << std::count_if(words.begin(), words.end(), 
		[](std::string &s) {return s.size() > 6; }) << std::endl;

	return 0;
}