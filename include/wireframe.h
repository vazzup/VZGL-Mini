#ifndef __LINE_H__
#define __LINE_H__

#include "tgaimage.h"
#include "geometry.h"
#include "model.h"

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

void draw_wireframe(TGAImage &image, Model &model, int height, int width, TGAColor color);

#endif
