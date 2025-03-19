/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:17:21 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/19 20:46:20 by llaakson         ###   ########.fr       */
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
	_nbAccounts++;
}
Account::~Account( void ){
}
/*int	Account::getNbAccounts( void ){
return (1);}
int	Account::getTotalAmount( void ){
return (1);}
int	Account::getNbDeposits( void ){
return (1);}
int	Account::getNbWithdrawals( void ){
return (1);}*/
void	Account::displayAccountsInfos( void ){
std::cout << "displayAccountsInfos: " << std::endl;
}

void    Account::makeDeposit( int deposit ){
	(void)deposit;
	std::cout << "makeDeposit: " << std::endl;
}

bool    Account::makeWithdrawal( int withdrawal ){
	std::cout << "makeWithdrawal: " << std::endl;
	return(withdrawal);
}

int     Account::checkAmount( void ) const {
	std::cout << "checkAmount: " << std::endl;
	return(1);
}

void    Account::displayStatus( void ) const {
		_displayTimestamp();
		std::cout << "index:" << Account::_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

void Account::_displayTimestamp( void ){
	time_t timestamp;
	char output[50];
	struct tm * datetime;
	time(&timestamp);
	datetime = localtime(&timestamp);
	strftime(output, 50, "[%Y%m%d_%H%M%S]", datetime);
	std::cout << output;
}
