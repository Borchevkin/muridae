#include "cli.hpp"

Cli::Params Cli::ArgParser::GetParams() {
    Params params{.in_filepath = tokens_.at(0), .out_filepath = tokens_.at(1)};

    return params;
}