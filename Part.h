#ifndef SP_CPPBANK_PART_H
#define SP_CPPBANK_PART_H

#include <chrono>
#include <string>  // Include for std::string
#include "Facility.h"  // Include for Facility

class Part {  // Define class Part
public:
    Part(Facility& facility, double repaymentAmount, std::chrono::system_clock::time_point repaymentDate);  // Update the constructor
    Facility& getFacility();  // Method to get the facility
    double getRepaymentAmount();  // Method to get the repayment amount
    std::chrono::system_clock::time_point getRepaymentDate();
    double getRemainingToPay() const { return remainingToPay; }  // Moved to public section

private:
    Facility& facility;  // Private member variable: reference to Facility
    double repaymentAmount;  // Private member variable: repayment amount
    std::chrono::system_clock::time_point repaymentDate;
    double remainingToPay; // Amount remaining to be paid

    void setRemainingToPay(double amount) { remainingToPay = amount; }
};

#endif //SP_CPPBANK_PART_H