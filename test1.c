#include<stdio.h>
#include<String.h>
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
	printf("3.�˳�\n");
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
				flag = 0;
				break;
			default:
				break;
		}
	}
    return 0;
}
