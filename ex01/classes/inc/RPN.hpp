#ifndef RPN_HPP
	#define RPN_HPP

	#include <iostream>
	#include <string>
	#include <stack>
	#include <cstdlib>

	class RPN
	{
		public:
			RPN(void);
			RPN(const RPN& obj);
			RPN(const std::string& str);
			~RPN(void);

			RPN&	operator=(const RPN& rhd);

			int					getResult(void) const;
			std::stack< int >	getStack(void) const;
			std::string			getStr(void) const;

		private:
			std::stack< int >	_numberStack;
			int					_result;
			std::string			_str;

			void				processStr(void);
	};

#endif // RPN_HPP