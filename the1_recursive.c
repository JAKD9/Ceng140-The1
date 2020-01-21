#include <stdio.h>


int recurcive_count(int a[][100],int x, int y, int l, int size, char way, char way2, char way3, char way4, int sw)
{
	if((way!='S'&&way2!='S'&&way3!='S'&&way4!='S')&&(x-1>=0)&&a[x-1][y]==l)
	{
		/*printf("N\n");*/
		return 1+recurcive_count(a,x-1,y,l,size,'N','A','A','N',0)+recurcive_count(a,x,y,l,size,'S','E','W',way4,-1)+recurcive_count(a,x,y,l,size,'S','N','W',way4,-1)+recurcive_count(a,x,y,l,size,'S','N','E',way4,-1);
		
	}
	if((way!='N'&&way2!='N'&&way3!='N'&&way4!='N')&&(x+1<size)&&a[x+1][y]==l)
	{
		/*printf("S\n");*/
		if(sw==-1)
		{	
		
			return 1+recurcive_count(a,x+1,y,l,size,'S','A','A','S',0);
		}
		else
		{
			
		
			return 1+recurcive_count(a,x+1,y,l,size,'S','A','A','S',0)+recurcive_count(a,x,y,l,size,'N','S','W',way4,-2)+recurcive_count(a,x,y,l,size,'N','S','E',way4,-2);
		}
	}	
	if((way!='E'&&way2!='E'&&way3!='E'&&way4!='E')&&(y-1>=0)&&a[x][y-1]==l)
	{
		/*printf("W\n");*/
		if(sw==-1||sw==-2)	
		{
			return 1+recurcive_count(a,x,y-1,l,size,'W','A','A','W',0);	
		}
		else
		{
			return 1+recurcive_count(a,x,y-1,l,size,'W','A','A','W',-3)+recurcive_count(a,x,y,l,size,'E','S','N',way4,-3);
		}
	}
	if((way!='W'&&way2!='W'&&way3!='W'&&way4!='W')&&(y+1<size)&&a[x][y+1]==l)
	{
		/*printf("E\n");*/
		
		return 1+recurcive_count(a,x,y+1,l,size,'E','A','A','E',0);
		
		
	}
	else
	{
		return 0;
		
	}
}
void recurcive_construct(int a[][100],int x, int y,int x1,int y1, int l, int size,int time, int c)
{
	if(c>=2)
	{	
		if(a[x1][y1]==l)
		{
			/*printf("hello\n");*/
			a[x1][y1]=l+1;
		}
		if(time>0)
		{
			
			if(a[x-1][y]==l&&x-1>=0)
			{
				a[x-1][y]=0;
				recurcive_construct(a,x-1,y,x1,y1,l,size,time-1,c);
			}
			if(a[x+1][y]==l&&x+1<size)
			{
				a[x+1][y]=0;
				recurcive_construct(a,x+1,y,x1,y1,l,size,time-1,c);
			}
			if(a[x][y-1]==l&&y-1>=0)
			{
				a[x][y-1]=0;
				recurcive_construct(a,x,y-1,x1,y1,l,size,time-1,c);
			}
			if(a[x][y+1]==l&&y+1<size)
			{
				a[x][y+1]=0;
				recurcive_construct(a,x,y+1,x1,y1,l,size,time-1,c);
			}
			if(a[x1-1][y1]==l+1||a[x1+1][y1]==l+1||a[x1][y1-1]==l+1||a[x1][y1+1]==l+1)
			{
				c=recurcive_count(a,x1,y1,l+1,size,'A','A','A','A',0);
				/*printf("wat %d\n",c);*/
				recurcive_construct(a,x1,y1,x1,y1,l+1,size,c,c);
			}
		}
	}
} 
int main()
{
	int row,column,level;
	int x,y,c;
	int size;
	int array[100][100];
	scanf("%d",&size);
	
	for(x=size-1;x+1;x--)
	{
		for(y=size-1;y+1;y--)
		{
			array[x][y]=0;
		}
	}
	while(scanf("%d %d %d",&level,&column,&row)!=EOF)
	{
		array[row][column]=level;
		c=recurcive_count(array,row,column,level,size,'A','A','A','A',0);
		recurcive_construct(array,row,column,row,column,level,size,c,c);


	}
	for(x=0;x<size;x++)
	{
		for(y=0;y<size;y++)
		{
			printf("%d ", array[x][y]);
		}
		printf("\n");
	}
	return 0;
}

