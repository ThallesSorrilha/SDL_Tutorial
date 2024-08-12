#pragma once

#include <map>
#include <string>

#include "../../libraries/TinyXML2/tinyxml2.h"

#include "GameMap.h"
#include "TileLayer.h"
#include "TileSet.h"

class MapParser
{
private:
    static inline std::map<std::string, GameMap *> mapDict;

    static bool parse(std::string id, std::string source);
    static TileSet parseTileSet(tinyxml2::XMLElement *xmlTileset);
    static TileLayer *parseTileLayer(tinyxml2::XMLElement *xmlLayer, TileSetList tileSets, int tileSize, int rowCount, int colCount);

public:
    static bool load(std::string id, const std::string &tmxFilePath);
    static void clean();

    static GameMap *getMap(std::string id, float x = 0, float y = 0);
};