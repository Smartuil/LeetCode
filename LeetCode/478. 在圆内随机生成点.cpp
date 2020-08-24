#include "iostream"
#include <vector>
#include <random>
#include <corecrt_math_defines.h>
using namespace std;

class Solution {
public:
	double rad, xc, yc;
	//c++11 random floating point number generation
	mt19937 rng{ random_device{}() };
	uniform_real_distribution<double> uni{ 0, 1 };

	Solution(double radius, double x_center, double y_center) {
		rad = radius, xc = x_center, yc = y_center;
	}

	vector<double> randPoint() {
		double x0 = xc - rad;
		double y0 = yc - rad;

		while (true) {
			double xg = x0 + uni(rng) * 2 * rad;
			double yg = y0 + uni(rng) * 2 * rad;
			if (sqrt(pow((xg - xc), 2) + pow((yg - yc), 2)) <= rad)
				return { xg, yg };
		}
	}

	vector<double> randPoint() {
		double d = rad * sqrt(uni(rng));
		double theta = uni(rng) * (2 * M_PI);
		return { d * cos(theta) + xc, d * sin(theta) + yc };
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

int main() {
	Solution *solution = new Solution(1, 0, 0);
	vector<double> ret = solution->randPoint();
	for (auto i : ret) {
		cout << i << " ";
	}
	return 0;
}