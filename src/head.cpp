#include "head.hpp"

void head::set_info(int sz, std::string cnt) {
	this->size = sz;
	this->content = cnt;
}

int head::get_info_size() {
	return this->size;
}

std::string head::get_info_content() {
	return this->content;
}