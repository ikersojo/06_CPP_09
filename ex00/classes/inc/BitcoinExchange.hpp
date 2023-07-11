/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:00:48 by isojo-go          #+#    #+#             */
/*   Updated: 2023/07/10 17:27:51 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
	#define BITCOINEXCHANGE_HPP

	#include <map>
	#include <iostream>
	#include <fstream>
	#include <stdexcept>
	#include "../inc/Date.hpp"


	class BitcoinExchange
	{
		public:
			BitcoinExchange(void);
			~BitcoinExchange(void);

			void	importDB(const std::string& db_file);
			void	printDB(void);
			void	processInput(const std::string& input_file);

		private:
			BitcoinExchange(const BitcoinExchange& obj);
			BitcoinExchange&	operator=(const BitcoinExchange& rhs);

			std::map< Date, double >	_exchangeRateDB;
			Date						_min;

			void	processLine(const std::string& line);
	};

#endif // BITCOINEXCHANGE_HPPd
