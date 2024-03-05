#include <stdio.h>
#include "vector.h"

int main(int argc, char** argv) {
    int num;
    TVector v1, v2, s, m;
    char* infilename, * outfilename;
    double d;
    if (argc < 3) {
        printf("Incorrect arguments. You haven't input all the arguments.\n");
        return 1;
    }
    infilename = argv[1];
    outfilename = argv[2];
    read(infilename, &v1, &v2);
    s = sum(&v1, &v2);
    m = minus(&v1, &v2);
    d = dotproduct(&v1, &v2);
    write(outfilename, &v1, &v2, &s, &m, d);
    if (s.x != NULL) {
        free(s.x);
    }
    free(v1.x);
    free(v2.x);
    return 0;
}
