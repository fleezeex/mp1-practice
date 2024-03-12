#include <iostream>
#include "vector.h"
using namespace std;

int main(int argc, char** argv) {
    char* infilename, * outfilename;
    if (argc < 3) {
        cout << "Incorrect arguments. You haven't input all the arguments." << endl;
        return 1;
    }
    infilename = argv[1];
    outfilename = argv[2];
    int i = 0;
    FILE* f = fopen(infilename, "r+");
    if (f == NULL) {
        std::cout << "File not found.";
        abort();
    }
    TVector v1(f);
    TVector v2(f);
    fclose(f);
    TVector s = v1 + v2;
    TVector m = v1 - v2;
    double d = dotproduct(&v1, &v2);
    write(outfilename, &s, &m, d);
    return 0;
}
