#include<iostream>
#include<cstring>
#include<arpa/inet.h>
#define MAX_NAME 25
#define MAX_PASSWORD 18
using namespace std;
void get_uer();
void swap(int *a,int *d);
//结构体 共用体 指针(部分) 等练习
struct User
{
  char name[MAX_NAME];
  char password[MAX_PASSWORD];
};
struct sockaddr_11
{
   int addr_family;
   char addr_data[4];
};
union message
{
  char head[20];
  int age;
  float payment;
  char job[4][5];
};
struct Request{
  char Accept[100];
  char User_Agent[100];
  char Accept_Encoding[100];
  char Accept_Language[100];
  char Connection[100];
  char Host[100];
  char Cookie[100];
};
int main()
{
    User user_1[3]={{"BILIBILI","1234567"},{"FIREFOX","12131415"},
    {"google-chrome","1818181818"}};
    for(int i=0;i<3;i++)
    {
      cout<<"Usr name:"<<user_1[i].name<<endl;
      cout<<"password:"<<user_1[i].password<<endl;
    }
    struct sockaddr_11 ser_addr;
    ser_addr.addr_family=3;
    strcpy(ser_addr.addr_data,"127.0.0.1");
    cout<<"数据结构：sockeaddr_11 成员变量 addr_family="<<ser_addr.addr_family<<endl;
    cout<<"数据结构：sockeaddr_11 成员变量 addr_data="<<ser_addr.addr_data<<endl;
    cout<<"数据结构：sockeaddr_11 占用内存："<<sizeof(ser_addr)<<endl;
    //----------------------------------------------
    struct Request request;
    strcpy(request.Accept,"text/html,application/xhtml+xm…plication/xml;q=0.9,*/*;q=0.8");
    strcpy(request.User_Agent,"Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:59.0) Gecko/20100101 Firefox/59.0");
    strcpy(request.Accept_Encoding,"gzip, defla");
    strcpy(request.Accept_Language,"en-US,en;q=0.5");
    strcpy(request.Connection,"keep-aliv");
    strcpy(request.Cookie,"logged_in=yes; _ga=GA1.2.94545…om_user=yearinyearout; _gat=1");
    strcpy(request.Host,"assets-cdn.github.com");
    //----------------------------------------------
    cout<<"Host:"<<request.Host<<endl<<"Accept:"<<request.Accept<<endl
        <<"Accept-Encoding:"<<request.Accept_Encoding<<endl<<"Accept-Language:"
        <<request.Accept_Language<<endl<<"User-agent:"<<request.User_Agent<<endl
        <<"Connection:"<<request.Connection<<endl<<"Cookie:"<<request.Cookie<<endl;
    cout<<sizeof(request)<<endl;
    union  message msg;
    //----------------------------------------------
    strcpy(msg.head,"Hello World!");
    msg.age=1000;
    msg.payment=123,456;
    cout<<msg.head<<endl;//系统默认值
    cout<<msg.age<<endl;//系统默认值
    cout<<msg.payment<<endl;//正确输出值
    cout<<sizeof(msg)<<endl;//共用体最大存储单元
    char *p;
    p=request.Host;
    cout<<"P指向变量地址："<<&p<<endl<<"P指向变量值"<<*p<<endl<<endl;
    //利用for循环输出p指向的内容
    for(int i=0;i<strlen(request.Host);i++)
    {
    cout<<"P指向变量地址："<<&p<<endl<<"P指向变量值"<<*(p+i)<<endl;
    }
    int *q;
    q=&ser_addr.addr_family;
    cout<<q<<endl<<*q<<endl;
    int *point_1,*point_2;
    int var_1=100,var_2=1000;
    point_1=&var_1;
    point_2=&var_2;
    cout<<"转换前：var_1="<<var_1<<"\t var_2="<<var_2<<endl;
    swap(*point_1,*point_2);//调用函数
    cout<<"转换后： var_1="<<var_1<<"\t var_2="<<var_2<<endl;
    const char *name="hacker";//这里用const 的原因是： “ ”是一个字符串常量在之后的改变中会出错
    cout<<"对指针类型字符串进行赋值："<<name<<endl;
    name="hacking";
    cout<<"对指针类型字符串常量改变值："<<name<<endl;//对于指针类型居然是支持的
    return 0;
  }
void swap(int *a ,int *d) //传入指针参数，而指针指向变量，既而改变main函数中传递过来变量的值
{
  int temp; //定义临时变量 ，在函数运行完时，自动释放内存
  temp=*a;
  *a=*d;
  *d=temp;
}
