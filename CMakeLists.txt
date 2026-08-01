cmake_minimum_required(VERSION 3.20)

project(AmusementParkTicketGenerator VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

function(configure_project_target target_name)
    target_include_directories(${target_name} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
    if(MSVC)
        target_compile_definitions(${target_name} PRIVATE _CRT_SECURE_NO_WARNINGS)
        target_compile_options(${target_name} PRIVATE /W4)
    else()
        target_compile_options(${target_name} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endfunction()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/user.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/ride_display.c")
    add_library(prisha_modules STATIC
        src/user.c
        src/ride_display.c
    )
    configure_project_target(prisha_modules)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/eligibility.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/selection.c")
    add_library(daksh_modules STATIC
        src/eligibility.c
        src/selection.c
    )
    configure_project_target(daksh_modules)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/delete.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/billing.c")
    add_library(naitik_modules STATIC
        src/delete.c
        src/billing.c
    )
    configure_project_target(naitik_modules)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/file_io.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/exit_module.c")
    add_library(pratyasa_modules STATIC
        src/file_io.c
        src/exit_module.c
    )
    configure_project_target(pratyasa_modules)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c")
    add_executable(park_app src/main.c)
    configure_project_target(park_app)

    foreach(module_target IN ITEMS
            prisha_modules
            daksh_modules
            naitik_modules
            pratyasa_modules)
        if(TARGET ${module_target})
            target_link_libraries(park_app PRIVATE ${module_target})
        endif()
    endforeach()
endif()

enable_testing()

set(TEST_FRAMEWORK
    tests/test_framework.c
)

function(add_individual_module_test target_name test_source compile_definition)
    add_executable(${target_name}
        ${TEST_FRAMEWORK}
        ${test_source}
        ${ARGN}
    )
    configure_project_target(${target_name})
    target_include_directories(${target_name} PRIVATE tests)
    target_compile_definitions(${target_name} PRIVATE ${compile_definition})
    add_test(NAME ${target_name} COMMAND ${target_name})
    set_tests_properties(${target_name} PROPERTIES
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    )
endfunction()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_user.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/user.c")
    add_individual_module_test(
        user_tests
        tests/test_user.c
        RUN_USER_TESTS_ONLY
        src/user.c
    )
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_ride_display.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/ride_display.c")
    add_individual_module_test(
        ride_display_tests
        tests/test_ride_display.c
        RUN_RIDE_DISPLAY_TESTS_ONLY
        src/ride_display.c
    )
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_eligibility.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/eligibility.c")
    add_individual_module_test(
        eligibility_tests
        tests/test_eligibility.c
        RUN_ELIGIBILITY_TESTS_ONLY
        src/eligibility.c
    )
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_selection.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/selection.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/eligibility.c")
    add_individual_module_test(
        selection_tests
        tests/test_selection.c
        RUN_SELECTION_TESTS_ONLY
        src/selection.c
        src/eligibility.c
    )
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_delete.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/delete.c")
    add_individual_module_test(
        delete_tests
        tests/test_delete.c
        RUN_DELETE_TESTS_ONLY
        src/delete.c
    )
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_billing.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/billing.c")
    add_individual_module_test(
        billing_tests
        tests/test_billing.c
        RUN_BILLING_TESTS_ONLY
        src/billing.c
    )
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_file_io.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/file_io.c")
    add_individual_module_test(
        file_io_tests
        tests/test_file_io.c
        RUN_FILE_IO_TESTS_ONLY
        src/file_io.c
    )
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_exit_module.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/exit_module.c")
    add_individual_module_test(
        exit_module_tests
        tests/test_exit_module.c
        RUN_EXIT_MODULE_TESTS_ONLY
        src/exit_module.c
    )
endif()

if(TARGET prisha_modules
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_user.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_ride_display.c")
    add_executable(prisha_tests
        ${TEST_FRAMEWORK}
        tests/runners/test_prisha_main.c
        tests/test_user.c
        tests/test_ride_display.c
    )
    configure_project_target(prisha_tests)
    target_include_directories(prisha_tests PRIVATE tests)
    target_link_libraries(prisha_tests PRIVATE prisha_modules)
    add_test(NAME PrishaModules COMMAND prisha_tests)
    set_tests_properties(PrishaModules PROPERTIES WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
endif()

if(TARGET daksh_modules
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_eligibility.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_selection.c")
    add_executable(daksh_tests
        ${TEST_FRAMEWORK}
        tests/runners/test_daksh_main.c
        tests/test_eligibility.c
        tests/test_selection.c
    )
    configure_project_target(daksh_tests)
    target_include_directories(daksh_tests PRIVATE tests)
    target_link_libraries(daksh_tests PRIVATE daksh_modules)
    add_test(NAME DakshModules COMMAND daksh_tests)
    set_tests_properties(DakshModules PROPERTIES WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
endif()

if(TARGET naitik_modules
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_delete.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_billing.c")
    add_executable(naitik_tests
        ${TEST_FRAMEWORK}
        tests/runners/test_naitik_main.c
        tests/test_delete.c
        tests/test_billing.c
    )
    configure_project_target(naitik_tests)
    target_include_directories(naitik_tests PRIVATE tests)
    target_link_libraries(naitik_tests PRIVATE naitik_modules)
    add_test(NAME NaitikModules COMMAND naitik_tests)
    set_tests_properties(NaitikModules PROPERTIES WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
endif()

if(TARGET pratyasa_modules
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_file_io.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_exit_module.c")
    add_executable(pratyasa_tests
        ${TEST_FRAMEWORK}
        tests/runners/test_pratyasa_main.c
        tests/test_file_io.c
        tests/test_exit_module.c
    )
    configure_project_target(pratyasa_tests)
    target_include_directories(pratyasa_tests PRIVATE tests)
    target_link_libraries(pratyasa_tests PRIVATE pratyasa_modules)
    add_test(NAME PratyasaModules COMMAND pratyasa_tests)
    set_tests_properties(PratyasaModules PROPERTIES WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
endif()

if(TARGET prisha_modules
   AND TARGET daksh_modules
   AND TARGET naitik_modules
   AND TARGET pratyasa_modules
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_main.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_user.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_ride_display.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_eligibility.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_selection.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_delete.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_billing.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_file_io.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_exit_module.c"
   AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/test_integration.c")
    add_executable(park_tests
        ${TEST_FRAMEWORK}
        tests/test_main.c
        tests/test_user.c
        tests/test_ride_display.c
        tests/test_eligibility.c
        tests/test_selection.c
        tests/test_delete.c
        tests/test_billing.c
        tests/test_file_io.c
        tests/test_exit_module.c
        tests/test_integration.c
    )
    configure_project_target(park_tests)
    target_include_directories(park_tests PRIVATE tests)
    target_link_libraries(park_tests PRIVATE
        prisha_modules
        daksh_modules
        naitik_modules
        pratyasa_modules
    )
    add_test(NAME AllModulesAndIntegration COMMAND park_tests)
    set_tests_properties(AllModulesAndIntegration PROPERTIES
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    )
endif()
