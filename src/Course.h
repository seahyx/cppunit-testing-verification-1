#ifndef Course_h
#define Course_h

#include <string>

class Course {
public:
  // Default constructor
  Course();

  // Constructor
  Course(std::string course_id, int grade_score);

  // Get the course id
  std::string getCourseId();

  // Get name of the course
  std::string getCourseName();

  // Get the numerical grade of the course (0-100)
  int getCourseGradeScore();

  // Set the course grade score
  void setCourseGradeScore(int grade_score);

  // Get the grade letter of the course
  std::string getCourseGradeLetter();

private:
  std::string id; // id of this course
  int score;      // numerical grade score of this course
};
#endif
