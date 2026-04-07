#include "Product.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
bool Product::CheckProducts(string ID){
    if(productID==ID)
        return 1;
    return 0;
}
void Product::PrintProduct(){
    cout<<endl;
    cout<<setw(10)<<setfill('*')<<" "<<"Product Details "<<setw(11)<<' '<<setfill(' ')<<endl;
    cout<<left<<setw(20)<<"Product ID"<<right<<setw(15)<<productID<<endl;
    cout<<left<<setw(20)<<"Product Name"<<right<<setw(15)<<productName<<endl;
    cout<<left<<setw(20)<<"Product Stock"<<right<<setw(15)<<productStock<<endl;
    cout<<left<<setw(20)<<"Product Price"<<right<<setw(11)<<productPrice<<setw(4)<<"INR"<<endl;
    cout<<left<<setw(20)<<"Product Shelf Life"<<right<<setw(10)<<daysToExpire<<setw(5)<<"Days"<<endl;
    cout<<left<<setw(20)<<"Product Purchased"<<right<<setw(15)<<productPurchased<<endl;
    cout<<left<<setw(20)<<"Product Code"<<right<<setw(15);
    PrintCode(seasonCode);
    cout<<endl<<endl;
}
void Market::ProductDisplay(string ID){
    bool flag=0;
    for(int i=0;i<productCount;i++)
        if(products[i]->CheckProducts(ID)){
            products[i]->PrintProduct();
            flag=1;
        }
    if(!flag)cout<<endl<<"Product Not Found!"<<endl;
}
