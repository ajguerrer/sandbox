include(FetchContent)

FetchContent_Declare(
  abseilcpp
  GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
  GIT_TAG master
)

FetchContent_GetProperties(abseilcpp)
if(NOT abseilcpp_POPULATED)
  FetchContent_Populate(abseilcpp)
  add_subdirectory(${abseilcpp_SOURCE_DIR} ${abseilcpp_BINARY_DIR})
endif()