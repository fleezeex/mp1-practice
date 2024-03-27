#include <iostream>
#include <fstream>
#include "vector.h"
using namespace std;

int main(int argc, char** argv) {
    std::ifstream in;
    std::ofstream out;

    if (argc < 3) {
        cout << "Incorrect arguments. You haven't input all the arguments." << endl;
        return 1;
    }
    char* infilename = argv[1];
    char* outfilename = argv[2];
    
    TVector v1, v2;
    in.open(infilename);
    in >> v1 >> v2;
    in.close();

    std::cout << v1;
    std::cout << v2;
    
    out.open(outfilename);
    out << v1 + v2 << v1 - v2 << "Vector dotproduct: " << v1 * v2;
    out.close();

    return 0;
}
