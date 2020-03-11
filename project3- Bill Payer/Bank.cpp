#include <string>

#include "Bank.hpp"

/************************************************
** Member function definitions
************************************************/
// PLEASE ADD IMPLEMENTATIONS OF ALL FUNCTION MEMBERS OF CLASS BANK

Bank::Bank(const std::string& x,const double& starting,const double& salary){

	name_ = x;
	amount_starting_ = starting;
	amount_salary_ = salary;



}
void Bank::setAmountleft(double x){

	amount_left_ += x;


}
void Bank::setAmountsalary(double x){

	amount_salary_ += x;



}
double Bank::getAmountleft(){

	return  amount_left_;



}