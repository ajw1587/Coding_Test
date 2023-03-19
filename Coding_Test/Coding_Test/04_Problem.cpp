#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// N(2<=N<=100) ���� ���̰� �Էµ˴ϴ�.
// N���� ��� �� ���� �������̰� ���� ���� ���� �� ������ ���Ͻÿ�.
int No04()
{
	string txt_path;
	ifstream is(txt_path);
	string line;
	int min = 10000, max = -1;

	if (is.is_open())
	{
		while (getline(is, line)) cout << line << endl;
	}

	// split �ϱ�
	stringstream ss(line);
	string tmp;
	vector<int> answer;
	
	while (getline(ss, tmp, ' '))
	{
		answer.push_back(stoi(tmp));
	}

	// Min, Max ã���ֱ�
	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] < min) min = answer[i];
		if (answer[i] > max) max = answer[i];
	}
	cout << max - min << endl;

	return 0;
}

//int main()
//{
//	No04();
//
//	return 0;
//}