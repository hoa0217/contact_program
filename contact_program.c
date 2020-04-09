#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX_NUM 100

//정보 저장 구조체
typedef struct{
	char name [30];
	char number[30];
	char address[30];
	char email[30];
}User; 

void add(User*ptr,int*num);
int deleted(User*ptr,int*num);
int search(User*ptr,int*num);
void list(User*ptr,int*num);
int edit(User*ptr,int*num);
void egg(User*ptr,int*num);

int main(void) {
	int input;
	User user[MAX_NUM];//정보 저장 구조체 배열 
	int person = 0;
	
	//메뉴선택
	while(1){
		system( "cls" );
		printf("\t**** Welcome to Contact Management System ****\n\n");
		printf("\t\t\tMAIN MENU\n");
		printf("=========================================================\n");
		printf("\t\t[1] Add a new Contact\n");
		printf("\t\t[2] List all Contacts\n");
		printf("\t\t[3] Search for contact\n");
		printf("\t\t[4] Edit a Contact\n");
		printf("\t\t[5] Delete a Contact\n");
		printf("\t\t[6] Eater Egg\n");
		printf("\t\t[0] Exit\n");
		printf("=========================================================\n");
		printf("\nEnter the choice: \n");
		scanf("%d", &input);
		
		if (input == 1){
			system( "cls" );
			printf("\n[Add]\n");
			add(user,&person);
			getch();
		}
		else if (input == 2){
			system( "cls" );
			printf("\n[List]\n");
			list(user,&person);
			getch();
		}
		else if (input == 3){
			system( "cls" );
			printf("\n[Search]\n");
			search(user,&person);
			getch();
		}
		else if (input == 4){
			system( "cls" );
			printf("\n[Edit]\n");
			edit(user,&person);
			getch();
		}
		else if (input == 5){
			system( "cls" );
			printf("\n[Deleted]\n");
			deleted(user,&person);
			getch();
		}
		else if (input == 6){
			system( "cls" );
			printf("\n[Egg]\n");
			egg(user,&person);
			getch();
		}
		else if (input == 0){
			system( "cls" );
			printf("\n[Exit]\n");
			return 0;
		}
		else
			system( "cls" );
			printf("\nerror! Please retry! \n\n");

		} 
	return 0;
}

//1번 데이터  추가 
void add(User* ptr, int*num){
	if (*num < MAX_NUM){
          printf("Input Name: ");
          scanf("%s", ptr[*num].name);
          printf("Input Phone number: ");
          scanf("%s", ptr[*num].number);
          printf("Input Address: ");
          scanf("%s", ptr[*num].address);
          printf("Input Email: ");
          scanf("%s", ptr[*num].email);

          (*num)++;
          printf("=========================================================\n");
          printf("\t\tSuccessful Data Inserted");
     }
     
     else
          printf("\t\tData Full");
    }

//2번 리스트 출력  
void list(User* ptr, int*num){
	int i = 0;
	 if (*num > 0){
          for (i = 0; i < *num; i++){
               printf("Name: %s", ptr[i].name);
               printf("\tPhone: %s", ptr[i].number);
               printf("\tAddress: %s", ptr[i].address);
               printf("\tEmail: %s\n", ptr[i].email);
          }
          printf("=========================================================\n");
          printf("\t\tSuccessful Data Print");
     }
     else{
     	printf("=========================================================\n");
        printf("\t\tNo Data");
    }
}

//3번 검색기능  
int search(User* ptr, int*num){
	char phone[30];
	int i;
	

	if(*num>0){
		printf("Input Phone number: ");
		scanf("%s", phone);
		for(i=0;i<MAX_NUM;i++){
			if(!strcmp(phone,ptr[i].number)){
				printf("Name: %s", ptr[i].name);
				printf("\tPhone: %s", ptr[i].number);
				printf("\tAddress: %s", ptr[i].address);
				printf("\tEmail: %s\n", ptr[i].email);
				printf("=========================================================\n");
				printf("\t\tSuccessful Data Found");
				return 0;
			}
		}
		printf("=========================================================\n");
		printf("\t\tNot Found");
		return 0;
	} 

	else{
		printf("=========================================================\n");
		printf("\t\tNo Data");
	}
}

