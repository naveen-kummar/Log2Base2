#pragma once

class Knapsack_0_1
{
    int knapSack(const int c, const int n, const int wt[], const int val[])
    {

        const int targetWeight = c;
        const int items = n;

        int result = 0;

        int** matrix = new int* [items];

        for (int i = 0; i < items; i++) 
        {

            matrix[i] = new int[targetWeight+1];
        }

        for (int i = 0; i < items; i++)
        {
            for (int j = 0; j < targetWeight + 1; j++)
            {
                if (j == 0)
                {
                    matrix[i][j] = 0; //Make always 0 when target weight is zero
                }
                else
                {
                    int prevItemVal = (i > 0) ? matrix[i - 1][j] : 0; //Reuse prev sub-problem

                    if (j < wt[i])
                    {
                        matrix[i][j] = prevItemVal;//We cant add current weight so just take prev item's val
                    }
                    else
                    {
                        int newVal = val[i]; //We can just add current weight fully

                        int remainingWt = j - wt[i]; //Determine how much further wt can appended after adding current wt 

                        newVal += (i > 0) ? matrix[i - 1][remainingWt] : 0; //Append remaining wt's val after appending the cuurent wt's val

                        matrix[i][j] = (newVal > prevItemVal) ? newVal : prevItemVal;
                    }


                }

            }

        }

        return matrix[items - 1][targetWeight];

    }

};
