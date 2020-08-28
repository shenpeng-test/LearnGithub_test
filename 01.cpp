#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool dfs(vector<int>&,int,int,int&);

int main()
{
	int N, M;
	cin >> N;
	cin >> M;
	vector<int>D(M, 0);
	for (int i = 0; i < M; ++i)
	{
		int temp;
		cin >> temp;
		D[i] = temp;
	}

	int count = 0;
	
	for (int i = 1; i <= N; ++i)
		if (dfs(D, i, 0, N))
			++count;

	cout << count << endl;

	system("pause");

	return 0;
}

bool dfs(vector<int>&D, int pos, int num , int &N)
{
	if (pos < 1 || pos >= N)
		return false;
	if (num == D.size())
		return true;

	return dfs(D, pos + D[num], num+1,N) || dfs(D, pos - D[num],num+1, N);


}