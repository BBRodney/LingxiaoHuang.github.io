/*��ͷ�ļ��ں������ڽ�ʦ��ӿγ�ʱ��ʱ��ѡ��
������֤ʱ���Ƿ��ͻ������
�����ļ���classcodeForTeacher.txt�����ڴ��ʱ��Ĵ���
ѧ��ѡ��ʱҲ���õ�����ļ�*/ 
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
	int buffer_year,buffer_term,buffer_weekday,buffer_period_amount;//buffer����������ʱ����û����������ݣ�����ݴ����д����ʽ���� 
	char period[15],courseNUM[MAXN];
	char buffer_str[20];
	int i,j,amount;
	int flag;
	FILE* fp;
	
	fp=fopen("classcodeForTeacher.txt","r");
	if(fp==NULL)
	{
		printf("classcodeForTeacher.txt�򿪹����г����������\n");
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
	}//���ļ��пγ̵�ʱ����븴�Ƶ��ṹ���������Ա�Ƚ� 
	fclose(fp);

	do{ 
	
	flag=0;
	 
	printf("��������ѡ���Ͽ�ʱ�䣺\n");
	printf("\n��ѡ���Ͽε�ѧ�꣺\n");//ѡ��ѧ�� 
	printf("1.2020-2021 2.2021-2022 3.2022-2023\n");
	while(1)
	{
		check_choice(&buffer_year,1,3 );
		year=buffer_year;
		break;
	}
	
	printf("\n������ѡ���ѧ����Ͽ�ѧ�ڣ���һѧ�ڣ���\n");//ѡ��ѧ�� 
	printf("1.�＾ѧ�� 2.����ѧ��\n");
	while(1)
	{
		check_choice(&buffer_term,1,2);
		term=buffer_term;
		break;
		
	}
	
	printf("\n������Ĭ��Ϊ�ڶ��ܵ���ʮ���ܡ�\n");//�޷�����ѡ�񿪿����� 
	 
	printf("\n������ѡ��ÿ���������Ͽ�(��һ��)��\n");
	printf("1.��һ 2.�ܶ� 3.���� 4.���� 5.����\n");//ѡ������һ���Ͽ� 
	while(1)
	{
		check_choice(&buffer_weekday,1,5);
		weekday=buffer_weekday;
		break;
		
	}
	
	printf("\n��������Щʱ��οɹ�ѡ��\n") ;
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
	
	printf("\n�����������ܹ���Ҫ���ٸ�ʱ��Σ�(���9��)\n");//�ϼ��ڿ� 
	while(1)
	{
		check_choice(&buffer_period_amount,1,9);
		getchar();
		period_amount=buffer_period_amount;
		break;
	}
	
	
	printf("\n���ܹ���Ҫ%d��ʱ��Σ������������Ϸ�ÿ��ʱ���ǰ�ı����ѡ��\n",period_amount);
	printf("(����һλ��ź��»س�ѡ����һ��ʱ��Σ�ע�����һ��ʱ��α��Ϊ0)\n"); //���ļ��ڿ� 
	for(i=0;i<period_amount;i++)
	{

		while(1)
		{
			gets(buffer_str);

			if(strlen(buffer_str)!=1)
			{
				printf("���ϸ�����һλ���֣�\n");
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
				printf("\n����ʱ����Ƿ��ظ����Ŵ���!");
			    i--;
			    break; 
			} 	
		}
		

	}
	period[period_amount]='\0';//�����ַ����������� 
	
    
	for(i=0;i<amount;i++)
	{ 
        if(strcmp(input_name,date[i].teacher_name)==0)//���Ⱥ˶����� 
        {
			if(year==date[i].year)//�Ƿ�ͬһѧ�� 
			{
				if(term==date[i].term)//�Ƿ�ͬһѧ�� 
				{
					if(weekday==date[i].weekday)//�Ƿ�ͬһ���Ͽ� 
					{
						int a,b;
					for(a=0;a<strlen(period);a++)
					{
						for(b=0;b<strlen(date[i].period);b++)
						{
							if(period[a]==date[i].period[b])
							{
								printf("**����**������ı��: %c �����������γ̳�ͻ��\n",period[a]);
								flag=1;//��ʱ���ͻflag=1������ѡ�񿪿�ʱ�� 
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
    	printf("\nѡ��γ�ʱ��ɹ���\n");
    	
    	strcpy(courseNUM,COU[n].CNUM);
    	
    	fp=fopen("classcodeForTeacher.txt","a");//д��γ�ʱ���ļ� 
    	fprintf(fp,"%s %s %d %d %d %s\n",input_name,courseNUM,year,term,weekday,period); 
    	fclose(fp);
    	
    	COU[n].CLAST=period_amount*18;//�����ʱ 
    	
    	switch(year)
    	{
    		case 1:strcpy(COU[n].CBEGIN,"2020-2021ѧ��"); break;
    		case 2:strcpy(COU[n].CBEGIN,"2021-2022ѧ��"); break;
    		case 3:strcpy(COU[n].CBEGIN,"2022-2023ѧ��"); break;
    		default: break;
		}
		switch(term)
		{
			case 1:strcat(COU[n].CBEGIN,"�＾ѧ�ڵڶ��ܵ���ʮ���� ");break;
			case 2:strcat(COU[n].CBEGIN,"����ѧ�ڵڶ��ܵ���ʮ���� ");break;
			default:break;
		}
		
		switch(weekday)
		{
			case 1:strcpy(COU[n].CTIME,"��һ");break;
			case 2:strcpy(COU[n].CTIME,"�ܶ�");break;
			case 3:strcpy(COU[n].CTIME,"����");break;
			case 4:strcpy(COU[n].CTIME,"����");break;
			case 5:strcpy(COU[n].CTIME,"����");break;
			default:break;
		}
		
		
		i=0;
		if(period_amount == 1)//�����д�����ڿγ���Ϣ�Ľṹ������ 
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
		printf("\n\n*****ϵͳ��⵽��ѡ���ʱ����������������γ�ʱ���ͻ��������ѡ��*****\n\n");
	}
	
	
	} while(flag!=0) ;
	
}


