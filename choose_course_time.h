/*该头文件内函数用于教师添加课程时的时间选择
具有验证时间是否冲突的特性
打开了文件“classcodeForTeacher.txt”用于存放时间的代码
学生选课时也会用到这个文件*/ 
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#include "allstruct.h"
#include "check.h"


void choose_course_time(char input_name[],int n)
{
	int year,term,weekday,period_amount;
	int buffer_year,buffer_term,buffer_weekday,buffer_period_amount;//buffer变量用于临时存放用户的输入数据，检查容错后再写入正式变量 
	char period[15],courseNUM[MAXN];
	char buffer_str[20];
	int i,j,amount;
	int flag;
	FILE* fp;
	
	fp=fopen("classcodeForTeacher.txt","r");
	if(fp==NULL)
	{
		printf("classcodeForTeacher.txt打开过程中出现意外错误\n");
	}
	
	amount=0;
	while(!feof(fp))
	{
		fscanf(fp,"%s %s %d %d %d %s",
	          date[amount].teacher_name,
	          date[amount].course_num,
			  &date[amount].year,
			  &date[amount].term,
			  &date[amount].weekday,
			  date[amount].period);
		amount++;
	}//将文件中课程的时间代码复制到结构体数组中以便比较 
	fclose(fp);

	do{ 
	
	flag=0;
	 
	printf("接下来请选择上课时间：\n");
	printf("\n请选择上课的学年：\n");//选择学年 
	printf("1.2020-2021 2.2021-2022 3.2022-2023\n");
	while(1)
	{
		check_choice(&buffer_year,1,3 );
		year=buffer_year;
		break;
	}
	
	printf("\n现在请选择该学年的上课学期（仅一学期）：\n");//选择学期 
	printf("1.秋季学期 2.春季学期\n");
	while(1)
	{
		check_choice(&buffer_term,1,2);
		term=buffer_term;
		break;
		
	}
	
	printf("\n开课周默认为第二周到第十九周。\n");//无法自由选择开课周数 
	 
	printf("\n现在请选择每周在哪天上课(仅一天)：\n");
	printf("1.周一 2.周二 3.周三 4.周四 5.周五\n");//选择在哪一天上课 
	while(1)
	{
		check_choice(&buffer_weekday,1,5);
		weekday=buffer_weekday;
		break;
		
	}
	
	printf("\n当天有这些时间段可供选择：\n") ;
	printf("1.8:00-8:50\n") ;
	printf("2.9:00-9:50\n") ;
	printf("3.10:00-10:50\n") ;
	printf("4.11:00-11:50\n") ;
	printf("5.13:30-14:20\n") ;
	printf("6.14:30-15:20\n") ;
	printf("7.15:30-16:20\n") ;
	printf("8.16:30-17:20\n") ;
	printf("9.18:30-19:20\n") ;
	printf("0.19:30-20:20\n") ;
	
	printf("\n请问您当天总共需要多少个时间段？(最多9节)\n");//上几节课 
	while(1)
	{
		check_choice(&buffer_period_amount,1,9);
		getchar();
		period_amount=buffer_period_amount;
		break;
	}
	
	
	printf("\n您总共需要%d个时间段，请依次输入上方每个时间段前的编号以选择\n",period_amount);
	printf("(输入一位编号后按下回车选择下一个时间段，注意最后一个时间段编号为0)\n"); //上哪几节课 
	for(i=0;i<period_amount;i++)
	{

		while(1)
		{
			gets(buffer_str);

			if(strlen(buffer_str)!=1)
			{
				printf("请严格输入一位数字！\n");
			}
			
			else
			{
				period[i]=buffer_str[0];
				break;
			}
		}
		
		for(j=0;j<i;j++)
		{
			if(period[i] == period[j] || period[i]<'0' || period[i]>'9')
			{
				printf("\n请检查时间段是否重复或编号错误！!");
			    i--;
			    break; 
			} 	
		}
		

	}
	period[period_amount]='\0';//结束字符串否则乱码 
	
    
	for(i=0;i<amount;i++)
	{ 
        if(strcmp(input_name,date[i].teacher_name)==0)//首先核对姓名 
        {
			if(year==date[i].year)//是否同一学年 
			{
				if(term==date[i].term)//是否同一学期 
				{
					if(weekday==date[i].weekday)//是否同一天上课 
					{
						int a,b;
					for(a=0;a<strlen(period);a++)
					{
						for(b=0;b<strlen(date[i].period);b++)
						{
							if(period[a]==date[i].period[b])
							{
								printf("**警告**您输入的编号: %c 与您的其他课程冲突！\n",period[a]);
								flag=1;//若时间冲突flag=1将重新选择开课时间 
								//b=strlen(date[i].period);
								//a=strlen(period);
								//i=amount;
							}
						}
					}
					
					}
					
				}
			}	
		}
    }
    

    if(flag==0)
    {
    	printf("\n选择课程时间成功！\n");
    	
    	strcpy(courseNUM,COU[n].CNUM);
    	
    	fp=fopen("classcodeForTeacher.txt","a");//写入课程时间文件 
    	fprintf(fp,"%s %s %d %d %d %s\n",input_name,courseNUM,year,term,weekday,period); 
    	fclose(fp);
    	
    	COU[n].CLAST=period_amount*18;//计算课时 
    	
    	switch(year)
    	{
    		case 1:strcpy(COU[n].CBEGIN,"2020-2021学年"); break;
    		case 2:strcpy(COU[n].CBEGIN,"2021-2022学年"); break;
    		case 3:strcpy(COU[n].CBEGIN,"2022-2023学年"); break;
    		default: break;
		}
		switch(term)
		{
			case 1:strcat(COU[n].CBEGIN,"秋季学期第二周到第十九周 ");break;
			case 2:strcat(COU[n].CBEGIN,"春季学期第二周到第十九周 ");break;
			default:break;
		}
		
		switch(weekday)
		{
			case 1:strcpy(COU[n].CTIME,"周一");break;
			case 2:strcpy(COU[n].CTIME,"周二");break;
			case 3:strcpy(COU[n].CTIME,"周三");break;
			case 4:strcpy(COU[n].CTIME,"周四");break;
			case 5:strcpy(COU[n].CTIME,"周五");break;
			default:break;
		}
		
		
		i=0;
		if(period_amount == 1)//分情况写入用于课程信息的结构体数组 
		{
			if(period[i]=='1')strcat(COU[n].CTIME,"8:00-8:50 ");
			if(period[i]=='2')strcat(COU[n].CTIME,"9:00-9:50 ");
			if(period[i]=='3')strcat(COU[n].CTIME,"10:00-10:50 ");
			if(period[i]=='4')strcat(COU[n].CTIME,"11:00-11:50 ");
			if(period[i]=='5')strcat(COU[n].CTIME,"13:30-14:20 ");
			if(period[i]=='6')strcat(COU[n].CTIME,"14:30-15:20 ");
			if(period[i]=='7')strcat(COU[n].CTIME,"15:30-16:20 ");
			if(period[i]=='8')strcat(COU[n].CTIME,"16:30-17:20 ");
			if(period[i]=='9')strcat(COU[n].CTIME,"18:30-19:20 ");
			if(period[i]=='0')strcat(COU[n].CTIME,"19:30-20:20 ");
			
			printf("\n\n%s\n\n",COU[n].CTIME);
			
		}else if(period_amount > 1)
		{
			for(i=0;i<period_amount - 1;i++)
			{
				if(period[i]=='1')strcat(COU[n].CTIME,"8:00-8:50,");
				if(period[i]=='2')strcat(COU[n].CTIME,"9:00-9:50,");
				if(period[i]=='3')strcat(COU[n].CTIME,"10:00-10:50,");
				if(period[i]=='4')strcat(COU[n].CTIME,"11:00-11:50,");
				if(period[i]=='5')strcat(COU[n].CTIME,"13:30-14:20,");
				if(period[i]=='6')strcat(COU[n].CTIME,"14:30-15:20,");
				if(period[i]=='7')strcat(COU[n].CTIME,"15:30-16:20,");
				if(period[i]=='8')strcat(COU[n].CTIME,"16:30-17:20,");
				if(period[i]=='9')strcat(COU[n].CTIME,"18:30-19:20,");
				if(period[i]=='0')strcat(COU[n].CTIME,"19:30-20:20,");
			}
			
			if(period[period_amount-1]=='1') strcat(COU[n].CTIME,"8:00-8:50 ");
		    if(period[period_amount-1]=='2') strcat(COU[n].CTIME,"9:00-9:50 ");
		    if(period[period_amount-1]=='3') strcat(COU[n].CTIME,"10:00-10:50 ");
		    if(period[period_amount-1]=='4') strcat(COU[n].CTIME,"11:00-11:50 ");
		    if(period[period_amount-1]=='5') strcat(COU[n].CTIME,"13:30-14:20 ");
		    if(period[period_amount-1]=='6') strcat(COU[n].CTIME,"14:30-15:20 ");
		    if(period[period_amount-1]=='7') strcat(COU[n].CTIME,"15:30-16:20 ");
		    if(period[period_amount-1]=='8') strcat(COU[n].CTIME,"16:30-17:20 ");
		    if(period[period_amount-1]=='9') strcat(COU[n].CTIME,"18:30-19:20 ");
		    if(period[period_amount-1]=='0') strcat(COU[n].CTIME,"19:30-20:20 ");
		}
		
		
	}
	if(flag==1)
	{
		printf("\n\n*****系统检测到您选择的时间与您开设的其他课程时间冲突，请重新选择！*****\n\n");
	}
	
	
	} while(flag!=0) ;
	
}


