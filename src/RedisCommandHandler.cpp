#include <include/RedisCommandHandler.h>
#include <vector>
#include <sstream>

// RESP parser:
// *2\r\n$4\r\n\PING\r\n$4\r\nTEST\r\n
// *2 -> array has 2 elements
// $4 -> next string has 4 characters
// PING
// TEST

std::vector<std::string> parseRespCommand(const std::string &input) {
    std::vector<std::string> tokens;
    if (input.empty()) return tokens;

    // If it doesn't start with *, fallback to splitting by whitespace
    if (input[0] != '*') {
        std::istringstream iss(input);
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        return tokens;
    }

    size_t pos = 0;
    // Expect * followed by number of elements
    if (input[pos] != '*') return tokens;
    pos++; //skip '*'
}