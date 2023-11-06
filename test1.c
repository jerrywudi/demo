#include<stdio.h>
#include<String.h>
//加密函数
void encrypt()
{
	int len,i;
	char temp1,password[20];
	printf("请输入密码：");
	scanf("%s",password);
	len = strlen(password);
	//将每个字符的ASCII码加上其在字符串中的位置（1开始）和偏移值3
	for(i = 0;i<len;i++)
	{
		password[i] = password[i]+i+1+3; 
	}
	//将字符串的第一位和最后一位调换顺序
	temp1 = password[0];
	password[0] = password[len-1];
	password[len-1] = temp1;
	//将字符串反转
	for(i = 0;i<len/2;i++)
	{
		char temp2;
		temp2 = password[i];
		password[i] = password[len-1-i];
		password[len-1-i] = temp2;
	}
	printf("加密后的密码为：%s\n",password);
}
//解密函数
void decrypt()
{
	int len,i;
	char temp4,password[20];
    printf("请输入密码：");
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
	printf("解密后的密码为：%s\n",password);
}
void menu()
{
	printf("----------------------\n");
    printf("----------------------\n");
	printf(" 欢迎使用密码管理系统\n");
	printf("----------------------\n");
	printf("----------------------\n");
    printf("请选择操作：\n");
	printf("1.加密\n");
	printf("2.解密\n");
	printf("3.退出\n");
}
int main()
{
	int flag = 1;
	while(flag)
	{
		int n = 0;
		menu();
		printf("请输入选择序号：");
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
