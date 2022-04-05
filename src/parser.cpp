#include <parser.hpp>

void Parser::set_input_file() {
	this->mkText_I_f.open(this->filename, std::fstream::in);
}

void Parser::set_input_file() {
	this->mkText_O_f.open(this->filename.replace(this->filename.length() - 3, 3, "html"), std::fstream::trunc);
}

void Parser::get_obj_data (const std::string& line, std::string& id, std::string& cls) {
	int pos_start = line.find(':');
	int pos_end = line.find(')');
	id = line.substr(5, pos_start - 5);
	cls = line.substr(pos_start + 1, pos_end - pos_start - 1);
}