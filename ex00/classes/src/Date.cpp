#include "../inc/Date.hpp"

Date::Date(void)
{
	this->_year = 1900;
	this->_month = 1; 
	this->_day = 1;
}

Date::Date(int year, int month, int day)
{
	this->_year = year;
	this->_month = month; 
	this->_day = day;

	if ((this->_year <= 0 || this->_year > 2300) || (this->_month < 1 || this->_month > 12)
	|| (this->_day > daysInMonth(this->_month, this->_year) || this->_day < 1))
	{
		throw std::invalid_argument("Error: invalid date!");
	}
}

Date::Date(const std::string& str)
{
	size_t firstDashPos = str.find('-');
	size_t secondDashPos = str.find_last_of('-');
	
	if (firstDashPos != std::string::npos && secondDashPos != std::string::npos)
	{
		try
		{
			this->_year = atoi(str.substr(0, firstDashPos).c_str());
			this->_month = atoi(str.substr(firstDashPos + 1, secondDashPos - firstDashPos - 1).c_str());
			this->_day = atoi(str.substr(secondDashPos + 1).c_str());
		}
		catch(const std::exception& e)
		{
			throw std::invalid_argument("Error: invalid date!");
		}
	}
	if ((this->_year <= 0 || this->_year > 2300) || (this->_month < 1 || this->_month > 12)
		|| (this->_day > daysInMonth(this->_month, this->_year) || this->_day < 1))
	{
		throw std::invalid_argument("Error: invalid date!");
	}
}

Date::Date(const Date& obj)
{
	*this = obj;
}

Date::~Date(void)
{

}

Date&	Date::operator=(const Date& rhs)
{
	if (this != &rhs)
	{
		this->_day = rhs.getDay();
		this->_month = rhs.getMonth();
		this->_year = rhs. getYear();
	}
	return (*this);
}
bool Date::operator<(const Date& rhs) const
{
	if (this->getYear() < rhs.getYear())
		return true;
	else if (this->getYear() == rhs.getYear() && this->getMonth() < rhs.getMonth())
		return true;
	else if (this->getYear() == rhs.getYear() && this->getMonth() == rhs.getMonth() && this->getDay() < rhs.getDay())
		return true;
	return false;
}

bool Date::operator<=(const Date& rhs) const
{
	return (*this < rhs) || (*this == rhs);
}

bool Date::operator>(const Date& rhs) const
{
	return !(*this <= rhs);
}

bool Date::operator>=(const Date& rhs) const
{
	return !(*this < rhs);
}

bool Date::operator==(const Date& rhs) const
{
	return (this->getYear() == rhs.getYear() && this->getMonth() == rhs.getMonth() && this->getDay() == rhs.getDay());
}

bool Date::operator!=(const Date& rhs) const
{
	return !(*this == rhs);
}

void	Date::increment(void)
{
	this->_day++;
	if (this->_day > daysInMonth(this->_month, this->_year))
	{
		this->_day = 1;
		this->_month++;
		if (this->_month > 12)
		{
			this->_month = 1;
			this->_year++;
		}
	}
}

void	Date::decrement(void)
{
	this->_day--;
	if (this->_day < 1)
	{
		this->_month--;
		if (this->_month < 1)
		{
			this->_month = 12;
			this->_year--;
		}
		this->_day = daysInMonth(this->_month, this->_year);
	}
}

int		Date::getYear(void) const
{
	return (this->_year);
}

int		Date::getMonth(void) const
{
	return (this->_month);
}

int		Date::getDay(void) const
{
	return (this->_day);
}

std::string	Date::str(void) const
{
	std::string dateString;
	std::stringstream ss;
	std::string yearStr;
	std::string monthStr;
	std::string dayStr;

	ss << this->_year;
	ss >> yearStr;
	ss.clear();

	ss << this->_month;
	ss >> monthStr;
	ss.clear();

	ss << this->_day;
	ss >> dayStr;
	ss.clear();

	if (monthStr.length() < 2)
		monthStr = "0" + monthStr;
	if (dayStr.length() < 2)
		dayStr = "0" + dayStr;

	dateString = yearStr + "-" + monthStr + "-" + dayStr;
	return dateString;
}

std::ostream& operator<<(std::ostream& os, const Date& obj)
{
	os << obj.str();
	return (os);
}
