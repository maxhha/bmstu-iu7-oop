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

    SECTION("zero vector")
    {
        auto c = Vector<int>(10);

        for (auto it = c.begin(); it < c.end(); ++it)
        {
            REQUIRE(*it == 0);
        }
    }

    SECTION("vector from list")
    {
        Vector<int> c({1, 5, 3, 10});

        auto it = c.begin();
        REQUIRE(*it == 1);
        REQUIRE(*(++it) == 5);
        REQUIRE(*(++it) == 3);
        REQUIRE(*(++it) == 10);
        REQUIRE_THROWS_AS(*(++it), OutOfRangeException);
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

    SECTION("out of range index")
    {
        auto c = Vector<int>(10);
        auto it = c.begin() + 10;

        REQUIRE_THROWS_AS(*it, OutOfRangeException);
    }
}

TEST_CASE("Vector operations are tested", "[Vector]")
{
    SECTION("length")
    {
        auto c = Vector<int>({3, 4});
        REQUIRE(c.length<int>() == 5);
    }

    SECTION("length of empty vec")
    {
        Vector<int> c;
        REQUIRE_THROWS_AS(c.length<int>(), EmptyVectorException);
    }

    SECTION("is zero")
    {
        Vector<int> c(10);
        REQUIRE(c.isZero() == true);
    }

    SECTION("normalized")
    {
        Vector<int> c({8, 6, 0});
        REQUIRE(c.normalized<double>() == Vector<double>({0.8, 0.6, 0.0}));
    }
}