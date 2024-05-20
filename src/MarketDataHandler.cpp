#include "MarketDataHandler.h"

void MarketDataHandler::handleMarketData(const MarketData &data, OrderBook &orderBook)
{
    Order order = {0, data.price, data.quantity, data.side, data.symbol, data.timestamp};
    orderBook.addOrder(order);
}
