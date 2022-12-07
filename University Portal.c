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
void display_screen2();  //for styling of all pages except front page  
void main_page();  //front page
void admin();   //admin portal
void admin_password();  //for password of admin portal
void admin_teacher_management(); //teacher management in admin portal
void admin_teacher_information_management(); //teacher info update and review in admin portal
void teacher_info_add(); // teacher info add in admin portal
void teacher_info_read(); //teacher info review in admin portal
void admin_teacher_information_remove();//To remove data of teacher
void admin_student_management(); //student management in admin portal
void admin_student_information_management(); //student info update and review in admin portal
void student_info_add(); //student info add in admin portal
void student_info_read(); //student info review in admin portal
void admin_student_information_remove(); //To remove data of a student
void admin_course_management(); //course management in admin portal
void admin_course_add();//to add a new course
void admin_course_read();//to read all the course
void teacher();
void teacher_pass();
void timetable_review();
void rev_attendance();
void add_attendance();
void add_marking();
void rev_marking();
float GetGPA(float total);
void student();

int main(){
//	admin_password();
    int  user_choice;
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
	scanf(" %c", &user_choice);
	fflush(stdin);
	system("CLS");
	
	switch(user_choice){
		case 'A':                         //Admin Portal
		case 'a':                         //Admin Portal
		    admin_password();
			break;	
		
	    case 'T':
	    case 't':
	    	teacher_pass();
	    	break;
	}
}

void display_screen(){                    //for styling of front page
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

void display_screen2(){                         //for styling of all pages except front page
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
	char d[40]="Welcome to University Portal ";
	for(i=0;i<40;i++){
		printf("%c",d[i]);
	}
}

void admin_password(){
	system("CLS");
	fflush(stdin);
    display_screen2();
    int i=0;
	char password[10];
	char ch;
	char pass[6] = "admin";
	gotoxy(22,12);
    printf("Enter Password: ");
    fflush(stdin);
	while(1){
		fflush(stdin);
		ch = getch();
		fflush(stdin);
		
		if(ch == 13){
			fflush(stdin);
			password[i] = '\0';
			break;
		}
		else if(ch == 8){
			if(i>0){
				i--;
				fflush(stdin);
				printf("\b \b");
			}
		}
		else{
			fflush(stdin);
			password[i++] = ch;
			printf("* \b");
		}
		
	 }
	 
	 if(strcmp(password, pass)==0){
	 	gotoxy(22,14);
	 	printf("Password is correct\n");
	 	system("CLS");
	 	admin();
	 }
	 
	 else if(strcmp(password, pass)!=0){
	 	int choice;
	 	gotoxy(22,14);
	    printf("Password is incorrect");
	 	gotoxy(22,15);
		printf("Press 1 to try again");
	 	gotoxy(22,16);
		printf("Press 2 to exit");
	 	gotoxy(22,18);
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				system("CLS");
				admin_password();
				break;
			
			case 2:
				break;
		}	
	 }
}

void admin(){                                 //Admin Portal
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
	printf("Press 4 to Exit");
    gotoxy(22,17);
	printf("Enter choice: ");
    scanf("%d", &admin_choice);
    system("CLS");
    switch (admin_choice)
    {
    case 1:                                    //Teacher Management in Admin Portal
    	admin_teacher_management();           
        break;
        
    case 2:
    	admin_student_management();            //Student Management in Admin Portal
        break;

	case 3:
	    admin_course_management();	           //Course Management in Admin Portal
        break;
	 
	case 4:
	    break;                                 //To Exit
	}
}

