#include "max_value.h"
#include <vector>

using namespace std;

double calculateMaxValue(double* nums, int n) {
	double resmax = nums[0], resmin = nums[0];
	for (int i = 1; i < n; i++) {
		if (nums[i] != 0) {
			auto res = { resmin + nums[i], resmin - nums[i], resmin * nums[i], resmin / nums[i], resmax + nums[i], resmax - nums[i], resmax * nums[i], resmax / nums[i] };
			resmin = min(res);
			resmax = max(res);
		}
		else {
			auto res = { 0., resmin, resmax };
			resmin = min(res);
			resmax = max(res);
		}
	}
	return resmax;
}
