#include<string.h>
#include<ctype.h>
#include<stdio.h>
void keyword(char str[10])
{
	if(strcmp("for",str)==0 || strcmp("while",str)==0||strcmp("do",str)==0 || strcmp("int",str)=0||strcmp("float",str)==0 || strcmp("char",str)==0||strcmp("double",str)==0 || strcmp("static",str)==0||strcmp("switch",str)==0 || strcmp("case",str)==0)
	{
		printf("\n %s is a keyword: ",str);
	}
	else
	{
		printf("\n %s is an identifier ",str);
	}
}
int main()
{
	FILE *f1,*f2,*f3;
	char a,str[10],st1[10];
	int num[100],lineno=0,tokenvalue=0;
	i=0,j=0,k=0;
	clrscr();
	printf("\nenter the c program: ");
	f1=fopen("input","w");
	while((c=getchar())!=EOF)
	{
		put(c,f1);
		fclose(f1);
	}
	f1=open("input","r");
	f2=open("identifier","w");
	f3=open("special char","w");
	while((c=getc(f1))!=EOF)
	{
		if(isdigit(c))
		{
			tokenvalue=c-'0';
			c=getc(f1);
			while(isdigit(c))
			{
				tokenvalue*=10+c-'0';
				c=getc(f1);
			}
			num[i++]=tokenvalue;
			ungetc(c,f1);
		}
		else if(isalpha(c))
		{
			put(c,f2);
			c=getc(f1);
			while(isdigit(c)||isalpha(c)||c=='-'||c=='$')
			{
				putc(c,f2);
				c=getc(f1);
			}
				putc('',f2);
		unget(c,f1);
		
		}
		else if(c==''||c=='\t')
		{
			printf(" ");
		}
		else if(c=="\n")
		{
			lineno++;
		}
		else{
			put(c,f3);
		}
	
	}
	
}
 
