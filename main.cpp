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
	printf("�����뵱ǰ��Դ�����Լ����̸���\n");
	int m,n;//m ��Դ����, n �ǽ��̸��� 
	scanf("%d%d",&m,&n);
	
	int i=0,j=0;
	int Max[100][100]={0}; //�����̵����������
	int Allocation[100][100]={0}; //�������ѷ������Դ����
	int Need[100][100]={0};  //�����̵���Ҫ�� 
	int Available[100]={0};
	int Available_Max[100]={0};
	int p_need[100]={0};//����i�������Դ���� 
	
	//������Դ���� һά����
	printf("������%d ����Դ�ĸ���\n",m);
	for(i=0;i<m;i++)
	{
	  scanf("%d",&Available[i]);
	  Available_Max[i]=Available[i];
	}   
	
	 
	printf("����������������\n");
	for( i=0;i<n;i++)
	 for(j=0;j<m;j++)
	 {
	 	scanf("%d",&Max[i][j]);
	 }
	printf("\n����������������Դ��\n");
	display(Max,n,m);
	
	
	printf("�������ѷ�����Դ����:\n");
	for(i=0;i<n;i++)
	  for(j=0;j<m;j++)
	  {
	  	scanf("%d",&Allocation[i][j]);
	  }
	printf("\n�������ѷ������Դ��\n");
	display(Allocation,n,m);
	
	//��������̻���Ҫ��Դ��
	for(i=0;i<n;i++)
	  for(j=0;j<m;j++)
	  {
	    Need[i][j]=Max[i][j]-Allocation[i][j];	
	  }
	printf("\n�����̻������Դ��\n");
	display(Need,n,m);
	
	//������Դ��ʣ����
	for(i=0;i<m;i++)
	  for(j=0;j<n;j++)
	  {
	  	Available[i]=Available[i]-Allocation[j][i];
	  }
	printf("\n��ʣ��Դ��Ϊ\n");
	for(i=0;i<m;i++)
	{
	  printf("%d ",Available[i]);	
	}
	//�������i��������Դ��
	int p_i=0; //����i���±��0��ʼ 
	
	printf("\n�����뵱ǰ����Ҫ������Դ�Ľ���i\n");
	scanf("%d",&p_i); 
	printf("���������%d �������Դ����\n",p_i);
	for(i=0;i<m;i++)
	{
		scanf("%d",&p_need[i]);
	}
	printf("��ʾ����%d �������Դ����\n",p_i);
	for(i=0;i<m;i++)
	{
		printf("%d ",p_need[i]);
	 }
	
	int stop=0;
	//�жϽ�������Ҫ��
	for(i=0;i<m;i++)
	{
		if( p_need[i]>Need[p_i][i])
		{
			stop=1;
			printf("����\n");
		}
		if(p_need[i]>Available[i])
		{
			stop=1;
			printf("����\n"); 
		}
	}
	//printf("aaaaa %d aaa\n",stop);
	if(stop==0)
	{ //���Է���
	  for(i=0;i<m;i++)
	  {
	  	Need[p_i][i] =Need[p_i][i]-p_need[i];
	  	Available[i] =Available[i]-p_need[i];
	  	Allocation[p_i][i]=Allocation[p_i][i]+p_need[i];
	  	//printf("������ִ��\n");
	   } 
	  printf("\nʣ����Դ��\n");
	  for(i=0;i<m;i++)
	  {
		printf("%d ",Available[i]);
	  }
	  printf("\nʣ���������\n");
	  for(i=0;i<n;i++)
	  { 
	    for(j=0;j<m;j++)
	    {
	    	printf("%d ",Need[i][j]);
	    } 
	    printf("\n");	
	  }
	
	 printf("\n�ѷ������\n");
	  for(i=0;i<n;i++)
	  { 
	    for(j=0;j<m;j++)
	    {
	      printf("%d ",Allocation[i][j]);
	    } 
	    printf("\n");	
      }
	  
	//��ʼִ�а�ȫ�Բ���
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
	 
	//Ѱ�����������Ľ���
	int alo=0;
	int t=m; //��Դ��
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
	    if(alo==1)  //�ҵ�һ������� 
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
	  printf("�ҵ���һ������������\n"); 
	  for(i=0;i<n;i++)
	  {
	 	printf("%d  ",doc[i]);
	  }
	}
	else
	{
	  printf("�Ҳ�������������\n");
	  for(i=0;i<n;i++)
	  {
	 	printf("%d  ",doc[i]);
	  } 
	} 
	   	
	}
	
	
	
	
	 

	return 0;
}

