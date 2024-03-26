#include "max_value.h"
#include <vector>

double calculateMaxValue(double* nums, int n) {
	double resmax = nums[0], resmin = nums[0];
	for (int i = 1; i < n; i++) {
		if (nums[i] != 0) {
			auto res = { resmin + nums[i], resmin - nums[i], resmin * nums[i], resmin / nums[i], resmax + nums[i], resmax - nums[i], resmax * nums[i], resmax / nums[i] };
			resmin = std::min(res);
			resmax = std::max(res);
		}
		else {
			auto res = { 0., resmin, resmax };
			resmin = std::min(res);
			resmax = std::max(res);
		}
	}
	return resmax;
}
