#include<stdio.h>
int main(){
	char str1[] = "Geeks",str2[30];
	scanf("%s",str2);
	printf("%s",str2);
	for(int i=0; i<sizeof(str2);i++){
		if(str2[i]=='\0') break;
		printf("%d : %c\n",i, str2[i]);
	}
	for(int i=0; i<sizeof(str1);i++){
		printf("%d : %c\n",i, str1[i]);
	}


	return 0;
}
