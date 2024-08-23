/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:13:51 by avallet           #+#    #+#             */
/*   Updated: 2023/11/21 09:57:16 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <string>

class Harl
{
	private:
		void	_debug( void );
		void	_info( void );
		void	_warning( void );
		void	_error( void );

	public:
		Harl( void );
		~Harl( void );
		void	complain( std::string level );
};

#endif