#include<cstdio>
#include<cmath>
#include <string>
#include<cstdlib>
#include<iostream>
#include<time.h>
using namespace std;
#define MAX 10000
#define MAX1 20000
//���峵����Ϣ�ṹ��
typedef struct node{
char eng,chi[5];
int num;
}key;
int n[34];//ȫ�ֱ�������Ÿ�ʡ��������
key sf[34][MAX];//ȫ�ֱ�������ų�����Ϣ�����ɴ��34*MAX��
key resf[MAX];//�������ӳ�����Ϣ
int number=MAX;//ȫ�ֱ�������ʾ��������
int number_=0;//ȫ�ֱ�������ʾ����ӳ�����
//����������
void sort(key* k){
 for(int i=0;i<34;i++)
	n[i]=0;
 for(int i=0;i<number;i++)
 {
	 if(strcmp(k[i].chi,"��")==0){sf[0][n[0]]=k[i],n[0]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[1][n[1]]=k[i],n[1]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[2][n[2]]=k[i],n[2]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[3][n[3]]=k[i],n[3]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[4][n[4]]=k[i],n[4]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[5][n[5]]=k[i],n[5]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[6][n[6]]=k[i],n[6]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[7][n[7]]=k[i],n[7]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[8][n[8]]=k[i],n[8]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[9][n[9]]=k[i],n[9]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[10][n[10]]=k[i],n[10]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[11][n[11]]=k[i],n[11]++;}
	 else if(strcmp(k[i].chi,"ԥ")==0){sf[12][n[12]]=k[i],n[12]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[13][n[13]]=k[i],n[13]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[14][n[14]]=k[i],n[14]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[15][n[15]]=k[i],n[15]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[16][n[16]]=k[i],n[16]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[17][n[17]]=k[i],n[17]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[18][n[18]]=k[i],n[18]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[19][n[19]]=k[i],n[19]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[20][n[20]]=k[i],n[20]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[21][n[21]]=k[i],n[21]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[22][n[22]]=k[i],n[22]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[23][n[23]]=k[i],n[23]++;}
	 else if(strcmp(k[i].chi,"³")==0){sf[24][n[24]]=k[i],n[24]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[25][n[25]]=k[i],n[25]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[26][n[26]]=k[i],n[26]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[27][n[27]]=k[i],n[27]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[28][n[28]]=k[i],n[28]++;}
	 else if(strcmp(k[i].chi,"̨")==0){sf[29][n[29]]=k[i],n[29]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[30][n[30]]=k[i],n[30]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[31][n[31]]=k[i],n[31]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[32][n[32]]=k[i],n[32]++;}
	 else if(strcmp(k[i].chi,"��")==0){sf[33][n[33]]=k[i],n[33]++;}
}
 //ѡ������
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
 //�������10000�����ƺ�
 void creat_k(key *&k){
 k=new key[MAX1];
char s2[26]={'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
for(int i=0,r=0;i<MAX;i++)
{
	if(i%2==0)
	    strcpy(k[i].chi,"��");
	else if(i%3==0)
		strcpy(k[i].chi,"��");
	else if(i%5==0)
		strcpy(k[i].chi,"��");
	else if(i%7==0)
		strcpy(k[i].chi,"��");
	else
		strcpy(k[i].chi,"��");
	k[i].eng=s2[r];
	r++;
	if(r==26)r=0;
}
for(int i=0,q=0,w=0,e=1,r=1,t=0;i<MAX;i++)
{
	//���������
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
 //��ӳ�����Ϣ
 void recreat_k(key *&k){
 cout<<"��������Ҫ��ӵĳ���������"<<endl;
 int n;
 cin>>n;

 if(number_>=MAX)
 {
	 cout<<"�����洢��Χ����"<<endl;
	 return;
 }
 cout<<"�����복�ƺţ������ֺ���ĸ֮����Ҫ�����ո񣬲ο���ʽ���� B12345��"<<endl;
 for(int i=0;i<n;i++)
 {
	 cin>>resf[number_].chi>>resf[number_].eng>>resf[number_].num;
	 number_++;
 }
 cout<<"��ӳɹ���"<<endl;
 }
 //���������ҳ��ƶ�Ӧ�±꺯��
 int find_(char *c){
     if(strcmp(c,"��")==0){return 0;}
     else if(strcmp(c,"��")==0){return 1;}
	 else if(strcmp(c,"��")==0){return 2;}
	 else if(strcmp(c,"��")==0){return 3;}
	 else if(strcmp(c,"��")==0){return 4;}
	 else if(strcmp(c,"��")==0){return 5;}
	 else if(strcmp(c,"��")==0){return 6;}
	 else if(strcmp(c,"��")==0){return 7;}
	 else if(strcmp(c,"��")==0){return 8;}
	 else if(strcmp(c,"��")==0){return 9;}
	 else if(strcmp(c,"��")==0){return 10;}
	 else if(strcmp(c,"��")==0){return 11;}
	 else if(strcmp(c,"ԥ")==0){return 12;}
	 else if(strcmp(c,"��")==0){return 13;}
	 else if(strcmp(c,"��")==0){return 14;}
	 else if(strcmp(c,"��")==0){return 15;}
	 else if(strcmp(c,"��")==0){return 16;}
	 else if(strcmp(c,"��")==0){return 17;}
	 else if(strcmp(c,"��")==0){return 18;}
	 else if(strcmp(c,"��")==0){return 19;}
	 else if(strcmp(c,"��")==0){return 20;}
	 else if(strcmp(c,"��")==0){return 21;}
	 else if(strcmp(c,"��")==0){return 22;}
	 else if(strcmp(c,"��")==0){return 23;}
	 else if(strcmp(c,"³")==0){return 24;}
	 else if(strcmp(c,"��")==0){return 25;}
	 else if(strcmp(c,"��")==0){return 26;}
	 else if(strcmp(c,"��")==0){return 27;}
	 else if(strcmp(c,"��")==0){return 28;}
	 else if(strcmp(c,"̨")==0){return 29;}
	 else if(strcmp(c,"��")==0){return 30;}
	 else if(strcmp(c,"��")==0){return 31;}
	 else if(strcmp(c,"��")==0){return 32;}
	 else if(strcmp(c,"��")==0){return 33;}
	 else
		 return 34;
 }
 //�۰���Һ���
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
 //�����Զ����ɵĳ�����Ϣ
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
lala:cout<<"��Ϣ�����ڣ�"<<endl;
	 cout<<"��Ӵ���Ϣ����1����������0��"<<endl;
	 int q;
	 cin>>q;
	 if(q==0)return;
	 if(q==1)
	 {
		 resf[number_]=qq;
		 number_++;
		 cout<<"��ӳɹ���"<<endl;
	 }
	 return;
 }
 int result=0;
 bs_num(add,a1,a2,qq.num,result);
 if(result==0)
	 goto lala;
 else
 {
	 cout<<"��ѯ�ɹ�����ϸ��Ϣ���£�"<<endl;
	 cout<<"���ƺţ�"<<sf[add][result].chi<<' '<<sf[add][result].eng<<sf[add][result].num<<endl;
	 cout<<"������Ϣ��"<<endl;
 }
 }
 //������ӵĳ�����Ϣ
 int find2(key qq){
 if(number_==0)return 0;
 for(int i=0;i<number_;i++)
 {
	 if(strcmp(resf[i].chi,qq.chi)==0&&resf[i].eng==qq.eng&&resf[i].num==qq.num)
	 {
		 cout<<"��ѯ�ɹ�����ϸ��Ϣ���£�"<<endl;
	     cout<<"���ƺţ�"<<qq.chi<<' '<<qq.eng;
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
	     cout<<"������Ϣ��"<<endl;
		 return 1;
	 }
 }
 return 0;
 }
 //���ҳ�����Ϣ
 void find(key *k){
 cout<<"����������Ҫ��ѯ�ĳ��ƺ��룺(�ο���ʽ���� B12345)"<<endl;
 int add;
 key q;
 cin>>q.chi>>q.eng>>q.num;
 add=find_(q.chi);
 if(add==34)
	 cout<<"�����ʽ���󣬲ο���ʽ���� B12345"<<endl;
 int t=find2(q);
 if(t==0)
 find1(add,q);
 }
int main(){
	cout<<"***************************************** ���ƹ���ϵͳ��ʵ�ֳ�����Ϣ��¼�����ѯ **************************************"<<endl;
	cout<<"������˵������ϵͳ������ɷ�ʽΪ��ʡ�ݼ��+�����д�����ĸ+��λ���֣��磺�� B12345����ע�⺺�ֺ���ĸ֮���豣���ո�"<<endl;
key *k;
creat_k(k);
sort(k);//����������
//cout<<sf[5][3].eng<<sf[5][3].num<<' '<<sf[5][5].eng<<sf[5][5].num<<endl;
delete(k);//�ͷŶ�̬�ڴ�
begin:cout<<"��ѡ������Ҫ��������Ŀ��"<<endl;
cout<<"1.��ӳ�����Ϣ"<<endl<<"2.��ѯ������Ϣ"<<endl;
int q;
cin>>q;
if(q==1)
	recreat_k(k);
else if(q==2)
	find(k);
else
	cout<<"����������Ч������������"<<endl;
cout<<"������������1,��������0��"<<endl;
int w;
cin>>w;
if(w==1)
	goto begin;
return 0;
}
