#include<stdio.h>
#include<String.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
//���ܺ���
void encrypt()
{
	int len,i;
	char temp1,password[20];
	printf("���������룺");
	scanf("%s",password);
	len = strlen(password);
	//��ÿ���ַ���ASCII����������ַ����е�λ�ã�1��ʼ����ƫ��ֵ3
	for(i = 0;i<len;i++)
	{
		password[i] = password[i]+i+1+3; 
	}
	//���ַ����ĵ�һλ�����һλ����˳��
	temp1 = password[0];
	password[0] = password[len-1];
	password[len-1] = temp1;
	//���ַ�����ת
	for(i = 0;i<len/2;i++)
	{
		char temp2;
		temp2 = password[i];
		password[i] = password[len-1-i];
		password[len-1-i] = temp2;
	}
	printf("���ܺ������Ϊ��%s\n",password);
	printf("\n");
}
//���ܺ���
void decrypt()
{
	int len,i;
	char temp4,password[20];
    printf("���������룺");
	scanf("%s",password);
	len = strlen(password);
	for(i = 0;i<len/2;i++)
	{
		char temp3;
		temp3 = password[i];
		password[i] = password[len-1-i];
		password[len-1-i] = temp3;
	}
	temp4 = password[0];
	password[0] = password[len-1];
	password[len-1] = temp4;
	for(i = 0;i<len;i++)
	{
		password[i] = password[i]-1-i-3;
	}
	printf("���ܺ������Ϊ��%s\n",password);
	printf("\n");
}
void strength()
{
	char password[20];
	int i,length,sum,n1 = 0,n2 = 0,n3 = 0;
	printf("���������룺");
	getchar();
	gets(password);
	length = strlen(password);
	if(length<8)
	{
		sum = 1;
	}
	if(length>=8)
	{
		for(i = 0;i<length;i++)
		{
			if(isdigit(password[i]))
			{
				n1 = 1;
			}
			else if(isupper(password[i]))
			{
				n2 = 1;
			}
			else if(islower(password[i]))
			{
				n3 = 1;
			}
		}
		sum = n1+n2+n3;
	}
	switch(sum)
	{
		case 1:
			printf("����ǿ�ȣ���\n");
			break;
		case 2:
			printf("����ǿ�ȣ���\n");
			break;
		case 3:
			printf("����ǿ�ȣ�ǿ\n");
			break;
		default:
			printf("�������������룡\n");
			break;
	}
	printf("\n");
}
void generate()
{
	char password[20];
	int i,len,mark;
	int n1 = 0,n2 = 0,n3 = 0;
	srand("���������볤�ȣ�");
	scanf("%d",&len);
	do
	{
		for(i = 0;i<len;i++)
		{
			mark = rand()%3+1;
			switch(mark)
			{
				case 1:
					password[i] = rand()%10+'0';
					n1 = 1;
					break;
				case 2:
					password[i] = rand()%26+'A';
					n2 = 1;
					break;
				case 3:
					password[i] = rand()%26+'a';
					n3 = 1;
					break;
			}
		}
		password[len] = '\0';
	}while(n1+n2+n3!=3);
	printf("���ɵ�����Ϊ��%s\n",password);
	printf("\n");
}
void menu()
{
	printf("----------------------\n");
        printf("----------------------\n");
	printf(" ��ӭʹ���������ϵͳ\n");
	printf("----------------------\n");
	printf("----------------------\n");
        printf("��ѡ�������\n");
	printf("1.����\n");
	printf("2.����\n");
	printf("3.�ж�����ǿ��\n");
	printf("4.��������\n");
	printf("5.�˳�\n");
}
int main()
{
	int flag = 1;
	while(flag)
	{
		int n = 0;
		menu();
		printf("������ѡ����ţ�");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
	                        encrypt();
				break;
			case 2:
	                        decrypt();
				break;
			case 3:
				strength();
				break;
			case 4:
				generate();
				break;
			case 5:
				flag = 0;
				break;
			default:
				break;
		}
	}
    return 0;
}
