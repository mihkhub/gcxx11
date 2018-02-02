#include <exception>

int main()
{
	std::set_terminate(__gnu_cxx::__verbose_terminate_handler);

	throw "anything";

	return 0;
}
