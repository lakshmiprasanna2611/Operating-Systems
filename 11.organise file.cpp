#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
int nf=0,i=0,j=0,ch;
char mdname[10],fname[10][10],name[10];
printf("Enter the directory name:");
scanf("%s",mdname);
printf("Enter the number of files:");
scanf("%d",&nf);
do
{
printf("Enter file name to be created:");
scanf("%s",name);
for(i=0;i<nf;i++)
{
if(!strcmp(name,fname[i]))
break;
}
if(i==nf)
{
strcpy(fname[j++],name);
nf++;
}
else
printf("There is already %s\n",name);
printf("Do you want to enter another file(yes - 1 or no - 0):");
scanf("%d",&ch);
}
while(ch==1);
printf("Directory name is:%s\n",mdname);
printf("Files names are:");
for(i=0;i<j;i++)
printf("\n%s",fname[i]);
getch();
}

/*Enter the directory name:courses
Enter the number of files:3
Enter file name to be created:python
Do you want to enter another file(yes - 1 or no - 0):1
Enter file name to be created:dbms
Do you want to enter another file(yes - 1 or no - 0):1
Enter file name to be created:data structures
Do you want to enter another file(yes - 1 or no - 0):Enter file name to be created:Do you want to enter another file(yes - 1 or no - 0):0
Directory name is:courses
Files names are:
python
dbms
data structures