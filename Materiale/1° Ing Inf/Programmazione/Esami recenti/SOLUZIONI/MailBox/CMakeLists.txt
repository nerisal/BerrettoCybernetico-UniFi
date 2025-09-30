cmake_minimum_required(VERSION 3.10)
project(MailBox)

set(CMAKE_CXX_STANDARD 11)

add_executable(MailBox main.cpp MailBox.h Mail.h Observer.h header.h Subject.h GuiNotifier.h IconBadgeMonitor.h)