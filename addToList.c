#include "Header.h"
void addtolist(teacher** allt, char* user, char* name) {
	if (*allt == NULL) {
		printf("no teachers signed up!\n");
		return;
	}
	bool exist = false;
	teacher* t;
	teacher* ret;
	t = (struct teacher*) malloc(sizeof(struct teacher));
	t = *allt;
	bool contin = true;
	while (contin) {
		if (streql(t->username, user)) {
			exist = true;
			ret = t;
		}
		if (t->nextteacher != NULL)
		{
			t = t->nextteacher;
		}
		else {
			contin = false;
		}
	}
	if (!exist) {
		printf("no such teacher exist! \n");
		return;
	}
	if (*(ret->pendingstudentptr) == NULL) {
		printf("waiting list is empty! \n");
		return;
	}
	/*search for student to delete it from pending list*/
	student* s;
	student* returnendstudent;
	student* prevstudent;
	student* previous=NULL;
	s = (struct student*) malloc(sizeof(struct student));
	s = *(ret->pendingstudentptr);
	contin = true;
	exist = false;
	int counter = 0, number = 0;
	while (contin) {
		if (streql(s->username, name)) {
			exist = true;
			returnendstudent = s;
			prevstudent = previous;
			number = counter; //save its position
		}
		if (s->next != NULL)
		{
			previous = s;
			s = s->next;
			counter++;
		}
		else {
			contin = false;
		}
	}
	if (!exist) {
		printf("no such student exist in your pending list! \n");
		return;
	}
	if (number == 0) {
		/*he was the first student in the pending list 
		fisrt student should be his next student */
		*(ret->pendingstudentptr) = returnendstudent->next;
	}
	else {
		/*he was not the first student in the pending list
		/next of his previous should be his next
		/  prevstudent ---> s --->  (s->next)*/
		prevstudent->next = returnendstudent->next;
		/* prevstudent --------->  (s->next)
		                 
		 then we can free s or we can let it remain in the memory*/
	}

	/*add the student to the list
	make the student*/
	s = (struct student*) malloc(sizeof(struct student));
	s->username = name;
	s->grade_score = -1; /*-1 means he has not a grade.
						 adding him to the wait list*/
	s->next = *(ret->firststudentptr);
	*(ret->firststudentptr) = s;
}