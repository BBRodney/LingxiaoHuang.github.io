//������ֵΪ0���ʾ����ʦδ����γ̣������޷���ֵ 
#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"allstruct.h"

struct Buffer_Course{
	char number[MAXN];
	char name[MAXN];
	int roll;
}buffer_course[MAXN];//����ṹ���������ڴ洢����� 

int rank_my_course(char input_name[])//������ʦ��name 
{
	int i,j,k=0;
	int flag;
	
	FILE* fp;
	fp=fopen("CourseInf.txt","r");
	if(fp==NULL)
	{
		printf("����\n");
		system("pause");
	}
	i=0;
	while(!feof(fp)){
		fscanf(fp,"%s %s %d %d %s %s %s %s %s %s %d %d %s %s",
                COU[i].CNUM,
                COU[i].CNAME,
                &COU[i].CSCORE,
                &COU[i].CLAST,
                COU[i].CELE,
				COU[i].CTEACH,
				COU[i].CACA,
				COU[i].CBEGIN,
				COU[i].CTIME,
			    COU[i].CLASSROOM,
				&COU[i].CURNUM,
				&COU[i].MAXSTU,
				COU[i].INTRO,
				COU[i].TEXTBOOK);//���ܿγ���Ϣ�ļ��л�ȡ���пγ���Ϣ 
		

		i++;
	}
    j=i-1;
	fclose(fp); 
	
	
	for(i=0;i<j;i++)
	{
		if(strcmp(input_name,COU[i].CTEACH) == 0)//��¼�ý�ʦ����Ŀγ̣��ж�����Ϊ��ʦ���� 
		{
			k++;	
			
			strcpy(buffer_course[k].number,COU[i].CNUM); 
			
			
			strcpy(buffer_course[k].name,COU[i].CNAME);
			
			
			buffer_course[k].roll=COU[i].CURNUM;

		}
	}
	
	if(k==0)//kΪ��ʦ������Ŀγ���Ŀ 
	{
		printf("\n����û�п�����γ̣�\n\n");
		
		system("pause");

		return 0;
	}
	
	printf("\n���ܼƿ����%d���γ̡�\n",k);
	
	int max;
	flag=0;
	for(j=1;j<=k;j++)//�����k�� 
	{
		for(i=1;i<=k;i++)//��鵱ǰ����� 
	    {
	        if(flag<=buffer_course[i].roll) 
	        {
	    	    flag=buffer_course[i].roll;//ѡ������ 
	    	    max=i;
		    }
	    }
	    
	    printf("\n�γ̱��:%s\n",buffer_course[max].number); 
	    printf("�γ�����:%s\n",buffer_course[max].name); 
	    printf("ѡ������:%d\n",buffer_course[max].roll); 
	    flag=0;
		buffer_course[max].roll=-1;
	}
	
	char rubbish[10];//�ݴ� 
	gets(rubbish);
	printf("\n");
	system("pause");

	
	
 } 
