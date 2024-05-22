#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <map>
#include <vector>
#include <string>
#include <iostream>

struct Order
{
    int id;
    double price;
    int quantity;
    char side; // 'B' for Buy, 'S' for Sell
    std::string symbol;
    long timestamp;
};

class OrderBook
{
private:
    std::map<double, std::vector<Order>> buyOrders;
    std::map<double, std::vector<Order>> sellOrders;

public:
    void addOrder(const Order &order);
    void matchOrders();
    void printOrderBook(); // Add this method for debugging
};

#endif // ORDERBOOK_H
