#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Anagram이란 두 문자열이 알파벳의 나열 순서를 다르지만 그 구성이 일치하면 두 단어는 아나그램이라고 한다.
// 두 단어가 아나그램인지 판별하는 프로그래을 작성하시오. (대소문자 구분)
int No16()
{
	string s_1 = "ASDADZZzzzz";
	string s_2 = "ASDADZZzzzz";
	//cin >> s_1;
	//cin >> s_2;

	// 길이가 다르면 애초에 비교하지 않음!
	if (s_1.size() != s_2.size())
	{
		cout << "NO" << endl;
		return 0;
	}

	// 분석하기
	// 대문자 A ~ Z = 65 ~ 90 = 0 ~ 25
	// 소문자 a ~ z = 97 ~ 122 = 26 ~ 51
	vector<int> s_1_v(52, 0);
	vector<int> s_2_v(52, 0);
	int test1, test2;

	for (int i = 0; i < s_1.size(); i++)
	{
		test1 = s_1[i];
		test2 = s_2[i];

		if (test1 >= 65 && test1 <= 90) test1 -= 65;
		else test1 -= 71;
		if (test2 >= 65 && test2 <= 90) test2 -= 65;
		else test2 -= 71;

		s_1_v[test1]++;
		s_2_v[test2]++;
	}

	// 비교
	for (int i = 0; i < s_1_v.size(); i++)
	{
		if (s_1_v[i] != s_2_v[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}

//int main()
//{
//	No16();
//
//	return 0;
//}