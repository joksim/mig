set(CMAKE_CXX_STANDARD 17)

MACRO(SUBDIRLIST result curdir)
    FILE(GLOB children ${curdir}/*) # This was changed
    SET(dirlist "")
    FOREACH(child ${children})
        IF(IS_DIRECTORY ${child}) # This was changed
            LIST(APPEND dirlist ${child})
        ENDIF()
    ENDFOREACH()
    SET(${result} ${dirlist})
ENDMACRO()

#add_subdirectory(${CMAKE_CURRENT_LIST_DIR})

SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_LIST_DIR})

FOREACH(subdir ${SUBDIRS})
    #message(${subdir})
    ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()

#add_subdirectory(std-vector)