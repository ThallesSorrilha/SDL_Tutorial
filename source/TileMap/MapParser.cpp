#include <sstream>
#include <iostream>

#include "MapParser.h"

GameMap *MapParser::getMap(std::string id, float x, float y)
{
    mapDict[id]->setMapPosition(x, y);
    return mapDict[id];
}

bool MapParser::load(std::string id, const std::string &tmxFilePath)
{
    return parse(id, tmxFilePath);
}

void MapParser::clean()
{
    for (auto &[_, mapPtr] : mapDict)
    {
        mapPtr = nullptr; // Define o ponteiro armazenado no mapa como nullptr
    }

    mapDict.clear(); // Limpa o mapa
}

bool MapParser::parse(std::string id, std::string source)
{
    tinyxml2::XMLDocument xml;
    xml.LoadFile(source.c_str());

    if (xml.Error())
    {
        std::cout << "Failure to load the XML" << source << '\n';
        return false;
    }

    tinyxml2::XMLElement *root = xml.RootElement();
    int rowCount = 0;
    int columnCount = 0;
    int tileSize = 0;

    rowCount = root->IntAttribute("height", rowCount);
    columnCount = root->IntAttribute("width", columnCount);
    tileSize = root->IntAttribute("tilewidth", tileSize);

    // Parse Tile sets
    TileSetList tilesets;
    for (tinyxml2::XMLElement *e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("tileset"))
        {
            tilesets.push_back(parseTileSet(e));
        }
    }

    GameMap *gameMap = new GameMap();
    gameMap->setMapDimension(columnCount, rowCount);

    for (tinyxml2::XMLElement *e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("layer"))
        {
            TileLayer *tilelayer = parseTileLayer(e, tilesets, tileSize, rowCount, columnCount);
            gameMap->getLayers().push_back(tilelayer);
        }
    }

    mapDict[id] = gameMap;

    return true;
}

TileSet MapParser::parseTileSet(tinyxml2::XMLElement *xmlTileset)
{
    TileSet tileSet;
    // tileset.Name = xmlTileset->Attribute("name");
    tileSet.firstID = xmlTileset->IntAttribute("firstgid", tileSet.firstID);

    tileSet.tileCount = xmlTileset->IntAttribute("tilecount", tileSet.tileCount);
    tileSet.lastID = (tileSet.firstID + tileSet.tileCount) - 1;

    tileSet.columnCount = xmlTileset->IntAttribute("columns", tileSet.columnCount);
    tileSet.rowCount = tileSet.tileCount / tileSet.columnCount;
    tileSet.tileSize = xmlTileset->IntAttribute("tilewidth", tileSet.tileSize);

    tinyxml2::XMLElement *image = xmlTileset->FirstChildElement();
    tileSet.source = image->Attribute("source");
    return tileSet;
}

TileLayer *MapParser::parseTileLayer(tinyxml2::XMLElement *xmlLayer, TileSetList tileSets, int tileSize, int rowCount, int columnCount)
{
    tinyxml2::XMLElement *data;
    for (tinyxml2::XMLElement *e = xmlLayer->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("data"))
        {
            data = e;
            break;
        }
    }

    std::string matrix(data->GetText());
    std::istringstream iss(matrix);
    std::string id;

    TileMap tileMap(rowCount, std::vector<int>(columnCount, 0));

    for (int row = 0; row < rowCount; row++)
    {
        for (int col = 0; col < columnCount; col++)
        {
            getline(iss, id, ',');
            std::stringstream convertor(id);
            convertor >> tileMap[row][col];

            if (!iss.good())
            {
                break;
            }
        }
    }

    return (new TileLayer(tileSize, rowCount, columnCount, tileMap, tileSets));
}