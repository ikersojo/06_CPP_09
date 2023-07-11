#ifndef DATE_HPP
	#define DATE_HPP

	#include <string>
	#include <iostream>
	#include <stdexcept>

	int		daysInMonth(int month, int year);

	class Date
	{
		public:
			Date(void);
			Date(int year, int month, int day);
			Date(const std::string& str);
			Date(const Date& obj);
			~Date(void);

			void	increment(void);
			void	decrement(void);

			// Operator Overloads
			Date&	operator=(const Date& rhs);

			bool	operator<(const Date& rhs) const;
			bool	operator<=(const Date& rhs) const;
			bool	operator>(const Date& rhs) const;
			bool	operator>=(const Date& rhs) const;
			bool	operator!=(const Date& rhs) const;
			bool	operator==(const Date& rhs) const;

			// Class Public Methods
			int				getYear(void) const;
			int				getMonth(void) const;
			int				getDay(void) const;
			std::string		str(void) const;

		private:
			int			_year;
			int			_month;
			int			_day;
	};

	// Stream operator overload to print Date Class instances:
	std::ostream& operator<<(std::ostream& os, const Date& obj);

#endif // DATE_HPP
