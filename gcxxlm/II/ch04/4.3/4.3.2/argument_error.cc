#include <exception>

#include <stdexcept>

struct argument_error : public std::runtime_error

{

	argument_error(const std::string& s): std::runtime_error(s) { }

};

int main(int argc, char **argv)

{

	std::set_terminate(__gnu_cxx::__verbose_terminate_handler);

	if (argc > 5)

		throw argument_error("argc is greater than 5!");

	else

		throw argc;

	return 0;
}
