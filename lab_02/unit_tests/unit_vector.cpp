#include "../lib/catch/single_include/catch2/catch.hpp"
#include "vector.h"

TEST_CASE("Vectors are created and sized", "[Vector]")
{
    SECTION("empty vector")
    {
        Vector<int> c;
        REQUIRE(c.getSize() == 0);
    }

    SECTION("sized vector")
    {
        auto c = Vector<int>(10);
        REQUIRE(c.getSize() == 10);
    }
}

TEST_CASE("Vector iterators are iterating", "[VectorIterator]")
{
    SECTION("empty vector")
    {
        Vector<int> c;
        REQUIRE(c.begin() == c.end());
    }

    SECTION("expired vector")
    {
        auto b = std::shared_ptr<Vector<int>>(new Vector<int>(10));
        auto it = b->begin();

        b.reset(new Vector<int>(0));

        REQUIRE_THROWS_AS(it += 1, ExpiredPointerException);
    }
}