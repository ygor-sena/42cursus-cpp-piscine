/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:53:38 by yde-goes          #+#    #+#             */
/*   Updated: 2023/08/28 13:53:40 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <iomanip>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return (_nbAccounts); }

int Account::getTotalAmount(void) { return (_totalAmount); }

int Account::getNbDeposits(void) { return (_totalNbDeposits); }

int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) {
  this->_accountIndex = getNbAccounts();
  _nbAccounts++;
  this->_amount = initial_deposit;
  _totalAmount += _amount;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit
            << ";created" << std::endl;
}

Account::~Account(void) {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  this->_amount += deposit;
  this->_nbDeposits++;
  _totalNbDeposits += this->_nbDeposits;
  _totalAmount += deposit;
  std::cout << "index:" << this->_accountIndex
            << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit
            << ";amount:" << this->_amount
            << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  if (this->_amount < withdrawal) {
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount << ";withdrawal:refused"
              << std::endl;
    return (false);
  }
  this->_amount -= withdrawal;
  _totalAmount -= withdrawal;
  this->_nbWithdrawals++;
  _totalNbWithdrawals += this->_nbWithdrawals;
  std::cout << "index:" << this->_accountIndex
            << ";p_amount:" << this->_amount + withdrawal
            << ";withdrawal:" << withdrawal << ";amount:" << this->_amount
            << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
  return (true);
}

int Account::checkAmount(void) const { return (this->_amount); }

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
  time_t now = time(0);
  tm *ltm = localtime(&now);
  std::cout << "[" << 1900 + ltm->tm_year << 1 + ltm->tm_mon << ltm->tm_mday
            << "_" << std::setfill('0') << std::setw(2) << 5 + ltm->tm_hour
			<< std::setfill('0') << std::setw(2) << 30 + ltm->tm_min
			<< std::setfill('0') << std::setw(2) << ltm->tm_sec
            << "] ";
}
