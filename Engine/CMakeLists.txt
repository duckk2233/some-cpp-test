add_library(Engine)
aux_source_directory(${PROJECT_SOURCE_DIR}/Engine/src SRC_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/Engine/include INCLUDE_LIST)
target_sources(Engine
    PRIVATE
        ${SRC_LIST}
    
    PUBLIC
        FILE_SET HEADERS
        FILES
            ${INCLUDE_LIST}
)