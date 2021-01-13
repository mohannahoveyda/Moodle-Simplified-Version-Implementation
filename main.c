#include "Header.h"
int main() {
	student* allstudents = NULL;
	teacher* allteachers = NULL;
	student** alls = &allstudents;
	teacher** allt = &allteachers;

	char* currentuser = (char*)malloc(20 * sizeof(char));
	char* currentpassword = (char*)malloc(20 * sizeof(char));
	char* input;
	char* temp1;
	char* temp2;
	float grade;
	bool isloggedin = false;
	bool isteacher = false;
	while (1) {
		printf("\n Enter what you want to do:\n");
		input = (char*)malloc(20 * sizeof(char));
		scanf("%s", input);
		if (streql(input, "signup_teacher")) {
			if (isloggedin) {
				printf("please first log out. \n");
			}
			else {
				temp1 = (char*)malloc(20 * sizeof(char));
				temp2 = (char*)malloc(20 * sizeof(char));
				scanf("%s", temp1);
				scanf("%s", temp2);
				if (isthereteacher(allt, temp1)) {
					printf("this username is taken. please choose another one. \n");
				}
				else {
					addteacher(allt, temp1, temp2);
					printf("successful signup. now %s is added to teachers and logged in... \n",temp1);
					currentpassword = (char*)malloc(20 * sizeof(char));
					currentuser = (char*)malloc(20 * sizeof(char));
					currentuser = temp1;
					currentpassword = temp2;
					isloggedin = true;
					isteacher = true;
				}
			}
		}
		else if (streql(input, "signup_student")) {
			if (isloggedin) {
				printf("please first log out. \n");
			}
			else {
				temp1 = (char*)malloc(20 * sizeof(char));
				temp2 = (char*)malloc(20 * sizeof(char));
				scanf("%s", temp1);
				scanf("%s", temp2);
				if (istherestudent(alls, temp1)) {
					printf("this username is taken. please choose another one. \n");
				}
				else {
					addstudent(alls, temp1, temp2);
					printf("successful signup. now %s is added to students and logged in... \n",temp1);
					currentpassword = (char*)malloc(20 * sizeof(char));
					currentuser = (char*)malloc(20 * sizeof(char));
					currentuser = temp1;
					currentpassword = temp2;
					isloggedin = true;
					isteacher = false;
				}
			}
		}
		else if (streql(input, "current")) {
			if (!isloggedin) {
				printf("no one is logged in. \n");
			}
			else {
				if (isteacher) {
					printf("current user is a teacher and his user is: %s \n", currentuser);
				}
				else {
					printf("current user is a student and his user is: %s \n", currentuser);
				}
			}
		}
		else if (streql(input, "login_teacher")) {
			if (isloggedin) {
				printf("please first log out. \n");
			}
			else {
				temp1 = (char*)malloc(20 * sizeof(char));
				temp2 = (char*)malloc(20 * sizeof(char));
				scanf("%s", temp1);
				scanf("%s", temp2);
				if (LoginTeacher(allt, temp1, temp2)) {
					printf("you are logged in,welcome back %s. \n",temp1);
					currentuser = temp1;
					currentpassword = temp2;
					isloggedin = true;
					isteacher = true;
				}
				else if (isthereteacher(allt, temp1)) {
					printf("wrong password! \n");
				}
				else {
					printf("this user has not signed up yet! \n");
				}
			}
		}
		else if (streql(input, "login_student")) {
			if (isloggedin) {
				printf("please first log out. \n");
			}
			else {
				temp1 = (char*)malloc(20 * sizeof(char));
				temp2 = (char*)malloc(20 * sizeof(char));
				scanf("%s", temp1);
				scanf("%s", temp2);
				if (LoginStudent(alls, temp1, temp2)) {
					printf("you are logged in,welcome back %s. \n", temp1);
					currentuser = temp1;
					currentpassword = temp2;
					isloggedin = true;
					isteacher = false;
				}
				else if (istherestudent(alls, temp1)) {
					printf("wrong password! \n");
				}
				else {
					printf("this user has not signed up yet! \n");
				}
			}
		}
		else if (streql(input, "logout")) {
			isloggedin = false;
			printf("you logged out successfully");
		}
		else if (streql(input, "request_course")) {
			if (!isloggedin) {
				printf("no one is logged in. \n");
			}
			else if (isteacher) {
				printf("teachers cannot request a course!. \n");
			}
			else {
				temp1 = (char*)malloc(20 * sizeof(char));
				scanf("%s", temp1);
				if (isthereteacher(allt, temp1)) {
					addtowaitlist(allt, temp1, currentuser);
					printf("your request has been sent to %s \n", temp1);
				}
				else {
					printf("there is no teacher with this username! \n");
				}
			}
		}
		else if (streql(input, "requests_list")) {
			if (!isloggedin) {
				printf("no one is logged in. \n");
			}
			else if (!isteacher) {
				printf("students are not allowed to request show pending list! \n");
			}
			else {
				showwaitlist(allt, currentuser);
			}
		}
		else if (streql(input, "show_my_classlist")) {
			if (!isloggedin) {
				printf("no one is logged in. \n");
			}
			else if (!isteacher) {
				printf("students are not allowed to request show pending list! \n");
			}
			else {
				showlist(allt, currentuser);
			}
		}
		else if (streql(input, "accept")) {
			if (!isloggedin) {
				printf("no one is logged in. \n");
			}
			else if (!isteacher) {
				printf("stuents cannot accept a request!\n");
			}
			else {
				temp1 = (char*)malloc(20 * sizeof(char));
				scanf("%s", temp1);
				if (istherestudent(alls, temp1)) {
					addtolist(allt, currentuser, temp1);
					printf("%s is added to your class.\n", temp1);
				}
				else {
					printf("there is no student with this username! \n");
				}
			}
		}
		else if (streql(input, "grade")) {
			if (!isloggedin) {
				printf("no one is logged in. \n");
			}
			else if (!isteacher) {
				printf("this feature is just for stuents!\n");
			}
			else {
				temp1 = (char*)malloc(20 * sizeof(char));
				scanf("%s", temp1);
				scanf("%f", &grade);

				if (istherestudent(alls, temp1)) {
					gradestudent(allt, currentuser, temp1, grade);
					printf("your grade submitted.\n");
				}
				else {
					printf("there is no student with this username! \n");
				}
			}
		}
		else if (streql(input, "show_grade")) {
			if (!isloggedin) {
				printf("no one is logged in. \n");
			}
			else if (isteacher) {
				printf("this feature is just for stuents!\n");
			}
			else {
				temp1 = (char*)malloc(20 * sizeof(char));
				scanf("%s", temp1);
				if (isthereteacher(allt, temp1)) {
					grade = getgrade(allt, temp1, currentuser);
					printf("your grade is: %f\n", grade);
				}
				else {
					printf("there is no teacher with this username! \n");
				}
			}
		}
		else if (streql(input, "teachers_list")) {
			if (!isloggedin) {
				printf("no one is logged in. \n");
			}
			else if (isteacher) {
				printf("this feature is just for stuents!\n");
			}
			else {
				showteachers(allt, currentuser);
			}
		}
		else if (streql(input, "show_grades")) {
			if (!isloggedin) {
				printf("no one is logged in. \n");
			}
			else if (isteacher) {
				printf("this feature is just for stuents!\n");
			}
			else {
				showteachersandgrades(allt, currentuser);
			}
		}
		else if (streql(input, "exit")) {
			return 0;
		}
		else {
			printf("your request can't be read");
		}

	}


	return 0;
}
