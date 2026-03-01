 #include <stdio.h>
#include <math.h>
float f(float x) {
return (x*x*x)-4*x-9;
}
int main() {
float x, x1, x2, aerr;
 int flag = 0, itr = 0;
do {
printf("\nEnter the values of x1 and x2: ");
scanf("%f %f", &x1, &x2);
if (f(x1) * f(x2) < 0) {
flag = 1;
printf("\nThe roots lie between %f and %f", x1, x2);
} else {
printf("\nWrong intervals, try again.");
}
} while (flag != 1);
printf("\nEnter the allowed error: ");
scanf("%f", &aerr);
do {
itr++;
x = (x1 + x2) / 2.0;
printf("\nIteration %d: Midpoint value = %f", itr, x);
if (fabs(f(x)) <= aerr) {
printf("\nThe root found at %f after %d iterations", x, itr);
flag = 0;
} else {
if (f(x) * f(x1) < 0) {
x2 = x;
} else {
x1 = x;
}
}
} while (flag != 0);
return 0;
}