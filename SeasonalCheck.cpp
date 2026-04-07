#include "Product.h"
#include "TimeHandler.h"
#include <iostream>
#include <iomanip>
using namespace std;
SeasonalCheck::SeasonalCheck(Market *market,TimeHandler &time){
    timeSet.date=time.date;
    timeSet.month=time.month;
    timeSet.year=time.year;
    this->market=market;
}
SeasonalCode Product::GetSeasonalCode(){
    return seasonCode;
}
bool SeasonalCheck::CheckSeason_Stock(Product *prod,int month){
    SeasonalCode tempSeacode;
    if(month>=1&&month<=4) tempSeacode=Winter;
    else if(month>=5&&month<=8) tempSeacode=Summer;
    else if(month>=9&&month<=12) tempSeacode=Rainy;
    else if(month==-1) tempSeacode=General;
    if(prod->GetActualStocks()<35&&prod->GetSeasonalCode()==tempSeacode)
        return 1;
    return 0;
}
void SeasonalCheck::Show(Product *prod,int count){
    cout<<setw(87)<<setfill('_')<<" "<<setfill(' ')<<endl;
    cout<<'|'<<setw(4)<<count<<setw(3)<<'|'<<setw(15)<<prod->productID<<setw(3)<<'|'<<setw(25)<<prod->productName<<setw(3)<<'|'<<setw(14)<<prod->productStock<<setw(3)<<'|'<<setw(12);
    prod->PrintCode(prod->seasonCode);
    cout<<setw(3)<<'|'<<endl;
}
void SeasonalCheck::ProductShow(){
    cout<<endl;
    timeSet.PrintDate();
    cout<<endl;
    int count=1;
    cout<<setw(15)<<setfill('*')<<" "<<"Product according to Seasonal Trend and Remaining Stocks "<<setw(15)<<" "<<endl;
    cout<<setw(87)<<setfill('_')<<" "<<setfill(' ')<<endl;
    cout<<'|'<<setw(4)<<"S.no"<<setw(3)<<'|'<<setw(15)<<"Product ID"<<setw(3)<<'|'<<setw(25)<<"Product Name"<<setw(3)<<'|'<<setw(14)<<"Product Stock"<<setw(3)<<'|'<<setw(12)<<"Season"<<setw(3)<<'|'<<endl;
    for(int i=0;i<market->GetProductCount();i++)
        if(CheckSeason_Stock(market->products[i],timeSet.GetMonth()))
            Show(market->products[i],count++);
    cout<<setw(87)<<setfill('_')<<" "<<setfill(' ')<<endl;
    cout<<endl<<"Total Products Count:"<<setw(5)<<count-1<<endl;
}
