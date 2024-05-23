#include "OrderBook.h"

void OrderBook::addOrder(const Order &order)
{
    if (order.side == 'B')
    {
        buyOrders[order.price].push_back(order);
    }
    else
    {
        sellOrders[order.price].push_back(order);
    }
}

void OrderBook::matchOrders()
{
    while (!buyOrders.empty() && !sellOrders.empty())
    {
        auto buyIt = buyOrders.rbegin();  // Highest buy price
        auto sellIt = sellOrders.begin(); // Lowest sell price

        if (buyIt->first >= sellIt->first)
        {
            auto &buyOrder = buyIt->second.back();
            auto &sellOrder = sellIt->second.back();

            // Execute the trade at the seller's price to ensure fairness
            double tradePrice = sellIt->first;

            int quantity = std::min(buyOrder.quantity, sellOrder.quantity);

            buyOrder.quantity -= quantity;
            sellOrder.quantity -= quantity;

            std::cout << "Matched Order: Buy ID " << buyOrder.id
                      << " and Sell ID " << sellOrder.id
                      << " Quantity: " << quantity
                      << " at Price: " << tradePrice << std::endl;

            if (buyOrder.quantity == 0)
            {
                buyIt->second.pop_back();
                if (buyIt->second.empty())
                {
                    buyOrders.erase(buyIt->first);
                }
            }

            if (sellOrder.quantity == 0)
            {
                sellIt->second.pop_back();
                if (sellIt->second.empty())
                {
                    sellOrders.erase(sellIt->first);
                }
            }
        }
        else
        {
            break;
        }
    }
}

void OrderBook::printOrderBook()
{
    std::cout << "Buy Orders:\n";
    for (const auto &[price, orders] : buyOrders)
    {
        for (const auto &order : orders)
        {
            std::cout << "ID: " << order.id << " Price: " << price << " Quantity: " << order.quantity << std::endl;
        }
    }
    std::cout << "Sell Orders:\n";
    for (const auto &[price, orders] : sellOrders)
    {
        for (const auto &order : orders)
        {
            std::cout << "ID: " << order.id << " Price: " << price << " Quantity: " << order.quantity << std::endl;
        }
    }
}
