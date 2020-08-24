//
// Created by Johannes Flieger on 14/01/2020.
//

//
// Created by Johannes Flieger on 02/01/2020.
//
#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#endif

//#include <memory>
//#include "grid.h"
#include "grid_tests.h"

TEST_CASE("Create Grid objects from vectors of States")
{
    Grid grid1(grid_tests::sample_grid_1);
    Grid grid2(grid_tests::sample_grid_2);

    SECTION("Check rows and columns")
    {
        CHECK(grid1.num_rows == grid_tests::sample_grid_1_rows);
        CHECK(grid1.num_cols == grid_tests::sample_grid_1_cols);
        CHECK(grid1.Size() == grid_tests::sample_grid_1_size);
    }

    SECTION("Check valid cell positions")
    {
        CHECK(grid1.CellIsOnGrid(0,0));
        CHECK(grid1.CellIsOnGrid(2,3));
        CHECK(grid1.CellIsOnGrid(4,5));
        CHECK_FALSE(grid1.CellIsOnGrid(2,10));
        CHECK_FALSE(grid1.CellIsOnGrid(5,4));
        CHECK_FALSE(grid1.CellIsOnGrid(10,2));
        CHECK_FALSE(grid1.CellIsOnGrid(-2, 10));
        CHECK_FALSE(grid1.CellIsOnGrid(10, -2));
        CHECK_FALSE(grid1.CellIsOnGrid(2, -3));
    }

    SECTION("Equality")
    {
        CHECK(grid1 == grid1); // Sanity check
        CHECK_FALSE(grid1 == grid2);
    }
}
TEST_CASE("Write and read grid files")
{
    Grid grid1(grid_tests::sample_grid_1);

    SECTION("Write to file")
    {
        CHECK(grid1.ToFile(grid_tests::testfile));
    }
    SECTION("Read from file")
    {
        Grid grid2(grid_tests::testfile);
        CHECK( grid1 == grid2);
    }
}

