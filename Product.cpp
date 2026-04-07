#include "Product.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;
Product::Product(std::string ID, std::string Name, int Stock, float Price, int Expdays, int seasonNumber) : productID(ID), productName(Name), productStock(Stock), productPrice(Price),daysToExpire(Expdays) {
				if(seasonNumber>=1&&seasonNumber<=4) seasonCode=Winter;
				else if(seasonNumber>=5&&seasonNumber<=8) seasonCode=Summer;
				else if(seasonNumber>=9&&seasonNumber<=12) seasonCode=Rainy;
				else if(seasonNumber==-1) seasonCode=General;
}
Product::Product(){}
void Product::Show(int count){
			cout<<setfill('_')<<setw(111)<<" "<<setfill(' ')<<endl;
			cout<<"|"<<setw(9)<<productID<<setw(2)<<"|"<<setw(25)<<productName<<setw(2)<<"|"<<setw(13)<<productStock<<setw(2)<<"|"<<setw(15)<<productPrice<<setw(2)<<"|"<<setw(20)<<daysToExpire<<setw(2)<<"|"<<setw(15);
			PrintCode(seasonCode);
			cout<<setw(2)<<"|"<<endl;}
void Product::PrintCode(SeasonalCode seacode){
		switch(seacode){
			case Summer:
				cout<<"Summer";
				break;
			case Winter:
				cout<<"Winter";
				break;
			case Rainy:
				cout<<"Rainy";
				break;
			default:
				cout<<"General";
				break;}}
void Product::SetPStock(int totalStock, int purchasedStock){
		productTotalstock=totalStock;
		productPurchased=purchasedStock;}
string Product::ReturnID(){
    return productID;
}
void Product::operator+=(int n){
    this->productStock+=n;
}
void Product::operator-=(int n){
    this->productStock-=n;
    if(productStock<0) productStock=0;
}
Product Product::AddItem(){
    string id,name;
    int shelfLife,totalstock,purchased,code;
    float price;
    cout<<endl;
    cout<<"Enter the following in the given order:\n\t1. Product ID\n\t2. Product Name\n\t3. Product Price\n\t4. Product Shelf Life\n\t5. TotalStock\n\t6. Purchased Stock\n\t7. Seasonal Code(1-12)"<<endl;
    cin>>id>>name>>price>>shelfLife>>totalstock>>purchased>>code;
    Product temp(id,name,totalstock-purchased,price,shelfLife,code);
    if(code>=1&&code<=4) temp.seasonCode=Winter;
    else if(code>=5&&code<=8) temp.seasonCode=Summer;
	else if(code>=9&&code<=12) temp.seasonCode=Rainy;
	else if(code==-1) temp.seasonCode=General;
    temp.productTotalstock=totalstock;
    temp.productPurchased=purchased;
    return temp;
}
