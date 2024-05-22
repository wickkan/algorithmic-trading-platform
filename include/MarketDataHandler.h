#ifndef MARKETDATAHANDLER_H
#define MARKETDATAHANDLER_H

#include "OrderBook.h"
#include <atomic>

struct MarketData
{
    double price;
    int quantity;
    char side; // 'B' for Buy, 'S' for Sell
    std::string symbol;
    long timestamp;
};

class MarketDataHandler
{
public:
    MarketDataHandler() : orderIdCounter(0) {}
    void handleMarketData(const MarketData &data, OrderBook &orderBook);

private:
    std::atomic<int> orderIdCounter;
    int generateOrderId();
};

#endif // MARKETDATAHANDLER_H