void admin_teacher_management(){               //teacher management in admin portal
    display_screen2();
	int admin_choice_teacher;
    gotoxy(22,10);
    printf("Welcome to Teacher Management");
    gotoxy(22,12);
    printf("Press 1 for Updating or Showing Teacher's Information");
    gotoxy(22,13);
    printf("Press 2 for Deleting Teacher's Information");
    gotoxy(22,14);
    printf("Press 3 for Teacher's Salary Management");
    gotoxy(22,15);
    printf("Press 4 to go to the Previous Menu");
    gotoxy(22,16);
    printf("Press 5 to Exit");
	gotoxy(22,18);
	printf("Enter Choice: ");
    scanf("%d", &admin_choice_teacher);
    system("CLS");
    switch(admin_choice_teacher){
        case 1:                                   //To xadd and review teacher's information
            admin_teacher_information_management();
            break;
            
        case 2:                                  //To remove teacher's information
        	admin_teacher_information_remove();
        	break;
          	   
		case 4:                                 //To go to the previous menu
		    admin();
		    break;
			
		case 5:                                  //To  Exit
            break;		 
	}
} 


void admin_teacher_information_management(){              //teacher info add and review in admin portal
    display_screen2();
    int admin_choice_teacher_info;
 	gotoxy(22,11);
    printf("Press 1 for reviewing information");
    gotoxy(22,12);
 	printf("Press 2 for adding new information");
    gotoxy(22,13);
    printf("Press 3 to go to the previous menu");
    gotoxy(22,14);
    printf("Press 4 to exit");
    gotoxy(22,17);
 	printf("Enter choice: ");
    scanf("%d", &admin_choice_teacher_info);
    system("CLS");
    switch(admin_choice_teacher_info){
        case 1:                                         //to review teacher's information in admin portal
      	    teacher_info_read();  
      	    break;
      	   
        case 2:                                        //to add teacher's information in admin portal
      	    teacher_info_add();
            break;
               
        case 3:
		    admin_teacher_management();                //to go to the previous menu
		  	   
		case 4:                                        //to exit
		    break; 
    }
}

