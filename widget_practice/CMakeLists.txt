set(TARGET_NAME WidgetPractice)
set(HEADERS
    mymainwindow.h
    mywidget.h
)
set(SRCS
    main.cpp
    mymainwindow.cpp
    mainwindow.ui
    mywidget.cpp
)

set(QRCS
    resource.qrc
)

qt_add_executable(${TARGET_NAME} ${HEADERS} ${SRCS} ${QRCS})
target_link_libraries(${TARGET_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets)
#qt_standard_project_setup()
#qt6_deploy_runtime_dependencies()
#WINDEPLOYQT_EXECUTABLE
#qt_generate_deploy_app_script(
#    TARGET ${TARGET_NAME}
#    OUTPUT_SCRIPT deploy_script
#)
#install(SCRIPT ${deploy_script})

#qt_deploy_runtime_dependencies(
#    EXECUTABLE \"\${QT_DEPLOY_BIN_DIR}/$<TARGET_FILE_NAME:${TARGET_NAME}>\"
#    GENERATE_QT_CONF
#)

#add_custom_command(TARGET ${TARGET_NAME}
#    POST_BUILD
#    COMMAND ECHO STDOUT
#    COMMAND "${__QT_DEPLOY_TOOL}" "${arg_EXECUTABLE}" ${tool_options}
#    )
    #execute_process(
    #    COMMAND_ECHO STDOUT
    #    COMMAND "${__QT_DEPLOY_TOOL}" "${arg_EXECUTABLE}" ${tool_options}
    #    WORKING_DIRECTORY "${QT_DEPLOY_PREFIX}"
    #    RESULT_VARIABLE result
    #)
#qt_generate_deploy_app_script(
#    TARGET ${TARGET_NAME}
#    OUTPUT_SCRIPT deploy_script
#    NO_UNSUPPORTED_PLATFORM_ERROR
#)

#qt_generate_deploy_script(
#	TARGET ${TARGET_NAME}
#)
#qt_deploy_runtime_dependencies(EXECUTABLE \"$<TARGET_FILE_NAME:${TARGET_NAME}>\")

install(TARGETS ${TARGET_NAME}
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET ${TARGET_NAME}
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
message("deploy_script:${deploy_script}")
#install(SCRIPT ${deploy_script})
#install(FILES main.cpp DESTINATION $<CONFIG>/hello/)
install(CODE "execute_process(COMMAND ${WINDEPLOYQT_EXECUTABLE} $<TARGET_FILE:${TARGET_NAME}>)")