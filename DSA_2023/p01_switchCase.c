#include<stdio.h>

int main(){
    int suite =1;
    int a=37, b=27;
    printf("%d\n", (a%b));
    switch(suite)
    {
        default:
        printf("Default\n");
        case 0:
        printf("Club\n");
        case 1:
        printf("Diamond\n");
    }
    for (int a=0; a<5; a++){
        switch (a){
            case 0: printf("%d ",a++);
            case 1: printf("%d ", ++a);
            case 2: printf("%d", a);
            case 3: printf("%d", a);
            case 4: printf("%d", a);
            default:printf("End ");
        }
    }

    int d[5] = {1,2,3,4,5};
    /*
    for (int i=0;i<5;i+1){
        printf(",%d",i);
    }*/






    return 0;
}