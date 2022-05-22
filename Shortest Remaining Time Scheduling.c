#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
void gotoxy(int x,int y)
{
	COORD Pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

//gotoxy() = 커서 위치를 이동시키는 함수
//delay() = 프로그램 실행을 지연 
//clsrcr() = 콘솔 화면을 클리어하는 함수
void delay(int x)
{
	Sleep(x);
}

void clsrcr(void)
{

//n = 프로세스의 개수 저장
//b[10] = 작업시간 저장
//w[10] = 대기시간 저장
//i,j = for문에 사용
//h = ‘ㅜ’에 해당하는 아스키코드 번호 저장
//t = 프로세스 위치 변경을 위한 임시변수 저장
//tt = 프로세스 위치 변경을 위한 임시변수 저장
//a[10] = 프로세스의 번호 저장
//avg = 누적 대기시간
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

//콘솔 화면을 클리어 한 후 n에 일의 개수를 입력받는다.
//for문을 돌려서 배열b[]에 각 일의 실행시간을 입력받고 배열 a[]에 프로세스 번호를 저장한다.
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

//임시변수 t,tt를 사용하여 프로세스의 작업시간이  짧으면 앞으로 보내 우선처리되게 한다.
// w[1] = 0을 통해 처음 처리되는 프로세스의 대기시간은 0으로 설정한다. 
		      b[j]=t;     a[j]=tt;
		      }

 w[1]=0;  


 printf("\nprocess %d waiting time is 0",a[1]); 

 for(i=2;i<=n;i++)
 {
  w[i]=b[i-1]+w[i-1]; // 이전 대기시간을 더해서 다음 대기시간을 구함, 또한 이 코드는 w배열에 대기시간을 저장한다. 
  printf("\nProcess %d waiting time: %d",a[i],w[i]); // 프로세스 이름, 프로세스 대기시간 
  avg+=w[i];// 총 대기시간을 구함 
 }
 printf("\ntotal waiting time:%f",avg);
 printf("\n\nthe average waiting time is:%f\n",avg/n);
 printf("\nGaunt Chart\n***************************************\n\n\t");


//배열w[]에 이전 대기시간을 더해서 다음 대기시간을    구한다. 또한 배열w[]에 대기시간을 저장한다.
//avg에 배열w[]을 더해 총 대기시간을 구한다.
 h=22;

 for(i=1;i<=n;i++)
 {
  printf("%d",a[i]);
  for(j=1;j<=b[i];j++)
   printf("%c",h);
 }
 printf("\n\t");

//총 대기시간과 평균대기시간을 출력한다.
//for문을 돌려 작업시간과 대기시간만큼 ‘ㅜ’를 출력한다.

 for(i=1;i<=n;i++)
 {
  printf("%d",a[i]);
  for(j=1;j<=w[i];j++)
   printf("%c",h);
  delay(1000);
 }

getch();
}
