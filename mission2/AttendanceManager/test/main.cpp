#include "gmock/gmock.h"
#include "attendance.h"

#ifdef _DEBUG
int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
#else
int main() {
	Attendance attendence;
	attendence.startAttendanceSystem("attendance_weekday_500.txt");
}
#endif
