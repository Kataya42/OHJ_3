TEMPLATE = subdirs

SUBDIRS += \
	CourseLib \
	Game \
	StatisticsTest \
	UnitTests

CourseLib.subdir = Course/CourseLib
Game.depends = CourseLib

HEADERS +=


SOURCES +=


