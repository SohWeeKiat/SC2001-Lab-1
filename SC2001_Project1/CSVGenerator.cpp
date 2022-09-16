#include "CSVGenerator.hpp"

CSVGenerator::CSVGenerator(const std::string& Path, const std::string& header) :
	file(Path, std::fstream::out | std::fstream::trunc)
{
	if (!this->file.is_open())
		return;
	this->file << header << "\n";
}

std::fstream& CSVGenerator::get()
{
	return this->file;
}