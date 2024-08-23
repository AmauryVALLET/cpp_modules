/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:31:15 by avallet           #+#    #+#             */
/*   Updated: 2024/02/29 10:27:39 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPN {
    
	private:

		std::stack<int>	_stack;
		
		RPN(const RPN &src);
		RPN	&operator=(const RPN &rhs);



	public:

		RPN();
		~RPN();
		std::stack<int>		getStack() const ;
		void				addParam(int param);
		int					popParam(void);
		int					rpn(std::string str);


		
		class ParamIssueException : public std::exception {
			public :
				const char *what() const throw();
		};
		class FailComputeException : public std::exception {
			public :
				const char *what() const throw();
		};
};