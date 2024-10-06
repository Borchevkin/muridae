#pragma once

#include <fstream>
#include <string>
#include <vector>

class Snippeter {
   public:
    explicit Snippeter(const std::string& in_filepath)
        : in_filepath_{in_filepath} {
        in_stream_.open(in_filepath_);
        if (!in_stream_) {
            throw std::runtime_error("Cannot open file");
        }
    };
    ~Snippeter() {
        in_stream_.close();
    }

    void CreateSnippetFile(const std::string& out_filepath);

   private:
    std::string in_filepath_;
    std::ifstream in_stream_;
};