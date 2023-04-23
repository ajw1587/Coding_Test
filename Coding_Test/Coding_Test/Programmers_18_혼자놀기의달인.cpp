#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace chrono;

// ȥ�� ����� ����
// https://school.programmers.co.kr/learn/courses/30/lessons/131130
int No()
{
	system_clock::time_point start = system_clock::now();

	int answer = 0;
	vector<int> cards =
	{ 8, 6, 3, 7, 2, 5, 1, 4 };

	// ������ ���� �ε���
	int idx = 0;

	// �̾Ҵ��� �Ȼ̾Ҵ��� üũ�ϴ� ����
	vector<bool> ch_box(cards.size(), true);

	// count ���� �� ������ ����
	int cnt = 0;
	vector<int> cnt_size;

	// üũ���ֱ�
	for (int i = 0; i < cards.size(); i++)
	{
		if (ch_box[idx])
		{
			ch_box[idx] = false;
			idx = cards[idx] - 1;
			cnt++;
			if (i == cards.size() - 1)
			{
				cnt_size.push_back(cnt);
			}
		}
		else  // ch_box[idx] = false
		{
			i--;
			cnt_size.push_back(cnt);
			cnt = 0;
			for (int j = 0; j < ch_box.size(); j++)
			{
				if (ch_box[j])
				{
					idx = j;
					break;
				}
			}
		}
	}

	sort(cnt_size.begin(), cnt_size.end());

	answer = cnt_size[cnt_size.size() - 1] * cnt_size[cnt_size.size() - 2];

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