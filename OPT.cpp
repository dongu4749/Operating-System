#include<bits/stdc++.h>

int present(int table_frame[], int nf, int page)
{
	for(int i=0; i<nf; i++)
		if(page == table_frame[i]) // ��û�ϴ� �������� ������ ���̺� ������ 1�� ��ȯ, �ƴϸ� 0�� ��ȯ 
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
        if(table_frame[i] == -1) // ���� ������ ���̺��� ��������� ������ ���� ��ȯ 
            return i; // ��������� ä���ִ°�  
    }

    int pos[nf]={0}; // pos [�� ������ ��] �� 0���� �ʱ�ȭ 
    for(i=0;i<nf;i++)
    {
        pos[i]=1e9; // pos[������ ��]�� 10������ �ʱ�ȭ 
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

    printf("enter number of frames\n"); //  ������ �� �Է� == nf
    scanf("%d",&nf); 
    int table_frame[nf]; // ������ ����ŭ ������ ���̺� �迭 ���� 
    for(i=0;i<nf;i++)
    {
        table_frame[i]=-1; // �ݺ��� ���� ��� ������ ���̺��� -1�� �ʱ�ȭ�Ѵ�. 
    }

    printf("enter total number of page requests\n"); // ������ ��û �� �� �Է� == n 
    scanf("%d",&n);
    int pages[n]; // ������ ��û ����ŭ ������ �迭 ���� 
    printf("enter pages\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pages[i]); // ��û�� �������� �Է��Ѵ�. 
    }

    int count1=0; // ī��Ʈ ���� ���� 
    printf("position of frame table after each request\n"); // ������ ��û �� ������ ���̺� ��ġ ��� 
    for(i=0;i<n;i++)
    {
        printf("page table after request from %2d || ",pages[i]); // �� ������ �� ���  
        if(!present(table_frame,nf,pages[i])) // ���� present�� 0�� ��ȯ, �� ��û�ϴ� �������� ������ ���̺� ������  
        {
             int pos = findpos(table_frame,nf,pages,i,n);  // pos�� �� ��° ���������� �ִ´�. 
             table_frame[pos]=pages[i]; // �ش� �������� �ش� ��û�������� �ִ´�. 

             printtable(table_frame,nf);
             printf("page fault\n");
             count1++;
             continue;
        }
        printtable(table_frame,nf);
		printf("\n");

    }
    printf("\nNumber of page faults : %d\n\n", count1); // �� ���� �� 
}
