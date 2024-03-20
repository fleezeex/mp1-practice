#include <iostream>
#include <fstream>
#include "vector.h"
using namespace std;

int main(int argc, char** argv) {
    std::ifstream in;
    std::ofstream out;

    char* infilename, * outfilename;
    if (argc < 3) {
        cout << "Incorrect arguments. You haven't input all the arguments." << endl;
        return 1;
    }
    infilename = argv[1];
    outfilename = argv[2];
    
    TVector v1, v2;
    in.open(infilename);
    in >> v1 >> v2;
    in.close();

    std::cout << v1;
    std::cout << v2;
    
    TVector s = v1 + v2;
    TVector m = v1 - v2;
    double d = v1 * v2;

    out.open(outfilename);
    out << s << m << "Vector dotproduct: " << d;
    out.close();

    return 0;
}
