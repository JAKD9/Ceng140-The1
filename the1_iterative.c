#include <stdio.h>



int main()
{
	int row,column,level;
	int x,y,counter;
	int t1,t2,t3,t4;
	int size;
	int array[100][100]	;
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
		for(counter=1;counter==1;)
		{
			counter=0;
			if(array[row-1][column]==level+1||array[row+1][column]==level+1||array[row][column-1]==level+1||array[row][column+1]==level+1)
			{counter=1;}
			for(x=row,y=column-1,t1=0;y>=0;y-=1)
			{
				if (array[x][y]==level)
				{
					t1+=1;
					if(x+1<size && array[x+1][y]==level)
					{
						t1+=1;	
					}
					if(x-1>=0 && array[x-1][y]==level)
					{
						t1+=1;	
					}
				}
				else
				{
			
					break;
				}

			  }
			for(x=row,y=column+1,t2=0;y<size;y+=1)
			{
				if (array[x][y]==level)
				{
					t2+=1;
					if(x+1<size && array[x+1][y]==level)
					{
						t2+=1;	
					}
					if(x-1>=0 && array[x-1][y]==level)
					{
						t2+=1;	
					}
				}
				else
				{

					break;
				}

			  }
			for(x=row-1,y=column,t3=0;x>=0;x-=1)
			{
				if (array[x][y]==level)
				{
					t3+=1;
					if(y+1<size && array[x][y+1]==level)
					{
						t3+=1;	
					}
					if(y-1>=0 && array[x][y-1]==level)
					{
						t3+=1;	
					}
				}
				else
				{
	
					break;
				}

			  }
			for(x=row+1,y=column,t4=0;x<size;x+=1)
			{
				if (array[x][y]==level)
				{
					t4+=1;
					if(y+1<size && array[x][y+1]==level)
					{
						t4+=1;	
					}
					if(y-1>=0 && array[x][y-1]==level)
					{
						t4+=1;	
					}
				}
				else
				{	

					break;
				}

			  }
			  if(t1+t2+t3+t4>=2)
			  {
			  	array[row][column]=level+1;

				for(x=row,y=column-1,t1=0;y>=0;y-=1)
				{
					if (array[x][y]==level)
					{
						array[x][y]=0;
						if(x+1<size && array[x+1][y]==level)
						{
							array[x+1][y]=0;	
						}
						if(x-1>=0 && array[x-1][y]==level)
						{
							array[x-1][y]=0;	
						}
					}
					else
					{
						break;
					}

				  }
				for(x=row,y=column+1,t2=0;y<size;y+=1)
				{
					if (array[x][y]==level)
					{
						array[x][y]=0;
						if(x+1<size && array[x+1][y]==level)
						{
							array[x+1][y]=0;	
						}
						if(x-1>=0 && array[x-1][y]==level)
						{
							array[x-1][y]=0;	
						}
					}
					else
					{
						break;
					}
	
			  	}
				for(x=row-1,y=column,t3=0;x>=0;x-=1)
				{
					if (array[x][y]==level)
					{
						array[x][y]=0;
						if(y+1<size && array[x][y+1]==level)
						{
							array[x][y+1]=0;	
						}
						if(y-1>=0 && array[x][y-1]==level)
						{
							array[x][y-1]=0;	
						}
					}
					else
					{
						break;
					}

				}
				for(x=row+1,y=column,t4=0;x<size;x+=1)
				{
					if (array[x][y]==level)
					{
						array[x][y]=0;
						if(y+1<size && array[x][y+1]==level)
						{
							array[x][y+1]=0;	
						}
						if(y-1>=0 && array[x][y-1]==level)
						{
							array[x][y-1]=0;	
						}
					}
					else
					{	
						break;
					}
	
				}
			}	
			if(array[row][column]==level+1)
			  {level+=1;}
			else{break;}
			  	
			
		}
	
		
		
		
		
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



