#include "tgaimage.h"
#include "wireframe.h"
#include "geometry.h"
#include "model.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

int main(int argc, char** argv)
{
    if(argc == 1)
    {
        std::cout << "Usage: ./render /Path/to/.obj/file" << std::endl;
        return 0;
    }
    int height = 1000, width = 1000;
    TGAImage image(height, width, TGAImage::RGB);
    Model model(argv[1]);
    draw_wireframe(image, model, height, width, white);
    return 0;
}
