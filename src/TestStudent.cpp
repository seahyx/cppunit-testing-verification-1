#include "TestStudent.h"
#include "CourseList.h"
#include "Student.h"
#include <cppunit/TestAssert.h>
#include <cppunit/config/SourcePrefix.h>

#include <iostream>
#include <string>

void StudentTest::setUp() {}

void StudentTest::tearDown() {}

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(StudentTest);

// Test Student object constructor
void StudentTest::testConstructor() {

  // Create a student object
  std::string test_name = "Seah Ying Xiang";
  std::string test_id = "t12902136";
  Student stu(test_name, test_id);

  // check that the object is constructed correctly
  std::string student_name = stu.getName();
  CPPUNIT_ASSERT(student_name == test_name);

  std::string student_id = stu.getId();
  CPPUNIT_ASSERT(student_id == test_id);

  return;
}

// Test assigning courses without initial score, verifying the default grade
// score
void StudentTest::testAssignNoInitialGradeScore() {

  // Create a student object
  std::string test_name = "Teng Hsuen";
  std::string test_id = "t12902135";
  Student stu(test_name, test_id);

  // Assign a few courses to this student without initial grade score
  CPPUNIT_ASSERT(stu.addCourse("50.001"));
  CPPUNIT_ASSERT(stu.addCourse("50.004"));
  CPPUNIT_ASSERT(stu.addCourse("50.053"));

  // Verify that assigned courses should have initial grade score of -1
  CPPUNIT_ASSERT_EQUAL(-1, stu.getGradeScore("50.001"));
  CPPUNIT_ASSERT_EQUAL(-1, stu.getGradeScore("50.004"));
  CPPUNIT_ASSERT_EQUAL(-1, stu.getGradeScore("50.053"));

  // Verify that invalid/unassigned courses should return a grade score of
  // -100
  CPPUNIT_ASSERT_EQUAL(-100, stu.getGradeScore("50.002"));
  CPPUNIT_ASSERT_EQUAL(-100, stu.getGradeScore("11.141"));
  CPPUNIT_ASSERT_EQUAL(-100, stu.getGradeScore("abcdef"));

  return;
}

// Test assigning courses without initial score, verifying the default grade
// letter
void StudentTest::testAssignNoInitialGradeLetter() {

  // Create a student object
  std::string test_name = "Teng Hsuen";
  std::string test_id = "t12902135";
  Student stu(test_name, test_id);

  // Assign a few courses to this student without initial grade score
  CPPUNIT_ASSERT(stu.addCourse("50.001"));
  CPPUNIT_ASSERT(stu.addCourse("50.004"));
  CPPUNIT_ASSERT(stu.addCourse("50.053"));

  // Verify that assigned courses should have initial grade letter of "NA"
  CPPUNIT_ASSERT_EQUAL((std::string) "NA", stu.getGradeLetter("50.001"));
  CPPUNIT_ASSERT_EQUAL((std::string) "NA", stu.getGradeLetter("50.004"));
  CPPUNIT_ASSERT_EQUAL((std::string) "NA", stu.getGradeLetter("50.053"));

  // Verify that invalid/unassigned courses should return a grade letter of ""
  CPPUNIT_ASSERT_EQUAL((std::string) "", stu.getGradeLetter("50.002"));
  CPPUNIT_ASSERT_EQUAL((std::string) "", stu.getGradeLetter("11.141"));
  CPPUNIT_ASSERT_EQUAL((std::string) "", stu.getGradeLetter("abcdef"));

  return;
}

// Test assigning courses with initial grade score
void StudentTest::testAssignInitialGradeScore() {

  // Create a student object
  std::string test_name = "Paul Ong Zesheng";
  std::string test_id = "t12902130";
  Student stu(test_name, test_id);

  // Assign a few courses to this student with initial grade score
  CPPUNIT_ASSERT(stu.addCourse("50.001", -10));
  CPPUNIT_ASSERT(stu.addCourse("50.002", 0));
  CPPUNIT_ASSERT(stu.addCourse("50.003", 30));
  CPPUNIT_ASSERT(stu.addCourse("50.004", 50));
  CPPUNIT_ASSERT(stu.addCourse("50.005", 60));
  CPPUNIT_ASSERT(stu.addCourse("50.006", 70));
  CPPUNIT_ASSERT(stu.addCourse("50.007", 80));
  CPPUNIT_ASSERT(stu.addCourse("50.012", 90));
  CPPUNIT_ASSERT(stu.addCourse("50.017", 100));
  CPPUNIT_ASSERT(stu.addCourse("50.021", 110));

  // Verify adding course beyond the max value should not proceed
  CPPUNIT_ASSERT(!stu.addCourse("50.040"));

  // Verify that assigned courses should have correctly assigned grade scores
  CPPUNIT_ASSERT_EQUAL(-10, stu.getGradeScore("50.001"));
  CPPUNIT_ASSERT_EQUAL(0, stu.getGradeScore("50.002"));
  CPPUNIT_ASSERT_EQUAL(30, stu.getGradeScore("50.003"));
  CPPUNIT_ASSERT_EQUAL(50, stu.getGradeScore("50.004"));
  CPPUNIT_ASSERT_EQUAL(60, stu.getGradeScore("50.005"));
  CPPUNIT_ASSERT_EQUAL(70, stu.getGradeScore("50.006"));
  CPPUNIT_ASSERT_EQUAL(80, stu.getGradeScore("50.007"));
  CPPUNIT_ASSERT_EQUAL(90, stu.getGradeScore("50.012"));
  CPPUNIT_ASSERT_EQUAL(100, stu.getGradeScore("50.017"));
  CPPUNIT_ASSERT_EQUAL(110, stu.getGradeScore("50.021"));

  // Verify that invalid/unassigned courses should return a grade score of
  // -100
  CPPUNIT_ASSERT_EQUAL(-100, stu.getGradeScore("50.040"));
  CPPUNIT_ASSERT_EQUAL(-100, stu.getGradeScore("50.052"));
  CPPUNIT_ASSERT_EQUAL(-100, stu.getGradeScore("11.141"));
  CPPUNIT_ASSERT_EQUAL(-100, stu.getGradeScore("abcdef"));

  return;
}

