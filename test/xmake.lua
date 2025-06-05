add_requires("conan::packio/2.5.0", {alias = "packio"})

target "test"
set_kind("binary")
add_packages("packio")
add_files("main.cpp")

