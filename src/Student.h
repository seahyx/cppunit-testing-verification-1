#ifndef Student_h
#define Student_h

#include "Course.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

const int MAX_COURSES = 10; // Maximum number of courses allowed per student

class Student {
public:
  // Constructor
  Student(std::string student_name, std::string student_id);

  // Get the student's name.
  std::string getName();

  // Get the student's id.
  std::string getId();

  // Add a course. Returns true on success, false if a new course cannot be
  // added.
  bool addCourse(std::string course_id);

  // Add a course with grades. Returns true on success, false if a new course
  // cannot be added.
  bool addCourse(std::string course_id, int grade_score);

  // Drop a course. Returns true on success, false if no course matches
  // course_id.
  bool dropCourse(std::string course_id);

  // Assign a grade scorer to a course. Returns true on success, false if no
  // course matches course_id.
  bool assignGradeScore(std::string course_id, int grade_score);

  // Get the grade score of a specific course. Returns -100 if no course matches
  // course_id.
  int getGradeScore(std::string course_id);

  // Get the letter grade of a specific course. Returns empty string if no
  // course matches course_id.
  std::string getGradeLetter(std::string course_id);

  int getNumberOfAssignedCourses();

  Course getCourseByIndex(int idx);

private:
  std::string name;            // name of the student
  std::string id;              // the student's id number
  Course courses[MAX_COURSES]; // courses taken by student
  int no_of_courses; // the current number of courses taken by the student

  // Helper function to find the index of a specific course in the courses
  // array. Returns -1 if no course matches course_id.
  int findCourseIndex(std::string course_id);
};
#endif
