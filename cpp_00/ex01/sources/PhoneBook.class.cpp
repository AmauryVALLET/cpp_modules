/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:30:13 by avallet          #+#    #+#             */
/*   Updated: 2023/11/13 16:00:31 by avallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"


PhoneBook::PhoneBook(void) : _index(-1), _quit(false) {
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

std::string	PhoneBook::_getInput(std::string const claim) {
	std::string	input;

	std::cout << "Please enter " << claim << ": " << std::endl << "> ";
	if (!std::getline(std::cin, input) || std::cin.eof()) {
		_quit = true;
		std::cout << std::endl;
		return(std::string());
	}
	input = trimBlank(input);
	return (input);
}

void	PhoneBook::_incrementIndex(void) {
	_index++;
	if (_index > 7) {
		_index = 0;
	}
}

void	PhoneBook::_displayContactTable(void) const {
	std::cout	<< "+----------+----------+----------+----------+" << std::endl
				<< "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
				<< "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < 8; i++) {
		_fillContactToTable(i);
	}
	std::cout << std::endl;
	return ;
}

void	PhoneBook::_fillContactToTable(int const index) const {
	if (this->_contactList[index].isEmpty())
		return ;
	std::cout << "|" << std::setw(10) << index << "|";
	_reformatCell(this->_contactList[index].getFirstname());
	_reformatCell(this->_contactList[index].getLastname());
	_reformatCell(this->_contactList[index].getNickname());
	std::cout	<< std::endl
				<< "+----------+----------+----------+----------+" << std::endl;
	return ;
}

void PhoneBook::_reformatCell(std::string str) const {
	if (str.length() > 10) {
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10) << str << "|";
	return ;
}

bool	PhoneBook::_displayContactByIndex(std::string const input) const {

	int			index;
	if (input.length() == 1 && std::isdigit(input[0])) {
		index = input[0] - '0';
		if (index >= 0 && index <= 7) {
			if (this->_contactList[index].displayContactInfo())
				return (true);
			else {
				std::cout << "Error: Nothing at index [" << index << "]. ADD a contact first." << std::endl;
				return (false);
			}
		}
	}
	std::cout << "Error: \'" << input << "' is not a valid index, chose between 0 and 7." << std::endl;
	return (false);
}


std::string	PhoneBook::trimBlank(std::string str) {
	std::string	blank = " \t\n\r\v\f";
	size_t		start;
	size_t		end;

	start = str.find_first_not_of(blank);
	end = str.find_last_not_of(blank);
	if (start == end)
		return (str);
	return (str.substr(start, end - start + 1));
}


bool 	PhoneBook::addContact(void) {
	std::string	input;

	_incrementIndex();
	std::cout << std::endl << "*************** NEW CONTACT MENU **************" << std::endl << std::endl;
	while (!_quit) {
		input = _getInput("a first name");
		if (_quit || this->_contactList[_index].setFirstname(input))
			break ;
	}
	while (!_quit) {
		input = _getInput("a last name");
		if (_quit || this->_contactList[_index].setLastname(input))
			break ;
	}
	while (!_quit) {
		input = _getInput("a nickname");
		if (_quit || this->_contactList[_index].setNickname(input))
			break ;
	}
	while (!_quit) {
		input = _getInput("a phone number");
		if (_quit || this->_contactList[_index].setNumber(input))
			break ;
	}
	while (!_quit) {
		input = _getInput("a darkest secret");
		if (_quit || this->_contactList[_index].setSecret(input))
			break ;
	}
	if (_quit) {
		_quit = false;
		return (false);
	}
	std::cout << "Contact added to Phonebook." << std::endl;
	return (true);
}

void	PhoneBook::displayContact(int index) const {
	if (index >= 0 && index <= 7) {
		if (this->_contactList[index].displayContactInfo())
			return ;
	}
	std::cout << "Error: No record for the requested contact." << std::endl;
}

bool	PhoneBook::searchContact(void) {
	std::string	input;

	std::cout << std::endl << "***************** SEARCH MENU *****************" << std::endl << std::endl;
	if (_index == -1) {
		std::cout << "No contacts in record. Please ADD a contact first." << std::endl;
		return (true);
	}
	this->_displayContactTable();
	input = _getInput("the index of the contact to display");
	if (input.empty())
		return (false);
	this->_displayContactByIndex((std::string const)input);
	return (true);
}
