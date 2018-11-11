/*********************************************************
 * @auhtor: wupeng
 * @date: 2018-04-22
 * @version: v0.1
 * @desrciption：深入理解动态规划，参考网址：
 * https://blog.csdn.net/zls986992484/article/details/69863710
 * https://blog.csdn.net/baidu_28312631/article/details/47418773
 ********************************************************/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  N 50

void dp(char *pstr1, int length1, char *pstr2, int length2)
{
    int i, j;
    int dp[N][N] = {0};
    int maxlen;
    int maxindex;
    
    for(i = 1; i < length1 + 1; i++)
    {
        for(j = 1; j < length2 + 1; j++)
        {
            if(pstr1[i-1] == pstr2[j-1])
            {
                dp[i][j] =  dp[i-1][j-1] + 1;
                printf("d[%d][%d]: %d \n", i, j , dp[i][j]);
                if(dp[i][j] > maxlen)
                {
                    maxlen = dp[i][j];
                    maxindex = i -1;
                }
            }
        }
    }
    
    printf("maxlen: %d, maxindex: %d\n", maxlen, maxindex);
}
int main()
{
    char str1[N], str2[N];
    
    int maxlen = 0;
    int length1, length2; 
    
    printf("please input first str1: ");
    gets(str1);
     
    printf("please input second str2: ");
    gets(str2);
    
    length1 = strlen(str1);
    length2 = strlen(str2);
    
    dp(str1, length1, str2, length2);
    
}