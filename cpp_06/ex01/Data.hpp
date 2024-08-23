/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:20:35 by avallet           #+#    #+#             */
/*   Updated: 2024/01/24 15:20:36 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Data {
    private:
        const std::string     _type;
        const int             _nbInfo;
        const bool            activated;

        Data();
        Data(const Data& rhs);
        Data&   operator=(const Data &src);
        
    public:
    
        Data(std::string type, int nbInfo, bool activated);
        ~Data();
        std::string     getType() const;
        int             getNbInfo() const;
        bool            getState() const;
};

std::ostream& operator<<(std::ostream & o, Data const & data);