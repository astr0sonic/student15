#include "volume.h"
#include <algorithm>

int getMaxVolume(int a, int b, int c, int n, int* arr) {
	int maxStart = 0;
	int max = 0;

	for (int i = 0; i + a < n; ++i)
		if (std::min({ arr[i], arr[a + i] }) > max && std::min({ arr[i], arr[a + i] }) <= c)
		{
			max = std::min({ arr[i], arr[a + i] });
			maxStart = i;
		}

	int i1 = maxStart, i2 = maxStart + std::min(a, n - 1);
	max *= a;

	while (i1 != i2)
	{
		if (std::min(i1, i2) <= c)
			max = std::max<int>(max, (i2 - i1) * std::min({ arr[i1], arr[i2] }));
		if (arr[i1] == std::min(arr[i1], arr[i2]))
			i1++;
		else
			i2--;
	}
	return b * max;
}
