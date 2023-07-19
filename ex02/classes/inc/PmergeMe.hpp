#ifndef PMERGEME_HPP
	#define PMERGEME_HPP

	#include <iostream>
	#include <string>
	#include <stack>
	#include <cstdlib>

	class PmergeMe
	{
		public:
			PmergeMe(void);
			PmergeMe(const PmergeMe& obj);
			PmergeMe(const std::string& str);
			~PmergeMe(void);

			PmergeMe&	operator=(const PmergeMe& rhd);


			std::string		getStr(void) const;

		private:
			std::string	_str;

	};

#endif // PMERGEME_HPP
