#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
void gotoxy(int x,int y)
{
	COORD Pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

//gotoxy() = Ŀ�� ��ġ�� �̵���Ű�� �Լ�
//delay() = ���α׷� ������ ���� 
//clsrcr() = �ܼ� ȭ���� Ŭ�����ϴ� �Լ�
void delay(int x)
{
	Sleep(x);
}

void clsrcr(void)
{

//n = ���μ����� ���� ����
//b[10] = �۾��ð� ����
//w[10] = ���ð� ����
//i,j = for���� ���
//h = ���̡��� �ش��ϴ� �ƽ�Ű�ڵ� ��ȣ ����
//t = ���μ��� ��ġ ������ ���� �ӽú��� ����
//tt = ���μ��� ��ġ ������ ���� �ӽú��� ����
//a[10] = ���μ����� ��ȣ ����
//avg = ���� ���ð�
	int i;
	for(i=0;i<1;i++)
	{
		gotoxy(0,i);
		printf("%80c",' ');
	}
}
void main()
{
 int n,b[10],w[10],i,j,h,t,tt;
 int a[10];
 float avg=0;
 clsrcr();
 printf("\n\tJOB SCHEDULING ALGORITHM[SJF]");
 printf("\n\t*****************************************************\n");
 printf("\nEnter howmany jobs:");
 scanf("%d",&n); 
 printf("\nEnter burst time for corresponding job....\n");

//�ܼ� ȭ���� Ŭ���� �� �� n�� ���� ������ �Է¹޴´�.
//for���� ������ �迭b[]�� �� ���� ����ð��� �Է¹ް� �迭 a[]�� ���μ��� ��ȣ�� �����Ѵ�.
 for(i=1;i<=n;i++)
 {
  printf("\nProcess %d:",i);
  scanf("%d",&b[i]);  
  a[i]=i;  
 }
	for(i=1;i<=n;i++)
		   for(j=i;j<=n;j++)
		      if(b[i]>b[j]) 
		      {
		      t=b[i]; tt=a[i];  
		      b[i]=b[j];  a[i]=a[j];

//�ӽú��� t,tt�� ����Ͽ� ���μ����� �۾��ð���  ª���� ������ ���� �켱ó���ǰ� �Ѵ�.
// w[1] = 0�� ���� ó�� ó���Ǵ� ���μ����� ���ð��� 0���� �����Ѵ�. 
		      b[j]=t;     a[j]=tt;
		      }

 w[1]=0;  


 printf("\nprocess %d waiting time is 0",a[1]); 

 for(i=2;i<=n;i++)
 {
  w[i]=b[i-1]+w[i-1]; // ���� ���ð��� ���ؼ� ���� ���ð��� ����, ���� �� �ڵ�� w�迭�� ���ð��� �����Ѵ�. 
  printf("\nProcess %d waiting time: %d",a[i],w[i]); // ���μ��� �̸�, ���μ��� ���ð� 
  avg+=w[i];// �� ���ð��� ���� 
 }
 printf("\ntotal waiting time:%f",avg);
 printf("\n\nthe average waiting time is:%f\n",avg/n);
 printf("\nGaunt Chart\n***************************************\n\n\t");


//�迭w[]�� ���� ���ð��� ���ؼ� ���� ���ð���    ���Ѵ�. ���� �迭w[]�� ���ð��� �����Ѵ�.
//avg�� �迭w[]�� ���� �� ���ð��� ���Ѵ�.
 h=22;

 for(i=1;i<=n;i++)
 {
  printf("%d",a[i]);
  for(j=1;j<=b[i];j++)
   printf("%c",h);
 }
 printf("\n\t");

//�� ���ð��� ��մ��ð��� ����Ѵ�.
//for���� ���� �۾��ð��� ���ð���ŭ ���̡��� ����Ѵ�.

 for(i=1;i<=n;i++)
 {
  printf("%d",a[i]);
  for(j=1;j<=w[i];j++)
   printf("%c",h);
  delay(1000);
 }

getch();
}
