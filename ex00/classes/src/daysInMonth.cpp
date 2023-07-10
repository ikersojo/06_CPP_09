static bool isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return (true);
	return (false);
}

int		daysInMonth(int month, int year)
{
	static const int daysInEachMonth[] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

    int days = daysInEachMonth[month - 1];

	if (month == 2 && isLeapYear(year))
		days++;
	return days;
}
