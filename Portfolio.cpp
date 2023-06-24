#include <algorithm>
#include "Portfolio.h"

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
    double totalInterest = 0;
    for (const auto& facility : facilities) {
        totalInterest += facility.calculateInterest();
    }
    return totalInterest;
}