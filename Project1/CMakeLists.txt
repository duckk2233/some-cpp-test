add_executable(Project1-x86_64)
#target_compile_options(Project1 PRIVATE -fno-rtti)
aux_source_directory(${PROJECT_SOURCE_DIR}/Project1/src SRC_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/Project1/include INCLUDE_LIST)

target_compile_definitions(Project1-x86_64 PUBLIC $<$<CONFIG:Debug>:DEBUG>)

target_sources(Project1-x86_64
    PUBLIC
        ${SRC_LIST}
    
    PUBLIC
        FILE_SET HEADERS
        FILES
            ${INCLUDE_LIST}
)

#target_precompile_headers(Project1-x86_64 PRIVATE "include/pch.h")

target_link_libraries(Project1-x86_64 PRIVATE Engine)

#target_link_libraries(Project-x86_64 PRIVATE ${CMAKE_SOURCE_DIR}/external/glfw/lib-mingw-w64/libglfw3.a)
target_link_libraries(Project1-x86_64 PRIVATE ${CMAKE_SOURCE_DIR}/external/glfw/lib-mingw-w64/libglfw3dll.a)
target_link_libraries(Project1-x86_64 PRIVATE ${CMAKE_SOURCE_DIR}/external/glfw/lib-mingw-w64/glfw3.dll)
target_link_libraries(Project1-x86_64 PRIVATE opengl32 gdi32 user32 shell32)
target_include_directories(Project1-x86_64 PRIVATE ${CMAKE_SOURCE_DIR}/external/glfw/include)
add_custom_command(TARGET Project1-x86_64 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/external/glfw/lib-mingw-w64/glfw3.dll"
        "$<TARGET_FILE_DIR:Project1-x86_64>"
)

#file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/asm)
#target_compile_options(Project1-x86_64 PRIVATE
#    -g
#    -O0
#    -fverbose-asm
#    -Wa,-adhlns=${CMAKE_SOURCE_DIR}/asm/Project1-x86_64.lst
#)