#include "include/RedisServer.h"

static RedisServer* globalServer = nullptr;

RedisServer::RedisServer(int port) : port(port), server_socket(-1), running(true) {
    globalServer = this;
}
