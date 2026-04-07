#include "Product.h"
#include <iostream>
#include <iomanip>
using namespace std;
int Product::GetActualStocks(){
		return productTotalstock-productPurchased;}

int Product::GetPurchasedStocks(){
		return productPurchased;}

TrendUsage::TrendUsage(Market *market){this->market=market;}

void TrendUsage::Show(Product *prod,int i){
		cout<<setfill('_')<<setw(76)<<" "<<setfill(' ')<<endl;
		cout<<"|"<<right<<setw(2)<<i<<setw(3)<<"|"<<right<<setw(25)<<prod->productName<<setw(3)<<"|"<<right<<setw(15)<<prod->productID<<setw(3)<<"|"<<right<<setw(20)<<prod->productPurchased<<setw(3)<<"|"<<endl;}

void TrendUsage::ProductShow(){
        cout<<endl;
		cout<<setw(22)<<setfill('*')<<" "<<"High Selling Products by Stocks "<<setw(22)<<" "<<endl;
		cout<<setw(76)<<setfill('_')<<" "<<setfill(' ')<<endl;
		cout<<right<<"|"<<setw(4)<<"S.No"<<"|"<<setw(25)<<"Product Name"<<setw(3)<<"|"<<setw(15)<<"Product ID"<<setw(3)<<"|"<<setw(20)<<"Stocks Purchased"<<setw(3)<<"|"<<endl;
		int count=1;
		for(int i=0;i<market->GetProductCount();i++){
			if(market->products[i]->GetPurchasedStocks()>42)
				   Show(market->products[i],count++);}
		cout<<setw(76)<<setfill('_')<<" "<<setfill(' ')<<endl;
        cout<<endl<<"Total Products Count:"<<setw(5)<<count-1<<endl;}
