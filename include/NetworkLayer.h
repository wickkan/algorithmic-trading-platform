#ifndef NETWORKLAYER_H
#define NETWORKLAYER_H

#include <zmq.hpp>
#include <string>

class NetworkLayer
{
private:
    zmq::context_t context;
    zmq::socket_t socket;

public:
    NetworkLayer();
    ~NetworkLayer();

    void setupPublisher(const std::string &address);
    void setupSubscriber(const std::string &address);

    void sendData(const std::string &data);
    std::string receiveData();
};

#endif // NETWORKLAYER_H
