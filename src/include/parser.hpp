#ifndef PARSER_HPP
#define PARSER_HPP

#include<string>
#include<fstream>

class Parser {
private:
	std::string filename;
	std::ifstream mkText_I_f;
	std::ofstream mkText_O_f;
public:
	Parser(std::string);

	void set_input_file();

	void set_output_file();

void get_obj_data(const std::string&, std::string&, std::string&);

};

#endif