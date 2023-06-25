#ifndef SP_CPPBANK_FACILITY_H
#define SP_CPPBANK_FACILITY_H
#pragma once
#include <vector>
#include "Deal.h"

class Part;  // forward declaration
// Forward declaration of Deal
class Deal;
class Facility : public Deal {
private:
    double interestRate;
    std::chrono::system_clock::time_point repaymentSchedule;
    double earlyRepaymentPenalty;
    std::vector<Part*> parts;
    double calculateInterestRate() const;
    double totalPrincipalRepaid; // Add this line
    double getRemainingPrincipal() const;
public:
    Facility(const std::string& contractNumber,
             const Lender& agent,
             const std::vector<Lender>& pool,
             const Borrower& borrower,
             double amount,
             const Currency& currency,
             const std::chrono::system_clock::time_point& start,
             const std::chrono::system_clock::time_point& ending,
             const std::chrono::system_clock::time_point& repaymentSchedule,
             double earlyRepaymentPenalty);

    double getInterestRate() const { return interestRate; }
    void setInterestRate(double interestRate) { this->interestRate = interestRate; }

    std::chrono::system_clock::time_point getRepaymentSchedule() const { return repaymentSchedule; }
    void setRepaymentSchedule(const std::chrono::system_clock::time_point& repaymentSchedule) { this->repaymentSchedule = repaymentSchedule; }

    double getEarlyRepaymentPenalty() const { return earlyRepaymentPenalty; }
    void setEarlyRepaymentPenalty(double earlyRepaymentPenalty) { this->earlyRepaymentPenalty = earlyRepaymentPenalty; }

    double calculateInterest() const;
    void addPart(const Part& part);
    std::vector<Part> getParts() const;
    void makeRepayment(double amount);
    bool isPaidInFull() const;

    double getRemainingPrincipal();

};

#endif // SP_CPPBANK_FACILITY_H