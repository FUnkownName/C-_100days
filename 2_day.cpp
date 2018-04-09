#include<iostream>
#include<cmath>//调用该库
#include<iomanip>
using namespace std;
int sum(int start ,int n); //声明函数
inline char max(char ch1,char ch2);
int fun(int n);
void display(void);
void printdiamond(int n);
int global=100;
int main()
{
  int a;
  int main_start(0),main_n=0,result=0;//初始化
  cout<<"Enter start number and n:"<<endl;
  cin>>main_start>>main_n;
  result=sum(main_start,main_n);//调用函数
  cout<<"实参地址:  main_start: "<<&main_start<<"\tn:  "<<&main_n<<endl;
  cout<<"实参内容:  main_start: "<<main_start<<"\tn:   "<<main_n<<endl;
  cout<<setiosflags(ios::right)<<setw(45)<<result<<endl;
  cout<<max('a','b')<<endl;
  //------------
  int n;
  cin>>n;
  fun(n);
  display();

  cout<<global<<endl;
  cout<<&a<<endl;
  //------------
  extern int var_1;
  cout<<var_1<<endl;//调用外部变量
  //============
  int var_n;
  cin>>var_n;
  printdiamond(var_n);
  return 0;
}
  int var_1=1000;
//函数定义
int sum(int start,int n)
{ start=22;
  int sum=0;
  cout<<"形参地址:  start:"<<&start<<"\tn: "<<&n<<endl;
  cout<<"形参内容:  start:"<<start<<"\t n: "<<n<<endl;
  for(int i=start;i<n;++i)
  {
    sum+=i;
    }
  return sum;//返回函数值,sum类型与函数返回类型应一致
}
//内联函数 一般比较短小 不能包括复杂的控制语句  不能包括递归调用语句，不能有太多函数体语句
inline char max(char ch1,char ch2)
{
  return (ch1>ch2?ch1:ch2);
}
//递归调用
int fun(int n)
{
  int m=0;
  if(n==0||n==1)
  {
    m=1;
  }
  else
{
  m=n*fun(n-1);
  cout<<m<<endl;
}
  return m;
}
//全局变量or局部变量
void display(void)
{ static int a=11;//定义静态局部变量
  cout<<&a<<"\t"<<a<<endl;
  a=22;
  cout<<&a<<"\t"<<a<<endl;
  cout<<"全局变量："<<global<<endl;
  global=999; //覆盖全局变量 ,影响函数外该变量
  cout<<"局部变量："<<global<<endl;
}
//全局变量在程序结束前，一直占用空间
//输出菱形
void printdiamond(int n)
{
  int i,j,k;
  for(i=1;i<=(n+1)/2;i++)
  {
    for(j=1;j<=(n+1)/2-i;j++)
      cout<<" ";
    for(k=1;k<=2*i-1;k++)
      cout<<"*";
    cout<<endl;
  }
  for(i=1;i<=(n-1)/2;i++)
  {
    for(j=1;j<=i;j++)
      cout<<" ";
    for(k=n-2*i;k>=1;k--)
      cout<<"*";
    cout<<endl;
  }
}
