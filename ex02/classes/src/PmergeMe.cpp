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
		if ((*(str + i) >= '0' && *(str + i) <= '9') || *(str + i) == ' ')
			i++;
		else
			return false;
	}
	return true;
}

PmergeMe::PmergeMe(const std::string& str)
{
	if (!validChars(str.c_str()))
		throw std::invalid_argument("Error: invalid input!");
	this->_str = str;
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

static long currentTime()
{
	return static_cast<long>(clock());
}

void addIntegersToVector(const std::string& str, std::vector<int>& vector)
{
	std::istringstream	iss(str);
	int					num;
	int					low;
	int					high;

	while (iss >> num)
	{
		if (num <= 0)
			throw std::invalid_argument("Error: invalid input!");
		low = 0;
		high = vector.size() - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (vector[mid] == num)
			{
				// If the num already exists, insert after the last occurrence
				while (mid < (int)vector.size() && vector[mid] == num)
					++mid;
				vector.insert(vector.begin() + mid, num);
				return ;
			}
			else if (vector[mid] < num)
				low = mid + 1;
			else
				high = mid - 1;
		}
		vector.insert(vector.begin() + low, num);
		while (iss.peek() == ' ')
			iss.ignore();
	}
}

void addIntegersToList(const std::string& str, std::list<int>& list)
{
	std::istringstream	iss(str);
	int					num;

	while (iss >> num)
	{
		if (num <= 0)
			throw std::invalid_argument("Error: invalid input!");
		std::list<int>::iterator it = list.begin();
		while (it != list.end() && *it < num)
			++it;
		list.insert(it, num);
		while (iss.peek() == ' ')
			iss.ignore();
	}
}

void	PmergeMe::processStr(void)
{
	long startTime;
	long endTime;

	startTime = currentTime();
	addIntegersToVector(this->_str, this->_vector);
	endTime = currentTime();
	this->_elapsedTimeV = endTime - startTime;

	startTime = currentTime();
	addIntegersToList(this->_str, this->_list);
	endTime = currentTime();
	this->_elapsedTimeL = endTime - startTime;
	this->printResults();
}

void	PmergeMe::printResults(void)
{
	std::cout << "Before: " << this->_str << std::endl;
	std::cout << "After: ";

	std::vector< int >::iterator	it = this->_vector.begin();	
	while (it != this->_vector.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector : " << this->_elapsedTimeV << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_vector.size() << "elements with std::list : " << this->_elapsedTimeL << " us" << std::endl;
}
