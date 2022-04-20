#ifndef __PLY_PARSER__
#define __PLY_PARSER__

#include <fstream>
#include <vector>
#include <iostream>
#include "ply_parser.h"

class PlyParser
{
public:
    PlyParser(std::string path_file);
    ~PlyParser();
    float _vertex_count;
    float _face_count;
    std::vector<std::vector<float>> parse_file();

private:
    std::string _path_file;
};
#endif