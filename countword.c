#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 1024

int main(void){
	char buf[MAX_NUM];			//�ַ�������
	FILE *fp;            
	int len,total=0;           //ÿ���ַ�������������
	if((fp = fopen("C:/1.txt","r")) == NULL){
		perror("the file fail to read");
		getchar();				//��ͣ��ʾ
		exit (1) ;
		}
	 while(!feof(fp) && !ferror(fp)){	//�ļ���ȡ������������˳�
	//while(fgets(buf,MAX_NUM,fp) != NULL)
		fgets(buf,MAX_NUM,fp);//ÿ�ζ�ȡһ�л���MAX_NUM���ַ�
		len = strlen(buf);
		if(buf[len-1] == '\n'){
			buf[len-1] = '\0';  //ȥ�����з������
			len--;
		}
		if(len == 0) continue;	//�����հ���
	//	printf("%s  \n",buf);
		total+=len;
	 }
	printf("�ַ��ĸ���Ϊ %d \n",total);
	fclose(fp);				//�ر��ļ�
	getchar();
	return 0;
}

