#ifndef SP_CPPBANK_FACILITY_H
#define SP_CPPBANK_FACILITY_H

#include "Deal.h"
#include "Part.h"

class Facility : public Deal {
private:
    double interestRate;
    std::chrono::system_clock::time_point repaymentSchedule;
    double earlyRepaymentPenalty;
    std::vector<Part> parts; // Store parts in a vector

public:
    Facility(const std::string& contractNumber, const Lender& agent, const std::vector<Lender>& pool,
             const Borrower& borrower, double amount, const Currency& currency,
             const std::chrono::system_clock::time_point& start,
             const std::chrono::system_clock::time_point& ending,
             double interestRate,
             const std::chrono::system_clock::time_point& repaymentSchedule,
             double earlyRepaymentPenalty);

    double getInterestRate() const { return interestRate; }
    void setInterestRate(double interestRate) { this->interestRate = interestRate; }

    std::chrono::system_clock::time_point getRepaymentSchedule() const { return repaymentSchedule; }
    void setRepaymentSchedule(const std::chrono::system_clock::time_point& repaymentSchedule) { this->repaymentSchedule = repaymentSchedule; }

    double getEarlyRepaymentPenalty() const { return earlyRepaymentPenalty; }
    void setEarlyRepaymentPenalty(double earlyRepaymentPenalty) { this->earlyRepaymentPenalty = earlyRepaymentPenalty; }

    double calculateInterest() const;
    // Method to add a part
    void addPart(const Part& part) {
        parts.push_back(part);
    }

    // Method to get all parts
    std::vector<Part> getParts() const {
        return parts;
    }
};

#endif // SP_CPPBANK_FACILITY_H