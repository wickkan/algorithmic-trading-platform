#include "MarketDataHandler.h"

void MarketDataHandler::handleMarketData(const MarketData &data, OrderBook &orderBook)
{
    int orderId = generateOrderId();
    Order order = {orderId, data.price, data.quantity, data.side, data.symbol, data.timestamp};
    orderBook.addOrder(order);
}

int MarketDataHandler::generateOrderId()
{
    return orderIdCounter++;
}
