#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void pm();
void plus();
void divF();
char *strrev(char *str);
int i,ch,j,l,addr=100;
char ex[10], arr[10] ,arr1[10],arr2[10],id1[5],op[5],id2[5];

void main()
{
	while(1)
	{
		printf("\n\t1.assignment\n\t2.arithmetic\n\t3.relational\n\t4.Exit\n\tEnter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n\tEnter the arrression with assignment operator:");
				scanf("%s",arr);
				l=strlen(arr);
				arr2[0]='\0';
				i=0;
				while(arr[i]!='=')
				{
					i++;
				}
				strncat(arr2,arr,i);
				strrev(arr);
				arr1[0]='\0';
				strncat(arr1,arr,l-(i+1));
				strrev(arr1);
				printf("\tThree address code:\n\ttemp=%s\n\t%s=temp\n\t",arr1,arr2);
				break;

			case 2:
				printf("\n\tEnter the arrression with arithmetic operator:");
				scanf("%s",ex);
				strcpy(arr,ex);
				l=strlen(arr);
				arr1[0]='\0';

				for(i=0;i<l;i++)
				{
					if(arr[i]=='+'||arr[i]=='-')
					{
						if(arr[i+2]=='/'||arr[i+2]=='*')
						{
							pm();
							break;
						}
						else
						{
							plus();
							break;
						}
					}
					else if(arr[i]=='/'||arr[i]=='*')
					{
						divF();
						break;
					}
				}
				break;

			case 3:
				printf("\tEnter the arrression with relational operator");
				scanf("%s%s%s",id1,op,id2);
				if(((strcmp(op,"<")==0)||(strcmp(op,">")==0)||
						(strcmp(op,"<=")==0)||(strcmp(op,">=")==0)||
								(strcmp(op,"==")==0)||(strcmp(op,"!=")==0))==0)
					printf("arrression is error");

				else
				{
					printf("\n\t%d\tif %s%s%s goto %d",addr,id1,op,id2,addr+3);
					addr++;
					printf("\n\t%d\t T:=0",addr);
					addr++;
					printf("\n\t%d\t goto %d",addr,addr+2);
					addr++;
					printf("\n\t%d\t T:=1",addr);
				}
				break;

			case 4:
				exit(0);
		}
	}
}


void pm()
{
	strrev(arr);
	j=l-i-1;
	strncat(arr1,arr,j);
	strrev(arr1);
	printf("\tThree address code:\n\ttemp=%s\n\ttemp1=%c%ctemp\n\t",arr1,arr[j+1],arr[j]);
}

void divF()
{
	strncat(arr1,arr,i+2);
	printf("\tThree address code:\n\ttemp=%s\n\ttemp1=temp%c%c\n\t",arr1,arr[i+2],arr[i+3]);
}

void plus()
{
	strncat(arr1,arr,i+2);
	printf("\tThree address code:\n\ttemp=%s\n\ttemp1=temp%c%c\n\t",arr1,arr[i+2],arr[i+3]);
}

char *strrev(char *str){
    char c, *front, *back;

    if(!str || !*str)
        return str;
    for(front=str,back=str+strlen(str)-1;front < back;front++,back--){
        c=*front;*front=*back;*back=c;
    }
    return str;
}
