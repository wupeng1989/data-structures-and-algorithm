/*********************************************************
 * @auhtor: wupeng
 * @date: 2018-04-22
 * @version: v0.1
 * @desrciption：深入理解递归，参考网址：
 * https://blog.csdn.net/dq_dm/article/details/45043689
 * https://blog.csdn.net/lz161530245/article/details/76943991
 * https://blog.csdn.net/hrn1216/article/details/51534607
 * http://www.cnblogs.com/huangxincheng/archive/2012/11/11/2764625.html
 * https://blog.csdn.net/baidu_28312631/article/details/47418773
 ********************************************************/
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 int lcslength(char *str1,  char *str2, int **b)
 {
     int i, j, length1, length2, len;
     
     length1 = strlen(str1);
     length2 = strlen(str2);
     
     int **c  = (int **)malloc(sizeof(int *) * (length1 + 1)); // c的第0行和第0列没有用
     
     for(i = 0; i < length1 + 1; i++)
     {
         c[i] = (int *)malloc(sizeof(int) * (length2 + 1));
     }
     
    for(i = 0; i < length1 + 1; i++)
    {
        for(j = 0; j < length2 + 1; j++)
        {
            c[i][j] = 0; 
        }
    }
    
 
    for(i = 1; i < length1 + 1; i++)
    {
        for(j = 1; j < length2 + 1; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 0;
            }
            else if (c[i-1][j] > c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = -1;
            }
        }
    }
 
    len = c[length1][length2];
    
    free(c);
    
    return len;
 }
 
 void printlcs(int **b, char *str, int i, int j)
 {
     if(i == 0 || j ==0)
     {
         return ;
     }
     if(b[i][j] == 0)
     {
         printlcs(b, str, i-1, j-1);
         printf("%c ", str[i-1]);
         
     }else if(b[i][j] == 1)
     {
         printlcs(b, str, i-1,j);
         
     }else
     {
         printlcs(b, str, i, j-1);
     }
 }
 
 int main(void)
 {
     char str1[100], str2[100];
     int i, length1, length2, len;
     
     printf("please input first str1: ");
     gets(str1);
     
     printf("please input second str2: ");
     gets(str2);
     
     length1 = strlen(str1);
     length2 = strlen(str2);
     
     
     int **position  = (int **)malloc(sizeof(int *) * (length1 + 1)); 
     for(i = 0; i < length1 + 1 ; i ++)
     {
         position[i] = (int *)malloc(sizeof(int) * (length2 + 1));
     }
        
     len = lcslength(str1, str2, position);
     printf("lcs length: %d\n", len);
     
  #if  1      
     printf("lcs: ");
     printlcs(position, str1, length1 , length2);
     
     free(position);
#endif     
    
     return 0;
 }