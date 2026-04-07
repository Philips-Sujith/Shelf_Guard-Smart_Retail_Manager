#include "Product.h"
#include "TimeHandler.h"
#include <iostream>
#include <iomanip>
using namespace std;

void ProjectAbout();
void ProductMenu(Market &market){
    int choice;
    string id;
    int qty;

    do{
        cout << endl;
        cout << setw(10)<<setfill('*')<<" "<<"PRODUCT LIST MENU "<<setw(10)<<' '<<setfill(' ')<<endl;

        cout << "\n1. View All Products\n";
        cout << "2. Search Specific Product\n";
        cout << "3. Add Product\n";
        cout << "4. Buy Stocks\n";
        cout << "5. Restock Stocks\n";
        cout << "6. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                market.ProductShow();
                break;

            case 2:
                cout << "Enter Product ID: ";
                cin >> id;
                market.ProductDisplay(id);
                break;

            case 3:
                market.AddProduct();
                cout << "Product Added Successfully!\n";
                break;

            case 4:
                cout << "Enter Product ID: ";
                cin >> id;
                cout << "Enter Quantity to Buy: ";
                cin >> qty;
                market.PurchaseStocks(id, qty);
                break;

            case 5:
                cout << "Enter Product ID: ";
                cin >> id;
                cout << "Enter Quantity to Restock: ";
                cin >> qty;
                market.Restock(id, qty);
                break;
        }

    } while(choice != 6);
}

int main(){
    srand(time(0));

    Market market;
    TimeHandler time;
    time.SetDate();

    ThresholdRestock threshold(&market);
    SeasonalCheck seasonal(&market,time);
    ExpiryData expiry(&market);
    TrendUsage trend(&market);

    int choice;

    do{
        cout << endl << endl;
        cout << setw(12)<<setfill('*')<<" "<<"SHELF GUARD - THE RETAIL MANAGER "<<setw(12)<<' '<<setfill(' ')<<endl;

        cout << endl;
        time.PrintDate();
        cout << endl;

        cout << "1. Product List\n";
        cout << "2. Shelf Life Report\n";
        cout << "3. Trend Usage Predictor\n";
        cout << "4. Seasonal Products Report\n";
        cout << "5. Threshold Restock Alert\n";
        cout << "6. About\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){

            case 1:
                ProductMenu(market);
                break;

            case 2:
                expiry.ProductShow();
                break;

            case 3:
                trend.ProductShow();
                break;

            case 4:
                seasonal.ProductShow();
                break;

            case 5:
                threshold.ProductShow();
                break;

            case 6:
                cout << endl;
                ProjectAbout();
                break;

            case 7:
                cout<<setfill('*')<<setw(50)<<' '<<setfill(' ')<<endl;
                cout << "Thank You for Trying This Out"<<endl;
                cout<<setfill('*')<<setw(50)<<' '<<setfill(' ')<<endl;
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 7);

    return 0;
}
void ProjectAbout(){
    cout << endl;
    cout << setw(18)<<setfill('*')<<" "<<"ABOUT PROJECT "<<setw(18)<<' '<<setfill(' ')<<endl;
    cout << endl;
    cout << setw(10)<<setfill('*')<<" "<<"SHELF GUARD - THE RETAIL MANAGER "<<setw(10)<<' '<<setfill(' ')<<endl;
    cout << endl;
    cout << "Name      : Sujith" << endl;
    cout << "Roll No   : 2025503560" << endl;

    cout << endl;
    cout << "Shelf Guard is a Retail Inventory Management System developed using C++." << endl;

    cout << endl;
    cout << "In real-world retail stores, managing stock manually can lead to problems such as overstocking," << endl;
    cout << "stock shortages, and loss due to expired products. This project is designed to solve these issues" << endl;
    cout << "by providing a smart and structured way to monitor and analyze inventory." << endl;

    cout << endl;
    cout << "The system not only stores product details but also gives useful insights that help in better" << endl;
    cout << "decision making. It improves efficiency, reduces manual errors, and helps the user take quick actions." << endl;

    cout << endl;
    cout << setw(20)<<setfill('*')<<" "<<"KEY FEATURES"<<setw(20)<<' '<<setfill(' ')<<endl;

    cout << endl;
    cout << "1. Product Management:" << endl;
    cout << "   Allows adding new products, viewing all items, and searching specific products using ID." << endl;

    cout << endl;
    cout << "2. Stock Operations:" << endl;
    cout << "   Enables buying (reducing stock) and restocking (increasing stock) easily." << endl;

    cout << endl;
    cout << "3. Shelf Life Report:" << endl;
    cout << "   Identifies products that are close to expiry, helping to avoid losses." << endl;

    cout << endl;
    cout << "4. Trend Usage Predictor:" << endl;
    cout << "   Highlights high-demand products based on purchase patterns." << endl;

    cout << endl;
    cout << "5. Seasonal Product Analysis:" << endl;
    cout << "   Detects products relevant to the current season and checks if stock is sufficient." << endl;

    cout << endl;
    cout << "6. Threshold Restock Alert:" << endl;
    cout << "   Warns when product stock falls below a minimum level, ensuring timely restocking." << endl;

    cout << endl;
    cout << "Overall, this project demonstrates how basic C++ concepts can be used to build a practical" << endl;
    cout << "and efficient system that solves real-world retail problems." << endl;

    cout << endl;
    cout << "This system is simple, fast, and user-friendly, making it suitable for small-scale shop" << endl;
    cout << "management and learning purposes." << endl;
}
