#pragma once

#include <stdexcept>
#include <string>
#include <vector>

namespace Cli {
constexpr std::string_view HELP_STRING = "Help string\n";
constexpr int ARG_COUNT = 3; /**< Max arguments count */

/** Structure which holds all parameters passing to program */
struct Params {
    std::string in_filepath;  /**< In file filepath string */
    std::string out_filepath; /**< Out file filepath string */
};

class ArgParser {
   private:
    std::vector<std::string>
        tokens_; /**< Tokens - arguments passed to program */

   public:
    ArgParser(int argc, char** argv) {
        if (Cli::ARG_COUNT != argc) {
            throw std::runtime_error("Invalid arguments count");
        }

        for (int i = 1; i < argc; ++i) {
            tokens_.push_back(std::string(argv[i]));
        }
    }

    Params GetParams();
};
}  // namespace Cli