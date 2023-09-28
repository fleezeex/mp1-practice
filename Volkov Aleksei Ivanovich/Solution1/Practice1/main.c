#include <stdio.h>
#include <math.h>

int main()
{
    double x1, y1, r1;
    double x2, y2, r2;

    printf("Input the coordinates of the first circle and its radius. \n");
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    if (r1 < 0)
    {
        printf("The radius cannot be less than zero.");
        return 0;
    }

    printf("Input the coordinates of the second circle and its radius. \n");
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    if (r2 < 0)
    {
        printf("The radius cannot be less than zero.");
        return 0;
    }

    double distance;
    if (x1 == x2)
    {
        distance = fabs(y1 - y2);
    }
    else if (y1 == y2)
    {
        distance = fabs(x1 - x2);
    }
    else
    {
        distance = sqrt((fabs(x1) + fabs(x2)) * (fabs(x1) + fabs(x2)) + (fabs(y1) + fabs(y2)) * (fabs(y1) + fabs(y2)));
    }

    if (x1 == x2 && y1 == y2 && r1 == r2)
    {
        printf("The circles match.");
    }
    else if (distance > r1 + r2)
    {
        printf("There are no common points.");
    }
    else if (distance == r1 + r2)
    {
        printf("There is one common point (external touch).");
    }
    else if (distance == fabs(r1 - r2))
    {
        printf("There is one common point (internal touch).");
    }
    else if ((fabs(r1 - r2) < distance) && (distance < r1 + r2))
    {
        printf("There are two common points.");
    }
    else if (0 < distance < fabs(r1 - r2))
    {
        printf("There are no common points, one circle lies in another.");
    }

    return 0;
}