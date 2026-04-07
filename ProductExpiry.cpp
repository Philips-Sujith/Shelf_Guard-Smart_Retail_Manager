#include "Product.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool Product::CheckExpiry(){
	return daysToExpire<13?1:0;}

ExpiryData::ExpiryData(Market* market){this->market=market;}
void ExpiryData::Show(Product *prod,int i){
	cout<<setw(77)<<setfill('_')<<" "<<setfill(' ')<<endl;
	cout<<"|"<<setw(3)<<i<<setw(3)<<"|"<<setw(25)<<prod->productName<<setw(3)<<"|"<<setw(15)<<prod->productID<<setw(3)<<"|"<<setw(15)<<prod->daysToExpire<<setw(5)<<"Days"<<setw(3)<<"|"<<endl;i++;}

void ExpiryData::ProductShow(){
		cout<<setw(23)<<setfill('*')<<" "<<"Stocks Going to Expiring Soon "<<setw(24)<<" "<<endl;
		int count=1;
		cout<<setw(77)<<setfill('_')<<" "<<setfill(' ')<<endl;
		cout<<"|"<<setw(4)<<"S.No"<<setw(2)<<"|"<<setw(25)<<"Product Name"<<setw(3)<<"|"<<setw(15)<<"Product ID"<<setw(3)<<"|"<<setw(20)<<"Rem. Shelf Life (Days)"<<setw(3)<<"|"<<endl;
		for(int i=0;i<market->GetProductCount();i++){
			if(market->products[i]->CheckExpiry())
				Show(market->products[i],count++);}
		cout<<setw(77)<<setfill('_')<<" "<<setfill(' ')<<endl;
        cout<<endl<<"Total Products Count:"<<setw(5)<<count-1<<endl;}
