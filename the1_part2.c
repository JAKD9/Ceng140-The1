#include <stdio.h>


void rabbit_path1(int a1[][100], int a2[][100], int x, int y,int N)
{
int c;
c=a1[x][y];
if(x<N&&y<N)
{	
	if(c+a2[x+1][y]>=a1[x+1][y])
	{
		a1[x+1][y]=c+a2[x+1][y];
	}
	if(c+a2[x][y+1]>=a1[x][y+1])
	{
		a1[x][y+1]=c+a2[x][y+1];
	}	
	rabbit_path1(a1,a2,x+1,y,N);
	rabbit_path1(a1,a2,x,y+1,N);

}
}

void rabbit_path2(int a3[][100], char a4[], int x, int y, int time)
{
	if(x>=0&&y>=0)
	{
		
		/*printf("%d   %d  \n",x,y);*/
		if(y-1<0)
		{
			a4[time-1]='S';
			rabbit_path2(a3,a4,x-1,y,time-1);
		}
		else if(x-1<0)
		{
			a4[time-1]='E';
			rabbit_path2(a3,a4,x,y-1,time-1);
		}
		else if(a3[x-1][y]>=a3[x][y-1])
		{
			a4[time-1]='S';
			rabbit_path2(a3,a4,x-1,y,time-1);	
		}
		else if(a3[x-1][y]<a3[x][y-1])
		{
			a4[time-1]='E';
			rabbit_path2(a3,a4,x,y-1,time-1);
		}
	}	


}
void printer(char a5[], int N, int i)
{
	if(i<N)
	{
		printf("%c ",a5[i]);
		printer(a5,N,i+1);
	}
	
}

int main()
{
int array1[100][100];
int array2[100][100];
char array3[198];
int size;
int i,j,c;
scanf("%d",&size);
for(i=0;i<size;i++)
{
	for(j=0;j<size;j++)
	{
		scanf("%d ",&c);
		array1[i][j]=c;
		array2[i][j]=c;
	}
}
rabbit_path1(array1,array2,0,0,size);
rabbit_path2(array1,array3,size-1,size-1,2*size-2);
printer(array3,2*size-2,0);
printf(", final energy: %d\n",40*array1[size-1][size-1]);
return 0;
}



