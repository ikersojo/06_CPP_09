#include "../inc/main.hpp"

int		main(int argc, char **argv)
{

	if (argc == 2)
	try
	{
		RPN rpn(argv[1]);
		std::cout << rpn.getResult() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error1" << std::endl;
	}
	else
		std::cout << "Error2" << std::endl;
	return (0);
}
