#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;


//Dynamic recursive using memoaization
int lcs(int **memo, string text1, string text2)
{
    int len1 = text1.length();
    int len2 = text2.length();
    if (memo[len1][len2] == -1)
    {
        if (!len1 || !len2)
        {
            memo[len1][len2] = 0;
            return 0;
        }
        string cutted1 = text1.substr(1, len1 - 1);
        string cutted2 = text2.substr(1, len2 - 1);

        if (text1[0] == text2[0])
        {
            memo[len1][len2] = 1 + lcs(memo, cutted1, cutted2);
            return memo[len1][len2];
        }
        else
        {
            memo[len1][len2] = max(lcs(memo, cutted1, text2), lcs(memo, text1, cutted2));
            return memo[len1][len2];
        }
    }
    return memo[len1][len2];
}

//Simple recursive
int lcsLength(string X, string Y)
{
    int lenX = X.length();
    int lenY = Y.length();
    if (!lenX || !lenY)
        return 0;
    string cuttedX = X.substr(1, lenX - 1);
    string cuttedY = Y.substr(1, lenY - 1);
    if (X[0] == Y[0])
        return 1 + lcsLength(cuttedX, cuttedY);
    return max(lcsLength(cuttedX, Y), lcsLength(X, cuttedY));
}

int **prepareArray(int x, int y)
{
    int **arr = new int *[x + 1];
    for (int i = 0; i <= x; i++)
    {
        arr[i] = new int[y + 1];
        arr[i][0] = 0;
    }
    for (int i = 0; i <= y; i++)
    {
        arr[0][i] = 0;
    }
    return arr;
}

//Iterative dynamic
string lcsDynamic(int **dp, string x, string y)
{
    int lenX = x.length();
    int lenY = y.length();
    for (int i = 1; i <= lenX; i++)
    {
        for (int j = 1; j <= lenY; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else if (dp[i - 1][j] >= dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    string result = "";

    int i = lenX, j = lenY;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            result += x[i - 1];
            i--;
            j--;
        }
        //Tutaj w zależności od warunku, algorytm będzie rekonstruował najlepsze rozwiązanie idąc w lewo, lub w górę
        //dla '>' lcs będzie "BCBA"
        //dla '< lcs będzie "BDAB"
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    string text1 = "bdcaba";
    string text2 = "abcbdab";
    int len1 = text1.length();
    int len2 = text2.length();

    int **memo = prepareArray(len1, len2);
    cout << "Iterated dynamic" << endl;
    cout << "LCS:"<<lcsDynamic(memo, text1, text2) << endl;

    memo = new int *[len1 + 1];
    for (int i = 0; i <= len1; i++)
    {
        memo[i] = new int[len2 + 1];
        memo[i][0] = 0;
        for (int j = 1; j <= len2; j++)
        {
            memo[i][j] = -1;
        }
    }
    for (int j = 0; j <= len2; j++)
    {
        memo[0][j] = 0;
    }
    cout << "Recursive dynamic" << endl;
    cout << "Len:"<<lcs(memo, text1, text2) << endl;


    for (int i = 0; i <= len1; i++)
    {
        delete[] memo[i];
    }
    delete[] memo;
    return 0;
}
