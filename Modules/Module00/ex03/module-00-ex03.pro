# Define the project type
TEMPLATE = app

# Define the target executable name
TARGET = module-00-ex03

# Include the Qt core module (if needed)
QT += core

# Specify the source files
SOURCES += sources/main.cpp \
           sources/Contact.cpp \
           sources/PhoneBook.cpp

# Specify the header files
HEADERS += include/Contact.hpp \
           include/PhoneBook.hpp

# Specify additional include paths
INCLUDEPATH += include

# Specify the output directory (optional)
DESTDIR = ./bin