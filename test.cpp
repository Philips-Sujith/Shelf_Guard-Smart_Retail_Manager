#include "Product.h"
#include "TimeHandler.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main(){
	srand(time(0));
	Market* abc=new Market();;
	TimeHandler Time;
	Time.PrintDate();

	abc->ProductShow();
	cout<<"Endl"<<endl;
	ThresholdRestock ASD(abc);
	ASD.ProductShow();
	return 0;}
