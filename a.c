/*********file-test4.c******/
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>


int main()
{	int fd;
	char buf = 0;

	FILE *fp;
	FILE *fp1;

	fp = fopen("./foo.txt","r+");  			//打开被复制文件
	if(fp == NULL)
	{
		printf("error:%d",errno);			//输出错误信息
		perror("fopen");
	}	
	fp1 = fopen("./file.txt","w+");  		//打开目标文件
	if(fp1 == NULL)
	{
		printf("error:%d",errno);			//输出错误信息
		perror("fopen");
	}
	while((buf = fgetc(fp)) != EOF)			//复制文件内容到目标文件
	{
		fd = fputc(buf,fp1);
		if(fd == EOF)
			printf("write is failed");		//输出错误信息
	}
		
fclose(fp);									//关闭被复制文件
fclose(fp1);								//关闭目标文件

	return 0;
}
