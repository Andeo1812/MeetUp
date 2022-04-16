#include <iostream>

#define EXPECTED_ARG "2 arguments expected: ip and port"

#define ERR_ARG -1

int main(int argc, const char * argv[]) {
    if (argc != 3) {
        fprintf(stderr, EXPECTED_ARG);
        return ERR_ARG;
    }

    std::cout << "Starting server..." << std::endl;

    return EXIT_SUCCESS;
}
