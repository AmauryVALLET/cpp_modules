/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:21:58 by avallet           #+#    #+#             */
/*   Updated: 2024/01/30 15:21:59 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template< typename T >
void    swap(T& a, T& b){
    T   tmp;
    tmp = a;
    a = b;
    b = tmp;
}
template< typename T >
T       min(const T &a, const T &b) 
{
    return (a < b ? a : b);
}

template< typename T >
T       max(const T &a, const T &b)
{
    return (a > b ? a : b);
}
