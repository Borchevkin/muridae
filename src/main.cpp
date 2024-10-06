#include <iostream>
#include <stdexcept>
#include <string>

#include "errors.hpp"
#include "snippeter.hpp"
#include "cli.hpp"

int main(int argc, char *argv[]) {

    Cli::Params params;
    try {
        auto arg_parser = Cli::ArgParser(argc, argv);
        params = arg_parser.GetParams();
    }
    catch (...) {
        std::cout << Cli::HELP_STRING << std::endl;
        return ERR_NG;
    }

    try {
        auto snippeter = Snippeter(params.in_filepath);
        snippeter.CreateSnippetFile(params.out_filepath);
        std::cout << "Snippet was written to <" << params.out_filepath << ">" << std::endl;
        return ERR_OK;
    }
    catch (const std::runtime_error& e) {
        std::cout << "Error: <" << e.what() << ">" << std::endl;
    }
    catch (...) {
        std::cout << "Unknown error. Aborted" << std::endl;
        throw;
    }

    return ERR_NG;
}