#ifndef SP_CPPBANK_PORTFOLIO_H
#define SP_CPPBANK_PORTFOLIO_H

#include <vector>
#include "Facility.h"

class Portfolio {
public:
    Portfolio(); // Default constructor
    Portfolio(const std::vector<Facility>& facilities);

    void addFacility(const Facility& facility);
    double calculateTotalValue() const;
    double calculateTotalInterest() const;
    void makeRepayment(const std::string& contractNumber, double amount);
    bool isLoanPaidInFull() const;

private:
    std::vector<Facility> facilities;

    void removeFacility(const std::string& contractNumber);
};

#endif // SP_CPPBANK_PORTFOLIO_H