/*********************************************************
 * @auhtor: wupeng
 * @date: 2018-04-22
 * @version: v0.1
 * @desrciption：深入理解递归，参考网址：
 * https://www.cnblogs.com/zyoung/p/6764371.html
 * https://blog.csdn.net/summerxiachen/article/details/60579623
 ********************************************************/
 #include <stdio.h>
 
 void swap(int *ptemp, int i, int j)
 {
     int t;
     t = ptemp[i];
     ptemp[i] = ptemp[j];
     ptemp[j] = t;
 }
 
void permutation(int *ptemp,  int i, int j)
{
    int k = 0;
    if(i == j)
    {
        for(k = 0; k < j; k++)
        {
            printf("%d ", ptemp[k]);
        }
        printf("\r\n");
    }
        
    for(k = i; k < j; k++ )
    {
        swap(ptemp, i, k);
        permutation(ptemp, i+1, j);
        swap(ptemp, i, k);
    
    }    
}

int main(int argv, char **argc)
{
    int str[4] = {1, 2, 3, 4};
    
    permutation(str, 0, 4);
    
}
 
 