#include <iostream>
#include <fstream>
#include <vector>

#include "head.hpp"

enum OBJ {
	DIV, // div
	HDD, // head
	LST, // list
	LNK, // link
	IMG, // image
	TXT, // text
	TBL, // table
	CBX, // checkbox
	JSS, // javascript
	CSS // css
};



// check_obj

int check_obj(std::string s) {
	if (s == "DIV") {
		return DIV;
	}
	else if (s == "HDD") {return HDD;}
	else if (s == "LST") {return LST;}
	else if (s == "LNK") {return LNK;}
	else if (s == "IMG") {return IMG;}
	else if (s == "TXT") {return TXT;}
	else if (s == "TBL") {return TBL;}
	else if (s == "CBX") {return CBX;}
	else if (s == "JSS") {return JSS;}
	else if (s == "CSS") {return CSS;}

	return -1;
}



// obj_is

std::string obj_is(std::string obj) {
	switch (check_obj(obj)) {
	case 0:
		return "DIV";
		break;
	case 1:
		return "HDD";
		break;
	case 2:
		return "LST";
		break;
	case 3:
		return "LNK";
		break;
	case 4:
		return "IMG";
		break;
	case 5:
		return "TXT";
		break;
	case 6:
		return "TBL";
		break;
	case 7:
		return "CBX";
		break;
	case 8:
		return "JSS";
		break;
	case 9:
		return "CSS";
		break;
	}

	return "n";
}



// get_obj_data

void get_obj_data(const std::string& line, std::string& id, std::string& cls) {
	int pos_start = line.find(':');
	int pos_end = line.find(')');
	id = line.substr(5, pos_start - 5);
	cls = line.substr(pos_start + 1, pos_end - pos_start - 1);
}



// ext_src

void ext_src(const std::string& line, std::vector<std::string>& container) {
	int pos_end = line.find(')');
	container.push_back(line.substr(5, pos_end - 5));
}





int main(int argc, char* argv[]) {

	if (argc == 1) {
		std::cout << "Devi inserire il file da trasformare\n";

		return 0;
	}
	

	std::string filename = argv[1];

	std::ifstream mkText_I_f;
	mkText_I_f.open(filename, std::fstream::in);

	std::ofstream mkText_O_f;
	mkText_O_f.open(filename.replace(filename.length() - 3, 3, "html"), std::fstream::trunc);

	std::string ln;
	std::vector<std::string> css_links;
	std::vector<std::string> js_scripts;
	std::vector<std::string> obj_collection;

	mkText_O_f << "<!DOCTYPE html>\n";
	mkText_O_f << "<html>\n";

	head hd;

	while (std::getline(mkText_I_f, ln)) {
		int counter=0;
		int pos=0;
		bool obj;
		std::string obj_type="";
		std::string obj_id="";
		std::string obj_class="";
		std::string obj_body="";

		// #OBJ(ID:CLASS){_recursion1:recursion2:recursion3:...:recursionN_ CONTENT}
		// #___(...:...){...}

		if (ln[counter] == '#') {
			obj_type = obj_is(ln.substr(counter+1, 3));

			std::cout << obj_type << std::endl;

			if (obj_type != "JSS" && obj_type != "CSS")
				get_obj_data(ln, obj_id, obj_class);
			else if (obj_type == "JSS")
				ext_src(ln, js_scripts);
			else if (obj_type == "CSS")
				ext_src(ln, css_links);


			switch (check_obj(obj_type)) {
				case DIV:
					// mkText_O_f << "";
					break;
				// head <hN></hN> with N=1, 2, ..., 6
				// head -> ...{head_size:content}
				// head -> ...{2:just a test}
				case HDD:
					obj_body = ln.substr(ln.find('{') + 1, ln.find('}') - ln.find('{') - 1);
					hd.set_info(std::stoi(obj_body.substr(0, obj_body.find(':'))), obj_body.substr(obj_body.find(':') + 1, obj_body.length() - obj_body.find(':') + 1));
					std::cout << hd.get_info_size() << std::endl;
					std::cout << hd.get_info_content() << std::endl;
					std::cout << "PORCO ZEUS FUNZIONA !" << std::endl;
					// std::cout << obj_body.substr(0, obj_body.find(':')) << std::endl;
					// std::cout << obj_body.substr(obj_body.find(':') + 1, obj_body.length() - obj_body.find(':') + 1) << std::endl;
					mkText_O_f << "";
					break;
				case LST:
					break;
				case LNK:
					break;
				case IMG:
					break;
				case TXT:
					break;
				case TBL:
					break;
				case CBX:
					break;
				case JSS:
					std::cout << js_scripts[0] << "\n";
					break;
				case CSS:
					std::cout << css_links[0] << "\n";
					break;
			}
		}
	}

	mkText_O_f << "\t<head>\n";

	for (int i = 0; i < css_links.size(); i++) {
		mkText_O_f << "\t\t" << "<link rel=\"stylesheet\" href=\"" << css_links[i] << "\">" << "\n";
	}
	

	mkText_O_f << "\t</head>\n";
	mkText_O_f << "\t<body>\n";
	mkText_O_f << "\t\tMinchia sono un Dio !\n";

	for (int i = 0; i < obj_collection.size(); i++) {
		mkText_O_f << obj_collection[i] << "\n";
	}

	for (int i = 0; i < js_scripts.size(); i++) {
		mkText_O_f << "\t\t" << "<script type=\"text/javascript\" src=\"" << js_scripts[i] << "\"></script>\n";
	}

	mkText_O_f << "\t</body>\n";
	mkText_O_f << "</html>\n";

	return 0;
}