#include <stdio.h>
#include "vector.h"

int main() {
    int n;
    TVector s, m, v1, v2;
    double d;
    printf("Length of the first vector = ");
    scanf("%d", &n);
    alloc(&v1, n);
    printf("Length of the second vector = ");
    scanf("%d", &n);
    alloc(&v2, n);
    fill(&v1);
    fill(&v2);
    s = sum(&v1, &v2);
    m = minus(&v1, &v2);
    d = dotproduct(&v1, &v2);
    printf("Vector addition: ");
    print(&s);
    printf("Vector substraction: ");
    print(&m);
    printf("Vector dotproduct: ");
    printf("%lf", d);
    free(v1.x);
    free(v2.x);
    if (s.x != NULL) {
        free(s.x);
    }
    return 0;
}
