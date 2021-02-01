/*

MIT License

Copyright (c) 2021 PCSX-Redux authors

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#pragma once

#include <stdint.h>

#include "common/hardware/gpu.h"
#include "common/hardware/hwregs.h"
#include "shell/math.h"

#define WIDTH 512
#define HEIGHT 480

union GPUPoint {
    uint32_t packed;
    struct {
        int16_t x, y;
    };
};

void initGPU();
void flip();
void waitVSync();

static inline void sendGPUVertex(struct Vertex2D *v) {
    union GPUPoint p;
    int32_t y = v->y >> 22;
    y = y * 5 / 4;
    p.x = v->x >> 22;
    p.y = y + HEIGHT / 2;
    GPU_DATA = p.packed;
}

static const union Color s_bg = {.r = 0, .g = 64, .b = 91};
static const union Color s_saturated = {.r = 156, .g = 220, .b = 218};
