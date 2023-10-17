#include "Course.h"
#include "CourseList.h"

// default constructor
Course::Course() {
  id = "";
  score = -1;
}

// constructor
Course::Course(std::string course_id, int grade_score) : id(course_id) {
  score = grade_score;
}

std::string Course::getCourseId() { return id; }

std::string Course::getCourseName() { return COURSE_MAP.at(id); }

int Course::getCourseGradeScore() { return score; }

void Course::setCourseGradeScore(int grade_score) { score = grade_score; }

std::string Course::getCourseGradeLetter() {
  if (score > 100) {
    return "INV";
  } else if (score >= 90) {
    return "A";
  } else if (score >= 80) {
    return "B";
  } else if (score >= 70) {
    return "C";
  } else if (score >= 60) {
    return "D";
  } else if (score >= 50) {
    return "E";
  } else if (score >= 0) {
    return "F";
  } else if (score == -1) {
    return "NA";
  }
  return "INV";
}
