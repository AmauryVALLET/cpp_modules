/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:21:38 by avallet           #+#    #+#             */
/*   Updated: 2024/01/24 15:21:39 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer {
    
    private:

    Serializer();
    ~Serializer();
    Serializer(const Serializer& rhs);
    Serializer& operator=(const Serializer& rhs);

    public:
    
    static uintptr_t    serialize(Data* ptr);
    static Data*        deserialize(uintptr_t raw);
    
    class SerializeError : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class DeserializeError : public std::exception {
        public:
            virtual const char* what() const throw();
    };
}; 