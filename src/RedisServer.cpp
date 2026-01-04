#include "include/RedisServer.h"
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

static RedisServer* globalServer = nullptr;

RedisServer::RedisServer(int port) : port(port), server_socket(-1), running(true) {
    globalServer = this;
}

void RedisServer::shutdown() {
    running = false;
    if (server_socket != -1) {
        close(server_socket);
    }
    std::cout << "Server Shutdown Complete!\n";
}

void RedisServer::run() {
    // Get file descriptor for IPv4/TCP
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        std::cerr << "Error Creating Server Socket\n";
        return;
    }

    // Enable reusable addresses to resolve issues with TIME_WAIT
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Initialize address struct to hold IP and port info
    sockaddr_in serverAddr{};
}