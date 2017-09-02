#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <fstream>

static void word_count_pro()
{
	std::unordered_map<std::string, std::size_t> word_count;
	std::string input;
	while (std::cin >> input)
	{
		++word_count[input];
	}
	for (auto &c : word_count)
	{
		std::cout << c.first << " occurs " << c.second <<
			(c.second > 1 ? " times" : " time") << std::endl;
	}
}

static std::unordered_map<std::string, std::string> buildMap(std::ifstream &map_file)
{
	std::unordered_map<std::string, std::string> trans_map;
	std::string line;
	std::string word;
	while (map_file >> word && std::getline(map_file, line))
	{
		if (line.size() > 1)
			trans_map[word] = line.substr(1); //specific
		else
			throw std::runtime_error("no rule for " + word);
	}
	return trans_map;
}

static const std::string& transform(const std::string &s, const std::unordered_map<std::string, std::string> &map)
{
	auto map_it = map.find(s);
	if (map_it != map.end())
	{
		return map_it->second;
	}
	else {
		return s;
	}
}

static void word_transform(std::ifstream &map_file, std::ifstream &input)
{
	auto trans_map = buildMap(map_file);
	std::string text;
	while (std::getline(input, text))
	{
		std::istringstream iss(text);
		std::string word;
		bool firstWord = true;
		while (iss >> word)
		{
			if (firstWord)  //specific
				firstWord = false;
			else
				std::cout << " ";
			std::cout << transform(word, trans_map);
		}
		std::cout << std::endl;
	}
}

static void test_word_transform_pro()
{
	std::cout << "testing word_transform program:" << std::endl;
	std::ifstream rule("D:\\GitForks\\CppPrimer5thExerciseAnswers\\ch11\\exec11_33\\map_rules.txt");
	std::ifstream input("D:\\GitForks\\CppPrimer5thExerciseAnswers\\ch11\\exec11_33\\input.txt");
	word_transform(rule, input);
}

static void test_word_count()
{
	std::cout << "testing word_count program:" << std::endl;
	word_count_pro();
}

int main()
{
	
	//test_word_count();
	test_word_transform_pro();

	return 0;
}