#include "Header.h"
void savestudents(student* allstudents) {
	FILE *fp;
	fp = fopen("students.txt", "w");

	if (allstudents == NULL) {
		printf("no student signed up \n");
		return;
	}
	student* s;
	s = (struct student*) malloc(sizeof(struct student));
	s = allstudents;
	bool contin = true;
	while (contin) {
		printf("student: \t");
		printf("user:%s \t", s->username);
		printf("pass:%s\n", s->password);
		fprintf(fp, "%s\n", s->username);
		fprintf(fp, "%s\n", s->password);

		if (s->next != NULL)
		{
			s = s->next;
		}
		else {
			contin = false;
		}
	}
	fclose(fp);
}

