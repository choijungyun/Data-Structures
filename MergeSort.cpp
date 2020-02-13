#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

/*
재귀를 활용한 병합정렬
*/

int a[101];
int tmp[101];

void divide(int start, int end)
{
	int mid, p1, p2, p3;

	if (start < end)
	{
		mid = (start + end) / 2;
		divide(start, mid);
		divide(mid + 1, end);
		p1 = start;
		p2 = mid + 1;
		p3 = start;

		while (p1 <= mid && p2 <= end) {
			if (a[p1] < a[p2]) tmp[p3++] = a[p1++];
			else tmp[p3++] = a[p2++];
		}
		while (p1 <= mid) tmp[p3++] = a[p1++];
		while (p2 <= end) tmp[p3++] = a[p2++];

		for (int i = start; i <= end; i++)
		{
			a[i] = tmp[i];
		}
	}
}


int main() {
	//freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
	}

	divide(1, N);

	for (int i = 1; i <= N; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}