#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();



/*
 * Complete the 'getMinTotalNumChanges' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING oldPassStr
 *  2. STRING newPassStr
 */

int getMinTotalNumChanges(char* oldPassStr, char* newPassStr) {
    int ins=0,del=0, sz1=0,sz2=0; 
    // int sz1=sizeof(*oldPassStr)/sizeof(oldPassStr[0]);
    // int sz2=sizeof(*newPassStr)/sizeof(newPassStr[0]);
    printf("%d",sz1,sz2);
    while(oldPassStr[sz1++]);
    while(newPassStr[sz2++]);
    printf("%d,%d",sz1,sz2);
    // for(int i1=0; i1<sz1;i1++){
    //     for(int i2=0; i2<sz2; i2++){
    //         if(oldPassStr[i1] != newPassStr[i2]){
    //             if(i1<sz1 && oldPassStr[i1+1]==newPassStr[i2]){//delete from i1
    //                 del++; i1++;
    //             }
    //             else if(i2<sz2 && oldPassStr[i1]==newPassStr[i2+1]){//insert to i2
    //                 ins++; i2++;
    //             }
    //         }
    //     }
    // }
    return ins+del;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* oldPassStr = readline();

    char* newPassStr = readline();

    int result = getMinTotalNumChanges(oldPassStr, newPassStr);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
