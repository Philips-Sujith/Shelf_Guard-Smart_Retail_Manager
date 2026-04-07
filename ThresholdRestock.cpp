#include "Product.h"
#include <iostream>
#include <iomanip>
using namespace std;
bool ThresholdRestock::CheckStocks(Product &prod){
    return prod.productStock<thresholdLimit;
}
ThresholdRestock::ThresholdRestock(Market *market){this->market=market;thresholdLimit=13;}
void ThresholdRestock::show(Product *prod, int count){
        cout<<setw(63)<<setfill('_')<<' '<<setfill(' ')<<endl;
        cout<<'|'<<setw(3)<<count<<setw(2)<<'|'<<setw(20)<<prod->productName<<setw(3)<<"|"<<setw(12)<<prod->productID<<setw(3)<<"|"<<setw(15)<<prod->GetActualStocks()<<setw(3)<<"|"<<endl;
}
void ThresholdRestock::ProductShow(){
    int count=1;
    cout<<setw(13)<<setfill('*')<<' '<<"Stocks Requiring Immediate Restock!! "<<setw(14)<<' '<<setfill(' ')<<endl;
    cout<<setw(63)<<setfill('_')<<' '<<setfill(' ')<<endl;
    cout<<'|'<<setw(3)<<"S.no"<<setw(1)<<'|'<<setw(20)<<"Product Name"<<setw(3)<<"|"<<setw(12)<<"Product ID"<<setw(3)<<"|"<<setw(15)<<"Product Stocks"<<setw(3)<<"|"<<endl;
    for(int i=0;i<market->GetProductCount();i++){
        if(CheckStocks(*(market->products[i])))
            show(market->products[i],count++);
    }
    cout<<setw(63)<<setfill('_')<<' '<<setfill(' ')<<endl;
    cout<<endl<<"Total Products Count:"<<setw(5)<<count-1<<endl;}
