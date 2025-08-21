#include "gmock/gmock.h"
#include "attendance.h"

class AttendanceFixture : public ::testing::Test {
public:
	void SetUp() override {
		EXPECT_TRUE(attendance.startAttendanceSystem("attendance_weekday_500.txt"));
	}

	Attendance attendance;
};

TEST_F(AttendanceFixture, inputFileTrue) {
	EXPECT_TRUE(attendance.inputFromFile("attendance_weekday_500.txt"));
}

TEST_F(AttendanceFixture, inputFileFalse) {
	EXPECT_FALSE(attendance.inputFromFile("attendance_weekday_500_fail.txt"));
}

TEST_F(AttendanceFixture, addStatusFalse) {
	EXPECT_FALSE(attendance.addStatus({"alice", "holiday"}));
}

TEST_F(AttendanceFixture, checkName) {
	EXPECT_EQ("Umar", attendance.getName(1));
	EXPECT_EQ("Daisy", attendance.getName(2));
	EXPECT_EQ("Hannah", attendance.getName(6));
	EXPECT_EQ("Zane", attendance.getName(19));
}

TEST_F(AttendanceFixture, checkScore) {
	EXPECT_EQ(48, attendance.getScore(1));
	EXPECT_EQ(45, attendance.getScore(2));
	EXPECT_EQ(127, attendance.getScore(6));
	EXPECT_EQ(1, attendance.getScore(19));
}

TEST_F(AttendanceFixture, checkGrade) {
	EXPECT_EQ("SILVER", attendance.getPlayerGrade(1));
	EXPECT_EQ("SILVER", attendance.getPlayerGrade(2));
	EXPECT_EQ("GOLD", attendance.getPlayerGrade(6));
	EXPECT_EQ("NORMAL", attendance.getPlayerGrade(19));
}

TEST_F(AttendanceFixture, checkIsRemoved) {
	EXPECT_EQ(false, attendance.getisRemoved(1));
	EXPECT_EQ(false, attendance.getisRemoved(2));
	EXPECT_EQ(false, attendance.getisRemoved(6));
	EXPECT_EQ(true, attendance.getisRemoved(13));
	EXPECT_EQ(true, attendance.getisRemoved(19));
}

