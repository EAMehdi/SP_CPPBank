#include <iostream>
#include <vector>
#include "Lender.h"
#include "Borrower.h"
#include "Currency.h"
#include "Deal.h"
#include "Facility.h"
#include "Portfolio.h"
#include "Part.h"

int main() {
    // Create Lenders
    Lender lender1("Bank A");
    Lender lender2("Bank B");
    Lender lender3("Bank C");

    // Create a pool of lenders
    std::vector<Lender> pool = {lender1, lender2, lender3};

    // Create a Borrower
    Borrower borrower("Air France");

    // Create a Currency
    Currency currency("USD");

    auto now = std::chrono::system_clock::now();

    // Deal start and end dates
    std::chrono::system_clock::time_point start = now;
    std::chrono::system_clock::time_point ending = start + std::chrono::hours(24*365);  // One year later

    // Create a Deal
    Deal deal("S1234", lender1, pool, borrower, 10000000, currency, start, ending);

    // Create a Facility with an interest rate of 0.05 (5%) and an early repayment penalty of 0.2 (20%)
    Facility facility("FAC1", lender1, pool, borrower, 5000000.0, currency, start, ending, 0.05, now, 0.2);

    // Create a Part with a repayment of 1 million
    Part part(facility, 1000000.0);

    // Create a Portfolio
    Portfolio portfolio;

    // Add the facility to the portfolio
    portfolio.addFacility(facility);

    // Print some info about the deal
    std::cout << "Deal Contract Number: " << deal.getContractNumber() << std::endl;
    std::cout << "Deal Agent: " << deal.getAgent().getName() << std::endl;
    std::cout << "Deal Borrower: " << deal.getBorrower().getName() << std::endl;
    std::cout << "Deal Amount: " << deal.getAmount() << std::endl;
    std::cout << "Deal Currency: " << deal.getCurrency().getCode() << std::endl;
    std::cout << "Deal Status: " << deal.getStatus() << std::endl;

    // Print out details of the facility
    std::cout << "Facility Contract Number: " << facility.getContractNumber() << std::endl;
    std::cout << "Facility Agent: " << facility.getAgent().getName() << std::endl;
    std::cout << "Facility Borrower: " << facility.getBorrower().getName() << std::endl;
    std::cout << "Facility Amount: " << facility.getAmount() << std::endl;
    std::cout << "Facility Currency: " << facility.getCurrency().getCode() << std::endl;
    std::cout << "Facility Interest: " << facility.calculateInterest() << std::endl;  // Print calculated interest

    // Print out details of the Part
    std::cout << "Part Repayment Amount: " << part.getRepaymentAmount() << std::endl;

    // Print out details of the portfolio
    std::cout << "Portfolio Total Interest: " << portfolio.calculateTotalInterest() << std::endl;

    return 0;
}