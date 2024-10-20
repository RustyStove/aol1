#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct hotels {
	char location1[101];
	char location2[101];
	long int price;
	int room;
	int bathroom;
	int carpark;
	char type[101];
	int area;
	char furnish[101];
};

struct hotels hotel[4040];
int count;

int main() {
	FILE*f=fopen("file.csv","r");
	char header[101];
	fscanf(f,"%[^\n]\n",header);


	while(!feof(f)) {

		fscanf(f,"%[^,],",hotel[count].location1);
		fscanf(f,"%[^,],",hotel[count].location2);
		fscanf(f,"%ld,",&hotel[count].price);
		fscanf(f,"%d,",&hotel[count].room);
		fscanf(f,"%d,",&hotel[count].bathroom);
		fscanf(f,"%d,",&hotel[count].carpark);
		fscanf(f,"%[^,],",hotel[count].type);
		fscanf(f,"%d,",&hotel[count].area);
		fscanf(f,"%[^\n]\n",hotel[count].furnish);

		if(strcmp(hotel[count].location1,"\0")==0) {
			break;
		}
		count++;
	}


	int choice;
	while(choice!=10) {
		if(count > 1) {
			printf("\n======================LIST=======================\n\n");
			printf("1. Location 1\n");
			printf("2. Location 2\n");
			printf("3. Price\n");
			printf("4. Room\n");
			printf("5. Bathroom\n");
			printf("6. Carpark\n");
			printf("7. Room type\n");
			printf("8. Area\n");
			printf("9. Furnish\n");
			printf("10. Exit\n\n");

			printf("Select 1 Column: ");
			scanf("%d",&choice);

            if(choice==1){
                char a1[4040][101];
            char finds1[4040][101];
            int inc1=0;
            int find1[101];
	        for(int i=1;i<count;i++){
                strcpy(a1[i],hotel[i].location1);
	        }
            printf("\n\n========LIST========\n====================\n\n");
	        int counter1=0;
	        for(int i =1;i<count;i++){
		        if(strcmp(a1[i],"x")!=0){
			        char temp1[100];
			        strcpy(temp1,a1[i]);
			        counter1 =0;
			        for(int j=1;j<count;j++){	
				        if(strcmp(temp1,a1[j])==0){
					        strcpy(a1[j],"x");
					        counter1++;
				        }
			        }
			    printf("%s : %d\n",temp1,counter1);
                inc1++;
                strcpy(finds1[inc1],temp1);
                find1[inc1]=counter1; 
		        }   
	        }
            printf("Total: %d\n",inc1);
            int max1=find1[1];
            char maxs1[101];
            int min1=find1[1];
            char mins1[101];
            int inc11=inc1;
            for(int k=inc11;k>=1;k--){
                if(find1[k]<min1){
                    min1=find1[k];
                    strcpy(mins1,finds1[k]);
                }
            }
            printf("Minimum value: %s with frequency %d\n",mins1,min1);
            for(int j=1;j<inc1;j++){
                if(find1[j]>=max1){
                    max1=find1[j];
                    strcpy(maxs1,finds1[j]);
                } 
            }
            printf("Maximum value: %s with frequency %d\n",maxs1,max1);
            }
			else if(choice==3) { 
				int max3=hotel[1].price;
				int min3=hotel[1].price;
				for(int j=2; j<count; j++) {
					if(hotel[j].price>max3) {
						max3=hotel[j].price;
					}
				}

				for(int j=2; j<count; j++) {
					if(hotel[j].price<min3) {
						min3=hotel[j].price;
					}
				}
                printf("\n\n========LIST========\n====================\n\n");
				printf("Minimum price: %d\n",min3);
				printf("Maximum price: %d\n",max3);

				
				int average3=0;
				for(int j=0; j<count; j++) {
					average3+=hotel[j].price;
				}
				printf("Price Average: %d\n",average3/=count);

            
			} else if(choice==8) {
				int max8=hotel[1].area;
				int min8=hotel[1].area;
				for(int j=2; j<count; j++) {
					if(hotel[j].area>max8) {
						max8=hotel[j].area;
					}
				}

				for(int j=2; j<count; j++) {
					if(hotel[j].area<min8) {
						min8=hotel[j].area;
					}
				}
                printf("\n\n========LIST========\n====================\n\n");
				printf("Minimum area: %d\n",min8);
				printf("Maximum area: %d\n",max8);
				int average8=0;
				for(int j=1; j<count; j++) {
					average8+=hotel[j].area;
				}
				printf("Area Average: %d\n",average8/count);
            }
		}
	}

	fclose(f);
}

