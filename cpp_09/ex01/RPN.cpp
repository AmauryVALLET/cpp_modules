/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:31:12 by avallet           #+#    #+#             */
/*   Updated: 2024/02/29 15:51:38 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	compute(RPN &rpn, char op)
{
	int	number1;
	int	number2;
    
	if (rpn.getStack().size() != 0)
		number1 = rpn.popParam();
	else
		throw RPN::FailComputeException();
	if (rpn.getStack().size() != 0)
		number2 = rpn.popParam();
	else
		throw RPN::FailComputeException();
	if (op == '+')
		return (number2 + number1);
	else if (op == '-')
		return (number2 - number1);
	else if (op == '*')
		return (number2 * number1);
	else if (op == '/')
	{
		if (number1 == 0)
			throw RPN::FailComputeException();
		return (number2 / number1);
	}
    
	throw RPN::FailComputeException();
}




bool	isOperat(char c)
{
	char		str[4] = {'+', '-', '*', '/'};
	for (size_t i = 0; i < 4; i++)
	{
		if (c == str[i])
			return (true);
	}
	return (false);
}




RPN::RPN() {
	
};




RPN::~RPN() {
	
};



RPN::RPN(const RPN &src) {
	(void)src;
};




RPN	&RPN::operator=(const RPN &rhs) {
	(void)rhs;
	return (*this);
};




std::stack<int>		RPN::getStack() const {
	return (_stack);
};




void	RPN::addParam(int param) {
	_stack.push(param);
};




int		RPN::popParam() {
	int		rtn = _stack.top();
	_stack.pop();
	return (rtn);


    
};

int	RPN::rpn(std::string str){
	int		ret;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (isdigit(str[i]) && str[i + 1] != ' ')
			throw ParamIssueException();
		else if (isOperat(str[i]) && _stack.size() < 1)
			throw FailComputeException();
		else if (isdigit(str[i]))
			this->addParam(str[i] - '0');
		else if (isOperat(str[i]))
			this->addParam(compute(*this, str[i]));
		else if (str[i] != ' ')
			throw ParamIssueException();
	}
	if (_stack.size() != 1) // final result
		throw FailComputeException();
	ret = this->popParam();
	return (ret);
};



const char *RPN::ParamIssueException::what() const throw(){
	return ("Wrong param input");
};



const char *RPN::FailComputeException::what() const throw(){
	return ("failed to compute");
};
