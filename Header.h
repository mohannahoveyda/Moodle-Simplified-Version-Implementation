#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
typedef struct student {
	char* username;
	char* password;
	float grade_score;
	struct student* next;
}student;

typedef struct teacher {
	char* username;
	char* password;
	struct student* firststudent;
	struct student** firststudentptr;
	struct student* pendingstudent;
	struct student** pendingstudentptr;
	struct teacher* nextteacher;
}teacher;
bool streql(char a[], char b[]);
bool istherestudent(student** alls, char* user);
void addstudent(student** alls, char* user, char* pass);
bool LoginStudent(student** alls, char* user, char* pass);
bool isthereteacher(teacher** allt, char* user);
void addteacher(teacher** allt, char* user, char* pass);
bool LoginTeacher(teacher** allt, char* user, char* pass);
void addtowaitlist(teacher** allt, char* user, char* name);
float getgrade(teacher** allt, char* teacheruser, char* name);
void showteachers(teacher** allt, char* studentname);
void showteachersandgrades(teacher** allt, char* studentname);
void showwaitlist(teacher** allt, char* user);
void showlist(teacher** allt, char* user);
void addtolist(teacher** allt, char* user, char* name);
void gradestudent(teacher** allt, char* user, char* name, float grade);
void savestudents(student* allstudents);