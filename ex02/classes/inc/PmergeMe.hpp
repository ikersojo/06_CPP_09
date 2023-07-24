#ifndef PMERGEME_HPP
	#define PMERGEME_HPP

	#include <iostream>
	#include <string>
	#include <vector>
	#include <list>
	#include <cstdlib>
	#include <ctime>
	#include <sstream>
	#include <algorithm>

	class PmergeMe
	{
		public:
			PmergeMe(void);
			PmergeMe(const PmergeMe& obj);
			PmergeMe(const std::string& str);
			~PmergeMe(void);

			PmergeMe&	operator=(const PmergeMe& rhd);

			std::string		getStr(void) const;

			void	processStr(void);

		private:
			std::string			_str;
			std::vector< int >	_vector;
			std::list< int >	_list;
			long				_elapsedTimeV;
			long				_elapsedTimeL;

			void	printResults(void);

	};

#endif // PMERGEME_HPP
