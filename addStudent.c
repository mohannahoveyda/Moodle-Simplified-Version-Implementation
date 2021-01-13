#include "Header.h"
void addstudent(student** alls, char* user, char* pass) {
	//make the student
	student* s;
	s = (struct student*) malloc(sizeof(struct student));
	s->username = user;
	s->password = pass;


	//adding him to the wait list
	s->next = *alls;
	*alls = s;

}