#include <iostream>
#include <vector>

using namespace std;

// N�ڸ��� �ڿ����� �ԷµǸ� �Էµ� �ڿ����� �ڸ��� �� ���� ���� ���� ���ڸ� ����Ͻÿ�.
int No13()
{
	vector<int> num_cnt(10, 0);
	int num, answer, max = -1;
	string N;
	cin >> N;

	for (int i = 0; i < N.size(); i++)
	{
		num = N[i] - 48;
		num_cnt[num]++;
	}

	for (int i = 0; i < num_cnt.size(); i++)
	{
		if (max < num_cnt[i])
		{
			max = num_cnt[i];
			answer = i;
		}
	}

	cout << answer << endl;

	return 0;
}

//int main()
//{
//	No13();
//
//	return 0;
//}