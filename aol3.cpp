#include <stdio.h>
#include <string.h>

void bubbleSort(char arr[][5000], int n){
    long int i, j;
    char temp[5000];
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0){
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int main(){
	printf("Enter the number of towns: ");
	FILE *fp = fopen ("file.csv", "r");
    long int n;
	scanf("%ld", &n);
    char towns[n][5000];
    long int i;
    for (i = 0; i < n; i++){
        printf("Enter the name of town %d: ", i + 1);
        scanf("%s", towns[i]);
    }
    bubbleSort(towns, n);
    printf("Alphabetized list of towns: \n");
    for (i = 0; i < n; i++){
        printf("%s\n", towns[i]);
    }
    fclose(fp);
    return 0;
}
