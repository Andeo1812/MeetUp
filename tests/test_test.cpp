
#include <string>
#include <fstream>
#include <cassert>
#include <iostream>
int main() {
    // system("./int.sh");
    std::string host_name = "127.0.0.1 8000";
    std::string test_file = "GoodRequest.txt";

    std::string command = "echo 'GET /1.txt HTTP/1.1\r\nHost: localhost\r\nUser-Agent: my-custom-agent\r\n\r\n*CONTENT BODY*:{[\"a\" : \"b\"]}\r\n' | ncat "
        + host_name + " > " + test_file;

    system(command.c_str());

    std::ifstream fin1(test_file);
    std::ifstream fin2("GoodRequest_3.gold");
    assert(fin1);
    assert(fin2);

    char ch1, ch2;
    bool result = true;
    while (fin1.get(ch1) && fin2.get(ch2)) {
        if (ch1 != ch2) {
            result = false;
            break;
        }
    }
    assert(result == true);
    if (result == true) {
        std::cout << "good~\n";
    }

    return 0;
}