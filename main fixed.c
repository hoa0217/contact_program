#include <stdio.h>
#include <string.h>

#define MAX_NUM 100

//���� ���� ����ü
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
	User user[MAX_NUM];//���� ���� ����ü �迭 
	int person = 0;
	
	//�޴�����
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
void add(User* ptr, int*num){
	printf("1�� ����\n\n");
}

void list(User* ptr, int*num){
	printf("2�� ����\n\n");
}
int search(User* ptr, int*num){
	char name[30];
	int i;
	
	//����� �����Ͱ� �ִٸ�
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
	else{
		printf(" No Data\n\n");
		return 0;
	}
}

void edit(User* ptr, int*num){
	printf("4�� ����\n\n");
}

int deleted(User* ptr, int*num){
	printf("5�� ����\n\n");
}

void egg(User* ptr, int*num){
	printf("6�� ����\n\n"); 
}


