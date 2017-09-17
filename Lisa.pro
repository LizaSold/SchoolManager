#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T21:17:07
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lisa
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connection.cpp \
    studentinfo.cpp \
    addmark.cpp \
    studentsDialog.cpp \
    Models/student.cpp \
    DBModels/studentdb.cpp \
    Search/studentsdb.cpp \
    help.cpp \
    Models/studentclass.cpp \
    DBModels/studentclassdb.cpp \
    Search/studentclassesdb.cpp \
    Models/mark.cpp \
    DBModels/markdb.cpp \
    Search/marksdb.cpp \
    Models/subject.cpp \
    DBModels/subjectdb.cpp \
    Search/subjectsdb.cpp

HEADERS  += mainwindow.h \
    connection.h \
    studentinfo.h \
    addmark.h \
    studentsDialog.h \
    Models/student.h \
    DBModels/studentdb.h \
    Search/studentsdb.h \
    help.h \
    Models/studentclass.h \
    DBModels/studentclassdb.h \
    Search/studentclassesdb.h \
    Models/mark.h \
    DBModels/markdb.h \
    Search/marksdb.h \
    Models/subject.h \
    DBModels/subjectdb.h \
    Search/subjectsdb.h

FORMS    += mainwindow.ui \
    students.ui \
    studentinfo.ui \
    addmark.ui
