#ifndef HEAD_HPP
#define HEAD_HPP

#include <string>

class Head {
private:
	int size;
	std::string content="";
public:
	void set_info(int, std::string);

	int get_info_size();

	std::string get_info_content();
};

#endif