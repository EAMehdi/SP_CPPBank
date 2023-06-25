#include <algorithm>
#include "Portfolio.h"

Portfolio::Portfolio() {
    // Add any necessary initialization code here
}
Portfolio::Portfolio(const std::vector<Facility>& facilities)
        : facilities(facilities) {}

void Portfolio::addFacility(const Facility& facility) {
    facilities.push_back(facility);
}

void Portfolio::removeFacility(const std::string& contractNumber) {
    facilities.erase(std::remove_if(facilities.begin(), facilities.end(),
                                    [&contractNumber](const Facility& facility) {
                                        return facility.getContractNumber() == contractNumber;
                                    }),
                     facilities.end());
}

double Portfolio::calculateTotalInterest() const {
    double totalInterest = 0.0;

    for (const Facility& facility : facilities) {
        double interest = facility.calculateInterest();
        double conversionRate = facility.getCurrency().getConversionRateToUSD();
        totalInterest += interest * conversionRate;
    }
    return totalInterest;
}


bool Portfolio::isLoanPaidInFull() const {
    for (const auto& facility : facilities) {
        if (!facility.isPaidInFull()) {
            return false;
        }
    }
    return true;
}

void Portfolio::makeRepayment(const std::string& contractNumber, double amount) {
    for (auto& facility : facilities) {
        if (facility.getContractNumber() == contractNumber) {
            facility.makeRepayment(amount);
            break;
        }
    }
}