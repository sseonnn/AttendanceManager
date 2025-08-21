#include "gmock/gmock.h"
#include "attendance.h"

TEST(Attendance, inputFileTrue) {
	Attendance attendance;
	EXPECT_TRUE(attendance.inputFromFile("attendance_weekday_500.txt"));
}

TEST(Attendance, inputFileFalse) {
	Attendance attendance;
	EXPECT_FALSE(attendance.inputFromFile("attendance_weekday_500_fail.txt"));
}

TEST(Attendance, addStatusFalse) {
	Attendance attendance;
	EXPECT_FALSE(attendance.addStatus({"alice", "holiday"}));
}

TEST(Attendance, checkName) {
	Attendance attendance;
	EXPECT_TRUE(attendance.startAttendanceSystem("attendance_weekday_500.txt"));

	EXPECT_EQ("Umar", attendance.getName(1));
	EXPECT_EQ("Daisy", attendance.getName(2));
	EXPECT_EQ("Zane", attendance.getName(19));
}

TEST(Attendance, checkScore) {
	Attendance attendance;
	EXPECT_TRUE(attendance.startAttendanceSystem("attendance_weekday_500.txt"));

	EXPECT_EQ(48, attendance.getScore(1));
	EXPECT_EQ(45, attendance.getScore(2));
	EXPECT_EQ(1, attendance.getScore(19));
}

TEST(Attendance, checkGrade) {
	Attendance attendance;
	EXPECT_TRUE(attendance.startAttendanceSystem("attendance_weekday_500.txt"));

	EXPECT_EQ("SILVER", attendance.getPlayerGrade(1));
	EXPECT_EQ("GOLD", attendance.getPlayerGrade(3));
	EXPECT_EQ("NORMAL", attendance.getPlayerGrade(19));
}

TEST(Attendance, checkisRemoved) {
	Attendance attendance;
	EXPECT_TRUE(attendance.startAttendanceSystem("attendance_weekday_500.txt"));

	EXPECT_EQ(false, attendance.getisRemoved(1));
	EXPECT_EQ(false, attendance.getisRemoved(2));
	EXPECT_EQ(true, attendance.getisRemoved(19));
}

