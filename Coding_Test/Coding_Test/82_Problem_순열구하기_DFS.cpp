#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// �ڿ��� N�� R�� �־����� ���� �ٸ� N���� �ڿ��� �� R���� �̾� �Ϸķ�
// �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

//void test_DFS(int idx, int s, vector<int>& res, vector<int> test)
//{
//	if (idx == 5)
//	{
//		for (int i = 0; i < 5; i++)
//		{
//			cout << res[i] << ' ';
//		}
//		cout << endl;
//	}
//	else
//	{
//		// ���� �ߺ� ����
//		for (int i = s; i < test.size(); i++)
//		{
//			res[idx] = test[i];
//			test_DFS(idx + 1, i + 1, res, test);
//		}
//
//		// ���� �ߺ� ����
//		for (int i = s; i < test.size(); i++)
//		{
//			if (ch[i] == 0)
//			{
//				ch[i] = 1;
//				res[idx] = test[i];
//				test_DFS(idx + 1, 0, res, test);
//				ch[i] = 0;
//			}
//		}
//	}
//}

void DFS(int idx, vector<int> info, vector<bool> &ch, vector<int> &res)
{
	if (idx == 3)
	{
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << ' ';
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < info.size(); i++)
		{
			if (ch[i] == 0)
			{
				res[idx] = info[i];
				ch[i] = 1;
				DFS(idx + 1, info, ch, res);
				ch[i] = 0;
			}
		}
	}
}

int No82()
{
	system_clock::time_point start = system_clock::now();

	int N = 4, R = 3;
	vector<int> info = { 1, 3, 6, 7 };
	vector<bool> ch(N, 0);
	vector<int> res(3, 0);
	int idx = 0;

	DFS(idx, info, ch, res);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No82();

	return 0;
}