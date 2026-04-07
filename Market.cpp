#include "Product.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <cstdlib>
using namespace std;

string itemNames[] = {
 "Heavy_Blanket", "Winter_Jacket", "Full_Sleeve_Sweatshirt", "Room_Heater", "Skin_Cream", "Herbal_Health_Drink", "Flask_Bottle", "Insulated_Food_Jar", "Air_Conditioner", "Table_Fan", "Refrigerator", "Cotton_Apparel", "Inverter_Cooler", "Juice_Maker", "Sunglasses", "Frozen_Dessert", "Compact_Umbrella", "Rain_Suit", "Waterproof_Footwear", "Emergency_Light", "Electric_Kettle", "Mosquito_Vaporizer", "Anti_Skid_Mat", "Waterproof_Cover", "Smart_Television", "Washing_Machine", "Mixer_Grinder", "Microwave_Oven", "Induction_Cooktop", "Pressure_Cooker", "Dinner_Set", "Non_Stick_Cookware", "Storage_Container_Set", "Cleaning_Mop", "Laundry_Detergent", "Dishwash_Liquid", "Floor_Cleaner", "Toiletries_Kit", "Hand_Wash_Refill", "Premium_Rice_Bag", "Refined_Cooking_Oil", "Wheat_Flour_Pack", "Iodized_Salt", "Refined_Sugar", "Canned_Vegetables", "Canned_Fruits", "Instant_Noodles_Box", "Coffee_Powder", "Tea_Leaves_Pack", "Carbonated_Drink", "Fruit_Juice_Tetra", "Energy_Drink_Can", "Bottled_Water_Case", "Milk_Powder_Tin", "Malt_Health_Drink", "Breakfast_Cereal", "Pulse_And_Grains", "Organic_Honey", "Pickle_Assortment", "Bluetooth_Speaker", "Power_Bank", "USB_Charging_Cable", "LED_Bulb_Pack", "Home_Audio_System"};

int itemSeasons[] = {
1, 2, 3, 4, 1, 2, 3, 4, 5, 6, 7, 8, 5, 6, 7, 8, 9, 10, 11, 12, 9, 10, 11, 12, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

float itemPrices[] = {
1199.50, 2499.00, 849.75, 3150.00, 249.25, 450.50, 799.90, 1145.00, 34999.00, 1750.50, 21990.00, 649.50, 8499.00, 2150.75, 1199.00, 149.50, 449.50, 1499.00, 899.25, 645.50, 1849.00, 199.75, 349.50, 249.90, 44990.00, 18450.00, 4199.50, 9499.00, 3450.75, 1449.50, 2799.00, 3199.50, 849.25, 549.75, 449.50, 179.90, 209.50, 149.25, 98.50, 549.75, 819.50, 479.25, 24.50, 44.75, 119.50, 179.25, 64.50, 279.90, 349.50, 94.50, 109.75, 59.90, 39.50, 379.25, 449.50, 319.75, 179.50, 249.25, 219.90, 2499.00, 1499.50, 299.75, 449.50, 12499.00};

Market::Market() {productCount=0; for(int i=0;i<100;i++) products[i]={nullptr}; ProductLoad();}

void Market::ProductLoad(){
		for(int i=0;i<60;i++){
			int Total=rand()%20+50;
			int Purchased=rand()%10+35;
			int Remaining=Total-Purchased;
			if(Remaining<0) Remaining=0;
			products[productCount]=new Product(to_string((rand()%9000)+1000),itemNames[i],Remaining,itemPrices[i],rand()%30+7,itemSeasons[i]);
			products[productCount]->SetPStock(Total,Purchased);
			productCount++;
		}}

int Market::GetProductCount(){
	return productCount;}

void Market::ProductShow(){
        int count=1;
		cout<<setfill('_')<<setw(111)<<" "<<setfill(' ')<<endl;
		cout<<"|"<<setw(9)<<"Product ID"<<setw(1)<<"|"<<setw(25)<<"Product Name"<<setw(2)<<"|"<<setw(13)<<"Product Stock"<<setw(2)<<"|"<<setw(15)<<"Product Price"<<setw(2)<<"|"<<setw(20)<<"Rem.Shelf Life (Days)"<<setw(1)<<"|"<<setw(15)<<"Seasonal Code"<<setw(2)<<"|"<<endl;
		for(int i=0;i<productCount;i++){
			products[i]->Show();count++;}
		cout<<setfill('_')<<setw(111)<<" "<<setfill(' ')<<endl;
		cout<<endl<<"Total Products Count:"<<setw(5)<<count-1<<endl;
}
Market::~Market(){
    for(int i=0; i<100; i++) {
        if (products[i] != nullptr) {
            delete products[i];
            products[i] = nullptr;
        }
    }
}
void Market::PurchaseStocks(string ID,int n){
    bool flag=0;
    for(int i=0;i<productCount;i++)
        if(products[i]->ReturnID()==ID){
            (*products[i])-=n; flag=1;}
    if(!flag) cout<<"Product Not Found!"<<endl;
    else cout<<"Stock Updated!"<<endl;
}
void Market::Restock(string ID,int n){
    bool flag=0;
    for(int i=0;i<productCount;i++)
        if(products[i]->ReturnID()==ID){
            (*products[i])+=n; flag=1;}
    if(!flag) cout<<"Product Not Found!"<<endl;
    else cout<<"Stock Updated!"<<endl;
}
void Market::AddProduct(){
    Product temp;
    if(productCount>98){ cout<<"List is full!"<<endl;return;}
    (products[productCount++])= new Product(temp.AddItem());
}
