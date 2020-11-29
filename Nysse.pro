TEMPLATE = subdirs

SUBDIRS += \
	CourseLib \
	Game \
        UnitTests \
        StatisticsTest \
        ManseTest

CourseLib.subdir = Course/CourseLib
Game.depends = CourseLib

HEADERS +=


SOURCES +=


