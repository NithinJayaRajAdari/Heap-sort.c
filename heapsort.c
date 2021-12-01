#include<stdio.h>
#include<stdlib.h>
int no,c,i,j,root,temp;
int main()
{
	int *a,flag=0;
	void heaptree(int*);
	void heapsort(int*);
	printf("Enter the range of elements");
	scanf("%d",&no);
	a=(int*)malloc(no*sizeof(int));
	printf("Enter %d no of elements",no);
	for(i=0;i<no;i++)
	{
		scanf("%d",&a[i]);
		if(i>0)
		{
			if(a[i-1]>a[i])
			{
				flag++;
			}
		}
	}
	if(flag==0)
	{
		printf("Given elements are in sorted list");
		exit(0);
	}
	heaptree(a);
	printf("\n The maximum heap tree is \n");
	for(i=0;i<no;i++)
	  printf("%d \t",a[i]);
	heapsort(a);
	printf("\n Heap Sorted List is \n");
	for(i=0;i<no;i++)
	  printf("%d \t",a[i]);
  return 0;
}
void heaptree(int *a)
{
	for(i=1;i<no;i++)
	{
		c=i;
		do
		{
			root=(c-1)/2;
			if(a[root]<a[c])
			{
				temp=a[c];
				a[c]=a[root];
				a[root]=temp;
			}
			c=root;
		}while(c!=0);
	}
}
void heapsort(int *a)
{
	for(j=no-1;j>=0;j--)
	{
		temp=a[0];
		a[0]=a[j];
		a[j]=temp;
		root=0;
		do
		{
			c=2*root+1;
			if((a[c]<a[c+1]) && c<j-1)
			  c++;
			if(a[root]<a[c] && c<j)
			{
				temp=a[c];
				a[c]=a[root];
				a[root]=temp;
			}
			root=c;
		}while(c<j);
	}
}
