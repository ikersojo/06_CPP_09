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
	i = 0;
	while (*(str + i) && *(str + i + 1))
	{
		if (*(str + i) != ' ' && *(str +i + 1) != ' ')
		{
			std::cout << "double chars" << std::endl; // <------ DEBUG
			return false;
		}
		i++;
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
	const char*	str = this->_str.c_str();
	size_t		i = 0;
	int			temp = 0;

	this->_result = 0;
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) >= '0' && *(str + i) <= '9')
			this->_numberStack.push(*(str + i) - '0');
		else if (*(str + i) == ' ')
			;
		else
		{
			switch (*(str + i))
			{
				case '+':
					temp = this->_numberStack.top();
					this->_numberStack.pop();
					while (this->_numberStack.size() != 0)
					{
						temp += this->_numberStack.top();
						this->_numberStack.pop();
						// numCounter--;
					}
					this->_numberStack.push(temp);
					break;
				case '-':
					temp = this->_numberStack.top();
					this->_numberStack.pop();
					while (this->_numberStack.size() != 0)
					{
						temp -= this->_numberStack.top();
						this->_numberStack.pop();
						// numCounter--;
					}
					this->_numberStack.push(temp);
					break;
				case '/':
					temp = this->_numberStack.top();
					this->_numberStack.pop();
					while (this->_numberStack.size() != 0)
					{
						temp /= this->_numberStack.top();
						this->_numberStack.pop();
						// numCounter--;
					}
					this->_numberStack.push(temp);
					break;
				case '*':
					temp = this->_numberStack.top();
					this->_numberStack.pop();
					while (this->_numberStack.size() != 0)
					{
						temp *= this->_numberStack.top();
						this->_numberStack.pop();
						// numCounter--;
					}
					this->_numberStack.push(temp);
					break;
				default:
					break;
			}
		}
		i++;
	}
	// if (signCounter < 1 || initCounter < 2)
	// {
	// 	std::cout << "not enough args" << std::endl; // <------ DEBUG
	// 	throw std::invalid_argument("Error: invalid input!");
	// }
	this->_result = this->_numberStack.top();
	this->_numberStack.pop();
}
