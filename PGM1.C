#include<stdio.h>
#include<stdlib.h>
int main()
{
 char path[100];
 int c,w,l;
 FILE * file;
 char ch;
 printf("Enter the file path : ");
 scanf("%s",path);
 file=fopen(path,"r");
 if(file==NULL)
 {
  printf("Unable to open file \n");
  printf("Please check if file exist\n");
 }
 c=w=l=0;
 while((ch=fgetc(file))!=EOF)
 {
  c++;
  if(ch=='\n'||ch=='\0')
  l++;
  if(ch==' '||ch=='\t'||ch=='\n'||ch=='\0'||ch==',')
  w++;
 }
 if(c>0)
 {
  w++;
  l++;
 }
 printf("\n");
 printf("Total characters : %d\n",c);
 printf("Total words : %d\n",w);
 printf("Total lines : %d\n",l);
 fclose(file);
 getch();
 return 0;
}
