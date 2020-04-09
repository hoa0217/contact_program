#include <stdio.h>
#include <string.h>

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
void edit(User*ptr,int*num);
void egg(User*ptr,int*num);

int main(void) {
	int input;
	User user[MAX_NUM];//정보 저장 구조체 배열 
	int person = 0;
	
	//메뉴선택
	while(1){
		printf("**** Welcome to Contact Management System ****\n\n");
		printf("MAIN MENU\n");
		printf("===============\n");
		printf("[1] Add a new Contact\n");
		printf("[2] List all Contacts\n");
		printf("[3] Search for contact\n");
		printf("[4] Edit a Contact\n");
		printf("[5] Delete a Contact\n");
		printf("[6] Eater Egg\n");
		printf("[0] Exit\n");
		printf("===============\n");
		printf("Enter the choice: \n");
		scanf("%d", &input);
		
		if (input == 1){
			printf("\n[Add]\n");
			add(user,&person);
		}
		else if (input == 2){
			printf("\n[List]\n");
			list(user,&person);
		}
		else if (input == 3){
			printf("\n[Search]\n");
			search(user,&person);
		}
		else if (input == 4){
			printf("\n[Edit]\n");
			edit(user,&person);
		}
		else if (input == 5){
			printf("\n[Deleted]\n");
			deleted(user,&person);
		}
		else if (input == 6){
			printf("\n[Egg]\n");
			egg(user,&person);
		}
		else if (input == 0){
			printf("\n[Exit]\n");
			return 0;
		}
		else
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
          printf("===============\n");
          printf("  Successful Data Inserted \n\n");
     }
     
     else
          printf("  Data Full \n\n");
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
          printf("\n\t\tSuccessful Data Print \n\n");
     }
     else
          printf("\tNo Data \n\n");
    }


//3번 검색기능  
int search(User* ptr, int*num){
	char name[30];
	int i;
	
	//저장된 데이터가 있다면
	if(*num>0){
		printf("Input Name: ");
		scanf("%s", name);
		for(i=0;i<MAX_NUM;i++){
			if(!strcmp(name,ptr[i].name)){
				printf("Name: %s", ptr[i].name);
				printf("Tel: %s\n", ptr[i].number);
				printf("Address: %s\n", ptr[i].address);
				printf("Email: %s\n", ptr[i].email);
				printf(" Data Found\n\n");
				return 0;
			}
		}
		printf("Not Found\n\n");
		return 0;
	} 
	//저장된 데이터가 없다면 
	else{
		printf(" No Data\n\n");
	}
}

//4번 데이터 편집  
void edit(User* ptr, int*num){
	printf("4번 구현\n\n");
}
 
//5번 데이터 삭제  
int deleted(User* ptr, int*num){
	printf("5번 구현\n\n");
}

//이스터에그  
void egg(User* ptr, int*num){
	printf("6번 구현\n\n"); 
}
