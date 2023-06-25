// Created by diop on 24/06/2023.

#include "Part.h"
#include "Facility.h"  // include Facility header here
Part::Part(Facility& facility, double repaymentAmount, std::chrono::system_clock::time_point repaymentDate)
        : facility(facility), repaymentAmount(repaymentAmount), repaymentDate(repaymentDate) {
    // Initialize remainingToPay with the repaymentAmount
    remainingToPay = repaymentAmount;
}
// Define the constructor. It initializes the member variables with the provided arguments.

Facility& Part::getFacility() {  // Define method to get the facility
    return facility;  // Return reference to the facility
}

double Part::getRepaymentAmount() {  // Define method to get the repayment amount
    return repaymentAmount;  // Return the repayment amount
}

std::chrono::system_clock::time_point Part::getRepaymentDate() {
    return repaymentDate;  // Return the repayment date
}