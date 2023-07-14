#include "RPN.hpp"

RPN::RPN(void)
{
	this->_result = 0;
}

RPN::RPN(const RPN& obj)
{
	*this = obj;
}

static bool	validChars(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
	{
		if ((*(str + i) >= '0' && *(str + i) <= '9')
		 || *(str + i) == ' '
		 || *(str + i) == '+' || *(str + i) == '-'
		 || *(str + i) == '/' || *(str + i) == '*')
			i++;
		else
			return false;
	}
	return true;
}

RPN::RPN(const std::string& str)
{
	if (!validChars(str.c_str()))
		throw std::invalid_argument("Error: invalid input!");
	this->_str = str;
	this->processStr();
}

RPN::~RPN(void)
{

}

RPN&	RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
	{
		this->_numberStack = rhs.getStack();
		this->_result = rhs.getResult();
		this->_str = rhs.getStr();
	}
	return (*this);
}

int		RPN::getResult(void) const
{
	return(this->_result);
}

std::stack< int >	RPN::getStack(void) const
{
	return(this->_numberStack);
}

std::string			RPN::getStr(void) const
{
	return (this->_str);
}

void	RPN::processStr(void)
{
	std::cout << "STR OK: " << this->getStr() << std::endl; // DEBUG <-----------------

	const char*	str = this->_str.c_str();
	size_t		i = 0;
	size_t		counter = 0;

	i = 0;
	while (*(str + i))
	{
		std::cout << *(str + i) << std::endl; // DEBUG <-----------------
		if (*(str + i) >= '0' && *(str + i) <= '9')
		{
			this->_numberStack.push(*(str + i) - '0');
			counter++;
		}
		else if (*(str + i) == ' ')
			i++;
		else
		{
			if (counter < 2)
				throw std::invalid_argument("Error: invalid input!");
			switch (*(str + i))
			{
				case '+':
					std::cout << "adding... " << std::endl; // DEBUG <-----------------
					break;
				case '-':
					std::cout << "substracting... " << std::endl; // DEBUG <-----------------
					break;
				case '/':
					std::cout << "dividing... " << std::endl; // DEBUG <-----------------
					break;
				case '*':
					std::cout << "multiplying... " << std::endl; // DEBUG <-----------------
					break;
				default:
					break;
			}
		}
		i++;
	}
}
