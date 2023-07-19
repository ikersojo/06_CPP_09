#include "../inc/main.hpp"

int		main(int argc, char **argv)
{
	int			i = 0;
	std::string	input;

	while(++i < argc)
	{
		input.append(argv[i]);
		if (i < argc - 1)
			input.append(" ");
	}

	std::cout << input << std::endl;

	return (0);
}
