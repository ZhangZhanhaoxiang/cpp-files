#include<stdio.h>
#include<string.h>
char s[20];
int a[500000],b[500000];
int count=0;
void times(int a[],int b[],int m);
int main()
{
	int i,k,j,n,m;
	while(scanf("%s%d",s,&n)!=EOF)
	{
		
		//if(s[0]=='0'&&n==0)
		//	break;
		//if(n==0)
		//{
		//	printf("1\n");
		//	continue;
		//}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		m=strlen(s);
		j=k=0;
		for(i=m-1;i>=0;i--)
		{
			a[k++]=s[i]-'0';
			b[j++]=s[i]-'0';
		}
		n--;
		while(n)
		{
			times(a,b,m);
			n--;
		}
		for(i=1005;i>0;i--)
		{
			if(b[i]==0)
				continue;
			else
				break;
		}	
		while(i>=0)
		{
			printf("%d",b[i]);
			i--;
		}
		printf("\n");
	}
	return 0;
}
void times(int a[],int b[],int m)
{
	int i,j,k;
	int c[5000];
	memset(c,0,sizeof(c));
	for(i=0;i<m;i++)
		for(j=0;j<1005;j++)
			c[i+j]=c[i+j]+a[i]*b[j];
	for(i=0;i<1005;i++)
	{
		if(c[i]>=10)
			c[i+1]=c[i+1]+c[i]/10;
		b[i]=c[i]%10;
	}
}