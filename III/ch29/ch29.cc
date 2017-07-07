/*
 * transforming C++ ABI identifiers into the original C++ source identifiers is called "demangling."
 */
#include <exception>
#include <iostream>
#include <cxxabi.h>

struct empty {};

template <typename T, int N>
struct bar {};

int main(int argc, char **arv)
{
	int status;
	char *realname;
	std::bad_exception e;
	realname = abi::__cxa_demangle(e.what(), 0,0,&status);	
	std::cout << e.what() << "\t=> " << realname << "\t: " << status << '\n';
	free(realname);

	// typeid
	bar<empty, 17> u;
	const std::type_info &ti = typeid(u);

	realname = abi::__cxa_demangle(ti.name(), 0,0,&status);
	std::cout << ti.name() << "\t=> " << realname << "\t: " << status << '\n';
	free(realname);
	return 0;
}
