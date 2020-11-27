TEMPLATE = subdirs

SUBDIRS += \
	CourseLib \
	Game \
        UnitTests \
        StatisticsTest

CourseLib.subdir = Course/CourseLib
Game.depends = CourseLib

HEADERS +=


SOURCES +=


