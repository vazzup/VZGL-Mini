#ifndef __MODEL_H__
#define __MODEL_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "geometry.h"

class Model {
private:
    // Vectors to store vertices and faces as read from .obj files
    std::vector<Vec3f> verts_;
    std::vector<std::vector<int> > faces_;
public:
    Model(const char *filename);
    ~Model();
    int nverts();
    int nfaces();
    Vec3f vert(int i); // Function to get ith vertex
    std::vector<int> face(int i); // Function to get ith face
};

#endif
