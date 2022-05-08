#ifndef STUDENT_MS_H
#define STUDENT_MS_H
#include "student.h"

class studentMS
{
private:
	vector<student> students;

public:
	// constructor, destructor
	studentMS();
	studentMS(vector<student> &);
	studentMS(const studentMS &);
	~studentMS();

	// add and remove student
	void add();
	void remove(const string ID);

	// sort by ID
	void sortByID();

	// find student by id
	student *findByID(string id);

	// get data from file txt
	void importFromList(string filename);

	// classfy student by grade
	string classify(const float avg);

	// store data
	void writeToList();
	void output_avg();
	void output_rank();
	void display();

	// calculate average of all students
	float avg_class();
};

#endif // STUDENT_MS_H