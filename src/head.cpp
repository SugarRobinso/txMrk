#include "head.hpp"

void Head::set_info(int sz, std::string cnt) {
	this->size = sz;
	this->content = cnt;
}

int Head::get_info_size() {
	return this->size;
}

std::string Head::get_info_content() {
	return this->content;
}