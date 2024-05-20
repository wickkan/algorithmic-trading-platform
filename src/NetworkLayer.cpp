#include "NetworkLayer.h"

NetworkLayer::NetworkLayer() : context(1), socket(context, ZMQ_PAIR) {}

NetworkLayer::~NetworkLayer()
{
    socket.close();
    context.close();
}

void NetworkLayer::setupPublisher(const std::string &address)
{
    socket.bind(address);
}

void NetworkLayer::setupSubscriber(const std::string &address)
{
    socket.connect(address);
}

void NetworkLayer::sendData(const std::string &data)
{
    zmq::message_t message(data.size());
    memcpy(message.data(), data.data(), data.size());
    socket.send(message, zmq::send_flags::none);
}

std::string NetworkLayer::receiveData()
{
    zmq::message_t message;
    socket.recv(message, zmq::recv_flags::none);
    return std::string(static_cast<char *>(message.data()), message.size());
}
