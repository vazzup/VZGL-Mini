#include "model.h"

Model::Model(const char *filename)
    : verts_(), faces_()
{
    std::ifstream in;
    // Open file, and if it fails, chuck
    in.open(filename, std::ifstream::in);
    if(in.fail()) return;
    std::string line;
    while(!in.eof()) // Read until End of File
    {
        std::getline(in, line); // Read one line
        std::istringstream iss(line.c_str()); // Convert to stream of chars
        char trash;
        if(!line.compare(0, 2, "v "))
        {
            // If the line does not describe a vertex
            iss >> trash; // Get rid of character v
            Vec3f v;
            for(int i=0; i<3; i++) iss >> v.raw[i]; // Read formatted floats 
            verts_.push_back(v); // Add the 3 floats to vertices
        }
        else if(!line.compare(0, 2, "f "))
        {
            std::vector<int> f;
            int itrash, idx;
            iss >> trash; // Get rid of the character f
            while(iss >> idx >> trash >> itrash >> trash >> itrash) // Read formatted as f int/int/int
            {
                idx--; // in wavefront obj, all indices start at 1, not zero
                f.push_back(idx);
            }
            faces_.push_back(f);
        }
    }
    std::cerr << "# v# " << verts_.size() << " f# " << faces_.size() << std::endl;
}

Model::~Model() { }

int Model::nverts()
{
    return (int)verts_.size();
}

int Model::nfaces()
{
    return (int)faces_.size();
}

std::vector<int> Model::face(int i)
{
    return faces_[i];
}

Vec3f Model::vert(int i)
{
    return verts_[i];
}
