/*
 * Dungeon.h
 *
 *  Created on: 12/apr/2012
 *  Updated on: 13/mar/2018
 *  Author: bertini
 *
 *  Original dungeon building Java code from:
 *  http://roguebasin.roguelikedevelopment.org/index.php?title=Dungeon-Building_Algorithm
 */

#ifndef DUNGEON_H_
#define DUNGEON_H_

#include <iostream>
#include "GameFileException.h"

enum class TileType {
    Unused = 0, DirtWall, DirtFloor, StoneWall, Corridor, Door, UpStairs, DownStairs, Chest
};

static const char* const MAP_FILE_SIGNATURE = "DungeonMap";

static std::string TileTypeToTileString(const TileType& tile) {
    switch (tile) {
        case TileType::Unused:
            return " ";
        case TileType::DirtWall:
            return "+";
        case TileType::DirtFloor:
            return ".";
        case TileType::StoneWall:
            return "%";
        case TileType::Corridor:
            return "#";
        case TileType::Door:
            return "D";
        case TileType::UpStairs:
            return "<";
        case TileType::DownStairs:
            return ">";
        case TileType::Chest:
            return "*";
        default:
            return "";
    };
}

static TileType TileStringToTileType(const char& tile) {
    switch (tile) {
        case ' ':
            return TileType::Unused;
        case '+':
            return TileType::DirtWall;
        case '.':
            return TileType::DirtFloor;
        case '%':
            return TileType::StoneWall;
        case '#':
            return TileType::Corridor;
        case 'D':
            return TileType::Door;
        case '<':
            return TileType::UpStairs;
        case '>':
            return TileType::DownStairs;
        case '*':
            return TileType::Chest;
        default:
            return TileType::Unused;
    };
}

class Dungeon {
public:
    Dungeon();
    ~Dungeon();

    bool createDungeon(int inx, int iny, int inobj = 10);
    TileType getCell(int x, int y) const;

    int getXsize() const;
    void setXsize(int xsize);

    int getYsize() const;
    void setYsize(int ysize);

    // Write the member variables to stream objects
    void saveToFile(std::string fileName) throw(GameFileException);
    // Read data from stream object and fill it in member variables
    void loadFromFile(std::string fileName) throw(GameFileException, std::runtime_error, std::out_of_range) ;

private:
    bool makeCorridor(int x, int y, int lenght, int direction);
    bool makeRoom(int x, int y, int xlength, int ylength, int direction);
    int getRand(int min, int max);
    void setCell(int x, int y, TileType tile);

    TileType* dungeonMap;
    //size of the map
    int xsize, ysize;

    //max size of the map
    const int xmax; //80 columns
    const int ymax; //25 rows

    //number of "objects" to generate on the map
    int objects;

    //the old seed from the RNG is saved in this one
    long oldseed;
    //define the chance to generate either a room or a corridor on the map
    //BTW, rooms are 1st priority so actually it's enough to just define the chance
    //of generating a room
    const int chanceRoom;
    const int chanceCorridor;

    const int minRoomWidth;
    const int minRoomHeight;
};


#endif // DUNGEON_H_
