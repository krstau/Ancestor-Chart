set(publicHeaderDir ${PROJECT_SOURCE_DIR}/include)

set(publicHeaders
        "${publicHeaderDir}/AncestorChart.hpp"
        "${publicHeaderDir}/BinaryTree.hpp"
        "${publicHeaderDir}/Date.hpp"
        "${publicHeaderDir}/Formatting.hpp"
        "${publicHeaderDir}/Menu.hpp"
        "${publicHeaderDir}/Node.hpp"
        "${publicHeaderDir}/Person.hpp"
        )

set(sources
        AncestorChart.cpp
        Date.cpp
        Person.cpp
        )

add_library(AncestorChart_lib ${sources} ${publicHeaders})

target_include_directories(AncestorChart_lib PUBLIC ${publicHeaderDir})