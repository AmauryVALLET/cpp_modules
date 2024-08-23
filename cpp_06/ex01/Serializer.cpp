/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:21:33 by avallet           #+#    #+#             */
/*   Updated: 2024/01/24 15:21:34 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){
};

Serializer::~Serializer(){

};

Serializer::Serializer(const Serializer& rhs){
    (void)rhs;
};

Serializer& Serializer::operator=(const Serializer& rhs){
    (void)rhs;
    return (*this);
};

uintptr_t    Serializer::serialize(Data* ptr){
    uintptr_t   rawPtr = reinterpret_cast<uintptr_t>(ptr);
    if (!rawPtr)
        throw Serializer::SerializeError();
    else
        std::cout << "Serialization succeed" << std::endl;
    return (rawPtr);
};

Data*   Serializer::deserialize(uintptr_t raw){
    Data *data = reinterpret_cast<Data*>(raw);
    if (!data)
        throw Serializer::DeserializeError();
    else
        std::cout << "Deserialization succeed" << std::endl;
    return (data);
};
const char* Serializer::SerializeError::what() const throw(){
    return ("Serializion Failed");
};

const char* Serializer::DeserializeError::what() const throw(){
    return ("Deserializion Failed");
};
