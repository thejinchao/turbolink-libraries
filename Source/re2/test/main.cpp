#include <stdio.h>
#include <assert.h>

#include <re2/re2.h>

int main(int argc, char* argv[]) 
{
	int number;
	std::string str;
	assert(RE2::FullMatch("test:1234", "(\\w+):(\\d+)", &str, &number));
	printf("string=%s, number=%d\n", str.c_str(), number);
	assert(str == "test");
	assert(number == 1234);

	return 0;
}
