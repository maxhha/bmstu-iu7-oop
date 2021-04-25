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
        REQUIRE(c.lengthSquared() == 25);
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

    SECTION("x y z")
    {
        Vector<int> c({8, 6, 0});
        REQUIRE(c.x() == 8);
        REQUIRE(c.y() == 6);
        REQUIRE(c.z() == 0);

        c = Vector<int>({1, 2});
        REQUIRE_THROWS_AS(c.z(), OutOfRangeException);
    }

    SECTION("has zero")
    {
        Vector<int> c({8, 6, 0});
        REQUIRE(c.hasZero() == true);
    }

    SECTION("neg")
    {
        Vector<int> c({8, 6, 0});
        REQUIRE(c.neg() == Vector<int>({-8, -6, 0}));
        REQUIRE(c == Vector<int>({8, 6, 0}));
        REQUIRE(c.negUpdate() == Vector<int>({-8, -6, 0}));
        REQUIRE(c == Vector<int>({-8, -6, 0}));
    }

    SECTION("add vec")
    {
        Vector<int> a({1, 6, 0}), b({1, -10, -2}), d = Vector<int>({1, 2, 3, 4});

        REQUIRE(a.add(b) == Vector<int>({2, -4, -2}));
        REQUIRE(a == Vector<int>({1, 6, 0}));
        REQUIRE(a.addUpdate(b) == Vector<int>({2, -4, -2}));
        REQUIRE(a == Vector<int>({2, -4, -2}));
        REQUIRE_THROWS_AS(a.add(d), MismatchSizeException);
    }

    SECTION("add scalar")
    {
        Vector<int> a({1, 6, 0});
        int b = 2;

        REQUIRE(a.addScalar(b) == Vector<int>({3, 8, 2}));
        REQUIRE(a == Vector<int>({1, 6, 0}));
        REQUIRE(a.addScalarUpdate(b) == Vector<int>({3, 8, 2}));
        REQUIRE(a == Vector<int>({3, 8, 2}));
    }

    SECTION("sub vec")
    {
        Vector<int> a({1, 6, 0}), b({1, -10, -2}), d = Vector<int>({1, 2, 3, 4});

        REQUIRE(a.sub(b) == Vector<int>({0, 16, 2}));
        REQUIRE(a == Vector<int>({1, 6, 0}));
        REQUIRE(a.subUpdate(b) == Vector<int>({0, 16, 2}));
        REQUIRE(a == Vector<int>({0, 16, 2}));
        REQUIRE_THROWS_AS(a.add(d), MismatchSizeException);
    }

    SECTION("sub scalar")
    {
        Vector<int> a({1, 6, 0});
        int b = 6;

        REQUIRE(a.subScalar(b) == Vector<int>({-5, 0, -6}));
        REQUIRE(a == Vector<int>({1, 6, 0}));
        REQUIRE(a.subScalarUpdate(b) == Vector<int>({-5, 0, -6}));
        REQUIRE(a == Vector<int>({-5, 0, -6}));
    }

    SECTION("mul vec")
    {
        Vector<int> a({1, 6, 0}), b({1, -10, -2}), d = Vector<int>({1, 2, 3, 4});

        REQUIRE(a.mul(b) == Vector<int>({1, -60, 0}));
        REQUIRE(a == Vector<int>({1, 6, 0}));
        REQUIRE(a.mulUpdate(b) == Vector<int>({1, -60, 0}));
        REQUIRE(a == Vector<int>({1, -60, 0}));
        REQUIRE_THROWS_AS(a.mul(d), MismatchSizeException);
    }

    SECTION("mul scalar")
    {
        Vector<int> a({1, 6, 0});
        int b = 2;

        REQUIRE(a.mulScalar(b) == Vector<int>({2, 12, 0}));
        REQUIRE(a == Vector<int>({1, 6, 0}));
        REQUIRE(a.mulScalarUpdate(b) == Vector<int>({2, 12, 0}));
        REQUIRE(a == Vector<int>({2, 12, 0}));
    }

    SECTION("div vec")
    {
        Vector<int> a({1, 6, 0}), b({1, -2, -2}), d = Vector<int>({1, 2, 3, 4});

        REQUIRE(a.div(b) == Vector<int>({1, -3, 0}));
        REQUIRE(a == Vector<int>({1, 6, 0}));
        REQUIRE_THROWS_AS(b.div(a), ZeroDivisionException);
        REQUIRE(a == Vector<int>({1, 6, 0}));
        REQUIRE(a.divUpdate(b) == Vector<int>({1, -3, 0}));
        REQUIRE(a == Vector<int>({1, -3, 0}));
        REQUIRE_THROWS_AS(a.div(d), MismatchSizeException);
    }

    SECTION("div scalar")
    {
        Vector<int> a({1, 6, 0});

        REQUIRE(a.divScalar(2) == Vector<int>({0, 3, 0}));
        REQUIRE(a == Vector<int>({1, 6, 0}));
        REQUIRE_THROWS_AS(a.divScalar(0), ZeroDivisionException);
        REQUIRE(a.divScalarUpdate(2) == Vector<int>({0, 3, 0}));
        REQUIRE(a == Vector<int>({0, 3, 0}));
    }

    SECTION("dot product")
    {
        Vector<int> a({1, 6, 0}), b({1, -2, -2}), d = Vector<int>({1, 2, 3, 4});

        REQUIRE(a.dot(b) == -11);
        REQUIRE_THROWS_AS(a.dot(d), MismatchSizeException);
    }

    SECTION("cross product")
    {
        Vector<int> a({1, 6, 0}), b({1, -2, -2}), d = Vector<int>({1, 2, 3, 4});

        REQUIRE(a.cross(b) == Vector<int>({-12, 2, -8}));
        REQUIRE(a == Vector<int>({1, 6, 0}));
        REQUIRE_THROWS_AS(a.cross(d), MismatchSizeException);
        REQUIRE_THROWS_AS(d.cross(d), InvalidSizeException);
        REQUIRE(a.crossUpdate(b) == Vector<int>({-12, 2, -8}));
        REQUIRE(a == Vector<int>({-12, 2, -8}));
    }
}