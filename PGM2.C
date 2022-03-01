#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int isIdentifier (char a[])
{
	int flag, i=1;
	if(a[0]==95)
		flag=1;
	else if(isalpha(a[0]))
		flag=1;
	else
		return 0;
	while(a[i]!='\0')
	{
		if(!isdigit(a[i]) && !isalpha(a[i])&& a[i]!=95)
		{
			flag=0;
			break;
		}
		i++;
	}
	if(i>6)
		flag=0;
	if(flag==1)
		return 1;
}
int isKeyword(char buffer[]){
	char keywords[33][10] = {"auto","break","case","char","const","continue","default",
		"do","double","else","enum","extern","float","for","goto",
		"if","int","long","register","return","short","signed",
		"sizeof","static","struct","switch","typedef","union",
		"unsigned","void","volatile","while"};
	int i, flag = 0;
	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = 1;
			break;
		}
	}
	return flag;
}


int main(){
	char ch, buffer[15], operators[] = "+-*/%=",seperators[]=",;(){}[]";
	FILE *fp;
	int i,j=0,k;
	clrscr();
	fp = fopen("test2.txt","r");
	if(fp == NULL){
		printf("error while opening the file\n");
		exit(0);
	}
	while((ch = fgetc(fp)) != EOF){
		for(i = 0; i < 6; ++i){
   			if(ch == operators[i])
   			printf("%c is operator\n", ch);
   		}
   	
   		for(k=0;k<8;k++)
   		{
   			if(ch==seperators[k])
   				{
				printf("%c is delimiter\n", ch);
			}
		}
  
   		if(isalnum(ch) || ch==95){
   			buffer[j++] = ch;
   		}
   		else if((ch == ' ' || ch == '\n') && (j != 0)){
   			buffer[j] = '\0';
   			j = 0;
     
   			if(isKeyword(buffer) == 1){
   				printf("%s is keyword\n", buffer);
   				continue;
   			}
   			if(isIdentifier(buffer)==1){
   				printf("%s is identifier\n" , buffer);
   				continue;
   			}
   			if(isIdentifier(buffer)==0){
   				printf("%s is not identifier\n" , buffer);
   				continue;
   			}
		}
	}
fclose(fp);
getch();
return 0;
}