//
// Created by diop on 24/06/2023.
//

#ifndef SP_CPPBANK_PART_H
#define SP_CPPBANK_PART_H

#include <chrono>
#include <string>  // Include for std::string
#include "Facility.h"  // Include for Facility

class Part {  // Define class Part
public:
    Part(Facility& facility, double repaymentAmount);  // Constructor
    Facility& getFacility();  // Method to get the facility
    double getRepaymentAmount();  // Method to get the repayment amount
    std::chrono::system_clock::time_point getRepaymentDate();
private:
    Facility& facility;  // Private member variable: reference to Facility
    double repaymentAmount;  // Private member variable: repayment amount
    std::chrono::system_clock::time_point repaymentDate;
};


#endif //SP_CPPBANK_PART_H
