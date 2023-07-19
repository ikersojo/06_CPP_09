#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(const PmergeMe& obj)
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
			return false;
		i++;
	}
	return true;
}

PmergeMe::PmergeMe(const std::string& str)
{
	if (!validChars(str.c_str()))
		throw std::invalid_argument("Error: invalid input!");
	this->_str = str;
	// this->processStr();
}

PmergeMe::~PmergeMe(void)
{

}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
	{
		this->_str = rhs.getStr();
	}
	return (*this);
}

std::string			PmergeMe::getStr(void) const
{
	return (this->_str);
}

// void	PmergeMe::processStr(void)
// {

// }
