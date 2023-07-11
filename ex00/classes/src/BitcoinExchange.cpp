/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:00:45 by isojo-go          #+#    #+#             */
/*   Updated: 2023/07/10 17:33:26 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::~BitcoinExchange(void) {}

void	BitcoinExchange::importDB(const std::string& db_file)
{
	std::ifstream	inFile;
	std::string		line;

	inFile.open(db_file);
	if (!inFile.is_open())
		throw std::invalid_argument("Error: Database File could not be openned.");

	this->_min = Date(2100,1,1);
	
	while (getline(inFile, line))
	{
		if (line.find(",") != std::string::npos && line.find("date") == std::string::npos)
		{
			try
			{
				size_t		firstComaPos = line.find(',');
				Date		extractedDate(line.substr(0, firstComaPos));
				double		extractedValue = std::stod(line.substr(firstComaPos + 1, line.size()));

				_exchangeRateDB[extractedDate] = extractedValue;
				if (extractedDate < this->_min)
					_min = extractedDate;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << " => line: " << line << std::endl;
			}
			
		}
	}
	inFile.close();
}

void	BitcoinExchange::printDB(void)
{
	const int MAXVAL = 30;
	std::map< Date, double >::iterator	itr = this->_exchangeRateDB.begin();

	std::cout << std::endl << "DATABASE (date: xr)" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	int i = 0;
	while (itr != this->_exchangeRateDB.end() && i < MAXVAL)
	{
		std::cout << itr->first << ": " << itr->second << std::endl;
		++itr;
		++i;
	}
	if (i == MAXVAL)
		std::cout << "..." << std::endl << std::endl;
}

void	BitcoinExchange::processLine(const std::string& line)
{
	try
	{
		size_t	firstLinePos = line.find(' ');
		Date	extractedDate(line.substr(0, firstLinePos));
		double	extractedValue = std::stod(line.substr(firstLinePos + 1, line.size()));
		double	xr;
		bool	found = false;

		while (!found && extractedDate > this->_min)
		{
			if (this->_exchangeRateDB.find(extractedDate) != this->_exchangeRateDB.end())
			{
				xr = this->_exchangeRateDB.find(extractedDate)->second;
				found = true;
			}
			extractedDate.decrement();
		}
		
		if (extractedValue < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (extractedValue > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
			std::cout << extractedDate << " => " << extractedValue << " = "
				<< xr * extractedValue << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: bad input => " << line << std::endl;
	}
}

void	BitcoinExchange::processInput(const std::string& input_file)
{
	std::ifstream	inFile;
	std::string		line;

	inFile.open(input_file);
	if (!inFile.is_open())
		throw std::invalid_argument("Error: Input File could not be openned.");
	
	while (getline(inFile, line))
	{
		if (line.find(" | ") != std::string::npos)
		{
			if (line.find("date") == std::string::npos)
				this->processLine(line);
		}
		else
			std::cout << "Error: bad input => " << line << std::endl;
	}
	inFile.close();
}
