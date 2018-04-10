#include<iostream>
#include<string>
using namespace std;
void display_array(void);//声明显示一维数组内容函数，无返回值
int bubble_sort(int n);//声明冒泡排序函数
void dispaly_Array(void);//声明显示二维整型数组
void dispaly_char(void);声明字符串数组
int main()
{
  int main_n=0;
  display_array();
  cout<<"How many numbers is you want to handle?"<<endl;
  cin>>main_n;
  bubble_sort(main_n);
  dispaly_Array();
  dispaly_char();
  string name_1="BOB",name_2="Peter";
  cout<<"交换前："<<"name_1:"<<name_1<<"\tname_2:"<<name_2<<endl;
  name_1.swap(name_2);//交换字符串
  cout<<"交换后："<<"name_1:"<<name_1<<"\tname_2："<<name_2<<endl;
  name_1.append(" \nHello!Boy");//增添字符串
  cout<<name_1<<endl;
  name_2.clear();//删除所有字符
  cout<<name_2<<endl;
      return 0;
}
void display_array(void)
{
  const int N=10;
  auto int array[N]={0,1,0,1};//数组初始化
  int array_size=0;
  array_size=sizeof(array);
  //sizeof(array)数组长度,sizeof(int) 系统编译时对int型变量分配的地址空间长度
  cout<<"数组首地址数值: "<<array[0]<<"\t数组首地址: "<<&array[0]<<endl;
  cout<<"数组末地址数值: "<<array[array_size/sizeof(int)-1]<<"\t"
      <<"数组末地址： "<<&array[array_size/sizeof(int)-1]<<endl;
}
int bubble_sort(int n)
{
  const int var_s=n;
  int array_sort[var_s];
  int temp=0;
  for(int i=0;i<var_s;i++)
    {
        cout<<"Enter "<<i<<" numbers:"<<endl;
        cin>>array_sort[i];
    }
    cout<<"排序前首地址： "<<&array_sort<<"排序前 数组内容："<<endl;
  for(int i=0;i<var_s;i++)
  {
    cout<<array_sort[i]<<"\t";
    if(i!=0&&(i+1)%10==0)
      cout<<endl;
  }
  cout<<endl;
  /*
  设置一个临时变量temp用来储存中间量
  5 4 3 2 1
  5->4 5->3 5->2 5->1 =>4 3 2 1 5 => 4->3 4->2 4->1  => 3 2 1 4 5
  => 3->2 3->1  =>2 1 3 4 5 => 2->1 =>1 2 3 4 5
  */
  for(int i=0;i<var_s-1;i++)
    for(int j=0;j<var_s-1-i;j++)
      if(array_sort[j]>array_sort[j+1])
      {
        temp=array_sort[j];
        array_sort[j]=array_sort[j+1];
        array_sort[j+1]=temp;
      }
    cout<<"排序后数组首地址："<<&array_sort<<"排序后 数组内容："<<endl;
    for(int i=0;i<var_s;i++)
    {
      cout<<array_sort[i]<<"\t";
      if(i!=0&&(i+1)%10==0)
        cout<<endl;
    }
    cout<<endl;
}
void dispaly_Array(void)//输出二维数组
{
  const int var_a=10;
  //初始化二维数组
  int array_a[var_a][var_a]={{0,1,2,3,4,5,6,7,8,9},{10,11,12,13,14,15,16,17,18,19}};
  for(int i=0;i<var_a;i++)
    {
      for(int j=0;j<var_a;j++)
      cout<<array_a[i][j]<<"\t";
    cout<<endl;
  }
}
void dispaly_char()
{
  const int char_n=9;
  char array_char[char_n]={'H','e','l','l','o','!','b','o','b'};
  //char_array_c[char_n]="Hello!bob"; 运行这句会出错，数组界溢出
  for(int i=0;i<char_n;i++)
    {
      cout<<array_char[i]<<"\t";
      //cout<<char_array_c[i]<<endl;
  }
  cout<<endl;
}
