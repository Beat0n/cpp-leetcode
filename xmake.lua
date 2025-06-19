add_rules("mode.debug", "mode.release")

target("ex1")
    set_kind("binary")
    set_languages("c++20")
    add_files("src/excise/ex1/*.cc")

target("ex200")
    set_kind("binary")
    set_languages("c++20")
    add_files("src/excise/ex200/*.cc")

target("ex206")
    set_kind("binary")
    set_languages("c++20")
    add_files("src/excise/ex206/*.cc")

target("ex2")
    set_kind("binary")
    set_languages("c++20")
    add_files("src/excise/ex2/*.cc")

