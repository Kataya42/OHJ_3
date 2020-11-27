TEMPLATE = subdirs

SUBDIRS += \
	CourseLib \
	Game \
        UnitTests \
        ManseTest \
        StatisticsTest

CourseLib.subdir = Course/CourseLib
Game.depends = CourseLib

HEADERS +=


SOURCES +=


