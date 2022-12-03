#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#define size 500

void gotoxy (int column, int line){
      COORD coord = { 0 ,0 };
      coord.X = column;
      coord.Y = line;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
void display_screen(); //for styling of front page
void display_screen2();  //for styling of all pages after front page  
void main_page();  //front page
void admin();   //admin portal
//void admin_teacher_information_management(); //teacher management in admin portal
void admin_password();  //for password of admin portal
void admin_teacher_information_management();
void admin_student_information_management();
void teacher_info_add();
void teacher_info_read();

int main(){
	main_page();
    }

void main_page(){
	char user_choice;
	system("CLS");
	system("COLOR FC");
	display_screen();
	gotoxy(22,11);
	printf("Press S for Student Portal\n");
	gotoxy(22,12);
	printf("Press T for Teacher Portal\n");
	gotoxy(22,13);
	printf("Press A for Admin Portal\n");
	gotoxy(22,15);
	printf("Select choice: ");
	gotoxy(36,15);
	scanf("%c", &user_choice);
	system("CLS");
	
	switch(user_choice){
		case 'A':
		case 'a':
		     admin_password();
			 break;	
		
	}    
}

void display_screen(){
	int col=20,row=5,i;
	for(i=5;i<=20;i++){ 
		gotoxy(20,i);
		printf("\xdb");
		usleep(10000);
	}

	for(i=5;i<=20;i++){ 
		gotoxy(80,i);
		printf("\xdb");
		usleep(10000);
	}

	gotoxy(21,5);
	for(i=21;i<80;i++){ 
		usleep(10000);
		printf("\xdb");
	}

	gotoxy(21,20);
	for(i=21;i<80;i++){
		usleep(10000);
		printf("\xdb");
	}

	gotoxy(21,9);
	for(i=21;i<80;i++){
		usleep(10000);
		printf("\xdb");
	}
	
	gotoxy(21,7);
	printf("\t\t  ");
	char d[40]="Welcome to University Portal ";
	for(i=0;i<40;i++){
		usleep(10000);
		printf("%c",d[i]);
	}
}

void display_screen2(){
	int col=20,row=5,i;
	for(i=5;i<=20;i++){ 
		gotoxy(20,i);
		printf("\xdb");
	}

	for(i=5;i<=20;i++){ 
		gotoxy(80,i);
		printf("\xdb");
	}

	gotoxy(21,5);
	for(i=21;i<80;i++){ 
		printf("\xdb");
	}

	gotoxy(21,20);
	for(i=21;i<80;i++){
		printf("\xdb");
	}

	gotoxy(21,9);
	for(i=21;i<80;i++){
		printf("\xdb");
	}
	
	gotoxy(21,7);
	printf("\t\t  ");
	char d[40]="Welcome to UNIVERSITY PORTAL ";
	for(i=0;i<40;i++){
		printf("%c",d[i]);
	}
}
void admin_password(){
	display_screen2();
    int pass = 12345;
    int admin_pass, i, attempt = 3;
    for (i = 1; i <= 3; i++)
    {
    	gotoxy(22,15);
        printf("Enter password: ");
        scanf("%d", &admin_pass);
        attempt--;
        if (admin_pass != pass && attempt >= 1)
        {
            system("CLS");
            display_screen2();
            gotoxy(22,12);
            printf("Password Incorrect. ");
            printf("You have %d attempts left.\n", attempt);
        }
        else if (admin_pass != pass && attempt == 0)
        {
        	system("CLS");
        	display_screen2();
        	gotoxy(22,13);
            printf("Access Blocked\n");
            getch();
            system("CLS");
            break;
        }
        if (admin_pass == pass)
        {
        	display_screen2();
        	gotoxy(22,12);
            printf("Access Granted");
            usleep(10000);
            system("CLS");
            admin();
            break;
        }
    }
}
void admin(){
	display_screen2();
    int admin_choice, admin_choice_teacher, admin_choice_student, admin_choice_course;
    gotoxy(22,10);
    printf("Welcome to Admin Portal");
    gotoxy(22,12);
    printf("Press 1 for Teacher Management");
    gotoxy(22,13);
	printf("Press 2 for Student Manangement");
	gotoxy(22,14);
	printf("Press 3 for Course Management");
	gotoxy(22,15);
	printf("Press 4 to go to the Previous Menu");
    gotoxy(22,16);
	printf("Press 5 to Exit");
    gotoxy(22,18);
	printf("Enter choice: ");
    scanf("%d", &admin_choice);
    system("CLS");
    switch (admin_choice)
    {
    case 1:   
    	display_screen2();
    	gotoxy(22,10);
        printf("Welcome to Teacher Management");
        gotoxy(22,12);
        printf("Press 1 for Updating or showing Teacher's information");
        gotoxy(22,13);
        printf("Press 2 for Deleting Teacher's information\n");
        gotoxy(22,14);
        printf("Press 3 for Teacher's Class Shedule\n");
        gotoxy(22,15);
        printf("Press 4 for Teacher's salary management\n");
        gotoxy(22,18);
        printf("Enter choice: ");
        scanf("%d", &admin_choice_teacher);
        system("CLS");
        switch (admin_choice_teacher)
        {
        case 1:
            admin_teacher_information_management();
            break;
        }
        break;
        
    case 2:
    	display_screen2();
    	gotoxy(22,10);
        printf("Welcome to Student Management");
        gotoxy(22,12);
        printf("Press 1 for Updating or showing Student's information");
        gotoxy(22,13);
        printf("Press 2 for Deleting Student's information\n");
        gotoxy(22,14);
        printf("Press 3 for Student's Class Shedule\n");
        gotoxy(22,15);
        printf("Press 4 for Student's fees management\n");
        gotoxy(22,17);
        printf("Enter choice: ");
        scanf("%d", &admin_choice_student);
        system("CLS");
        switch (admin_choice_student)
        {
        case 1:
            admin_student_information_management();
            break;
        }
        break;

	case 3:
	    display_screen2();
	    gotoxy(22,10);
	    printf("Welcome to Course Management");
	    gotoxy(22,12);
	    printf("Press 1 for adding new course");
	    gotoxy(22,13);
	 	printf("Press 2 for reviewing courses");
	 	gotoxy(22,18);
	 	printf("Enter choice: ");
	 	scanf("%d", &admin_choice_course);
//		switch(admin_choice_course)	
        break;
	 }
}

 void admin_teacher_information_management(){   
    display_screen2();
    int admin_choice_teacher_info;
 	gotoxy(22,11);
    printf("Press 1 for reviewing information");
    gotoxy(22,12);
 	printf("Press 2 for adding new information");
    gotoxy(22,14);
 	printf("Enter choice: ");
    scanf("%d", &admin_choice_teacher_info);
    system("CLS");
    switch (admin_choice_teacher_info)
     {
      case 2:
      	teacher_info_add();
        break;
     }
 }

void admin_student_information_management(){   
	int admin_choice_student_info;
	display_screen2();
	gotoxy(22,11);
    printf("Press 1 for reviewing information");
    gotoxy(22,12);
	printf("Press 2 for adding new information");
    gotoxy(22,14);
	printf("Enter choice: ");
    scanf("%d", &admin_choice_student_info);
    system("CLS");
//    switch (admin_choice2_1)
//    {
//	}
//    	
}

void teacher_info_add(){
	display_screen2();
	int i;
	struct teacher_info_add{
		char name[50];
		int course_quantity;
		char course_name[50];
		int salary;
	}t1;
	
	FILE *fp;
	fp = fopen("teacher_info_add.txt", "w");
	
	if(fp == NULL){
		printf("File is not found\n");
	}
	
	gotoxy(22,10);
	printf("Enter teacher name: ");
    fflush(stdin);
	gets(t1.name);
	
	fprintf(fp, "Teacher's Name: %s\n", t1.name);
	
	gotoxy(22,11);
	printf("Enter number of courses: ");
	scanf("%d", &t1.course_quantity);
	
	fprintf(fp, "Total No of courses: %d\n", t1.course_quantity);
	
	int y = 12;
	for(i=0; i<t1.course_quantity; i++){
		fflush(stdin);
		gotoxy(22,y);
		printf("Enter course %d name: ", i+1);
		gets(t1.course_name);
		y++;
		fprintf(fp, "Course %d name: %s\n", i+1, t1.course_name);
	}
	
	gotoxy(22,y);
	printf("Enter salary: ");
	scanf("%d", &t1.salary);
	fflush(stdin);
	fprintf(fp, "Salary: %d\n", t1.salary);

    fclose(fp);
}

void teacher_info_read(){
	display_screen2();
	char data[size], name2[size];
    char name1[size] = {"Teacher's Name: "};
	char *fptr;
	
	fptr = (char *)malloc(size * sizeof(char));
	
	FILE *fp;
    
	fp = fopen("teacher_info_add.txt", "r");
	
	if(fp == NULL){
		printf("File not found");
	}
	
	gotoxy(22,10);
	printf("Enter teacher name: ");
	gets(name2);
	
	strcat(name1, name2);
	strcat(name1, "\n");
	
	while(fgets(data, 500, fp)){
		if(strcmp(name1, data)==0){
			printf("%s", data);
		    while(fgets(data, 500, fp) && data[0] != '\n'){
				printf("%s", data);	
	 	    }
	    }
	    else{
	    	printf("Name not found");
		}
		break;
	}
}

