#include <iostream>
#include <vector>
#include "Lender.h"
#include "Borrower.h"
#include "Currency.h"
#include "Deal.h"
#include "Facility.h"

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
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point ending = start + std::chrono::hours(24*365);  // One year later

    // Create a Deal
    Deal deal("S1234", lender1, pool, borrower, 10000000, currency, start, ending);

    // Print some info about the deal
    std::cout << "Deal Contract Number: " << deal.getContractNumber() << std::endl;
    std::cout << "Deal Agent: " << deal.getAgent().getName() << std::endl;
    std::cout << "Deal Borrower: " << deal.getBorrower().getName() << std::endl;
    std::cout << "Deal Amount: " << deal.getAmount() << std::endl;
    std::cout << "Deal Currency: " << deal.getCurrency().getCode() << std::endl;
    std::cout << "Deal Status: " << deal.getStatus() << std::endl;

/*
    Facility facility("FAC1", deal, lender1, 5000000.0, now, now);
    std::cout << "Facility ----------------" << std::endl;
    // Print out details of the facility
    std::cout << "Facility ID: " << facility.getFacilityId() << std::endl;
    std::cout << "Facility Deal Contract Number: " << facility.getDeal().getContractNumber() << std::endl;
    std::cout << "Facility Agent: " << facility.getAgent().getName() << std::endl;
    std::cout << "Facility Amount: " << facility.getAmount() << std::endl;
*/
    return 0;
}
