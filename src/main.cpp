#include <iostream>
#include <string>

#include "errors.hpp"
#include "snippeter.hpp"
#include "cli.hpp"

int main(int argc, char *argv[]) {
    const std::string in_filename =
        "./../../../tests/integration_cpp/test_file_code.txt";
    const std::string out_filename = "./test_file_output_snippet.txt";

    Cli::Params params;
    try {
        auto arg_parser = Cli::ArgParser(argc, argv);
        params = arg_parser.GetParams();
    }
    catch (...) {
        std::cout << std::endl << Cli::HELP_STRING << std::endl;
        return ERR_NG;
    }

    try {
        auto snippeter = Snippeter(in_filename);
        snippeter.CreateSnippetFile(out_filename);
        std::cout << "Snippet was written to <" << out_filename << ">" << std::endl;
        return ERR_OK;
    }
    catch (...) {
        std::cout << "pizdec" << std::endl;
    }

    return ERR_NG;
}