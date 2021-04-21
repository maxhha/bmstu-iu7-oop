#define CATCH_CONFIG_MAIN
#include "../lib/catch/single_include/catch2/catch.hpp"
#include "container.h"
#include "vector.hpp"

// TEST_CASE("Containers are created and sized", "[container]")
// {
//     SECTION("empty container")
//     {
//         Container c;
//         REQUIRE(c.getSize() == 0);
//     }

//     SECTION("container with size")
//     {
//         Container c = Container(10);
//         REQUIRE(c.getSize() == 10);
//     }
// }

TEST_CASE("Vectors are created and sized", "[vector]")
{
    SECTION("empty vector")
    {
        Vector<int> c;
        REQUIRE(c.getSize() == 0);
    }
}