void teacher_info_add(){                               //function to add teacher info in admin portal
	display_screen2();
	int i;
	struct teacher_info_add{
		  char name[50];
		  int course_quantity;
		  char course_name[50];
		  int salary;
		  char pass[50];
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
	
	fprintf(fp, "\nTeacher's Name: %s\n", t1.name);
	
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
    
    gotoxy(22, ++y);
    printf("Enter password: ");
    fflush(stdin);
	gets(t1.pass);
    fprintf(fp, "Password: %s\n", t1.pass);
    
    fclose(fp);
    system("CLS");
    display_screen2();
    int adminChoice;
    gotoxy(22,10);
    printf("Teacher information added successfully.....");
    gotoxy(22,12);
    printf("Press B or b to go to the previous menu");
    gotoxy(22,13);
    printf("Press E or e to exit");
    gotoxy(22,15);
    printf("Enter choice:");
    char choice;
    scanf("%c", &choice);
    switch(choice){
	    case 'B':
	    case 'b':
		  system("CLS");
		  admin_student_information_management();
		  break;
			
	    case 'E':
	    case 'e':
		  break;
			
	}
}

void teacher_info_read(){                             //function to review teacher's information in admin portal
	display_screen2();
	char stdata[size], entername[size];
    char namesearch[size] = {"Teacher's Name: "};
	
//	stdata[size] = (char *)malloc(size * sizeof(char));
	
	FILE *fp;
    
	fp = fopen("teacher_info_add.txt", "r");
	
	if(fp == NULL){
		printf("File not found");
	}
	
	fflush(stdin);
	gotoxy(22,10);
	printf("Enter teacher name: ");
	gets(entername);
	
	strcat(namesearch, entername);
	strcat(namesearch, "\n");
	
	int y = 12; 
    int occurance = 0;
    while(fgets(stdata, size, fp) != NULL) {
		 if((strcmp(namesearch, stdata)) ==0) {
			 gotoxy(22,y);
			 printf("%s",stdata);
			 while(fgets(stdata,size,fp) && stdata[0] != '\n'){
			     y++;
				 gotoxy(22,y);
				 printf("%s",stdata);
		     }
			 occurance++;
		 }
	}
	if(occurance == 0) {
		gotoxy(22, 11);
		printf("Sorry, couldn't find a match.");
	}

	gotoxy(22,++y);
	printf("Press B or b for previous menu");
	gotoxy(22,++y);
	printf("Press E or e to exit");
	gotoxy(22,++y);
    printf("Enter choice:");
    char choice;
    scanf("%c", &choice);
    switch(choice){
	    case 'B':
	    case 'b':
		  system("CLS");
		  admin_teacher_information_management();
		  break;
			
	    case 'E':
	    case 'e':
	 	  break;
			
	}
}

void admin_teacher_information_remove(){                        //function to remove teacher's information in admin portal
	display_screen2();
	int adminChoice;
	char erasedata[6][size];
	char stdata[size], entername[size];
    char namesearch[size] = {"Teacher's Name: "};
	int i;
//	stdata[size] = (char *)malloc(size * sizeof(char));
	
	FILE *fp;
    
	fp = fopen("teacher_info_add.txt", "r");
	
	if(fp == NULL){
		printf("File not found");
	}
	
	gotoxy(22,10);
	fflush(stdin);
	printf("Enter teacher name to delete record: ");
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

  file = fopen("teacher_info_add.txt", "r");
  temp = fopen("tempnew_teacher.txt", "w");

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

 
  remove("teacher_info_add.txt");
  rename("tempnew_teacher.txt","teacher_info_add.txt");
  system("CLS");
  display_screen2();
  gotoxy(22,10);
  printf("Teacher information removed successfully.....");
  gotoxy(22,12);
  printf("Press B or b to go to the previous menu");
  gotoxy(22,13);
  printf("Press E or e to exit");
  gotoxy(22,15);
  printf("Enter choice:");
  char choice;
  scanf("%c", &choice);
  switch(choice){
	  case 'B':
	  case 'b':
		system("CLS");
		admin_teacher_management();
		break;
			
	  case 'E':
	  case 'e':
		break;
			
	}
}

void admin_student_management(){                                            //student management in admin portal
	display_screen2();
    int admin_choice_student;
	gotoxy(22,10);
    printf("Welcome to Student Management");
    gotoxy(22,12);
    printf("Press 1 for Updating or showing Student's information");
    gotoxy(22,13);
    printf("Press 2 for Deleting Student's information\n");
    gotoxy(22,14);
    printf("Press 5 to go to the previous menu");
	gotoxy(22,16);
	printf("Press 6 to exit");
	gotoxy(22,18);
    printf("Enter choice: ");
    scanf("%d", &admin_choice_student);
    system("CLS");
    switch(admin_choice_student){
        case 1:                                                           //to add or review student information
            admin_student_information_management();
            break;
        
		case 2:
		    admin_student_information_remove();                          //to remove student information
	        break;
	        
	    case 5:
	    	admin();                                                    //to go to the previous menu
	    	break;
	
	    case 6:                                                         //to exit
	    	break;  
	}
	
}

void admin_student_information_management(){                           //student info add and review in admin portal  
	display_screen2();
	int admin_choice_student_info;
	gotoxy(22,12);
    printf("Press 1 for reviewing information");
    gotoxy(22,13);
	printf("Press 2 for adding new information");
    gotoxy(22,14);
    printf("Press 3 to go to the previous menu");
    gotoxy(22,15);
    printf("Press 4 to exit");
    gotoxy(22,16);
	printf("Enter choice: ");
    scanf("%d", &admin_choice_student_info);
    system("CLS");
    switch(admin_choice_student_info){
	    case 1:                                                         //student info review
	    	student_info_read();
	    	break;
	    	
	    case 2:                                                         //student info add
	    	student_info_add();
	    	break;
		       
	    case 3:                                                         //to go to previous menu
	    	admin_student_management();                              
	    	break;
	    	
	    case 4:                                                          //to exit
	    	break;
	}
	
}

void student_info_add(){                             //function to add student's information
	display_screen2();
    struct student_information{
	char name[50];
	char id[50];
	char dep[50];
	int semester;
	char section;
	char pass[50];
	long long int phone;
	char fee[20];
    }t2;
    
	FILE *fp;
	
	fp = fopen("student_info_add.txt", "a");
	
	if(fp == NULL){
		printf("File is not found\n");
	}
	int i, j;
	
	fflush(stdin);
	gotoxy(22,10);
	printf("Enter ID: ");
	scanf("%s", &t2.id);
	fprintf(fp, "\nID: %s\n", t2.id);

	gotoxy(22,11);
	printf("Enter student's name: ");
	fflush(stdin);
	gets(t2.name);
	fprintf(fp, "Student's Name: %s\n", t2.name);
	
	fflush(stdin);
	gotoxy(22,12);
	printf("Enter department: ");
	gets(t2.dep);
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
	printf("Enter password: ");
	fflush(stdin);
	scanf("%s", &t2.pass);
	fprintf(fp, "Password: %s\n", t2.pass);
	
	gotoxy(22,16);
	printf("Enter phone number: ");
	fflush(stdin);
	scanf("%lld", &t2.phone);
	fprintf(fp, "Phone: %lld\n", t2.phone);
	gotoxy(22, 16);
	
	printf("Enter fee status(Paid / Non- Paid): ");
	fflush(stdin);
	gets(t2.fee);
	fprintf(fp, "Fee Status: %s", t2.fee);
	gotoxy(22, 17);
	fclose(fp);
	
	system("CLS");
    display_screen2();
    int adminChoice;
    gotoxy(22,10);
    printf("Student information added successfully.....");
    gotoxy(22,12);
    printf("Press B or b to go to the previous menu");
    gotoxy(22,13);
    printf("Press E or e to exit");
    gotoxy(22,15);
    printf("Enter choice:");
    char choice;
    scanf("%c", &choice);
    switch(choice){
	    case 'B':
	    case 'b':
		  system("CLS");
		  admin_student_information_management();
		  break;
			
	    case 'E':
	    case 'e':
		  break;
			
	}
}

void student_info_read(){
	display_screen2();
	char stdata[size], entername[size];
    char namesearch[size] = {"ID: "};
	
//	stdata[size] = (char *)malloc(size * sizeof(char));
	
	FILE *fp;
    
	fp = fopen("student_info_add.txt", "r");
	
	if(fp == NULL){
		printf("File not found");
	}
	
	fflush(stdin);
	gotoxy(22,10);
	printf("Enter student ID: ");
	gets(entername);
	
	strcat(namesearch, entername);
	strcat(namesearch, "\n");
	
	int y = 12; 
    int occurance = 0;
   while(fgets(stdata, size, fp) != NULL) {
		if((strcmp(namesearch, stdata)) ==0) {
			gotoxy(22,y);
			printf("%s",stdata);
			while(fgets(stdata,size,fp) && stdata[0] != '\n'){
			    y++;
				gotoxy(22,y);
				printf("%s",stdata);
		    }
			occurance++;
		}
	}

	if(occurance == 0) {
		gotoxy(22,11);
		printf("\nSorry, couldn't find a match.\n");
	}
	
	gotoxy(22,y);
	printf("Press B or b  for previous menu");
	gotoxy(22,++y);
	printf("Press E or e to exit");
	gotoxy(22,++y);
    printf("Enter choice:");
    char choice;
    scanf("%c", &choice);
    switch(choice){
	   case 'B':
	   case 'b':
	   	  system("CLS");
	   	  admin_student_information_management();
	   	  break;
	   		
	   case 'E':
	   case 'e':
	     	break;
			
	}
	
}

void admin_student_information_remove(){        //to remove student's information
	display_screen2();
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
	
	gotoxy(22,10);
	printf("Enter student name to delete record: ");
	fflush(stdin);
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

  system("CLS");
  display_screen2();
  gotoxy(22,10);
  printf("Student information removed successfully.....");
  gotoxy(22,12);
  printf("Press B or b to go to the previous menu");
  gotoxy(22,13);
  printf("Press E or e to exit");
  gotoxy(22,15);
  printf("Enter choice:");
  char choice;
  scanf("%c", &choice);
  switch(choice){
	  case 'B':
	  case 'b':
		system("CLS");
		admin_student_management();
		break;
			
	  case 'E':
	  case 'e':
		break;
			
	}
}

void admin_course_management(){           //course management in admin portal
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

void admin_course_add(){                               //to add course in admin portal
    system("CLS");                             
	display_screen2();
	int max_size = 1000;
	char buffer[max_size]; 
	FILE *fp, *fp2;
	fp = fopen("Course_ Data.txt", "r");
	if(fp == NULL){
		gotoxy(22, 10);
		printf("File not found");
	}
	int i;
	struct add_course{
	       char course_name[20];
	       int credit_hours;
	}c1;
	int a=0;
	do{
	fflush(stdin);
	gotoxy(22, 13);
	printf("Enter course name: ");
	gets(c1.course_name);
	strcat(c1.course_name, "\n");
    while(fgets(buffer, max_size, fp)){
    	if(strcmp(c1.course_name,buffer)==0){
    		system("CLS");
    		display_screen2();
    		gotoxy(22, 10);
			printf("Course already exist. Please enter any other name.");
    		a=1;
    		fseek(fp,0,SEEK_SET);
    		break;
		}
	    else
	       a=0;
}
}while(a==1);
    
    fp2 = fopen("new_course.txt", "a+");
    fprintf(fp2, "\nCourse Name: %s", c1.course_name);
    
    fflush(stdin);
    gotoxy(22, 14);
	printf("Enter credit hours: ");
	scanf("%d", &c1.credit_hours);
	fprintf(fp2, "Credit hours: %d", c1.credit_hours);
    fclose(fp2);
	fclose(fp);
	system("CLS");
	gotoxy(22, 12);
	printf("Course Added Successfully");
	gotoxy(22, 16);
	printf("Press B or b to go to the previous menu");
	gotoxy(22, 17);
	printf("Press E or e to exit");
	gotoxy(22, 18);
	char choice;
	gotoxy(22, 19);
	printf("Enter choice:");
	scanf("%c", &choice);
	switch(choice){
		case 'B':
		case 'b':
			admin_course_management();
			break;
			
		case 'E':
		case 'e':
			break;
			
	}

}

void admin_course_read(){                //to read all the new courses
	system("CLS");
	display_screen2();
	FILE *fp;
	fp = fopen("new_course.txt", "r");
	char data[size];
	int y = 12;
	while(fgets(data, size, fp)){
		gotoxy(22,y);
		printf("%s", data);
		y++;
	}
	gotoxy(22, 16);
	printf("Press B or b to go to the previous menu");
	gotoxy(22, 17);
	printf("Press E or e to exit");
	gotoxy(22, 18);
	char choice;
	fflush(stdin);
	gotoxy(22, 19);
	printf("Enter choice:");
	scanf("%c", &choice);
	switch(choice){
		case 'B':
		case 'b':
			system("CLS");
			admin_course_management();
			break;
			
		case 'E':
		case 'e':
			break;
			
	}
}

void teacher_pass(){
	display_screen2();
	FILE *fp;
	char data[size];
	char tname[size];
	char tpass[size];
	char pass_t[size]={"Password: "};
	char name_t[size]={"Teacher's Name: "};
	fp= fopen("teacher_info_add.txt","r");
	gotoxy(22, 12);
	printf("Enter your name: ");
	gets(tname);
	strcat(name_t,tname);
	strcat(name_t, "\n");
	while(fgets(data, size, fp)!= NULL){
		if((strcmp(name_t,data))==0){
			gotoxy(22, 13);
			printf("Enter password: ");
			gets(tpass);
	        strcat(pass_t,tpass);
	        strcat(pass_t, "\n");
			while(fgets(data, size, fp) && data[0] != '\n'){
				if(strcmp(pass_t,data)==0)
				    teacher();
			}
	    }
}
fclose(fp);
}

void teacher(){
	system("CLS");
	display_screen2();
   int choice,mark_choice, att_choice ;
   gotoxy(22, 11);
   printf("Press 1 for marking management");
   gotoxy(22, 12);
   printf("Press 2 for attendance management");
   gotoxy(22, 13);
   printf("Press 3 for timetable review");
   gotoxy(22, 15);
   printf("Enter Choice: ");
   scanf("%d",&choice);
   switch(choice)
      {
      	case 1:
      		system("CLS");
      		display_screen2();
      		gotoxy(22, 11);
      		printf("Press 1 to add marking");
			gotoxy(22, 12);
			printf("Press 2 to review marking");
      		gotoxy(22, 14);
      		printf("Enter choice: ");
			scanf("%d",&mark_choice);
      		switch(mark_choice)
      		{
      			case 1:
      				add_marking();
      				break;
      			case 2:
      				rev_marking();
      				break;
			  }
		break;
		
		case 2:
			system("CLS");
			display_screen2();
			gotoxy(22, 11);
			printf("Press 1 to add attendance");
			gotoxy(22, 12);
			printf("Press 2 to review attendance");
			gotoxy(22, 14);
			printf("Enter Choice: ");
      		scanf("%d",&att_choice);
      		switch(att_choice)
      		{
      			case 1:
      				add_attendance();
      				break;
      			case 2:
      				rev_attendance();
      				break;
			  }
		break;
		
		case 3:
             timetable_review();
        break;
	  }	
}
void add_marking(){
	system("CLS");
	display_screen2();
	char choice3;
	float asg, quiz, mid1,mid2,final,total,gpa;
	char data[size];
	char id[15];
	char id_c[size]={"ID: "};
	
	FILE *fp,*pr;
	fp= fopen("student_marking.txt","a");
	pr= fopen("student_info_add.txt","r");
	
	gotoxy(22, 11);
	printf("Enter the student ID to add marks: ");
	scanf("%s",id);
	strcat(id_c,id);
	strcat(id_c, "\n");
	int y=12;
	while(fgets(data, size, pr)){
		if(strcmp(id_c,data)==0){
			gotoxy(22, y);
			fprintf(fp,"%s",data);
		int i;
		for(i=1;fgets(data, size, pr) && data[0] != '\n' && i<=6;i++){
				gotoxy(22, y++);
				fprintf(fp,"%s",data);
				if(i==1||i==2||i==3||i==4)
				    printf("%s",data);
			}
	    }
}
    gotoxy(22, y++);
    int choice;
    printf("Press 1 for Adding Marks");
    gotoxy(22, y++);
    printf("Press E or e to exit");
    gotoxy(22, y++);
    printf("Enter Choice: ");
    scanf("%d", &choice);
    switch(choice){
    	case 1:
    		system("CLS");
    		display_screen2();
            gotoxy(22, 11);
            printf("Enter Assignments weightage /10: ");
            scanf("%f",&asg);
            fprintf(fp,"Assignmnet: %.1f\n",asg);
            gotoxy(22, 12);
            printf("Enter quizzes weightage /10: ");
            scanf("%f",&quiz);
            fprintf(fp,"Quizzes: %.1f\n",quiz);
            gotoxy(22, 13);
			printf("Enter mid 1 weightage /15: ");
		    scanf("%f",&mid1);
		    fprintf(fp,"Mid1: %.1f\n",mid1);
			gotoxy(22, 14);
			printf("Enter mid 2 weightage /15: ");
		    scanf("%f",&mid2);
		    fprintf(fp,"Mid2: %.1f\n",mid2);
		    fflush(stdin);
		    gotoxy(22, 15);
		    printf("Enter Finals weightage /50: ");
		    scanf("%f",&final);
		    fprintf(fp,"Final: %.1f\n",final);
			total= asg+ quiz +mid1+mid2+final;
		    gpa =GetGPA(total);
		    gotoxy(22, 16);
		    printf("Calculated GPA is %.2f",gpa);
		    fprintf(fp,"GPA: %.2f\n",gpa);
		    fputs("\n\n",fp);  
			fclose(pr);				     
		    fclose(fp);
		    break;
			
		case 'E':
		case 'e':
		    break;     		
	}
	
	 		                    
}

void rev_marking(){
	system("CLS");
	display_screen2();
	char choice3;
	char id[15];
	char id_c[size]={"ID: "};
	char data[size];
	
	FILE *fp;
	fp= fopen("student_marking.txt","r");
	gotoxy(22, 11);
	printf("Enter the student ID to review marks: ");
	scanf("%s",id);
	strcat(id_c,id);
	strcat(id_c, "\n");
	int occur=0;
	while(fgets(data, size,fp)){
		if(strcmp(id_c,data)==0){
		while(fgets(data, size,fp) && data[0] != '\n'){
				printf("%s",data);
			}
			occur++;
	    }
}
if(occur == 0) {
	    gotoxy(22, 14);
		printf("Sorry, Student marks are not entered yet.");
	}
  fclose(fp);
}

void add_attendance(){
	system("CLS");
	int days;
	char data[size];
	char id[15];
	char id_c[size]={"ID: "};
	
	FILE *fp,*pr;
	fp= fopen("student_attendance.txt","a");
	pr= fopen("student_marking.txt","r");
	gotoxy(22, 11);
	printf("Enter the student ID to mark Attendace: ");
	scanf("%s",id);
	strcat(id_c,id);
	strcat(id_c, "\n");
	int y=12;
	while(fgets(data, size, pr)){
		if(strcmp(id_c,data)==0){
			gotoxy(22, y);
			fprintf(fp,"%s",data);	
		int i;
		for(i=1;fgets(data, size, pr) && data[0] != '\n' && i<=12;i++){
				gotoxy(22, y++);
				fprintf(fp,"%s",data);
				if(i==1|| i==2 || i==3 || i==4)
				    gotoxy(22, y++);
					printf("%s",data);
			}
	    }
}   printf("\nEnter the total no. days attended by student /90");
    scanf("%d",&days);
    int percent= (days/90.0)*100.0;
    fprintf(fp,"Attendance Percentage: %d %",percent);
    printf("Attendance added Successfully\n");
    printf("\nAttendance Percentage calculated to be: %d %",percent);
    fputs("\n\n",fp);
    fclose(fp);
    fclose(pr);
}

void timetable_review(void)
{
	int time_choice;
	char buffer[1000];
	FILE *fp;
		printf("\t\t\tWELCOME TO TIMETABLE REVIEW\t\t\t");
	        printf("\n\nSelect a Day to showcase its timetable\n\nPress\n1 for Monday\n2 for Tuesday\n3 for Wednesday\n4 for Thursday\n5 for Friday\n");
	        scanf("%d", &time_choice);
	        switch(time_choice)
	        {
		    case 1:
			   fp= fopen("Monday.txt","r");
			break;
		    case 2:
			   fp= fopen("Tuesday.txt","r");
			break;
		    case 3:
			   fp= fopen("Wednesday.txt","r");
			break;
		    case 4:
			   fp= fopen("Thursday.txt","r");
			break;
		    case 5:
			   fp= fopen("Friday.txt","r");
			break;
         	}
          while(fgets(buffer,1000,fp))
              {
              	printf("%s",buffer);
            	}
}

void rev_attendance(void)
{
	char data[size];
	FILE *fp;
	fp= fopen("student_attendance.txt","r");
	char id[15];
	char id_c[size]={"ID: "};
	printf("Enter the student ID to review attendance\t");
	scanf("%s",id);
	strcat(id_c,id);
	strcat(id_c, "\n");
	while(fgets(data, size, fp)){
		if(strcmp(id_c,data)==0){
		int i;
		for(i=1;fgets(data, size, fp) && data[0] != '\n' && i<=11;i++){
				if(i==1|| i==2 || i==3 || i==4 || i==11)
				    printf("%s",data);
			}
	    }
} 
   fclose(fp);
	
}




float GetGPA(float total)
{
	if (total>=86 && total<=100 )
        return(4);
    else if(total>=82 && total<=85 )
        return(3.67);
    else if(total>=78 && total<=81)
        return(3.33);
    else if(total>=74 && total<=77)
        return(3);
    else if(total>=70 && total<=73)
        return(2.67);
    else if(total>=66 && total<=69)
        return(2.33);
    else if(total>=62 && total<=65)
        return(2);
    else if(total>=58 && total<=61)
        return(1.67);
    else if(total>=54 && total<=57)
        return(1.33);
    else if(total>=50 && total<=53)
        return(1);
    else if(total>0 && total<49)
        return(0);
    else
       printf("Wrong weightage input, out of 0-100 range");
}
