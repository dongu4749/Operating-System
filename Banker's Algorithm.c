/*
   Banker's Algorithm
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


int need[100],alloc[100],max[100],available,result=0;
bool finish[100];


/*
  Safety Algorithm:
  1) Let Work and Finish be vectors of length ‘m’ and ‘n’ respectively.
     Initialize: Work = Available
     Finish[i] = false; for i=1, 2, 3, 4….n
  2) Find an i such that both
     a) Finish[i] = false
     b) Needi <= Work if no such i exists goto step (4)
  3) Work = Work + Allocation
     Finish[i] = true
     goto step (2)
  4) if finish [i] = true for all i
     then the system is in a safe state otherwise unsafe state
*/
// need 기대자원 alloc 할당자원 max 최대선언자원 available 가용자원이지만 변수 finish[] 안정불안정을 위해 배열 선언 

void issafe(int N,int M)
{
   int i,work;
   bool canAllot=false;
      work=available;
   for(i=0;i<100;i++)
      finish[i]=false;    
      for(i=0;i<N;i++)
      {
       if(finish[i]==false)   
	   {
        if(work>=need[i])
        {
		 printf("system is safe");
		 canAllot = true;
		 finish[i]==true;
         break;  
		}
	  }
      }     
    if(canAllot == false)
      {	  
      printf("system is not safe");    
      }
}



int main()
{
    int n,m,i,j;

    printf("enter number of processes\n");
    scanf("%d",&n);

    printf("enter number of resources\n");
    scanf("%d",&m);

    printf("Enter the Allocation Matrix :\n");
    for(i=0;i<n;i++)
    {    
          printf("P%d ",i+1);
          scanf("%d",&alloc[i]);       
    }
    printf("Enter the matrix for maximum demand of each process :\n");
    for(i=0;i<n;i++)
    {
    	printf("P%d ",i+1);
        scanf("%d",&max[i]);      
    }
        //calculation of need matrix
    for(i=0;i<n;i++)
    {    
        need[i]=max[i]-alloc[i];
        
    }
    for(i=0;i<n;i++)
    {
    	result += alloc[i];   	
	}
	available = m - result;
    //to check safe or not
    printf("Total = %d ",m);
	printf("Available = %d \n",available);
	printf("Process  Max  Allocation  Expect \n");
	for(i=0;i<n;i++)
	{
		printf("  P%d  %6d  %6d  %6d \n",i+1,max[i],alloc[i],need[i]);
	}
    issafe(n,m);
    
   return 0;
}
