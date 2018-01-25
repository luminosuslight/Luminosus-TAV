/*
typedef unsigned int size_t;

size_t m_x = 3;
size_t m_y = 3;

float m_hsvData[m_x][m_y][3];
float m_rgbData[m_x][m_y][3];

size_t getSX() { return m_x; }

size_t getSY() { return m_y; }

void main(int argc, char** argv) {
    float hsv[getSX()][getSY()][3] = malloc()
}
*/

#include <stdio.h>

void hsvToRgb(float h, float s, float v, float* r, float* g, float* b) {
    double f, p, q, t;

    if (s == 0.0) {
        (*r) = v;
        (*g) = v;
        (*b) = v;
        return;
    }

    int i = (int)(h*6);
    f = (h*6)-i;
    p = v*(1-s);
    q = v*(1-s*f);
    t = v*(1-s*(1-f));
    i = i % 6;
    switch (i) {
        case 0: *r = v, *g = t, *b = p; break;
        case 1: *r = q, *g = v, *b = p; break;
        case 2: *r = p, *g = v, *b = t; break;
        case 3: *r = p, *g = q, *b = v; break;
        case 4: *r = t, *g = p, *b = v; break;
        case 5: *r = v, *g = p, *b = q; break;
        default: *r = 0, *g = 0, *b = 0; break;
    }
}

void main(int argc, char** argv) {
    float r = 0.f;
    float g = 0.f;
    float b = 0.f;

    float h = 0.f;
    float s = 0.f;
    float v = 0.f;

    klee_make_symbolic(&h, sizeof(h), "h");
    klee_make_symbolic(&s, sizeof(s), "s");
    klee_make_symbolic(&v, sizeof(v), "v");

    hsvToRgb(h, s, v, &r, &g, &b);
}

/*
void hsvToRgb(float[][][] hsv, float[][][] rgb) {
    size_t sx = getSX();
    size_t sy = getSY();
    for (size_t x=0; x<sx; ++x) {
        for (size_t y=0; y<sy; ++y) {
            double h, s, v, f, p, q, t, r, g, b;
            h = hsv[x][y][0];
            s = hsv[x][y][1];
            v = hsv[x][y][2];
            if (s == 0.0) {
                rgb[x][y][0] = v;
                rgb[x][y][1] = v;
                rgb[x][y][2] = v;
                continue;
            }
            int i = (int)(h*6);
            f = (h*6)-i;
            p = v*(1-s);
            q = v*(1-s*f);
            t = v*(1-s*(1-f));
            i = i % 6;
            switch (i) {
                case 0: r = v, g = t, b = p; break;
                case 1: r = q, g = v, b = p; break;
                case 2: r = p, g = v, b = t; break;
                case 3: r = p, g = q, b = v; break;
                case 4: r = t, g = p, b = v; break;
                case 5: r = v, g = p, b = q; break;
				default: r = 0, g = 0, b = 0; break;
            }
            rgb[x][y][0] = r;
            rgb[x][y][1] = g;
            rgb[x][y][2] = b;
        }
    }
}
*/