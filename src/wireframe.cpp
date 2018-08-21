#include "wireframe.h"

void draw_wireframe(TGAImage &image, Model &model, int height, int width, TGAColor color)
{
    for(int i=0; i<model.nfaces(); i++)
    {
        std::vector<int> face = model.face(i);
        for(int j=0; j<3; j++)
        {
            Vec3f v0 = model.vert(face[j]);
            Vec3f v1 = model.vert(face[(j + 1) % 3]);
            int x0 = (v0.x + 1.)*width/2.;
            int y0 = (v0.y + 1.)*height/2.;
            int x1 = (v1.x + 1.)*width/2.;
            int y1 = (v1.y + 1.)*height/2.;
            line(x0, y0, x1, y1, image, color);
        }
    }
    image.flip_vertically();
    image.write_tga_file("output.tga");
}

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color)
{
    /* ***********************************************
     * Function to render a Line from point (x0, y0) to (x1, y1)
     * **********************************************/
    bool steep = false; // True if Slope > 1
    if(std::abs(x0 - x1) < std::abs(y0 - y1))
    {

        steep = true;
        std::swap(x0, y0);
        std::swap(x1, y1);
    }
    if(x0 > x1)
    {
        // (x0, y0) is to the right of (x1, y1)
        // So we swap the points to draw from left to right always
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    int dx = x1 - x0; // Difference in x
    int dy = y1 - y0; // Difference in y
    int derror = std::abs(dy) * 2; // Expected change in y with unit change in x times dx times 2
    int error = 0; // Cumulative change over multiple steps
    int y = y0;
    for(int x = x0; x <= x1; x++)
    {
        if(steep)
        {
            image.set(y, x, color); // Swap coordinates and set color
        }
        else
        {
            image.set(x, y, color); // Set color
        }
        error += derror;
        if(error > dx)
        {
            // Error is greater than dx implies change dy / (dx * 2) is greater than 0.5
            y += (y1 > y0? 1: -1); // Down to up or up to down
            error -= dx*2; // Keep error always below (dx * 2)
        }
    }
}
