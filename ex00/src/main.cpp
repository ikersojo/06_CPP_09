/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:00:36 by isojo-go          #+#    #+#             */
/*   Updated: 2023/07/10 17:15:01 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

int	printError(std::string str)
{
	std::cout << "\033[0;31m" << str << "\033[0;39m" << std:: endl;
	exit (1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		BitcoinExchange btc;

		btc.importDB("./db/data.csv");
		// btc.printDB();

		btc.processInput(argv[1]);

		//testing dates:
		// Date date(argv[1]);
		// std::cout << date << std::endl;

	}
	else
		printError("Syntax Error: ./bin/btc input.txt");
	return (0);
}
