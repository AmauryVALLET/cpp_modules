/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:30:03 by avallet          #+#    #+#             */
/*   Updated: 2023/11/13 16:00:30 by avallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <string>
# include "Contact.class.hpp"



class	PhoneBook {



	private:
		int		_index;
		bool	_quit;
		Contact	_contactList[8];

		std::string	_getInput(std::string const claim);
		void		_incrementIndex(void);
		bool		_displayContactByIndex(std::string const input) const;
		void		_displayContactTable(void) const;
		void		_fillContactToTable(int const index) const;
		void		_reformatCell(std::string str) const;




	public:
		PhoneBook(void);
		~PhoneBook(void);

		std::string	trimBlank(std::string str);
		bool		addContact(void);
		void		displayContact(int index) const;
		bool		searchContact(void);
};

#endif