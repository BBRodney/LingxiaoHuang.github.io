//若返回值为0则表示该老师未开设课程，否则无返回值 
#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"allstruct.h"

struct Buffer_Course{
	char number[MAXN];
	char name[MAXN];
	int roll;
}buffer_course[MAXN];//定义结构体数组用于存储和输出 

int rank_my_course(char input_name[])//传入老师的name 
{
	int i,j,k=0;
	int flag;
	
	FILE* fp;
	fp=fopen("CourseInf.txt","r");
	if(fp==NULL)
	{
		printf("出错！\n");
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
				COU[i].TEXTBOOK);//从总课程信息文件中获取所有课程信息 
		

		i++;
	}
    j=i-1;
	fclose(fp); 
	
	
	for(i=0;i<j;i++)
	{
		if(strcmp(input_name,COU[i].CTEACH) == 0)//记录该教师开设的课程，判断条件为教师姓名 
		{
			k++;	
			
			strcpy(buffer_course[k].number,COU[i].CNUM); 
			
			
			strcpy(buffer_course[k].name,COU[i].CNAME);
			
			
			buffer_course[k].roll=COU[i].CURNUM;

		}
	}
	
	if(k==0)//k为老师共开设的课程数目 
	{
		printf("\n您还没有开设过课程！\n\n");
		
		system("pause");

		return 0;
	}
	
	printf("\n您总计开设过%d个课程。\n",k);
	
	int max;
	flag=0;
	for(j=1;j<=k;j++)//共输出k项 
	{
		for(i=1;i<=k;i++)//检查当前最大项 
	    {
	        if(flag<=buffer_course[i].roll) 
	        {
	    	    flag=buffer_course[i].roll;//选择排序 
	    	    max=i;
		    }
	    }
	    
	    printf("\n课程编号:%s\n",buffer_course[max].number); 
	    printf("课程名称:%s\n",buffer_course[max].name); 
	    printf("选课人数:%d\n",buffer_course[max].roll); 
	    flag=0;
		buffer_course[max].roll=-1;
	}
	
	char rubbish[10];//容错 
	gets(rubbish);
	printf("\n");
	system("pause");

	
	
 } 
