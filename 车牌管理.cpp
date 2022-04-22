#include<cstdio>
#include<cmath>
#include <string>
#include<cstdlib>
#include<iostream>
#include<time.h>
using namespace std;
#define MAX 10000
#define MAX1 20000
//定义车牌信息结构体
typedef struct node{
char eng,chi[5];
int num;
}key;
int n[34];//全局变量，存放各省车牌数量
key sf[34][MAX];//全局变量，存放车牌信息，最大可存放34*MAX；
key resf[MAX];//存放新添加车牌信息
int number=MAX;//全局变量，表示车牌数量
int number_=0;//全局变量，表示新添加车牌数
//车牌排序函数
void sort(key* k){
 for(int i=0;i<34;i++)
	n[i]=0;
 for(int i=0;i<number;i++)
 {
	 if(strcmp(k[i].chi,"皖")==0){sf[0][n[0]]=k[i],n[0]++;}
	 else if(strcmp(k[i].chi,"澳")==0){sf[1][n[1]]=k[i],n[1]++;}
	 else if(strcmp(k[i].chi,"京")==0){sf[2][n[2]]=k[i],n[2]++;}
	 else if(strcmp(k[i].chi,"渝")==0){sf[3][n[3]]=k[i],n[3]++;}
	 else if(strcmp(k[i].chi,"闽")==0){sf[4][n[4]]=k[i],n[4]++;}
	 else if(strcmp(k[i].chi,"甘")==0){sf[5][n[5]]=k[i],n[5]++;}
	 else if(strcmp(k[i].chi,"粤")==0){sf[6][n[6]]=k[i],n[6]++;}
	 else if(strcmp(k[i].chi,"桂")==0){sf[7][n[7]]=k[i],n[7]++;}
	 else if(strcmp(k[i].chi,"贵")==0){sf[8][n[8]]=k[i],n[8]++;}
	 else if(strcmp(k[i].chi,"港")==0){sf[9][n[9]]=k[i],n[9]++;}
	 else if(strcmp(k[i].chi,"琼")==0){sf[10][n[10]]=k[i],n[10]++;}
	 else if(strcmp(k[i].chi,"冀")==0){sf[11][n[11]]=k[i],n[11]++;}
	 else if(strcmp(k[i].chi,"豫")==0){sf[12][n[12]]=k[i],n[12]++;}
	 else if(strcmp(k[i].chi,"黑")==0){sf[13][n[13]]=k[i],n[13]++;}
	 else if(strcmp(k[i].chi,"鄂")==0){sf[14][n[14]]=k[i],n[14]++;}
	 else if(strcmp(k[i].chi,"湘")==0){sf[15][n[15]]=k[i],n[15]++;}
	 else if(strcmp(k[i].chi,"赣")==0){sf[16][n[16]]=k[i],n[16]++;}
	 else if(strcmp(k[i].chi,"吉")==0){sf[17][n[17]]=k[i],n[17]++;}
	 else if(strcmp(k[i].chi,"苏")==0){sf[18][n[18]]=k[i],n[18]++;}
	 else if(strcmp(k[i].chi,"辽")==0){sf[19][n[19]]=k[i],n[19]++;}
	 else if(strcmp(k[i].chi,"蒙")==0){sf[20][n[20]]=k[i],n[20]++;}
	 else if(strcmp(k[i].chi,"宁")==0){sf[21][n[21]]=k[i],n[21]++;}
	 else if(strcmp(k[i].chi,"青")==0){sf[22][n[22]]=k[i],n[22]++;}
	 else if(strcmp(k[i].chi,"晋")==0){sf[23][n[23]]=k[i],n[23]++;}
	 else if(strcmp(k[i].chi,"鲁")==0){sf[24][n[24]]=k[i],n[24]++;}
	 else if(strcmp(k[i].chi,"陕")==0){sf[25][n[25]]=k[i],n[25]++;}
	 else if(strcmp(k[i].chi,"沪")==0){sf[26][n[26]]=k[i],n[26]++;}
	 else if(strcmp(k[i].chi,"川")==0){sf[27][n[27]]=k[i],n[27]++;}
	 else if(strcmp(k[i].chi,"津")==0){sf[28][n[28]]=k[i],n[28]++;}
	 else if(strcmp(k[i].chi,"台")==0){sf[29][n[29]]=k[i],n[29]++;}
	 else if(strcmp(k[i].chi,"藏")==0){sf[30][n[30]]=k[i],n[30]++;}
	 else if(strcmp(k[i].chi,"新")==0){sf[31][n[31]]=k[i],n[31]++;}
	 else if(strcmp(k[i].chi,"云")==0){sf[32][n[32]]=k[i],n[32]++;}
	 else if(strcmp(k[i].chi,"浙")==0){sf[33][n[33]]=k[i],n[33]++;}
}
 //选择排序
 for(int i=0;i<34;i++)
 {
	 for(int j=0;j<n[i];j++)
		 for(int r=j;r<n[i];r++)
			 if(sf[i][j].eng>sf[i][r].eng)
			 {
				 key t=sf[i][j];
				 sf[i][j]=sf[i][r];
				 sf[i][r]=t;
			 }
     for(int j=0;j<n[i];j++)
		 for(int r=j;r<n[i];r++)
			 if(sf[i][j].num>sf[i][r].num&&sf[i][j].eng==sf[i][r].eng)
			 {
				 key t=sf[i][j];
				 sf[i][j]=sf[i][r];
				 sf[i][r]=t;
			 }
 }
}
 //随机生成10000个车牌号
 void creat_k(key *&k){
 k=new key[MAX1];
char s2[26]={'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
for(int i=0,r=0;i<MAX;i++)
{
	if(i%2==0)
	    strcpy(k[i].chi,"辽");
	else if(i%3==0)
		strcpy(k[i].chi,"京");
	else if(i%5==0)
		strcpy(k[i].chi,"甘");
	else if(i%7==0)
		strcpy(k[i].chi,"沪");
	else
		strcpy(k[i].chi,"陕");
	k[i].eng=s2[r];
	r++;
	if(r==26)r=0;
}
for(int i=0,q=0,w=0,e=1,r=1,t=0;i<MAX;i++)
{
	//生成随机数
	int sum;
	sum=q*10000+w*1000+e*100+r*10+t;
	k[i].num=sum;
	q++,w++,e++,r++,t++;
	if(q==10)q=0;
	if(w==9)w=0;
	if(e==8)e=0;
	if(r==9)r=0;
	if(t==10)t=0;
}
 }
 //添加车牌信息
 void recreat_k(key *&k){
 cout<<"请输入需要添加的车牌数量："<<endl;
 int n;
 cin>>n;

 if(number_>=MAX)
 {
	 cout<<"超出存储范围！！"<<endl;
	 return;
 }
 cout<<"请输入车牌号：（汉字和字母之间需要保留空格，参考样式：京 B12345）"<<endl;
 for(int i=0;i<n;i++)
 {
	 cin>>resf[number_].chi>>resf[number_].eng>>resf[number_].num;
	 number_++;
 }
 cout<<"添加成功！"<<endl;
 }
 //返回所查找车牌对应下标函数
 int find_(char *c){
     if(strcmp(c,"皖")==0){return 0;}
     else if(strcmp(c,"澳")==0){return 1;}
	 else if(strcmp(c,"京")==0){return 2;}
	 else if(strcmp(c,"渝")==0){return 3;}
	 else if(strcmp(c,"闽")==0){return 4;}
	 else if(strcmp(c,"甘")==0){return 5;}
	 else if(strcmp(c,"粤")==0){return 6;}
	 else if(strcmp(c,"桂")==0){return 7;}
	 else if(strcmp(c,"贵")==0){return 8;}
	 else if(strcmp(c,"港")==0){return 9;}
	 else if(strcmp(c,"琼")==0){return 10;}
	 else if(strcmp(c,"冀")==0){return 11;}
	 else if(strcmp(c,"豫")==0){return 12;}
	 else if(strcmp(c,"黑")==0){return 13;}
	 else if(strcmp(c,"鄂")==0){return 14;}
	 else if(strcmp(c,"湘")==0){return 15;}
	 else if(strcmp(c,"赣")==0){return 16;}
	 else if(strcmp(c,"吉")==0){return 17;}
	 else if(strcmp(c,"苏")==0){return 18;}
	 else if(strcmp(c,"辽")==0){return 19;}
	 else if(strcmp(c,"蒙")==0){return 20;}
	 else if(strcmp(c,"宁")==0){return 21;}
	 else if(strcmp(c,"青")==0){return 22;}
	 else if(strcmp(c,"晋")==0){return 23;}
	 else if(strcmp(c,"鲁")==0){return 24;}
	 else if(strcmp(c,"陕")==0){return 25;}
	 else if(strcmp(c,"沪")==0){return 26;}
	 else if(strcmp(c,"川")==0){return 27;}
	 else if(strcmp(c,"津")==0){return 28;}
	 else if(strcmp(c,"台")==0){return 29;}
	 else if(strcmp(c,"藏")==0){return 30;}
	 else if(strcmp(c,"新")==0){return 31;}
	 else if(strcmp(c,"云")==0){return 32;}
	 else if(strcmp(c,"浙")==0){return 33;}
	 else
		 return 34;
 }
 //折半查找函数
 void bs_num(int add,int a1,int a2,int goal,int &result){
 while(a1<=a2)
 {
	 int mid=a1+(a2-a1)/2;
	 if(sf[add][mid].num>goal)
		 a2=mid-1;
	 else if(sf[add][mid].num<goal)
		 a1=mid+1;
	 else 
	 {
		 result=mid;
		 return;
	 }
 }
 }
 //查找自动生成的车牌信息
 void find1(int add,key qq){
 int num=n[add],a1=0,a2=0;
 for(int i=0;i<num;i++)
 {
	 if(sf[add][i].eng==qq.eng)
	 {
		 a1=i;
		 int j;
		 for(j=i;j<num;j++)
		 if(sf[add][j].eng!=qq.eng)
		 {
			 a2=j-1;
			 break;
		 }
		 if(j>=num)
			 a2=num-1;
		     break;

	 }
 }
 if(a1==a2)
 {
lala:cout<<"信息不存在！"<<endl;
	 cout<<"添加此信息输入1，结束输入0；"<<endl;
	 int q;
	 cin>>q;
	 if(q==0)return;
	 if(q==1)
	 {
		 resf[number_]=qq;
		 number_++;
		 cout<<"添加成功！"<<endl;
	 }
	 return;
 }
 int result=0;
 bs_num(add,a1,a2,qq.num,result);
 if(result==0)
	 goto lala;
 else
 {
	 cout<<"查询成功，详细信息如下："<<endl;
	 cout<<"车牌号："<<sf[add][result].chi<<' '<<sf[add][result].eng<<sf[add][result].num<<endl;
	 cout<<"其他信息："<<endl;
 }
 }
 //查找添加的车牌信息
 int find2(key qq){
 if(number_==0)return 0;
 for(int i=0;i<number_;i++)
 {
	 if(strcmp(resf[i].chi,qq.chi)==0&&resf[i].eng==qq.eng&&resf[i].num==qq.num)
	 {
		 cout<<"查询成功，详细信息如下："<<endl;
	     cout<<"车牌号："<<qq.chi<<' '<<qq.eng;
			 if(qq.num/1000>0&&qq.num/1000<=9)
				 cout<<"0"<<qq.num<<endl;
			 else if(qq.num/100>0&&qq.num/100<=9)
				 cout<<"00"<<qq.num<<endl;
			 else if(qq.num/10>0&&qq.num/10<=9)
				 cout<<"000"<<qq.num<<endl;
			 else if(qq.num/1>0&&qq.num/1<=9)
				 cout<<"0000"<<qq.num<<endl;
			 else
			     cout<<qq.num<<endl;
	     cout<<"其他信息："<<endl;
		 return 1;
	 }
 }
 return 0;
 }
 //查找车牌信息
 void find(key *k){
 cout<<"请输入您需要查询的车牌号码：(参考格式：京 B12345)"<<endl;
 int add;
 key q;
 cin>>q.chi>>q.eng>>q.num;
 add=find_(q.chi);
 if(add==34)
	 cout<<"输入格式错误，参考格式：京 B12345"<<endl;
 int t=find2(q);
 if(t==0)
 find1(add,q);
 }
int main(){
	cout<<"***************************************** 车牌管理系统：实现车牌信息的录入与查询 **************************************"<<endl;
	cout<<"（操作说明：此系统车牌组成方式为各省份简称+所在市代表字母+五位数字，如：京 B12345，需注意汉字和字母之间需保留空格）"<<endl;
key *k;
creat_k(k);
sort(k);//调用排序函数
//cout<<sf[5][3].eng<<sf[5][3].num<<' '<<sf[5][5].eng<<sf[5][5].num<<endl;
delete(k);//释放动态内存
begin:cout<<"请选择您需要操作的项目："<<endl;
cout<<"1.添加车牌信息"<<endl<<"2.查询车牌信息"<<endl;
int q;
cin>>q;
if(q==1)
	recreat_k(k);
else if(q==2)
	find(k);
else
	cout<<"输入数据无效，请重新输入"<<endl;
cout<<"继续操作输入1,结束输入0："<<endl;
int w;
cin>>w;
if(w==1)
	goto begin;
return 0;
}
