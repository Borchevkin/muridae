#include <gtest/gtest.h>
#include "snippeter.hpp"
#include <stdexcept>
#include <string>

TEST(Integration, HappyFlowToSnippet) {
    auto snippeter = Snippeter("./../../../tests/integration_cpp/test_file_code.txt");
    snippeter.CreateSnippetFile("./test_file_output_snippet.txt");
}

TEST(Integration, CannotOpenFile) {
    try {
        auto snippeter = Snippeter("./../../../tests/integration_cpp/ururu.txt");
        FAIL() << "Expected std::runtime_error";
    }
    catch (std::runtime_error const & err) {
        EXPECT_EQ(err.what(), std::string("Cannot open file"));
    }
    catch(...) {
        FAIL() << "Expected std::runtime_error";
    }
}