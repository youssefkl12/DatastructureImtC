#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct patient{
	char name[100];
	int age;
	char gender;
	int ID;
	struct patient* getNext;
}patient;



patient* addNode(patient*head,char name[100],int age,char gender,int ID ){
	if(head==NULL){
		head=(patient*)malloc(sizeof(patient));
		//when I tired to assign the value to a new node
      	//then equat it to head it didnt work 
		//but with head directly it works
		strcpy(head->name,name);
		head->age=age;
		head->gender=gender;
		head->ID=ID;
		head->getNext=NULL;
		
	}else{
		patient*ptr=head;
        patient*newnode=(patient*)malloc(sizeof(patient));
		//newnode->data=value;
		strcpy(newnode->name,name);
		newnode->age=age;
		newnode->gender=gender;
		newnode->ID=ID;
		newnode->getNext=NULL;
		while(ptr!=NULL){
			if(ptr->getNext==NULL){
				ptr->getNext=newnode;
				break;
			}else{
				ptr=ptr->getNext;
			}
		}
	}
	//printf("hello");
		return head;
}









void printList(patient*head){
	patient*ptr;
	ptr=head;
	if(head==NULL){
		printf("NULL\n");
		return;
	}
	while(ptr!=NULL){
	printf("///////////////////\n");
	printf("name:%s\n",ptr->name);
	printf("age:%d\n",ptr->age);
	printf("gender:%c\n",ptr->gender);
	printf("ID:%d\n",ptr->ID);
	printf("///////////////////\n");
    if(ptr->getNext==NULL){
		break;
	}else{
	ptr=ptr->getNext;	
	} 	
		
	}

};

patient* EditData(patient*head,int id){
	char flag=0;
	char name[100];
	int age;
	char gender[10];
	int ID;
	patient*ptr;
	ptr=head;
	while(ptr->ID!=id){
		if(ptr->getNext==NULL){
			printf("ID doesnt exsist");
			flag=1;
			break;
		}
		ptr=ptr->getNext;	
	}
	if(flag==1){
		return head;
	}else{
		printf("1 to name, 2 age, 3 gender:\n");
			char switchCheck;
		scanf("%d",&switchCheck);
		switch(switchCheck){
			case 1:
			printf("enter name:");
			scanf("%s",&name);
			strcpy(ptr->name,name);
			break;
			case 2:
			printf("enter age:");
			scanf("%d",&age);
			ptr->age=age;
			break;
			case 3:
			printf("enter gender:");
			scanf("%s",&gender);
			ptr->gender=gender[0];
			break;
			
			
		}
		return head;
	}
	
	
}



void printListPatient(patient*head,int id){
	patient*ptr;
	ptr=head;
	if(head==NULL){
		printf("NULL\n");
		return;
	}
	while(ptr!=NULL){
		if(id=ptr->ID){
	printf("///////////////////\n");
	printf("name:%s\n",ptr->name);
	printf("age:%d\n",ptr->age);
	printf("gender:%c\n",ptr->gender);
	printf("ID:%d\n",ptr->ID);
	printf("///////////////////\n");
		}
    if(ptr->getNext==NULL){
		break;
	}else{
	ptr=ptr->getNext;	
	} 	
		
	}

};









