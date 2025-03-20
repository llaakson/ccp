/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:17:21 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/20 12:40:35 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ){
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	_totalAmount += initial_deposit;
	std::cout << "index:" << Account::_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	_nbAccounts++;
}
Account::~Account( void ){
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void    Account::makeDeposit( int deposit ){
	_displayTimestamp();
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	std::cout << "index:" << Account::_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
}

bool    Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	if (this->_amount - withdrawal < 0){
		 std::cout << "index:" << Account::_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		 return(false);
		}
	this->_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	std::cout << "index:" << Account::_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	return(true);
}

int     Account::checkAmount( void ) const {
	return(this->_amount);
}

void    Account::displayStatus( void ) const {
		_displayTimestamp();
		std::cout << "index:" << Account::_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals<< std::endl;
}

void Account::_displayTimestamp( void ){
	time_t timestamp;
	char output[50];
	struct tm * datetime;
	time(&timestamp);
	datetime = localtime(&timestamp);
	strftime(output, 50, "[%Y%m%d_%H%M%S] ", datetime);
	std::cout << output;
}
