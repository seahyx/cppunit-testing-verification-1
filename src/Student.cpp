#include "Student.h"
#include <stdexcept>

// Constructor
Student::Student(std::string student_name, std::string student_id)
    : name(student_name), id(student_id) {
  no_of_courses = 0;
}

std::string Student::getName() { return name; }

std::string Student::getId() { return id; }

bool Student::addCourse(std::string course_id) {
  return addCourse(course_id, -1);
}

bool Student::addCourse(std::string course_id, int grade_score) {
  // check whether the maximum number of courses have been taken
  if (no_of_courses == MAX_COURSES) {
    std::cout << "You have exceeded the maximum number of courses !\n";
    return false;
  }

  Course course(course_id, grade_score);
  courses[no_of_courses++] = course;
  return true;
}

bool Student::dropCourse(std::string course_id) {
  bool found_course = false;
  for (int k = 0; k < no_of_courses; ++k) {
    if (!found_course) {
      // Find the course
      found_course = courses[k].getCourseId() == course_id;
    } else {
      // Remove the course by copying the next course over until the end
      courses[k - 1] = courses[k];
    }
  }
  if (found_course) {
    --no_of_courses;
    return true;
  }
  return false;
}

bool Student::assignGradeScore(std::string course_id, int grade_score) {
  int k = findCourseIndex(course_id);
  if (k != -1) {
    courses[k].setCourseGradeScore(grade_score);
    return true;
  }
  return false;
}

int Student::getGradeScore(std::string course_id) {
  int k = findCourseIndex(course_id);
  if (k != -1) {
    return courses[k].getCourseGradeScore();
  }
  return -100;
}

std::string Student::getGradeLetter(std::string course_id) {
  int k = findCourseIndex(course_id);
  if (k != -1) {
    return courses[k].getCourseGradeLetter();
  }
  return "";
}

int Student::getNumberOfAssignedCourses() { return no_of_courses; }

Course Student::getCourseByIndex(int idx) { return courses[idx]; }

int Student::findCourseIndex(std::string course_id) {
  for (int k = 0; k < no_of_courses; ++k) {
    if (courses[k].getCourseId() == course_id)
      return k;
  }
  return -1;
}
