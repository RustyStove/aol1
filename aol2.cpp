#include <stdio.h>
#include <string.h>

char loc1[4000][255], loc2[4000][255], price[4000][255], room[4000][255], bathrooms[4000][255], carparks[4000][255], type[4000][255], area[4000][255], furnish[4000][255];

int main() {
	FILE *fp = fopen("file.csv", "r");
	
	int line = 0;
	if(fp == NULL) {
		puts("File does not exist!");
		return 0;
	} else {
		while(!feof(fp)) {
			if(line == 0) {
				char header[2300];
				fscanf(fp, "%[^\n]\n", header);
			} else {
				fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", loc1[line], loc2[line], price[line], room[line], bathrooms[line], carparks[line], type[line], area[line], furnish[line]);
			}
			line++;
		}
	}
	
	char dataX[255], columnName[255];
	printf("Type \"[DataX] in [ColumnName]\" to search: ");
	scanf("%s in %[^\n]", dataX, columnName);
	getchar();
	puts("");
	
	if(strcmp(columnName, "loc1") == 0) {
		int found = 0;
		for(int i = 1; i < line; i++) {
			if(strstr(loc1[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (line - 1)) && (found == 0)) {
				printf("Data \"%s\" does not exist!\n", dataX);
			}
		}
	} else if(strcmp(columnName, "loc2") == 0) {
		int found = 0;
		for(int i = 1; i < line; i++) {
			if(strstr(loc2[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (line - 1)) && (found == 0)) {
				printf("Data \"%s\" does not exist!\n", dataX);
			}
		}
	} else if(strcmp(columnName, "room") == 0) {
		int found = 0;
		for(int i = 1; i < line; i++) {
			if(strstr(room[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (line - 1)) && (found == 0)) {
				printf("Data \"%s\" does not exist!\n", dataX);
			}
		}
	} else if(strcmp(columnName, "bathrooms") == 0) {
		int found = 0;
		for(int i = 1; i < line; i++) {
			if(strstr(bathrooms[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (line - 1)) && (found == 0)) {
				printf("Data \"%s\" does not exist!\n", dataX);
			}
		}
	} else if(strcmp(columnName, "carparks") == 0) {
		int found = 0;
		for(int i = 1; i < line; i++) {
			if(strstr(carparks[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (line - 1)) && (found == 0)) {
				printf("Data \"%s\" does not exist!\n", dataX);
			}
		}
	} else if(strcmp(columnName, "type") == 0) {
		int found = 0;
		for(int i = 1; i < line; i++) {
			if(strstr(type[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (line - 1)) && (found == 0)) {
				printf("Data \"%s\" does not exist!\n", dataX);
			}
		}
	} else if(strcmp(columnName, "furnish") == 0) {
		int found = 0;
		for(int i = 1; i < line; i++) {
			if(strstr(furnish[i], dataX) != NULL) {
				printf(" %-19s| %-20s| %-8s| %-3s| %-3s| %-3s| %s | %s | %s\n", loc1[i], loc2[i], price[i], room[i], bathrooms[i], carparks[i], type[i], area[i], furnish[i]);
				
				found = 1;
			} else if((i == (line - 1)) && (found == 0)) {
				printf("Data \"%s\" does not exist!\n", dataX);
			}
		}
	} else {
		printf("Column \"%s\" does not exist!\n", columnName);
	}
	
	fclose(fp);
	
	return 0;
}

