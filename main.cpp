#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void display(int a[100][100],int m,int n)
{
	for(int i=0;i<m;i++)
	{
	  for(int j=0;j<n;j++)
	  {
	  	printf("%d ",a[i][j]);
	  }
	  printf("\n");	
	}
	  
}
int main(int argc, char** argv) {
	printf("请输入当前资源个数以及进程个数\n");
	int m,n;//m 资源个数, n 是进程个数 
	scanf("%d%d",&m,&n);
	
	int i=0,j=0;
	int Max[100][100]={0}; //各进程的最大需求量
	int Allocation[100][100]={0}; //各进程已分配的资源数量
	int Need[100][100]={0};  //各进程的需要量 
	int Available[100]={0};
	int Available_Max[100]={0};
	int p_need[100]={0};//进程i仍需的资源向量 
	
	//输入资源总量 一维数组
	printf("请输入%d 类资源的个数\n",m);
	for(i=0;i<m;i++)
	{
	  scanf("%d",&Available[i]);
	  Available_Max[i]=Available[i];
	}   
	
	 
	printf("请输入最大需求矩阵\n");
	for( i=0;i<n;i++)
	 for(j=0;j<m;j++)
	 {
	 	scanf("%d",&Max[i][j]);
	 }
	printf("\n各进程所需的最大资源数\n");
	display(Max,n,m);
	
	
	printf("请输入已分配资源矩阵:\n");
	for(i=0;i<n;i++)
	  for(j=0;j<m;j++)
	  {
	  	scanf("%d",&Allocation[i][j]);
	  }
	printf("\n各进程已分配的资源数\n");
	display(Allocation,n,m);
	
	//计算各进程还需要资源数
	for(i=0;i<n;i++)
	  for(j=0;j<m;j++)
	  {
	    Need[i][j]=Max[i][j]-Allocation[i][j];	
	  }
	printf("\n各进程还需的资源数\n");
	display(Need,n,m);
	
	//计算资源的剩余量
	for(i=0;i<m;i++)
	  for(j=0;j<n;j++)
	  {
	  	Available[i]=Available[i]-Allocation[j][i];
	  }
	printf("\n还剩资源数为\n");
	for(i=0;i<m;i++)
	{
	  printf("%d ",Available[i]);	
	}
	//输入进程i的所需资源数
	int p_i=0; //进程i，下标从0开始 
	
	printf("\n请输入当前还需要申请资源的进程i\n");
	scanf("%d",&p_i); 
	printf("请输入进程%d 所需的资源向量\n",p_i);
	for(i=0;i<m;i++)
	{
		scanf("%d",&p_need[i]);
	}
	printf("显示进程%d 所需的资源向量\n",p_i);
	for(i=0;i<m;i++)
	{
		printf("%d ",p_need[i]);
	 }
	
	int stop=0;
	//判断进程所需要的
	for(i=0;i<m;i++)
	{
		if( p_need[i]>Need[p_i][i])
		{
			stop=1;
			printf("阻塞\n");
		}
		if(p_need[i]>Available[i])
		{
			stop=1;
			printf("阻塞\n"); 
		}
	}
	//printf("aaaaa %d aaa\n",stop);
	if(stop==0)
	{ //尝试分配
	  for(i=0;i<m;i++)
	  {
	  	Need[p_i][i] =Need[p_i][i]-p_need[i];
	  	Available[i] =Available[i]-p_need[i];
	  	Allocation[p_i][i]=Allocation[p_i][i]+p_need[i];
	  	//printf("这里已执行\n");
	   } 
	  printf("\n剩余资源量\n");
	  for(i=0;i<m;i++)
	  {
		printf("%d ",Available[i]);
	  }
	  printf("\n剩余需求矩阵\n");
	  for(i=0;i<n;i++)
	  { 
	    for(j=0;j<m;j++)
	    {
	    	printf("%d ",Need[i][j]);
	    } 
	    printf("\n");	
	  }
	
	 printf("\n已分配矩阵\n");
	  for(i=0;i<n;i++)
	  { 
	    for(j=0;j<m;j++)
	    {
	      printf("%d ",Allocation[i][j]);
	    } 
	    printf("\n");	
      }
	  
	//开始执行安全性策略
	int work[100]={0};
	int Finish[100]={0};
	for(i=0;i<m;i++)
	{
		work[i]=Available[i];
		
	}
	for(i=0;i<n;i++)
	{
	  Finish[i]=0;
	}
	 
	//寻找满足条件的进程
	int alo=0;
	int t=m; //资源数
	int doc[100]={0};
	int d=0;
	int j=0;
	int k=0;
	for(i=0;i<n;i++)
	{
	  for(j=0;j<n;j++)
	  {
	  	for(k=0;k<m;k++)
	    {
	  	  if(Finish[j]==0&&Need[j][k]<=work[k])
		  {
			alo=1;
	 	  }
		  else
		  {
			alo=0;
			break;
		  }
	    }
	    if(alo==1)  //找到一个满足的 
	    {
	  	  for(t=0;t<m;t++)
		  {
		    work[t]=work[t]+Allocation[j][t];	
	      }
		  Finish[j]=1;
		  doc[d]=j; 
		  d++;	
	    }
	  	
	   } 
	
	}
	int count=0;
	for(i=0;i<n;i++)
	{
		if(Finish[i]==1)
		{
		  count++;
		}		
	}
	if(count==5)
	{
	  printf("找到了一个这样的序列\n"); 
	  for(i=0;i<n;i++)
	  {
	 	printf("%d  ",doc[i]);
	  }
	}
	else
	{
	  printf("找不到这样的序列\n");
	  for(i=0;i<n;i++)
	  {
	 	printf("%d  ",doc[i]);
	  } 
	} 
	   	
	}
	
	
	
	
	 

	return 0;
}

