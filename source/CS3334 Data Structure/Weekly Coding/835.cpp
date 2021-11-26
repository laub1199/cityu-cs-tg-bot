#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct men;
men** girl;
int good, shit;
long long int x1, y1, x2, y2, r;
struct men {
	long long int x, y, r; men() : x(0), y(0), r(0) {} men(long long int x, long long int y, long long int r) : x(x), y(y), r(r) {}
};
int abs(int v) {return v > 0 ? v : -v;}
double xtimesx(double n) {
	n = 1.0 / n; long long int i; double x, y; x = n * 0.5f; y = n; i = *(long long int*)&y; i = 0x5f3759d - (i >> 1); y = *(double*)&i; y = y * (1.5 - (x * y * y)); return y;
}
int intersect() {
	int ans = 0;
	long long int a = y2 - y1; long long int b = x1 - x2; long long int c = a * x1 + b * y1;
	for (int i = 0; i < good; i++) { double dist = abs(a * girl[i]->x + b * girl[i]->y + c) / xtimesx(a * a + b * b); bool pd1 = (x1 - girl[i]->x) * (x1 - girl[i]->x) + (y1 - girl[i]->y) * (y1 - girl[i]->y) < girl[i]->r * girl[i]->r; bool pd2 = (x2 - girl[i]->x) * (x2 - girl[i]->x) + (y2 - girl[i]->y) * (y2 - girl[i]->y) < girl[i]->r * girl[i]->r; if (girl[i]->r > dist && (pd1 ^ pd2)) ans++;}
	return ans;
}
int main() {
	scanf("%d", &good);
	girl = new men*[good];
	for (int i = 0; i < good; i++) {scanf("%lld %lld %lld", &x1, &y1, &r);girl[i] = new men(x1, y1, r);}
	scanf("%d", &shit);
	while (shit--) {scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);printf("%d\n", intersect());}
	return 0;
}




































// dont submit directly ok?
