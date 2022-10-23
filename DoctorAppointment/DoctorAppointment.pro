QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appointmentbooking.cpp \
    appointmentcancelation.cpp \
    availableslots.cpp \
    chandima_appointment.cpp \
    doctorlogin.cpp \
    main.cpp \
    login.cpp \
    neelika_appointment.cpp \
    records.cpp \
    signup.cpp \
    thanuki_appointment.cpp

HEADERS += \
    appointmentbooking.h \
    appointmentcancelation.h \
    availableslots.h \
    chandima_appointment.h \
    doctorlogin.h \
    login.h \
    neelika_appointment.h \
    records.h \
    signup.h \
    thanuki_appointment.h

FORMS += \
    appointmentbooking.ui \
    appointmentcancelation.ui \
    availableslots.ui \
    chandima_appointment.ui \
    doctorlogin.ui \
    login.ui \
    neelika_appointment.ui \
    records.ui \
    signup.ui \
    thanuki_appointment.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
