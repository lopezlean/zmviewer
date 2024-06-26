set ( shell_SRCS
      about.cpp
      main.cpp
      mainwindow.cpp
      cameraviewer.cpp
      layoutbar.cpp
      controlbar.cpp
      layoutbutton.cpp
      sliderlayoutbutton.cpp
      adminpanel.cpp
      styles/styledialog.cpp
      styles/style.cpp
      config/pageswidget.cpp
      config/configdialog.cpp
      config/configdialogpage.cpp
      config/cameraconfigwidget.cpp
      config/languageconfigwidget.cpp
      preferencesdialog.cpp
      translator.cpp
    )

set ( shell_UI
      ui/cameraconfigwidget.ui
      ui/languageconfigwidget.ui
)

QT4_ADD_RESOURCES ( shell_SRCS shell_resources.qrc )
QT4_ADD_RESOURCES ( shell_SRCS ${CMAKE_SOURCE_DIR}/translations.qrc )

QT4_WRAP_UI( shell_SRCS ${shell_UI} )

include_directories ( ${CMAKE_CURRENT_BINARY_DIR}
                      ${CMAKE_CURRENT_SOURCE_DIR} 
                      ${CMAKE_SOURCE_DIR}/src/core
                      ${CMAKE_BINARY_DIR}/src/core
                      ${CMAKE_BINARY_DIR}
                      ${QT_QTXML_INCLUDE_DIR}
                      ${QT_QTWEBKIT_INCLUDE_DIR}
             )



QT4_AUTOMOC (${shell_SRCS})
add_executable (zmviewer ${shell_SRCS} )
target_link_libraries( zmviewer ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTXML_LIBRARY} ${QT_QTWEBKIT_LIBRARY} zmviewercore )
install(TARGETS zmviewer DESTINATION ${ZMVIEWER_BIN_DIR})

install ( DIRECTORY styles/examples/blackstyle DESTINATION ${ZMVIEWER_STYLE_DIR}  PATTERN ".svn" EXCLUDE )
install ( DIRECTORY styles/examples/whitestyle DESTINATION ${ZMVIEWER_STYLE_DIR} PATTERN ".svn" EXCLUDE )
