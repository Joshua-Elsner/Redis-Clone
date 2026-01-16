#include "RedisCommandHandler.h"
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

// Helper function to print vectors
void printVector(const std::vector<std::string>& vec) {
    std::cout << "[ ";
    for (const auto& str : vec) {
        std::cout << "\"" << str << "\" ";
    }
    std::cout << "]" << std::endl;
}

void testStandardRespCommand() {
    std::cout << "Running testStandardRespCommand... ";
    
    // RAW RESP: *3\r\n$3\r\nSET\r\n$3\r\nkey\r\n$5\r\nvalue\r\n
    // This represents: SET key value
    std::string input = "*3\r\n$3\r\nSET\r\n$3\r\nkey\r\n$5\r\nvalue\r\n";
    
    std::vector<std::string> result = parseRespCommand(input);
    
    // Assertions
    assert(result.size() == 3);
    assert(result[0] == "SET");
    assert(result[1] == "key");
    assert(result[2] == "value");
    
    std::cout << "PASSED" << std::endl;
}

void testInlineCommand() {
    std::cout << "Running testInlineCommand... ";
    
    // Inline command: PING
    std::string input = "PING";
    
    std::vector<std::string> result = parseRespCommand(input);
    
    assert(result.size() == 1);
    assert(result[0] == "PING");
    
    std::cout << "PASSED" << std::endl;
}

void testInlineWithArgs() {
    std::cout << "Running testInlineWithArgs... ";
    
    // Inline: ECHO hello world
    std::string input = "ECHO hello world";
    
    std::vector<std::string> result = parseRespCommand(input);
    
    assert(result.size() == 3);
    assert(result[0] == "ECHO");
    assert(result[1] == "hello");
    assert(result[2] == "world");
    
    std::cout << "PASSED" << std::endl;
}

void testEmptyInput() {
    std::cout << "Running testEmptyInput... ";
    
    std::string input = "";
    std::vector<std::string> result = parseRespCommand(input);
    
    assert(result.empty());
    
    std::cout << "PASSED" << std::endl;
}

int main() {
    std::cout << "--- Starting Parser Tests ---" << std::endl;
    
    testStandardRespCommand();
    testInlineCommand();
    testInlineWithArgs();
    testEmptyInput();
    
    std::cout << "--- All Tests Passed Successfully ---" << std::endl;
    return 0;
}