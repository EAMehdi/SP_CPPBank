//
// Created by diop on 24/06/2023.
//

#include "Part.h"

Part::Part(Facility& facility, double repaymentAmount) : facility(facility), repaymentAmount(repaymentAmount) {}
// Define the constructor. It initializes the member variables with the provided arguments.

Facility& Part::getFacility() {  // Define method to get the facility
    return facility;  // Return reference to the facility
}

double Part::getRepaymentAmount() {  // Define method to get the repayment amount
    return repaymentAmount;  // Return the repayment amount
}