//4번 데이터 편집  
int edit(User* ptr, int*num){
	char name[30];
	int i;
	
	if(*num>0){
		printf("Input Name: ");
		scanf("%s", name);
		for(i=0;i<MAX_NUM;i++){
			if(!strcmp(name,ptr[i].name)){
				printf("=========================================================\n");
				printf("\t\tData found\n");
				printf("\t\tpleas edit start!\n");
				printf("=========================================================\n");
				printf("Input Name: ");
		        scanf("%s", ptr[i].name);
		        printf("Input Phone number: ");
		        scanf("%s", ptr[i].number);
		        printf("Input Address: ");
		        scanf("%s", ptr[i].address);
		        printf("Input Email: ");
		        scanf("%s", ptr[i].email);
		        printf("=========================================================\n");
				printf("\t\tData edit success!");
				return 0;
			}
		}
		printf("=========================================================\n");
		printf("\t\tNot Found");
		return 0;
	} 

	else{
		printf("=========================================================\n");
		printf("\t\tNo Data\n\n");
	}
}
 
//5번 데이터 삭제  
int deleted(User* ptr, int*num){
	char name[30];
     int i, j;
     
     if (*num > 0){
          printf("Input Name: ");
          scanf("%s", name);

          for (i = 0; i < MAX_NUM; i++){
               
               if (strcmp(name, ptr[i].name) == 0){
                    (*num)--;
                    printf("=========================================================\n");
                    printf("\t\tSuccessful Data Deleted");
                    
                    if (i != MAX_NUM - 1){
                         for (j = i; j < MAX_NUM; j++){    
                              strcpy(ptr[j].name, ptr[j + 1].name);
                              strcpy(ptr[j].number, ptr[j + 1].number);
                              strcpy(ptr[j].address, ptr[j + 1].address);
                              strcpy(ptr[j].email, ptr[j + 1].email);
                         }

                     *ptr[MAX_NUM - 1].name = NULL;
                     *ptr[MAX_NUM - 1].number = NULL;
					 *ptr[MAX_NUM - 1].address = NULL;
                     *ptr[MAX_NUM - 1].email = NULL;
                }


                else{
                     *ptr[MAX_NUM - 1].name = NULL;
                     *ptr[MAX_NUM - 1].number = NULL;
                     *ptr[MAX_NUM - 1].address = NULL;
                     *ptr[MAX_NUM - 1].email = NULL;
                }
                return 0;
               }
          }
          printf("=========================================================\n");
          printf("\t\tNot Found");
          return 0;
	}
	else{
		printf("=========================================================\n");
		printf("\t\tNo data");
	}
}
//이스터에그  
void egg(User* ptr, int*num){
	if (*num < MAX_NUM){
		char name1[30]= "HAN YEON JAE";;
		char number1[30]= "01033797498";
		char address1[30]= "Wonju";
		char email1[30]="kevin7498@naver.com";
		char name2[30]= "HEO JEONG HWA";
		char number2[30]= "01033541083";
		char address2[30]= "Suncheon";
		char email2[30]="gjwjdghk123@gmail.com";
		strcpy(ptr[*num].name,name1);
		strcpy(ptr[*num].number,number1);
		strcpy(ptr[*num].address,address1);
		strcpy(ptr[*num].email,email1);
		++(*num);
		strcpy(ptr[*num].name,name2);
		strcpy(ptr[*num].number,number2);
		strcpy(ptr[*num].address,address2);
		strcpy(ptr[*num].email,email2);
        (*num)++;
        printf("=========================================================\n");
        printf("\t\tthis is egg!\n");
        printf("\t\tplease check list!");
        
     }
     
     else
          {
          	printf("=========================================================\n");
          	printf("\t\tSorry...full");
		  }
}

