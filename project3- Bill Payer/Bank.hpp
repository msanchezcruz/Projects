#pragma once
#include <iostream>
#include <string>


struct Bank {
 
    std::string name_; //bank name
    double amount_starting_; // stating amount in checking account
    double amount_salary_; // amount deposited first of the month
    double amount_left_; //amount left after paying possible bills

    Bank( const std::string & name="",
        const double & starting=0.0,
        const double & salary=0.0);
	public:
    void setAmountsalary(double x );
    void setAmountleft(double x);
    double getAmountleft();




};
