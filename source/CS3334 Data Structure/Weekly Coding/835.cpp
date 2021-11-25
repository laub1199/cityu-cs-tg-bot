#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Circle;
Circle** circle;
int wall, num;
long long int x1, y1, x2, y2, r;

struct Circle {
	long long int x, y, r;

	Circle() : x(0), y(0), r(0) {}
	Circle(long long int x, long long int y, long long int r) : x(x), y(y), r(r) {}
};

double sqrt(double n) {
	n = 1.0 / n;
	long long int i;
	double x, y;

	x = n * 0.5f;
	y = n;
	i = *(long long int*)&y;
	i = 0x5f3759d - (i >> 1);
	y = *(double*)&i;
	y = y * (1.5 - (x * y * y));

	return y;
}

int abs(int value) {
	return value > 0 ? value : -value;
}

int intersect() {
	int ans = 0;
	long long int a = y2 - y1;
	long long int b = x1 - x2;
	long long int c = a * x1 + b * y1;

	for (int i = 0; i < wall; i++) {
		double dist = abs(a * circle[i]->x + b * circle[i]->y + c) / sqrt(a * a + b * b);
		bool pd1 = (x1 - circle[i]->x) * (x1 - circle[i]->x) + (y1 - circle[i]->y) * (y1 - circle[i]->y) < circle[i]->r * circle[i]->r;
		bool pd2 = (x2 - circle[i]->x) * (x2 - circle[i]->x) + (y2 - circle[i]->y) * (y2 - circle[i]->y) < circle[i]->r * circle[i]->r;

		if (circle[i]->r > dist && (pd1 ^ pd2))
			ans++;
	}

	return ans;
}

int main() {
	scanf("%d", &wall);
	circle = new Circle*[wall];

	for (int i = 0; i < wall; i++) {
		scanf("%lld %lld %lld", &x1, &y1, &r);
		circle[i] = new Circle(x1, y1, r);
	}

	scanf("%d", &num);

	while (num--) {
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		printf("%d\n", intersect());
	}

	return 0;
}
