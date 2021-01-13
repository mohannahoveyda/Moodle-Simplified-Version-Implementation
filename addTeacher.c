#include "Header.h"
void addteacher(teacher** allt, char* user, char* pass) {
	//make the student
	teacher* t;
	t = (struct teacher*) malloc(sizeof(struct teacher));
	t->username = user;
	t->password = pass;
	t->firststudent = NULL;
	t->firststudentptr = &t->firststudent;
	t->pendingstudent = NULL;
	t->pendingstudentptr = &t->pendingstudent;
	//adding him to the wait list
	t->nextteacher = *allt;
	*allt = t;
}