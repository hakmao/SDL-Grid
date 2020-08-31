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
#include <tuple>
#include "grid_tests.h"

TEST_CASE("Create Grid objects from vectors of States")
{
    Grid grid1(grid_tests::sample_grid_1);
    Grid grid2(grid_tests::sample_grid_2);
    Grid grid3(grid_tests::sample_grid_3);
    Grid grid4;

    SECTION("Check height (rows) and width (columns)")
    {
        CHECK(grid1.height == grid_tests::sample_grid_1_rows);
        CHECK(grid1.width == grid_tests::sample_grid_1_cols);
        CHECK(grid1.Size() == grid_tests::sample_grid_1_size);
        // Default settings (empty constructor)
        CHECK(grid4.height == 23);
        CHECK(grid4.width == 29);
        CHECK(grid4.Size() == 29 * 23);
    }

    SECTION("Check valid cell positions")
    {
        CHECK(grid1.ContainsCell(0,0));
        CHECK(grid1.ContainsCell(2,3));
        CHECK(grid1.ContainsCell(5,4));
        CHECK_FALSE(grid1.ContainsCell(4,5));
        CHECK_FALSE(grid1.ContainsCell(2,10));
        CHECK_FALSE(grid1.ContainsCell(10,2));
        CHECK_FALSE(grid1.ContainsCell(-2, 10));
        CHECK_FALSE(grid1.ContainsCell(10, -2));
        CHECK_FALSE(grid1.ContainsCell(2, -3));
    }

    SECTION("Equality")
    {
        CHECK(grid1 == grid1); // Sanity check
        CHECK_FALSE(grid1 == grid2);
        CHECK_FALSE(grid2 == grid3);
    }

    SECTION("Find Player position")
    {
        auto [f1, x1, y1 ] = grid1.FindPlayerPosition();
        CHECK(f1 == true);
        CHECK(x1 == 1);
        CHECK(y1 == 1);
        auto [f2, x2, y2 ] = grid2.FindPlayerPosition();
        CHECK(f2 == true);
        CHECK(x2 == 1);
        CHECK(y2 == 3);
        auto [f3, x3, y3 ] = grid3.FindPlayerPosition();
        CHECK(f3 == false);
        CHECK(x3 == 0);
        CHECK(y3 == 0);
    }
}
TEST_CASE("Writing and reading grid files")
{
    Grid grid10{grid_tests::sample_grid_1};
    // Write to file
    grid10.ToFile(grid_tests::test_file_1);

    SECTION("Read from file") {
        Grid grid11(grid_tests::test_file_1);
        CHECK(grid10 == grid11 ); // Check that grids are equivalent
        // Write to file
        grid11 .ToFile(grid_tests::test_file_2);
    }
}

