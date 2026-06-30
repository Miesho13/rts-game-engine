function(push_def OPTION_NAME OPTION_MSG OPTION_VALUE)
    option(${OPTION_NAME} "${OPTION_MSG}" ${OPTION_VALUE})

    if(${OPTION_NAME})
        message(STATUS "${OPTION_MSG} - ENABLED")
        add_definitions(-D${OPTION_NAME})
    else()
        message(STATUS "${OPTION_MSG} - DISABLED")
    endif()

endfunction()

function(push_group_def GROUP_NAME GROUP_MSG GROUP_VALUE)
    option(${GROUP_NAME} "${GROUP_MSG}" ${GROUP_VALUE})

    if(${GROUP_NAME})
        message(STATUS "${GROUP_MSG} - ENABLED")

        foreach(DEFINITION ${ARGN})
            message(STATUS "  + ${DEFINITION}")
            add_definitions(-D${DEFINITION})
        endforeach()
    else()
        message(STATUS "${GROUP_MSG} - DISABLED")
    endif()
endfunction()