void main(){
	/////////////////////////////////////
	int slotArray[5]={0};
	/////////////////////////////////////
	int programCheck=1;
	int ID_serarch;
	char name[100];
	int ageNum=0;
	char gender[10];//turned ut to string beacuse it was affecting the age number 
	int ID;
	char mode;
	char adminModeChoice;
	char userModeChoice;
	short int password;
	char exitout=0;
	int whileCheck=1;
	patient*head=NULL;
	while(programCheck){
	printf("choose mode:user is 1,admin is 0:\n");
	scanf("%d",&mode);
	switch(mode){
		case 0:printf("you have entered admin mode\n");
		
		for(int i;i<3;i++){
		printf("please enter your password\n");
		scanf("%d",&password);
			if(password==1234){
				printf("password is correct\n");
				//////////////////////////////
		//admin mode choices start here
			//////////////////////////////
			while(whileCheck){
			printf("to add new patient press 1\n");
			printf("to edite patient data press 2\n");
			printf("to reserve slot press 3\n");
			printf("to cancel reservation press 4\n");
			scanf("%d",&adminModeChoice);
			
			switch(adminModeChoice){
				case(1):
				printf("add new patient:\n");
				printf("name:");
				scanf("%s",&name);
				printf("age:  ");
				scanf("%d",&ageNum);
				printf("AGECHECK:%d\n",ageNum);
				printf("gender:");
				scanf("%s",&gender);                                 //this is what is causing the age problem;;;;;;;;;;;;scanf("%s ",&gender);
				//printf("%d\n",gender);
				//printf("genderCHECK:%c\n",gender);
                printf("age in main1:%d\n",ageNum);
				printf("ID:");
				scanf("%d",&ID);
				printf("age in main2:%d\n",ageNum);
				head=addNode(head,name,ageNum,gender[0],ID);
				printList(head);
				
				
				
				break;
				case(2):
				
				printf("edit data of the patient:\n");
				printf("please enter the patient ID:");
				scanf("%d",&ID_serarch);
				head=EditData(head,ID_serarch);
				
				break;
				case(3):
				printf("please choose a time from the avaliable(enter the number next to the time):\n");
				for(int i=0;i<5;i++){
					if(slotArray[i]==0){
						if(i==0&&slotArray[i]==0){
							printf("2:00-->2:30:%d\n",i);
							
						}else if(i==1&&slotArray[i]==0){
							printf("2:30-->3:00:%d\n",i);
							
						}else if(i==2&&slotArray[i]==0){
							printf("3:00-->3:30:%d\n",i);
							
						}else if(i==3&&slotArray[i]==0){
							printf("4:00-->4:30:%d\n",i);
							
						}else if(i==4&&slotArray[i]==0){
							printf("4:30-->5:00:%d\n",i);
							
						}
					}
					
					
				}
				
				int reserve;
				scanf("%d",&reserve);
				printf("enter patient id:");
				scanf("%d",&ID);
				slotArray[reserve]=ID;
				break;
				case(4):
				printf("please enter the id of the patient:");
				scanf("%d",&ID);
				for(int i=0;i<5;i++){
					if(slotArray[i]==ID){
					slotArray[i]=0;
					}
				}
				break;
				default:
				break;	
			}
			printf("1 to cintinue 0 to exit\n");
			scanf("%d",&whileCheck);
			}	
			whileCheck=1;
			break;//for the password for loop to end 
			}else{
				printf("password is incorrect please try again:\n");
				exitout++;
			}
			
		}
		if(exitout==4){
			printf("you have entered the password incorrect 3 times,exiting out:");
			return;
		}
		break;
		case 1:printf("you have entered user mode\n");
		printf("Print patient data press1:\n");
		printf("Print reserved dates press2:\n");
		scanf("%d",&userModeChoice);
		switch(userModeChoice){
			case 1:
			printf("enter patient ID:");
			scanf("%d",&ID);
			printListPatient(head,ID);
			break;
			case 2:
			printf("hi\n");
			for(int i=0;i<5;i++){
					if(slotArray[i]!=0){
						if(i==0&&slotArray[i]!=0){
							printf("2:00-->2:30:%d\n",slotArray[i]);
							
						}else if(i==1&&slotArray[i]!=0){
							printf("2:30-->3:00:%d\n",slotArray[i]);
							
						}else if(i==2&&slotArray[i]!=0){
							printf("3:00-->3:30:%d\n",slotArray[i]);
							
						}else if(i==3&&slotArray[i]!=0){
							printf("4:00-->4:30:%d\n",slotArray[i]);
							
						}else if(i==4&&slotArray[i]!=0){
							printf("4:30-->5:00:%d\n",slotArray[i]);
							
			}}}
			
			break;
			
			
		}
		break;
		default:printf("you have entered a wrong number\n");
	}
	}
	
}
