#include <iostream>
#include <vector>
#include <chrono>
#include "Deal.h"
#include "Facility.h"
#include "Part.h"
#include "Portfolio.h"
#include "Lender.h"
#include "Borrower.h"
#include <iomanip>

std::string formatTime(const std::chrono::system_clock::time_point& tp) {
    auto t = std::chrono::system_clock::to_time_t(tp);
    auto* locTime = std::localtime(&t);
    std::ostringstream ss;
    ss << std::put_time(locTime, "%d/%m/%Y");
    return ss.str();
}

// ...

int main() {
    // Create lenders
    Lender lender1("JP Morgan Chase");
    Lender lender2("Bank of America");
    Lender lender3("Wells Fargo");

    // Add lenders to the pool
    std::vector<Lender> pool = {lender2, lender3};

    // Create borrower
    Borrower borrower("Air France");

    // Create a deal
    std::string contractNumber = "D1234";
    double amount = 1000000.0;
    Currency currency("EUR", 1.2);
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point ending = start + std::chrono::hours(24 * 365); // 1 year
    Deal deal(contractNumber, lender1, pool, borrower, amount, currency, start, ending);

    // Create facilities
    std::chrono::system_clock::time_point facilityStart = start;
    std::chrono::system_clock::time_point facilityEnd = start + std::chrono::hours(24 * 90); // 90 days
    double facilityAmount = 500000.0;
    Currency facilityCurrency("USD" , 1.0);
    std::chrono::system_clock::time_point repaymentSchedule = start + std::chrono::hours(24 * 30); // 30 days
    double earlyRepaymentPenalty = 0.2; // Example value
    Facility facility1(contractNumber, lender1, pool, borrower, facilityAmount, facilityCurrency, facilityStart,
                       facilityEnd, repaymentSchedule, earlyRepaymentPenalty);

    // Add facility to the deal
    deal.addFacility(facility1);

    // Create parts
    double partAmount = 100000.0;
    std::chrono::system_clock::time_point partRepaymentDate = facilityStart + std::chrono::hours(24 * 30); // 30 days
    Part part1(facility1, partAmount, partRepaymentDate);

    // Add part to the facility
    facility1.addPart(part1);

    // Create portfolio
    Portfolio portfolio;

    // Add facility to the portfolio
    portfolio.addFacility(facility1);

    std::cout << "Loan Details" << std::endl;
    std::cout << "Contract Number: " << contractNumber << std::endl;
    std::cout << "Borrower: " << borrower.getName() << std::endl;
    std::cout << "Amount: " << amount << " " << currency.getCode() << std::endl;
    std::cout << "Starting Date: " << formatTime(start) << std::endl;
    std::cout << "Ending Date: " << formatTime(ending) << std::endl;

    std::cout << "Facility Details" << std::endl;
    std::cout << "Amount: " << facilityAmount << " " << facilityCurrency.getCode() << std::endl;
    std::cout << "Repayment Schedule: " << formatTime(repaymentSchedule) << std::endl;
    std::cout << "Early Repayment Penalty: " << earlyRepaymentPenalty << std::endl;

    // Perform repayment cycles until the loan is paid in full
    while (!facility1.isPaidInFull()) {
        // Calculate and display the total interest in the portfolio
        double totalInterest = portfolio.calculateTotalInterest();
        std::cout << "Total Interest in the Portfolio: " << totalInterest << std::endl;

        // Make a repayment
        double remainingPrincipal = facility1.getRemainingPrincipal(); // Get the remaining principal amount
        double repaymentAmount = remainingPrincipal + totalInterest; // Repayment amount includes remaining principal and interest

        std::cout << "Making Repayment..." << std::endl;
        std::cout << "Repayment Amount: " << repaymentAmount << " " << facilityCurrency.getCode() << std::endl;
        std::cout << "Paying back lenders:" << std::endl;
        std::cout << "- Agent: " << facility1.getAgent().getName() << std::endl;
        std::cout << "- Pool Lenders: ";
        for (const Lender& lender : facility1.getPool()) {
            std::cout << lender.getName() << ", ";
        }
        std::cout << std::endl;

        facility1.makeRepayment(repaymentAmount);

        // Update the total interest after the repayment
        totalInterest = portfolio.calculateTotalInterest();

        // Create a new part for the next repayment cycle
        partRepaymentDate += std::chrono::hours(24 * 30); // 30 days
        Part newPart(facility1, partAmount, partRepaymentDate);

        // Add the new part to the facility and portfolio
        facility1.addPart(newPart);
        portfolio.addFacility(facility1);

        std::cout << "New Part Added for Repayment Cycle:" << std::endl;
        std::cout << "Part Repayment Date: " << formatTime(partRepaymentDate) << std::endl;
    }

    std::cout << "Loan has been fully repaid!" << std::endl;

    return 0;
}

// ...
