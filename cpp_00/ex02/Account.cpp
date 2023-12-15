#include "Account.hpp"
#include <time.h>
#include <iostream>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;


Account::Account(int initail_deposit){
    _amount = initail_deposit;
    _nbAccounts++;
    _accountIndex = _nbAccounts;
    _totalAmount += initail_deposit;  

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";" \
            << "amount:" << _amount << ";" << "created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";" \
        << "amount:" << _amount << ";" << "closed" << std::endl;

}
void	Account::makeDeposit( int deposit )
{
    if (deposit > 0) {  
        _amount += deposit;       
        _nbDeposits++;           
        _totalAmount += deposit;  
        _totalNbDeposits++;       

        _displayTimestamp();      
        std::cout << " index:" << _accountIndex << ";amount:" << _amount - deposit
                << ";deposit:" << deposit << ";withdrawals:" << _nbWithdrawals
                << std::endl;
    } else {
        std::cerr << "Error: Deposit amount must be greater than 0." << std::endl;
    }
}

void    Account::displayAccountsInfos()
{
    _displayTimestamp();      
    std::cout << " account" << _nbAccounts << ";total:" << _totalAmount
            << ";deposit:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
            << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (withdrawal <= _amount) {  
        _amount -= withdrawal;       
        _totalAmount -= withdrawal;  
        _nbWithdrawals++;
        _totalNbWithdrawals++;       

        _displayTimestamp();      
        std::cout << " index:" << _accountIndex << ";p_amount:" << _amount + withdrawal
                << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals
                << std::endl;
        return (true);
    } else {
        _displayTimestamp();      
        std::cout << " index:" << _accountIndex << ";p_amount:" << _amount
                << ";withdrawal:refused" << std::endl;
        return (false);
    }
}
void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
            << ";amount:" << _amount
            << ";deposits:" << _nbDeposits
            << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}


void Account::_displayTimestamp(void)
{
    time_t cur_t;
    char buff[16];
    
    time(&cur_t);
    strftime(buff, sizeof(buff), "%Y%m%d_%H%M%S", localtime(&cur_t));
    std::cout << "[" << buff << "]";
}
int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}



