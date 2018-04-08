#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
  //练习基本数据类型
  int var_int=10;
  float var_float=10.1f;
  double var_double=10.0;
  long int var_lint=123456;
  const int amount(30);
  string sign_1(amount,'*');
  //........................
  cout<<sign_1<<endl;
  cout<<"Type\t\tSize\n"<<"int\t\t"<<sizeof(var_int)<<endl<<"float\t\t"
      <<sizeof(var_float)<<endl<<"double\t\t"<<sizeof(var_double)
      <<endl<<"long int\t"<<sizeof(var_lint)<<endl<<sign_1<<endl;
//前面了解了一下如何设这数据对齐问题  <iomanip> setiosflags(ios::value) setw(value)
  enum day{SAT,SUN,MON,TUE,WED,THU,FRI};
  cout<<SAT<<"\t"<<SUN<<"\t"<<MON<<"\t"<<TUE<<"\t"
      <<WED<<"\t"<<THU<<"\t"<<FRI<<endl;
  enum days{SAT_1=6,SUN_1=7,MON_1=1,TUE_1,WED_1,THU_1,FRI_1};
  cout<<SAT_1<<"\t"<<SUN_1<<"\t"<<MON_1<<"\t"<<TUE_1<<"\t"
      <<WED_1<<"\t"<<THU_1<<"\t"<<FRI_1<<endl;
  char var_a='a',var_10='10',var_0='0';
  cout<<var_a-var_10<<"\t"<<var_a+var_0<<"\t"<<var_0*var_10<<endl;
  /*这块出现警告warning: multi-character character constant [-Wmultichar]
  char var_a='a',var_10='10',var_0='0';
                       ^

    不同机器对于单引号包含多个字符会有不同的响应*/
  cout<<var_0<<"\t"<<var_a<<"\t"<<var_10<<endl;//显示var_10：0 突然意识到ASCII码只有0～9！
  //改进
  char var_b='b',var_9='9',var_3='3';
  cout<<var_b-var_9<<"\t"<<var_b+var_3<<"\t"<<var_3*var_9<<endl;
  cout<<var_b<<"\t"<<var_3<<"\t"<<var_9<<endl;//与预计结果一致
  //练习对string类型的使用
  string name="BOB";
  string::size_type name_size;
  size_t name_size_1=name.size();
  name_size=name.size();
  cout<<name<<"\t"<<name_size<<"\t"<<name_size_1<<endl;
  cout<<name[0]<<"\t"<<name[2]<<endl;
  string greet("Hello, what are you like to do");
  cout<<greet+"?"+"\nI like code."<<endl;
  //string 类型可以与字符串常量连接
  string end_tag(50,'-');
  cout<<end_tag<<endl<<end_tag<<endl;
  //----------------运算符练习-----------------------------------
  const long double PI=3.1415926L;
  float radius;
  double area;
  cout<<"Please enter the radius :  ";
  cin>>radius;
  area=radius*radius*PI;
  cout<<setprecision(10)<<area<<endl;
  //cout默认输出精度6位 setprecision(value) 设置精度显示
  //test
  cout<<setprecision(10)<<PI<<"\t"<<radius<<endl;
  int var_x=10,var_y=30;
  cout<<var_x+++var_y<<endl;//期望输出40  结果正确  此时var_x =11;
  //编译器会根据最大化读取字符和已读取的组成有意义的符号，所以先var_x++ + var_y
  //大写转换小写
  char var_char;
  cin>>var_char;
  cout<<char(var_char+32)<<endl;
//调用函数转换大小写
  cout<<char(tolower(var_char))<<endl;
  cout<<char(toupper(var_char))<<endl;
//三目运算符
  cout<<"max:"<<(var_x>var_y?var_x:var_y)<<endl;
//逗号运算符
  int var_m;
  var_m=(var_x++,var_x*2,++var_y,var_x*var_y);//预计11 12*2 31 31*12=372
  cout<<var_m<<"\t"<<var_x<<"\t"<<var_y<<endl;
//----练习cmath----
  int var_i,var_ii,var_iii;
  cout<<"请一次输入A,B,C (用空格分割):";
  cin>>var_i>>var_ii>>var_iii;
  var_iii=sqrt(abs(var_i)+pow(var_ii,3));
  cout<<var_iii<<endl;
//逻辑运算符
  bool F=false,T=true;
  cout<<F<<"\t"<<T<<endl;
  cout<<(F&&T)<<"\t"<<(!F||T)<<endl;
  cout<<(F==T)<<"\t"<<(F<=T)<<"\t"<<(F>=T)<<endl;
//引用
  int age=22;
  int &age_1=age;
  cout<<age<<"\t"<<age_1<<endl;
  age_1=222;
  cout<<age<<"\t"<<age_1<<endl;
  const string greet_1="Hello  World!";
  const string &greet_2=greet_1;
  cout<<greet_1<<endl<<greet_2<<endl;
  cout<<end_tag<<endl<<end_tag<<endl;
  cout<<setiosflags(ios::right)<<setw(200)<<"THE END!"<<endl;
  return 0;
}
