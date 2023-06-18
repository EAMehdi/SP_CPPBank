#include "Facility.h"

Facility::Facility(const std::string& contractNumber, const Lender& agent, const std::vector<Lender>& pool,
                   const Borrower& borrower, double amount, const Currency& currency,
                   const std::chrono::system_clock::time_point& start,
                   const std::chrono::system_clock::time_point& ending,
                   double interestRate,
                   const std::chrono::system_clock::time_point& repaymentSchedule,
                   double earlyRepaymentPenalty)
    : Deal(contractNumber, agent, pool, borrower, amount, currency, start, ending),
      interestRate(interestRate),
      repaymentSchedule(repaymentSchedule),
      earlyRepaymentPenalty(earlyRepaymentPenalty) {}

