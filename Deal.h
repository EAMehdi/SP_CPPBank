#ifndef DEAL_H
#define DEAL_H

#include <string>
#include <vector>
#include <chrono>
#include "Lender.h"
#include "Borrower.h"
#include "Currency.h"

class Deal {
private:
    std::string contractNumber;
    Lender agent;
    std::vector<Lender> pool;
    Borrower borrower;
    double amount;
    Currency currency;
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point ending;
    std::string status;

public:
    // constructors, setters, etc...

    Deal(const std::string& contractNumber, const Lender& agent, const std::vector<Lender>& pool,
    const Borrower& borrower, double amount, const Currency& currency,
    const std::chrono::system_clock::time_point& start, const std::chrono::system_clock::time_point& ending);

    std::string getContractNumber() const { return contractNumber; }
    Lender getAgent() const { return agent; }
    std::vector<Lender> getPool() const { return pool; }
    Borrower getBorrower() const { return borrower; }
    double getAmount() const { return amount; }
    Currency getCurrency() const { return currency; }
    std::chrono::system_clock::time_point getStart() const { return start; }
    std::chrono::system_clock::time_point getEnd() const { return ending; }
    std::string getStatus() const { return status; }
    void setStatus(const std::string& status);
};
#endif
