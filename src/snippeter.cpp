#include "snippeter.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

/// @brief Create snippet file from input stream text
/// @param out_filepath path to output filepath
void Snippeter::CreateSnippetFile(const std::string& out_filepath) {
    std::ofstream out_stream;
    out_stream.open(out_filepath);

    if (!out_stream) {
        throw std::runtime_error("Cannot open file");
    }

    out_stream << "{" << std::endl;
    
    std::string line;
    bool is_first_line = true;
    while (getline(in_stream_, line)) {
        std::string escaped_line;
        if (!is_first_line) {
            out_stream << "," << std::endl;
        } else {
            is_first_line = false;
        }

        for (const char& symbol : line) {
            if ('"' == symbol) {
                escaped_line += "\\\"";
            } else {
                escaped_line += symbol;
            }
        }
        out_stream << "    \"" << escaped_line << "\"";
    }

    out_stream << std::endl;
    out_stream << "}" << std::endl;
    out_stream.close();
}
