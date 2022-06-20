#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void main(){

int i, j, ic = 0, m, cc = 0, oc = 0;
char b[30],operators[30],identifiers[30],constants[30]; // b is the input array

printf("\tenter the string : ");
scanf("%[^\n]s",b);

for(i = 0; i < strlen(b); i++){

    if(isspace(b[i])){
        continue;
    }
    else if(isalpha(b[i])){
        identifiers[ic] = b[i];
        ic++;
    }
    else if(isdigit(b[i])){
        m = (b[i] - '0');
        i=i+1;
        while(isdigit(b[i])){
            m = m * 10 + (b[i] - '0');
            i++;
        }
        constants[cc]=m;
        cc++;
    }
     else{
        if(b[i] == '*'){
            operators[oc] = '*';
            oc++;
        }
        else if(b[i] == '-'){
            operators[oc] = '-';
            oc++;
        }
        else if(b[i] == '+'){
            operators[oc] = '+';
            oc++;
        }
         else if(b[i] == '='){
            operators[oc] = '=';
            oc++;
        }

  }

}
// printing

    printf("\tidentifiers : ");
     for(j = 0; j < ic; j++){
        printf("%c ",identifiers[j]);
     }
     printf("\n\t constants : ");
     for(j = 0; j < cc; j++){
        printf("%d ",constants[j]);
     }
     printf("\n\t operators : ");
     for(j = 0; j < oc; j++){
       printf("%c ",operators[j]);
     }

	printf("\n");

}
