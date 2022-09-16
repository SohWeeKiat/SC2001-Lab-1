#pragma once
#include <fstream>
#include <string>

class CSVGenerator {

public:
	CSVGenerator(const std::string& Path, const std::string& header);

	std::fstream& get();
private:
	std::fstream file;
};