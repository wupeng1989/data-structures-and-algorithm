/*********************************************************
 * @auhtor: wupeng
 * @date: 2018-04-22
 * @version: v0.1
 * @desrciption：深入理解递归，参考网址：
 * https://blog.csdn.net/sinat_38052999/article/details/73303111
 * https://www.cnblogs.com/zyoung/p/6764371.html
 ********************************************************/
 
 /******************************************************
  * @function：逆序输出字符数组元素
  * @pararm: str 字符数组  
  * @pararm：len 字符串长度
*******************************************************/

void reverse_charstr_print(char str[], int len)
{
   if(len == 0)
    {
       return ;
    }
   else
    {
        printf("%c", str[len -1]);
        reverse_charstr_print(str, len-1);
    }
    
}

 /******************************************************
  * @function：逆序数组元素
  * @pararm: 数组  
  * @pararm： len 数组长度
*******************************************************/
void reverse_array(int a[], int k)
{
    int temp = 0;
    if(k <= 1)
    {
        return;
    }
    reverse_array(a+1, k-2);
    temp = a[0];
    a[0] = a[k-1];
    a[k-1] = temp;
}
 /******************************************************
  * @function：逆序输出一个整数
  * @pararm: presult 转换后的输出结果  
  * @pararm： 要转换的整数
*******************************************************/
void reverse_int(int *presult, int tmp)
{
    if(tmp / 10 == 0)
    {
        presult[0] = tmp;
        return;
    }
    presult[0] = tmp % 10;
    reverse_int(presult+1, tmp / 10);
}

 /******************************************************
  * @function：回文检测
  * @pararm: pstr字符串  
  * @pararm： len 字符串长度
*******************************************************/
int Palindrome_Check(char *pstr, int len)
{
    if(len <= 1)
    {
        return 1;
    }
    if(pstr[0] != pstr[len-1])
    {
        return 0;
    }else
    {
        return  Palindrome_Check(pstr+1, len-2);
    }
}

/******************************************************
  * @function：分解质因数
  * @pararm: 整数
*******************************************************/
 void Decompose_Qualityfactor(int m)
 {  
     int  i = 0;
     for(i = 2; i < m/2 + 1; i++)
     {
        if(m % i == 0) 
        {
            break;
        }
     }
     
     if(i == m/2 + 1)
     {
         printf("%d", m);  
     }else
         
     {
         printf("%d*", i);
         Decompose_Qualityfactor(m/i);
     }
 }
 
/******************************************************
  * @function：全排列
  * @pararm: 数组  
  * @pararm： len 数组长度
*******************************************************/


#include <stdio.h>
int main(int argc, char **argv)
{
//#define __TEST_Reverse_Charstr__
//#define __TEST_Reverse_Array__
//#define __TEST_Reverse_Int__
//#define __TEST_Palindrome_Check__
#define __TEST_Decompose_Qualityfactor__

/* 逆序输出字符数组元素 */

#ifdef  __TEST_Reverse_Charstr__  

    char str[100]= {0};
    gets(str);
    puts(str);
    reverse_charstr_print(str, strlen(str));
#endif

/* 逆序数组元素 */
#ifdef __TEST_Reverse_Array__
     int i = 0;
     int a[5] = {1, 2, 3, 4, 5};
     reverse_array(a, 5);
     for(i = 0; i < 5; i++)
     {
         printf("%d ", a[i]);
     }

#endif


/* 逆序输出一个整数 */
#ifdef  __TEST_Reverse_Int__
    int i = 0;
    int a = 123456;
    int b[10] = { 0 };
    reverse_int(b, a);
    for(i = 0; i < 6; i++)
    {
        printf("%d ", b[i]);
    }
 #endif
 
/* 回文检测*/
#ifdef __TEST_Palindrome_Check__

    char *str = "abcdeedcbaa";
    if(Palindrome_Check(str, strlen(str)))
    {
        printf("YES");
    }else
    {
        printf("NO");
    }
#endif

/* 分解质因数 */
#ifdef __TEST_Decompose_Qualityfactor__
    int a = 12;    
    printf("%d = ", a);
    Decompose_Qualityfactor(a);          
#endif

	return 0;
}
