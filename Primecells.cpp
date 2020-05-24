#include<bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define end  <<"\n";




int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fastIO

	int N;
	cin >> N;


	int mat[N][N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> mat[i][j];
	}


	int dp[N][N];


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j  < N; j++)
		{
			// first row and first corner
			if (i == 0 && j == 0)
				dp[i][j] = mat[i + 1][j] + mat[i][j + 1];

			// first row last corner
			else if (i == 0 && j == N - 1)
				dp[i][j] = mat[i][j - 1] + mat[i + 1][j];
                
      // last row first column
			else if (i == N - 1  && j == 0)
				dp[i][j] = mat[i - 1][j] + mat[i][j + 1];

      // last row lasst column
			else if (i == N - 1 && j == N - 1)
				dp[i][j] = mat[i - 1][j] + mat[i][j - 1];


			else if (i == 0  && j > 0 && j < N)
				dp[i][j] = mat[i][j - 1] + mat[i][j + 1] + mat[i + 1][j];


			else if (i ==  N - 1  && j > 0 && j < N)
				dp[i][j] = mat[i][j - 1] + mat[i][j + 1] + mat[i - 1][j] ;


			else if (i > 0 && i < N && j == 0)
				dp[i][j] = mat[i - 1][j] + mat[i + 1][j] + mat[i][j + 1];

			else if (i > 0 && i < N && j == N - 1)
				dp[i][j] = mat[i - 1][j] + mat[i + 1][j] + mat[i][j - 1];

			else if (i > 0 && i < N && j > 0 && j < N)
				dp[i][j] = mat[i - 1][j] + mat[i + 1][j] + mat[i][j - 1] + mat[i][j + 1];

		}
	}

	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (isPrime(dp[i][j]))
				count++;
		}
	}


	cout << count << "\n";

	return 0;

}
