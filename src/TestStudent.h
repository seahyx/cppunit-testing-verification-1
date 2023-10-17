#ifndef TestStudent_h
#define TestStudent_h

#include <cppunit/extensions/HelperMacros.h>

class StudentTest : public CPPUNIT_NS::TestFixture {
  CPPUNIT_TEST_SUITE(StudentTest);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testAssignNoInitialGradeScore);
  CPPUNIT_TEST(testAssignNoInitialGradeLetter);
  CPPUNIT_TEST(testAssignInitialGradeScore);
  CPPUNIT_TEST(testAssignInitialGradeLetter);
  CPPUNIT_TEST(testAssignGradeScore);
  CPPUNIT_TEST(testAddAndDropCourse);
  CPPUNIT_TEST(testGetAssignedCourseDetails);
  CPPUNIT_TEST(testSetCourseGradeScore);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

  void testConstructor();
  void testAssignNoInitialGradeScore();
  void testAssignNoInitialGradeLetter();
  void testAssignInitialGradeScore();
  void testAssignInitialGradeLetter();
  void testAssignGradeScore();
  void testAddAndDropCourse();
  void testGetAssignedCourseDetails();
  void testSetCourseGradeScore();
};
#endif
