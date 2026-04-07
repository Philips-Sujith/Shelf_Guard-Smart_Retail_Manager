#ifndef PRODUCT
#define PRODUCT
#include "TimeHandler.h"
#include <iostream>
#include <string>
#include <cstdlib>
enum SeasonalCode {
	Summer=1,Winter,Rainy,General};
class Product{
	protected:
	std::string productID;
	std::string productName;
	int productStock;
	float productPrice;
	int daysToExpire;
	int productTotalstock=0;
	int productPurchased=0;
	SeasonalCode seasonCode;
	public:
		Product(std::string ID, std::string Name, int Stock, float Price, int Expdays, int seasonNumber);
		Product();
		void Show(int count=0);
		void PrintCode(SeasonalCode seacode);
		void SetPStock(int totalStock,int purchasedStock);
		int GetActualStocks();
		int GetPurchasedStocks();
		bool CheckExpiry();
		friend class ExpiryData;
		friend class TrendUsage;
		friend class SeasonalCheck;
		friend class ThresholdRestock;
		std::string ReturnID();
		bool CheckProducts(std::string ID);
		void PrintProduct();
		SeasonalCode GetSeasonalCode();
		void operator -= (int n);
		void operator += (int n);
		Product AddItem();
};
class Market{
	protected:
	Product *products[100];
	int productCount;
	public:
	Market();
	~Market();
	void ProductLoad();
	int GetProductCount();
	void ProductShow();
	friend class ExpiryData;
	friend class SeasonalCheck;
	friend class TrendUsage;
	friend class ThresholdRestock;
	void SearchProducts();
	void ProductDisplay(std::string ID);
	void PurchaseStocks(std::string ID,int n);
	void Restock(std::string ID,int n);
	void AddProduct();
};
class TrendUsage{
	Market *market;
	public:
		TrendUsage(Market *market);
		void Show(Product* prod,int count=0);
		void ProductShow();
};
class ExpiryData{
	Market *market;
	public:
		ExpiryData(Market *market);
		void Show(Product* prod, int count=0);
		void ProductShow();
};
class SeasonalCheck{
    Market *market;
    TimeHandler timeSet;
    public:
        SeasonalCheck(Market *market,TimeHandler &time);
        bool CheckSeason_Stock(Product *prod,int month);
        void Show(Product *prod,int count=0);
        void ProductShow();
};
class ThresholdRestock{
    Market *market;
    int thresholdLimit;
    public:
    ThresholdRestock(Market *market);
    bool CheckStocks(Product &prod);
    void show(Product *prod, int count=0);
    void ProductShow();
};
#endif
