option(CLANG_TIDY_FIX "Perform fixes for Clang-Tidy" OFF)
find_program(
    CLANG_TIDY_EXE
    NAMES "clang-tidy"
    DOC "Path to clang-tidy executable"
)

if(CLANG_TIDY_EXE)
  string(CONCAT CLANG_TIDY_CHECKS "-checks="
                                  "abseil-*,"
                                  "bugprone-*,"
                                  "cppcoreguidelines-*,"
                                  "-cppcoreguidelines-owning-memory,"
                                  "-cppcoreguidelines-special-member-functions,"
                                  "modernize-*,"
                                  "readability-*")
  if(CLANG_TIDY_FIX)
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}" "${CLANG_TIDY_CHECKS}" "-fix")
  else()
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}" "${CLANG_TIDY_CHECKS}")
  endif()
endif()