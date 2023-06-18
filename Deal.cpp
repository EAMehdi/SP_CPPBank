#include "Deal.h"


Deal::Deal(const std::string &contractNumber,
           const Lender &agent,
           const std::vector<Lender> &pool,
           const Borrower &borrower,
           double amount,
           const Currency &currency,
           const std::chrono::system_clock::time_point &start,
           const std::chrono::system_clock::time_point &ending)
    : contractNumber(contractNumber), agent(agent), pool(pool), borrower(borrower), amount(amount), currency(currency), start(start), ending(ending) {
    status = "Initiated";
}

void Deal::setStatus(const std::string& status) {
    this->status = status;
}