// Test assigning courses with initial grade score, but checking the grade
// letter
void StudentTest::testAssignInitialGradeLetter() {

  // Create a student object
  std::string test_name = "Paul Ong Zesheng";
  std::string test_id = "t12902130";
  Student stu(test_name, test_id);

  // Assign a few courses to this student with initial grade score
  CPPUNIT_ASSERT(stu.addCourse("50.001", -10));
  CPPUNIT_ASSERT(stu.addCourse("50.002", 0));
  CPPUNIT_ASSERT(stu.addCourse("50.003", 30));
  CPPUNIT_ASSERT(stu.addCourse("50.004", 50));
  CPPUNIT_ASSERT(stu.addCourse("50.005", 60));
  CPPUNIT_ASSERT(stu.addCourse("50.006", 70));
  CPPUNIT_ASSERT(stu.addCourse("50.007", 80));
  CPPUNIT_ASSERT(stu.addCourse("50.012", 90));
  CPPUNIT_ASSERT(stu.addCourse("50.017", 100));
  CPPUNIT_ASSERT(stu.addCourse("50.021", 110));

  // Verify that assigned courses should have correctly assigned grade letters
  CPPUNIT_ASSERT_EQUAL((std::string) "INV", stu.getGradeLetter("50.001"));
  CPPUNIT_ASSERT_EQUAL((std::string) "F", stu.getGradeLetter("50.002"));
  CPPUNIT_ASSERT_EQUAL((std::string) "F", stu.getGradeLetter("50.003"));
  CPPUNIT_ASSERT_EQUAL((std::string) "E", stu.getGradeLetter("50.004"));
  CPPUNIT_ASSERT_EQUAL((std::string) "D", stu.getGradeLetter("50.005"));
  CPPUNIT_ASSERT_EQUAL((std::string) "C", stu.getGradeLetter("50.006"));
  CPPUNIT_ASSERT_EQUAL((std::string) "B", stu.getGradeLetter("50.007"));
  CPPUNIT_ASSERT_EQUAL((std::string) "A", stu.getGradeLetter("50.012"));
  CPPUNIT_ASSERT_EQUAL((std::string) "A", stu.getGradeLetter("50.017"));
  CPPUNIT_ASSERT_EQUAL((std::string) "INV", stu.getGradeLetter("50.021"));

  // Verify that invalid/non-assigned courses should return a grade letter of ""
  CPPUNIT_ASSERT_EQUAL((std::string) "", stu.getGradeLetter("50.052"));
  CPPUNIT_ASSERT_EQUAL((std::string) "", stu.getGradeLetter("11.141"));
  CPPUNIT_ASSERT_EQUAL((std::string) "", stu.getGradeLetter("abcdef"));

  return;
}

// Test assigning grade scores to courses after their construction
void StudentTest::testAssignGradeScore() {

  // Create a student object
  std::string test_name = "Paul Ong Zesheng";
  std::string test_id = "t12902130";
  Student stu(test_name, test_id);

  // Assign a few courses to this student without initial grade score
  CPPUNIT_ASSERT(stu.addCourse("50.001"));
  CPPUNIT_ASSERT(stu.addCourse("50.004"));
  CPPUNIT_ASSERT(stu.addCourse("50.053"));

  // Assign a grade score to these courses
  CPPUNIT_ASSERT(stu.assignGradeScore("50.001", 65));
  CPPUNIT_ASSERT(stu.assignGradeScore("50.004", 81));
  CPPUNIT_ASSERT(stu.assignGradeScore("50.053", 100));

  // Verify the assigned grade scores
  CPPUNIT_ASSERT_EQUAL(65, stu.getGradeScore("50.001"));
  CPPUNIT_ASSERT_EQUAL(81, stu.getGradeScore("50.004"));
  CPPUNIT_ASSERT_EQUAL(100, stu.getGradeScore("50.053"));

  // Verify trying to assign a score to an invalid/unassigned course will
  // fail
  CPPUNIT_ASSERT(!stu.assignGradeScore("50.002", 50));
  CPPUNIT_ASSERT(!stu.assignGradeScore("abcdef", 50));
}

