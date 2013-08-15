#include<stdio.h>
int main()
{
	int n,a[8],j,i,m,count;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		else{
		m=1;i=0;count=0;
		while(n/2!=0)
		{
			a[i]=n%2;
			n=n/2;
			i++;
		}
		a[i]=n%2;
		j=i;
		for(j=0;j<=i;j++)
		{
			if(a[j]!=1)
			{
				count++;
			}
			else break;
		}
		
		for(i=1;i<=count;i++)
		  m=m*2;
		  printf("%d\n",m);
		}
		
	}
	return 0;
}
