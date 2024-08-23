/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:12:15 by avallet           #+#    #+#             */
/*   Updated: 2024/02/29 15:27:27 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream	data;
    std::string		date;
    std::string		exchange_rate;

	data.open("data.csv");
	if (!data.is_open())
	{
		std::cerr << "Failed open csv file" << std::endl;
		exit(1);
	}
	else
	{
		getline(data, date);
		while (!getline(data, date, ',').eof())
		{
			getline(data, exchange_rate);
			this->btc.insert(std::make_pair(date, strtod(exchange_rate.c_str(), NULL)));
		}
		data.close();
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& btc)
{
    *this = btc;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& btc)
{
    if (this != &btc)
        this->btc = btc.btc;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


// match / begin / close to low
double	BitcoinExchange::matchDate(std::string date)
{
	double	rate = 0;

	if (this->btc.find(date) != this->btc.end())
		rate = this->btc[date];
	else if (this->btc.begin()->first > date)
		rate = this->btc.begin()->second;
	else
	{
		std::map<std::string, double>::iterator it = this->btc.lower_bound(date);
		it--;
		rate = it->second;
	}
	return rate;
}


std::map<std::string, double> BitcoinExchange::getBtc() const
{
    return this->btc;
}