/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:20:30 by avallet           #+#    #+#             */
/*   Updated: 2024/01/24 15:20:31 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _type("Data"), _nbInfo(42), activated(false) {};

Data::Data(const Data& rhs) : _type(rhs.getType()), _nbInfo(rhs.getNbInfo()), activated(rhs.getState()) {
    
};

Data&   Data::operator=(const Data &src) {
    (void)src;
    return *this;
};

Data::~Data() {
    
};

Data::Data(std::string type, int nbInfo, bool activated) : _type(type), _nbInfo(nbInfo), activated(activated) {
    
};

std::string     Data::getType() const {
    return (_type);
};

int             Data::getNbInfo() const {
    return (_nbInfo);
};

bool            Data::getState() const {
    return (activated);
};

std::ostream& operator<<(std::ostream & o, Data const & data){
    o << "Data Type: " << data.getType() << std::endl
        << "Data info: " << data.getNbInfo() << std::endl
        << "Data activated ?: " << (data.getState() ? "Yes" : "No");
    return (o);
};