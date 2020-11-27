TEMPLATE = subdirs

SUBDIRS += \
	CourseLib \
	Game \
    ManseTest \
        UnitTests \
        StatisticsTest

CourseLib.subdir = Course/CourseLib
Game.depends = CourseLib

HEADERS +=


SOURCES +=


