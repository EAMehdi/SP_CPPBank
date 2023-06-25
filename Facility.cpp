#include "Facility.h"
#include "Part.h"

Facility::Facility(const std::string& contractNumber,
                   const Lender& agent,
                   const std::vector<Lender>& pool,
                   const Borrower& borrower,
                   double amount,
                   const Currency& currency,
                   const std::chrono::system_clock::time_point& start,
                   const std::chrono::system_clock::time_point& ending,
                   const std::chrono::system_clock::time_point& repaymentSchedule,
                   double earlyRepaymentPenalty)
        : Deal(contractNumber, agent, pool, borrower, amount, currency, start, ending),
          repaymentSchedule(repaymentSchedule),
          earlyRepaymentPenalty(earlyRepaymentPenalty),totalPrincipalRepaid(0.0) {
    interestRate = calculateInterestRate(); // Calculate the interest rate using the method
}

double Facility::calculateInterestRate() const {
    // Calculate the interest rate based on some logic
    // You can modify this function according to your requirements
    return 0.05; // Return a dummy interest rate of 0.05 (5%)
}

double Facility::calculateInterest() const {
    auto duration = std::chrono::duration_cast<std::chrono::hours>(ending - start).count();
    double years = duration / (24.0 * 365.0);

    const double inflationRate = 0.02;  // assumed annual inflation rate of 2%
    double realInterestRate = ((1 + interestRate) / (1 + inflationRate)) - 1;

    return this->amount * realInterestRate * years;
}

void Facility::addPart(const Part& part) {
    parts.push_back(new Part(part)); // Create a new Part object and store its pointer
}

std::vector<Part> Facility::getParts() const {
    std::vector<Part> result;
    for (const Part* partPtr : parts) {
        result.push_back(*partPtr); // Dereference the stored pointer to get the actual Part object
    }
    return result;
}
bool Facility::isPaidInFull() const {
    return totalPrincipalRepaid >= amount;
}

void Facility::makeRepayment(double amount) {
    if (!isPaidInFull()) {
        totalPrincipalRepaid += amount;
    }
}

double Facility::getRemainingPrincipal() {
    double totalRepaid = 0.0;
    for (Part *part : parts) {
        totalRepaid += part->getRepaymentAmount();
    }
    return amount - totalRepaid;
}
