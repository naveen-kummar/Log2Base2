#pragma once

class LeastCommonSequence
{
    int lcs(const int m, const char* x, const int n, const char* y)
    {
        int** matrix = new int* [m + 1];
        for (int i = 0; i < m+1 + 1; i++)
        {
            matrix[i] = new int [n+1];
        }

        int resumepos = 0;
        int result = 0;

        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                matrix[i][j] = 0;
            }
        }

        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    continue;
                }


                if (x[i - 1] == y[j - 1])
                {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                }
                else
                {
                    matrix[i][j] = (matrix[i - 1][j] > matrix[i][j - 1]) ? matrix[i - 1][j] : matrix[i][j - 1];
                }

            }
        }

        return matrix[m][n];

    }
};
