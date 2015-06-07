#pragma once
#include <queue>

#include <Vorb/Timing.h>

#include "Constants.h"
#include "OpenGLStructs.h"

extern MultiplePreciseTimer globalMultiplePreciseTimer; ///< For easy global benchmarking
extern AccumulationTimer globalAccumulationTimer;
extern AccumulationTimer globalRenderAccumulationTimer; ///< for easy global benchmarking

extern class Item *ObjectList[OBJECT_LIST_SIZE];

struct PlanetGenData;

class FixedSizeBillboardVertex{
public:
    glm::vec3 pos;
    GLubyte uv[2];
};

//TODO(Ben): Make this work again
class Marker{
public:
    glm::dvec3 pos;
    ColorRGBA8 color;
    int num;
    double dist;
    nString name;

    vg::Texture distText;
    vg::Texture nameTex;

    Marker(const glm::dvec3 &Pos, nString Name, const glm::vec3 Color);
    void Draw(glm::mat4 &VP, const glm::dvec3 &playerPos);
};

//flags
const int TOOSTEEP = 0x4;

class HeightData;

class LoadData
{
public:
    LoadData()
    {
    }
    LoadData(const HeightData* hmap, const PlanetGenData* gData)
    {
        heightMap = hmap;
        genData = gData;
    }
    
    inline void init(const HeightData* hmap, const PlanetGenData* gData)
    {
        heightMap = hmap;
        genData = gData;
    }

    const HeightData* heightMap;
    const PlanetGenData* genData;
};

struct MineralData
{
    MineralData(GLint btype, GLint startheight, float startchance, GLint centerheight, float centerchance, GLint endheight, float endchance, GLint minsize, GLint maxsize)
    {
        blockType = btype;
        startHeight = startheight;
        startChance = startchance;
        endHeight = endheight;
        endChance = endchance;
        centerHeight = centerheight;
        centerChance = centerchance;
        minSize = minsize;
        maxSize = maxsize;
    }
    GLint blockType, startHeight, endHeight, centerHeight, minSize, maxSize;
    GLfloat startChance, centerChance, endChance;
};

class BillboardVertex
{
public:
    glm::vec3 pos;
    glm::vec2 uvMult;
    GLubyte texUnit;
    GLubyte texID;
    GLubyte light[2];
    GLubyte color[4];
    GLubyte size;
    GLubyte xMod;
    GLubyte padding[2]; //needs to be 4 byte aligned
};

class PhysicsBlockPosLight
{
public:
    f32v3 pos; //12
    ColorRGB8 color; //15
    GLubyte pad1; //16
    ColorRGB8 overlayColor; //19
    GLubyte pad2; //20
    GLubyte light[2]; //22
    GLubyte pad3[2]; //24
};

class TreeVertex
{
public:
    glm::vec2 pos; //8
    glm::vec3 center; //20
    GLubyte lr, lg, lb, size; //24
    GLubyte tr, tg, tb, ltex; //28
};

//No idea how this works. Something to do with prime numbers, but returns # between -1 and 1
inline double PseudoRand(int x, int z)
{
     int n= (x & 0xFFFF) + ((z & 0x7FFF) << 16);
     n=(n<<13)^n;
     int nn=(n*(n*n*60493+z*19990303)+x*1376312589)&0x7fffffff;
     return 1.0-((double)nn/1073741824.0);
}


inline double PseudoRand(int n)
{
    n = (n << 13) ^ n;
    int nn = (n*(n*n * 60493 + n * 19990303) + n * 1376312589) & 0x7fffffff;
    return 1.0 - ((double)nn / 1073741824.0);
}

