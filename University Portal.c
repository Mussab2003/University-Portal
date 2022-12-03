#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#define size 3000

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
void admin_password();  //for password of admin portal
void admin_teacher_management(); //teacher management in admin portal
void admin_teacher_information_management(); //teacher info update and review in admin portal
void teacher_info_add(); // teacher info add in admin portal
void teacher_info_read(); //teacher info review in admin portal
void admin_student_management(); //student management in admin portal
void admin_student_information_management(); //student info update and review in admin portal
void student_info_add(); //student info add in admin portal
void student_info_read(); //student info review in admin portal
void admin_student_information_remove(); //To remove data of a student
void admin_course_management(); //course management in admin portal
void admin_course_add();
void admin_course_read();

int main(){
	main_page();
    }

void main_page(){
	char user_choice;
	system("CLS");
	system("COLOR F3"); //to change the font colour
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
    for (i = 1; i <= 3; i++){
    	gotoxy(22,15);
        printf("Enter password: ");
        scanf("%d", &admin_pass);
        attempt--;
        if (admin_pass != pass && attempt >= 1){
            system("CLS");
            display_screen2();
            gotoxy(22,12);
            printf("Password Incorrect. ");
            printf("You have %d attempts left.\n", attempt);
        }
        else if (admin_pass != pass && attempt == 0){
        	system("CLS");
        	display_screen2();
        	gotoxy(22,13);
            printf("Access Blocked\n");
            getch();
            system("CLS");
            break;
        }
        if (admin_pass == pass){
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
    int admin_choice;
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
    	admin_teacher_management();
        break;
        
    case 2:
    	admin_student_management();
        break;

	case 3:
	    admin_course_management();	
        break;
	 
	 case 4:
	 	main_page();
	 	break;
	 
	 case 5:
	    break; 
	 }
}

void admin_teacher_management(){
    display_screen2();
	int admin_choice_teacher;
    gotoxy(22,10);
    printf("Welcome to Teacher Management");
    gotoxy(22,12);
    printf("Press 1 for Updating or showing Teacher's information");
    gotoxy(22,13);
    printf("Press 2 for Deleting Teacher's information");
    gotoxy(22,14);
    printf("Press 3 for Teacher's Class Shedule");
    gotoxy(22,15);
    printf("Press 4 for Teacher's salary management");
    gotoxy(22,16);
    printf("Press 5 to go to the Previous Menu");
    gotoxy(22,19);
	printf("Enter choice: ");
    scanf("%d", &admin_choice_teacher);
    system("CLS");
    switch(admin_choice_teacher){
          case 1:
               admin_teacher_information_management();
               break;
          
		  case 5:
		       admin(); 
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
    printf("Press 3 to go to the previous menu");
    gotoxy(22,15);
    printf("Press 4 to exit");
    gotoxy(22,18);
 	printf("Enter choice: ");
    scanf("%d", &admin_choice_teacher_info);
    system("CLS");
    switch(admin_choice_teacher_info){
          case 1:
      	       teacher_info_read();
      	       break;
      	   
          case 2:
      	       teacher_info_add();
               break;
               
          case 3:
		       admin_teacher_management();
		  	   
		  case 4:
		       break; 
    }
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
	fp = fopen("teacher_info_add.txt", "a");
	
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
    system("CLS");
    display_screen2();
    int adminChoice;
    gotoxy(22,10);
    printf("Teacher information added successfully.....");
    gotoxy(22,12);
    printf("Press 1 to go to the previous menu");
    gotoxy(22,13);
    printf("Press 2 to exit");
    gotoxy(22,15);
    printf("Enter choice: ");
    scanf("%d", &adminChoice);
    switch(adminChoice){
    	case 1:
    		admin_teacher_information_management();
    		break;
    	
    	case 2:
    		break;
	}
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
	fflush(stdin);
	printf("Enter teacher name: ");
	gets(name2);
	
	strcat(name1, name2);
	strcat(name1, "\n");
	
	int y=13;
	while(fgets(data, 500, fp)){
		if(strcmp(name1, data)==0){
			gotoxy(22,12);
			printf("%s", data);
		    while(fgets(data, 500, fp) && data[0] != '\n'){
				printf("%s", data);
				gotoxy(22,y);
				y++;	
	 	    }
	    }
	    else{
	    	printf("Name not found");
		}
		break;
	}
}

void admin_student_management(){
	display_screen2();
    int admin_choice_student;
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
    switch(admin_choice_student){
        case 1:
            admin_student_information_management();
            break;
        
		case 2:
		    admin_student_information_remove();    
	      
	}
}

void admin_student_information_management(){   
	display_screen2();
	int admin_choice_student_info;
	gotoxy(22,10);
    printf("Press 1 for reviewing information");
    gotoxy(22,11);
	printf("Press 2 for adding new information");
    gotoxy(22,12);
    printf("Press 3 to go to the previous menu");
    gotoxy(22,13);
    printf("Press 4 to exit");
    gotoxy(22,15);
	printf("Enter choice: ");
    scanf("%d", &admin_choice_student_info);
    system("CLS");
    switch(admin_choice_student_info){
	    case 1:
	    	student_info_read();
	    	break;
	    	
	    case 2:
	    	student_info_add();
	    	break;
		       
	    case 3:
	    	admin_student_management();
	    	break;
	    	
	    case 4:
	    	break;
	}
	
}

void student_info_add(){
	display_screen2();
    struct student_information{
	char name[50];
	char id[50];
	char dep[50];
	int semester;
	char section;
	long long int phone;
    }t2;
    
	FILE *fp;
	
	fp = fopen("student_info_add.txt", "a");
	
	if(fp == NULL){
		printf("File is not found\n");
	}
	int i, j;
	
	fflush(stdin);
	gotoxy(22,10);
	printf("Enter student's name: ");
	gets(t2.name);
	fprintf(fp, "\nStudent's Name: %s\n", t2.name);
	
	gotoxy(22,11);
	printf("Enter ID: ");
	scanf("%s", &t2.id);
	fprintf(fp, "ID: %s\n", t2.id);
	
	fflush(stdin);
	gotoxy(22,12);
	printf("Enter department: ");
	scanf("%s", &t2.dep);
	fprintf(fp, "Department: %s\n", t2.dep);
	fflush(stdin);
	
	gotoxy(22,13);
	printf("Enter semester: ");
	scanf("%d", &t2.semester);
	fprintf(fp, "Semester: %d\n", t2.semester);
	
	gotoxy(22,14);
	printf("Enter section: ");
	fflush(stdin);
	scanf("%c", &t2.section);
	fprintf(fp, "Section: %c\n", t2.section);
	
	gotoxy(22,15);
	printf("Enter phone number: ");
	fflush(stdin);
	scanf("%lld", &t2.phone);
	fprintf(fp, "Phone: %lld\n", t2.phone);
	
	fclose(fp);
	system("CLS");
    display_screen2();
    int adminChoice;
    gotoxy(22,10);
    printf("Student information added successfully.....");
    gotoxy(22,12);
    printf("Press 1 to go to the previous menu");
    gotoxy(22,13);
    printf("Press 2 to exit");
    gotoxy(22,15);
    printf("Enter choice: ");
    scanf("%d", &adminChoice);
    system("CLS");
    switch(adminChoice){
    	case 1:
    		admin_student_information_management();
    		break;
    	
    	case 2:
    		break;
	}
}

void student_info_read(){
	display_screen2();
	char stdata[size], entername[size];
    char namesearch[size] = {"Student's Name: "};
	
//	stdata[size] = (char *)malloc(size * sizeof(char));
	
	FILE *fp;
    
	fp = fopen("student.txt", "r");
	
	if(fp == NULL){
		printf("File not found");
	}
	
	fflush(stdin);
	gotoxy(22,10);
	printf("Enter student name: ");
	gets(entername);
	
	strcat(namesearch, entername);
	strcat(namesearch, "\n");
	
	int y=11;
	while(fgets(stdata, size, fp)){
		if(strcmp(namesearch, stdata)==0){
			gotoxy(22,y);
			printf("%s", stdata);
		while(fgets(stdata, size, fp) && stdata[0] != '\n'){
				y++;
				gotoxy(22,y);
				printf("%s", stdata);	
			}
	    }
	    else{
	    	printf("Name not found");
		}
		break;
	}
}

void admin_student_information_remove(){
	char erasedata[6][size];
	char stdata[size], entername[size];
    char namesearch[size] = {"Student's Name: "};
	int i;
//	stdata[size] = (char *)malloc(size * sizeof(char));
	
	FILE *fp;
    
	fp = fopen("student_info_add.txt", "r");
	
	if(fp == NULL){
		printf("File not found");
	}
	
	printf("Enter student name to delete record: ");
	gets(entername);
	
	strcat(namesearch, entername);
	strcat(namesearch, "\n");
	
	while(fgets(stdata, size, fp)){
		if(strcmp(namesearch, stdata)==0){
			strcpy(erasedata[0],namesearch);
		for(i=1;fgets(stdata, size, fp) && stdata[0] != '\n' && i<=5;i++){
				strcpy(erasedata[i],stdata);	
			}
	    }
	}
	fclose(fp);
	
  char buffer[size];
  
  FILE *file, *temp;

  file = fopen("student_info_add.txt", "r");
  temp = fopen("tempnew.txt", "w");

  if (file == NULL || temp == NULL)
  {
    printf("Error opening file(s).\n");
//    return 1;
  }

  bool keep_reading = true;
  int j=0;
  do {

      
    fgets(buffer, size, file);

   
    if (feof(file)) keep_reading = false;
    else if (strcmp(buffer, erasedata[j]) != 0)
      fputs(buffer, temp);
    else if (strcmp(buffer, erasedata[j]) == 0)
        j++;

  } while (keep_reading);
  


  fclose(file);
  fclose(temp);

 
  remove("student_info_add.txt");
  rename("tempnew.txt","student_info_add.txt");
}

void admin_course_management(){
	display_screen2();
	int admin_choice_course;
	gotoxy(22,10);
	printf("Welcome to Course Management");
	gotoxy(22,12);
	printf("Press 1 for reviewing courses");
	gotoxy(22,13);
	printf("Press 2 for adding new course");
	gotoxy(22,18);
	printf("Enter choice: ");
	scanf("%d", &admin_choice_course);
	switch(admin_choice_course){
		case 1:
			admin_course_read();
			break;
			
		case 2:
			admin_course_add();
			break;
	}
}

void admin_course_add(){
	int max_size = 1000;
	char buffer[max_size]; 
	FILE *course_check;
	course_check = fopen("Course_ Data.txt", "r");
	if(course_check == NULL){
		printf("File not found");
	}
	int i;
	struct add_course{
	       char course_name[20];
	       int credit_hours;
	       int semester;   
	       int course_department;
	       char department[20];
	}c1;
	int a=0;
	do{
	printf("Enter course name: ");
	gets(c1.course_name);
	strcat(c1.course_name, "\n");
    while(fgets(buffer, max_size, course_check)){
    	if(strcmp(c1.course_name,buffer)==0){
    		printf("Course already exist. Please enter any other name.\n");
    		a=1;
    		fseek(course_check,0,SEEK_SET);
    		break;
		}
	    else
	       a=0;
}
}while(a==1);

	printf("Enter credit hours: ");
	scanf("%d", &c1.credit_hours);
	printf("No of department in which course will be teach: ");
	scanf("%d", &c1.course_department);
	for(i=0; i<c1.course_department; i++){
		printf("Enter department name: ");
		fflush(stdin);
		gets(c1.department);
	}
	fflush(stdin);
	printf("Enter semester: ");
	scanf("%d", &c1.semester);
    fclose(course_check);
}

void admin_course_read(){
	display_screen2();
	FILE *fp;
	fp = fopen("Course_Data.txt", "r");
	char data[size];
	while(fgets(data, size, fp)){
		printf("%s", data);
	}
}
