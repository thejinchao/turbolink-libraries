#include <iostream>
#include <string>
#include <vector>
#include "absl/strings/str_join.h"

int main(int argc, char* argv[]) 
{
	std::vector<std::string> v = { "foo","bar","baz" };
	std::string s = absl::StrJoin(v, "-");
	std::cout << "Joined string:" << s << std::endl;
	return 0;
}
