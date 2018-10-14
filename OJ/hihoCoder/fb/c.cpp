#include <iostream>
#include <vector>

int cntSumK(std::vector<int> &v, int a, int b, const int K)
{
	if (a == b)
	{
		if (v[a] < K)
			return 1;
		else
			return 0;
	}
	
	int mid = (a + b) / 2;
	int leftCnt = cntSumK(v, a, mid, K);
	int rightCnt = cntSumK(v, mid + 1, b, K);

	int midCnt = 0, leftSum[mid - a + 1], rightSum[b - mid];
	leftSum[0] = v[mid];
	rightSum[0] = v[mid + 1];
	for (int i = 1; i < mid - a + 1; ++i)
		leftSum[i] = leftSum[i - 1] + v[mid - i];
	for (int i = 1; i < b - mid; ++i)
		rightSum[i] = rightSum[i - 1] + v[mid + 1 + i];

	for (auto l : leftSum)
		for (auto r : rightSum)
			if (l + r < K)
				++midCnt;

	return midCnt + leftCnt + rightCnt;
}

int main(int argc, char const *argv[])
{
	int N, K;
	std::cin >> N >> K;

	std::vector<int> v(N);
	for (int i = 0; i < N; ++i)
		std::cin >> v[i];

	std::cout << cntSumK(v, 0, N - 1, K) << std::endl;

	return 0;
}