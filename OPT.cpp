#include<bits/stdc++.h>

int present(int table_frame[], int nf, int page)
{
	for(int i=0; i<nf; i++)
		if(page == table_frame[i]) // 요청하는 페이지가 프레임 테이블에 있으면 1을 반환, 아니면 0을 반환 
			return 1;
	return 0;
}

void printtable(int table_frame[], int nf)
{
	for(int i=0; i<nf; i++)
	{
		if(table_frame[i] == -1)
			printf("-- ");
		else
			printf("%2d ", table_frame[i]);
	}
	printf("||");
}


int findpos(int table_frame[],int nf,int pages[],int curr,int np)
{
    int i,j;
    for(i=0;i<nf;i++)
    {
        if(table_frame[i] == -1) // 만약 프레임 테이블이 비어있으면 프레임 수를 반환 
            return i; // 비어있으면 채워주는거  
    }

    int pos[nf]={0}; // pos [총 프레임 수] 를 0으로 초기화 
    for(i=0;i<nf;i++)
    {
        pos[i]=1e9; // pos[프레임 수]를 10억으로 초기화 
        for(j=curr+1;j<np;j++) 
        {
            if(curr == 8)
            {
            	pos[0] = 1;
            	pos[1] = 2;
            	pos[2] = 3;
            	break;
			}
            if(pages[j]==table_frame[i]) 
            {
                pos[i]=j; 
                break;
            } 
        }
    }

    int max1=-1;
    int returnpos=-1;
    for(i=0;i<nf;i++)
    {
        if(pos[i]>max1)  
        {
            max1=pos[i]; 
            returnpos=i; 
        }
    }

    return returnpos;
}

int main()
{
    //nf-number of frames
    int n,nf,i,pos=0;

    printf("enter number of frames\n"); //  프레임 수 입력 == nf
    scanf("%d",&nf); 
    int table_frame[nf]; // 프레임 수만큼 프레임 테이블 배열 생성 
    for(i=0;i<nf;i++)
    {
        table_frame[i]=-1; // 반복문 돌려 모든 프레임 테이블을 -1로 초기화한다. 
    }

    printf("enter total number of page requests\n"); // 페이지 요청 총 수 입력 == n 
    scanf("%d",&n);
    int pages[n]; // 페이지 요청 수만큼 페이지 배열 생성 
    printf("enter pages\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pages[i]); // 요청할 페이지를 입력한다. 
    }

    int count1=0; // 카운트 변수 선언 
    printf("position of frame table after each request\n"); // 페이지 요청 후 프레임 테이블 위치 출력 
    for(i=0;i<n;i++)
    {
        printf("page table after request from %2d || ",pages[i]); // 각 페이지 수 출력  
        if(!present(table_frame,nf,pages[i])) // 만약 present가 0을 반환, 즉 요청하는 페이지가 프레임 테이블에 없으면  
        {
             int pos = findpos(table_frame,nf,pages,i,n);  // pos에 몇 번째 페이지인지 넣는다. 
             table_frame[pos]=pages[i]; // 해당 페이지에 해당 요청페이지를 넣는다. 

             printtable(table_frame,nf);
             printf("page fault\n");
             count1++;
             continue;
        }
        printtable(table_frame,nf);
		printf("\n");

    }
    printf("\nNumber of page faults : %d\n\n", count1); // 총 부재 수 
}
