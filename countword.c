#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 1024

int main(void){
	char buf[MAX_NUM];			//字符缓冲区
	FILE *fp;            
	int len,total=0;           //每行字符个数和总字数
	if((fp = fopen("C:/1.txt","r")) == NULL){
		perror("the file fail to read");
		getchar();				//暂停显示
		exit (1) ;
		}
	 while(!feof(fp) && !ferror(fp)){	//文件读取结束或出错则退出
	//while(fgets(buf,MAX_NUM,fp) != NULL)
		fgets(buf,MAX_NUM,fp);//每次读取一行或者MAX_NUM个字符
		len = strlen(buf);
		if(buf[len-1] == '\n'){
			buf[len-1] = '\0';  //去掉换行符在输出
			len--;
		}
		if(len == 0) continue;	//消除空白行
	//	printf("%s  \n",buf);
		total+=len;
	 }
	printf("字符的个数为 %d \n",total);
	fclose(fp);				//关闭文件
	getchar();
	return 0;
}