// Test adding and dropping courses
void StudentTest::testAddAndDropCourse() {

  // Create a student object
  std::string test_name = "Seah Ying Xiang";
  std::string test_id = "t12902136";
  Student stu(test_name, test_id);

  // Assign a few courses to this student with initial grade score
  CPPUNIT_ASSERT(stu.addCourse("50.001", 65));
  CPPUNIT_ASSERT(stu.addCourse("50.004", 81));
  CPPUNIT_ASSERT(stu.addCourse("50.053", 100));

  // Verify that assigned courses should have correctly assigned grades
  CPPUNIT_ASSERT_EQUAL(65, stu.getGradeScore("50.001"));
  CPPUNIT_ASSERT_EQUAL(81, stu.getGradeScore("50.004"));
  CPPUNIT_ASSERT_EQUAL(100, stu.getGradeScore("50.053"));

  // Drop a course, verify that the dropped course should now have a grade score
  // of -100, while the other courses are intact
  CPPUNIT_ASSERT(stu.dropCourse("50.001"));
  CPPUNIT_ASSERT_EQUAL(-100, stu.getGradeScore("50.001"));
  CPPUNIT_ASSERT_EQUAL(81, stu.getGradeScore("50.004"));
  CPPUNIT_ASSERT_EQUAL(100, stu.getGradeScore("50.053"));

  // Drop a course, verify that the dropped course should now have a grade score
  // of -100, while the other courses are intact
  CPPUNIT_ASSERT(stu.dropCourse("50.053"));
  CPPUNIT_ASSERT_EQUAL(-100, stu.getGradeScore("50.001"));
  CPPUNIT_ASSERT_EQUAL(81, stu.getGradeScore("50.004"));
  CPPUNIT_ASSERT_EQUAL(-100, stu.getGradeScore("50.053"));

  // Drop the final course, verify that all courses should now have a grade
  // score of -100
  CPPUNIT_ASSERT(stu.dropCourse("50.004"));
  CPPUNIT_ASSERT_EQUAL(-100, stu.getGradeScore("50.001"));
  CPPUNIT_ASSERT_EQUAL(-100, stu.getGradeScore("50.004"));
  CPPUNIT_ASSERT_EQUAL(-100, stu.getGradeScore("50.053"));

  // Verify dropping a non-assigned or dropped course should not proceed
  CPPUNIT_ASSERT(!stu.dropCourse("50.001"));
  CPPUNIT_ASSERT(!stu.dropCourse("50.012"));

  return;
}

// Test retrieving an assigned course object and getting its details
void StudentTest::testGetAssignedCourseDetails() {

  // Create a student object
  std::string test_name = "Seah Ying Xiang";
  std::string test_id = "t12902136";
  Student stu(test_name, test_id);

  // Assign a few courses to this student with initial grade score
  CPPUNIT_ASSERT(stu.addCourse("50.001", 65));
  CPPUNIT_ASSERT(stu.addCourse("50.004", 81));
  CPPUNIT_ASSERT(stu.addCourse("50.053", 100));

  // Verify number of courses assigned to the student
  CPPUNIT_ASSERT_EQUAL(3, stu.getNumberOfAssignedCourses());

  // Verify the first assigned course
  CPPUNIT_ASSERT_EQUAL((std::string) "50.001",
                       stu.getCourseByIndex(0).getCourseId());
  CPPUNIT_ASSERT_EQUAL(COURSE_MAP.at("50.001"),
                       stu.getCourseByIndex(0).getCourseName());
  CPPUNIT_ASSERT_EQUAL(65, stu.getCourseByIndex(0).getCourseGradeScore());

  // Verify the last assigned course
  CPPUNIT_ASSERT_EQUAL((std::string) "50.053",
                       stu.getCourseByIndex(2).getCourseId());
  CPPUNIT_ASSERT_EQUAL(COURSE_MAP.at("50.053"),
                       stu.getCourseByIndex(2).getCourseName());
  CPPUNIT_ASSERT_EQUAL(100, stu.getCourseByIndex(2).getCourseGradeScore());
}

// Test assigning a grade score to a course object after its construction
void StudentTest::testSetCourseGradeScore() {
  // Create a course object
  Course course = Course("50.001", -1);

  // Verify constructor
  CPPUNIT_ASSERT_EQUAL((std::string) "50.001", course.getCourseId());
  CPPUNIT_ASSERT_EQUAL(COURSE_MAP.at("50.001"), course.getCourseName());
  CPPUNIT_ASSERT_EQUAL(-1, course.getCourseGradeScore());
  CPPUNIT_ASSERT_EQUAL((std::string) "NA", course.getCourseGradeLetter());

  // Set course grade score
  course.setCourseGradeScore(65);
  CPPUNIT_ASSERT_EQUAL(65, course.getCourseGradeScore());
  CPPUNIT_ASSERT_EQUAL((std::string) "D", course.getCourseGradeLetter());
}