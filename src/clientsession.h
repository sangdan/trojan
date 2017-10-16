#ifndef _CLIENTSESSION_H_
#define _CLIENTSESSION_H_

#include "session.h"
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

class ClientSession : public Session {
private:
    boost::asio::ip::tcp::socket in_socket;
    char in_buffer[MAX_LENGTH];
    void in_async_read();
    void in_async_write(std::size_t length);
public:
    ClientSession(const Config &config, boost::asio::io_service &io_service, boost::asio::ssl::context &ssl_context);
    boost::asio::ip::tcp::socket& accept_socket();
    void start();
};

#endif // _CLIENTSESSION_H_