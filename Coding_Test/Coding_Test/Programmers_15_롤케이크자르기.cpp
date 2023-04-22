#include <iostream>
#include <chrono>
#include <vector>
#include <map>

using namespace std;
using namespace chrono;

// ������ũ �ڸ���
// https://school.programmers.co.kr/learn/courses/30/lessons/132265
int No()
{
	system_clock::time_point start = system_clock::now();

	int answer = 0;
	vector<int> topping =
	{ 1, 2, 1, 3, 1, 4, 1, 2 };

    map<int, int> old;
    map<int, int> young;
    int old_type = 0, young_type = 0;

    // ���� �� ä���ֱ�
    for (int i = 0; i < topping.size(); i++) young[topping[i]]++;
    young_type = young.size();

    // ö���� �ϳ��� ��������
    for (int i = 0; i < topping.size(); i++)
    {
        int idx = topping[i];

        if (old[idx] == 0) old_type++;
        old[idx]++;

        young[idx]--;
        if (young[idx] <= 0) young_type--;

        if (old_type > young_type) break;

        if (old_type == young_type) answer++;
    }

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No();

	return 0;
}