project(Multichain)

find_package(Qt5 5.11.3 COMPONENTS Quick Widgets Core REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
  basiccontroller.cpp
  srcgui/dropfilearea/dropfileareacontroller.cpp
  srcback/src/CmdClient.cpp
  srcback/src/IpfsClient.cpp
  srcback/src/IpfsTests.cpp
  srcback/src/MultichainClient.cpp
  main.cpp

  basiccontroller.h
  srcback/inc/CmdClient.hh
  srcback/inc/IpfsClient.hh
  srcback/inc/IpfsTests.hh
  srcback/inc/MultichainClient.hh
  srcgui/dropfilearea/dropfileareacontroller.h

  qml.qrc
)

target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${srcgui_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedantic -Wshadow")

set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC ON AUTORCC ON)
target_link_libraries(${PROJECT_NAME}
  Qt5::Quick
  Qt5::Widgets
  Qt5::Core
)
