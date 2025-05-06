/*
 * Dungeon.cpp
 *
 *  Created on: 12/apr/2012
 *  Updated on: 13/mar/2018
 *  Author: bertini
 *
 *  Original dungeon building Java code from:
 *  http://roguebasin.roguelikedevelopment.org/index.php?title=Dungeon-Building_Algorithm
 */

#include "Dungeon.h"
#include <iostream>

//#define VERBOSE

using namespace std;

// class constants have to be set in initializer list
Dungeon::Dungeon() :
        xmax(80), ymax(25), oldseed(0), chanceRoom(
        75), chanceCorridor(25), minRoomWidth(5), minRoomHeight(5) {
    dungeonMap = 0;
}

Dungeon::~Dungeon() {
    if (dungeonMap)
        delete[] dungeonMap;
}

void Dungeon::setCell(int x, int y, TileType tile) {
    dungeonMap[x + xsize * y] = tile;
}

TileType Dungeon::getCell(int x, int y) const {
    return dungeonMap[x + xsize * y];
}

// compute random number between min and max
int Dungeon::getRand(int min, int max) {
    //the seed is based on current time and the old, already used, seed
    long seed = time(NULL) + oldseed;
    oldseed = seed;

    srand(seed);
    int n = max - min + 1;
    int i = rand() % n; // 0 < i < n
    if (i < 0)
        i = -i;
    return min + i;
}

bool Dungeon::makeCorridor(int x, int y, int lenght, int direction) {
    //define the dimensions of the corridor (er.. only the width and height..)
    int len = getRand(2, lenght);
    TileType floor = TileType::Corridor;
    int dir = 0;
    if (direction > 0 && direction < 4)
        dir = direction;

    int xtemp = 0;
    int ytemp = 0;

    switch (dir) {
        case 0:
            //north
            //check if there's enough space for the corridor
            //start with checking it's not out of the boundaries
            if (x < 0 || x > xsize)
                return false;
            else
                xtemp = x;

            //same thing here, to make sure it's not out of the boundaries
            for (ytemp = y; ytemp > (y - len); ytemp--) {
                if (ytemp < 0 || ytemp > ysize)
                    return false; // out of boundaries
                if (getCell(xtemp, ytemp) != TileType::Unused)
                    return false;
            }

            //if we're still here, let's start building
            for (ytemp = y; ytemp > (y - len); ytemp--) {
                setCell(xtemp, ytemp, floor);
            }
            break;
        case 1:
            //east
            if (y < 0 || y > ysize)
                return false;
            else
                ytemp = y;

            for (xtemp = x; xtemp < (x + len); xtemp++) {
                if (xtemp < 0 || xtemp > xsize)
                    return false;
                if (getCell(xtemp, ytemp) != TileType::Unused)
                    return false;
            }

            for (xtemp = x; xtemp < (x + len); xtemp++) {
                setCell(xtemp, ytemp, floor);
            }
            break;
        case 2:
            //south
            if (x < 0 || x > xsize)
                return false;
            else
                xtemp = x;

            for (ytemp = y; ytemp < (y + len); ytemp++) {
                if (ytemp < 0 || ytemp > ysize)
                    return false;
                if (getCell(xtemp, ytemp) != TileType::Unused)
                    return false;
            }

            for (ytemp = y; ytemp < (y + len); ytemp++) {
                setCell(xtemp, ytemp, floor);
            }
            break;
        case 3:
            //west
            if (ytemp < 0 || ytemp > ysize)
                return false;
            else
                ytemp = y;

            for (xtemp = x; xtemp > (x - len); xtemp--) {
                if (xtemp < 0 || xtemp > xsize)
                    return false;
                if (getCell(xtemp, ytemp) != TileType::Unused)
                    return false;
            }

            for (xtemp = x; xtemp > (x - len); xtemp--) {
                setCell(xtemp, ytemp, floor);
            }
            break;
    }

    // Successful build
    return true;
}

bool Dungeon::makeRoom(int x, int y, int xlength, int ylength, int direction) {
    //define the dimensions of the room, it should be at least minRoomWidth x minRoomHeight tiles (i.e. 4x4 -> 2x2 for walking on, the rest is walls)
    int xlen = getRand(minRoomWidth, xlength);
    int ylen = getRand(minRoomHeight, ylength);
    //the tile type it's going to be filled with
    TileType floor = TileType::DirtFloor;
    TileType wall = TileType::DirtWall;
    //choose the way it's pointing at
    int dir = 0;
    if (direction > 0 && direction < 4)
        dir = direction;

    switch (dir) {
        case 0:
            //north
            //Check if there's enough space left for it
            for (int ytemp = y; ytemp > (y - ylen); ytemp--) {
                if (ytemp < 0 || ytemp > ysize)
                    return false;
                for (int xtemp = (x - xlen / 2); xtemp < (x + (xlen + 1) / 2);
                     xtemp++) {
                    if (xtemp < 0 || xtemp > xsize)
                        return false;
                    if (getCell(xtemp, ytemp) != TileType::Unused)
                        return false; //no space left...
                }
            }

            //we're still here, build
            for (int ytemp = y; ytemp > (y - ylen); ytemp--) {
                for (int xtemp = (x - xlen / 2); xtemp < (x + (xlen + 1) / 2);
                     xtemp++) {
                    //start with the walls
                    if (xtemp == (x - xlen / 2))
                        setCell(xtemp, ytemp, wall);
                    else if (xtemp == (x + (xlen - 1) / 2))
                        setCell(xtemp, ytemp, wall);
                    else if (ytemp == y)
                        setCell(xtemp, ytemp, wall);
                    else if (ytemp == (y - ylen + 1))
                        setCell(xtemp, ytemp, wall);
                        //and then fill with the floor
                    else
                        setCell(xtemp, ytemp, floor);
                }
            }
            break;
        case 1:
            //east
            for (int ytemp = (y - ylen / 2); ytemp < (y + (ylen + 1) / 2);
                 ytemp++) {
                if (ytemp < 0 || ytemp > ysize)
                    return false;
                for (int xtemp = x; xtemp < (x + xlen); xtemp++) {
                    if (xtemp < 0 || xtemp > xsize)
                        return false;
                    if (getCell(xtemp, ytemp) != TileType::Unused)
                        return false;
                }
            }

            for (int ytemp = (y - ylen / 2); ytemp < (y + (ylen + 1) / 2);
                 ytemp++) {
                for (int xtemp = x; xtemp < (x + xlen); xtemp++) {

                    if (xtemp == x)
                        setCell(xtemp, ytemp, wall);
                    else if (xtemp == (x + xlen - 1))
                        setCell(xtemp, ytemp, wall);
                    else if (ytemp == (y - ylen / 2))
                        setCell(xtemp, ytemp, wall);
                    else if (ytemp == (y + (ylen - 1) / 2))
                        setCell(xtemp, ytemp, wall);
                    else
                        setCell(xtemp, ytemp, floor);
                }
            }
            break;
        case 2:
            //south
            for (int ytemp = y; ytemp < (y + ylen); ytemp++) {
                if (ytemp < 0 || ytemp > ysize)
                    return false;
                for (int xtemp = (x - xlen / 2); xtemp < (x + (xlen + 1) / 2);
                     xtemp++) {
                    if (xtemp < 0 || xtemp > xsize)
                        return false;
                    if (getCell(xtemp, ytemp) != TileType::Unused)
                        return false;
                }
            }

            for (int ytemp = y; ytemp < (y + ylen); ytemp++) {
                for (int xtemp = (x - xlen / 2); xtemp < (x + (xlen + 1) / 2);
                     xtemp++) {

                    if (xtemp == (x - xlen / 2))
                        setCell(xtemp, ytemp, wall);
                    else if (xtemp == (x + (xlen - 1) / 2))
                        setCell(xtemp, ytemp, wall);
                    else if (ytemp == y)
                        setCell(xtemp, ytemp, wall);
                    else if (ytemp == (y + ylen - 1))
                        setCell(xtemp, ytemp, wall);
                    else
                        setCell(xtemp, ytemp, floor);
                }
            }
            break;
        case 3:
            //west
            for (int ytemp = (y - ylen / 2); ytemp < (y + (ylen + 1) / 2);
                 ytemp++) {
                if (ytemp < 0 || ytemp > ysize)
                    return false;
                for (int xtemp = x; xtemp > (x - xlen); xtemp--) {
                    if (xtemp < 0 || xtemp > xsize)
                        return false;
                    if (getCell(xtemp, ytemp) != TileType::Unused)
                        return false;
                }
            }

            for (int ytemp = (y - ylen / 2); ytemp < (y + (ylen + 1) / 2);
                 ytemp++) {
                for (int xtemp = x; xtemp > (x - xlen); xtemp--) {

                    if (xtemp == x)
                        setCell(xtemp, ytemp, wall);
                    else if (xtemp == (x - xlen + 1))
                        setCell(xtemp, ytemp, wall);
                    else if (ytemp == (y - ylen / 2))
                        setCell(xtemp, ytemp, wall);
                    else if (ytemp == (y + (ylen - 1) / 2))
                        setCell(xtemp, ytemp, wall);
                    else
                        setCell(xtemp, ytemp, floor);
                }
            }
            break;
    }

    // successful build
    return true;
}


// Generation of the whole map
bool Dungeon::createDungeon(int inx, int iny, int inobj) {
    if (inobj < 1)
        objects = 10;
    else
        objects = inobj;

    //adjust the size of the map, if it's smaller or bigger than the limits
    if (inx < 3)
        xsize = 3;
    else if (inx > xmax)
        xsize = xmax;
    else
        xsize = inx;

    if (iny < 3)
        ysize = 3;
    else if (iny > ymax)
        ysize = ymax;
    else
        ysize = iny;

    //redefine the map var, so it's adjusted to our new map size
    dungeonMap = new TileType[xsize * ysize];

    //start with making the "standard stuff" on the map
    for (int y = 0; y < ysize; y++) {
        for (int x = 0; x < xsize; x++) {
            //ie, making the borders of unwalkable walls
            if (y == 0)
                setCell(x, y, TileType::StoneWall);
            else if (y == ysize - 1)
                setCell(x, y, TileType::StoneWall);
            else if (x == 0)
                setCell(x, y, TileType::StoneWall);
            else if (x == xsize - 1)
                setCell(x, y, TileType::StoneWall);

                //and fill the rest with dirt
            else
                setCell(x, y, TileType::Unused);
        }
    }

    /*******************************************************************************
     And now the code of the random-map-generation-algorithm begins!
     *******************************************************************************/

    //start with making a room in the middle, which we can start building upon
    makeRoom(xsize / 2, ysize / 2, 10, 8, getRand(0, 3)); //getrand saken f????r att slumpa fram riktning p?? rummet

    //keep count of the number of "objects" we've made
    int currentFeatures = 1; //+1 for the first room we just made

    //then we start the main loop
    for (int countingTries = 0; countingTries < 1000; countingTries++) {
        //check if we've reached our quota
        if (currentFeatures == objects) {
            break;
        }

        //start with a random wall
        int newx = 0;
        int xmod = 0;
        int newy = 0;
        int ymod = 0;
        int validTile = -1;
        //1000 chances to find a suitable object (room or corridor)..
        //(yea, i know it's kinda ugly with a for-loop... -_-')
        for (int testing = 0; testing < 1000; testing++) {
            newx = getRand(1, xsize - 1);
            newy = getRand(1, ysize - 1);
            validTile = -1;
            //cout<<"tempx: " << newx << "\ttempy: " << newy<<endl;
            if (getCell(newx, newy) == TileType::DirtWall
                || getCell(newx, newy) == TileType::Corridor) {
                //check if we can reach the place
                if (getCell(newx, newy + 1) == TileType::DirtFloor
                    || getCell(newx, newy + 1) == TileType::Corridor) {
                    validTile = 0; //
                    xmod = 0;
                    ymod = -1;
                } else if (getCell(newx - 1, newy) == TileType::DirtFloor
                           || getCell(newx - 1, newy) == TileType::Corridor) {
                    validTile = 1; //
                    xmod = +1;
                    ymod = 0;
                } else if (getCell(newx, newy - 1) == TileType::DirtFloor
                           || getCell(newx, newy - 1) == TileType::Corridor) {
                    validTile = 2; //
                    xmod = 0;
                    ymod = +1;
                } else if (getCell(newx + 1, newy) == TileType::DirtFloor
                           || getCell(newx + 1, newy) == TileType::Corridor) {
                    validTile = 3; //
                    xmod = -1;
                    ymod = 0;
                }

                //check that we haven't got another door nearby, so we won't get a lot of openings besides
                //each other
                if (validTile > -1) {
                    if (getCell(newx, newy + 1) == TileType::Door) //north
                        validTile = -1;
                    else if (getCell(newx - 1, newy) == TileType::Door) //east
                        validTile = -1;
                    else if (getCell(newx, newy - 1) == TileType::Door) //south
                        validTile = -1;
                    else if (getCell(newx + 1, newy) == TileType::Door) //west
                        validTile = -1;
                }

                //if we can, jump out of the loop and continue with the rest
                if (validTile > -1)
                    break;
            }
        }
        if (validTile > -1) {
            //choose what to build now at our newly found place, and at what direction
            int feature = getRand(0, 100);
            if (feature <= chanceRoom) { //a new room
                if (makeRoom((newx + xmod), (newy + ymod), 8, 6, validTile)) {
                    currentFeatures++; //add to our quota

                    //then we mark the wall opening with a door
                    setCell(newx, newy, TileType::Door);

                    //clean up in front of the door so we can reach it
                    setCell((newx + xmod), (newy + ymod), TileType::DirtFloor);
                }
            } else if (feature >= chanceRoom) { //new corridor
                if (makeCorridor((newx + xmod), (newy + ymod), 6, validTile)) {
                    //same thing here, add to the quota and a door
                    currentFeatures++;

                    setCell(newx, newy, TileType::Door);
                }
            }
        }
    }

    /*******************************************************************************
     All done with the building, let's finish this one off
     *******************************************************************************/

    //sprinkle out the bonus stuff (stairs, chests etc.) over the map
    int newx = 0;
    int newy = 0;
    int ways = 0; //from how many directions we can reach the random spot from
    int state = 0; //the state the loop is in, start with the stairs
    while (state != 10) {
        for (int testing = 0; testing < 1000; testing++) {
            newx = getRand(1, xsize - 1);
            newy = getRand(1, ysize - 2); //cheap bugfix, pulls down newy to 0<y<24, from 0<y<25

            //cout<<"x: " << newx << "\ty: " << newy<<endl;
            ways = 4; //the lower the better

            //check if we can reach the spot
            if (getCell(newx, newy + 1) == TileType::DirtFloor
                || getCell(newx, newy + 1) == TileType::Corridor) {
                //north
                if (getCell(newx, newy + 1) != TileType::Door)
                    ways--;
            }
            if (getCell(newx - 1, newy) == TileType::DirtFloor
                || getCell(newx - 1, newy) == TileType::Corridor) {
                //east
                if (getCell(newx - 1, newy) != TileType::Door)
                    ways--;
            }
            if (getCell(newx, newy - 1) == TileType::DirtFloor
                || getCell(newx, newy - 1) == TileType::Corridor) {
                //south
                if (getCell(newx, newy - 1) != TileType::Door)
                    ways--;
            }
            if (getCell(newx + 1, newy) == TileType::DirtFloor
                || getCell(newx + 1, newy) == TileType::Corridor) {
                //west
                if (getCell(newx + 1, newy) != TileType::Door)
                    ways--;
            }

            if (state == 0) {
                if (ways == 0) {
                    //we're in state 0, let's place a "upstairs" thing
                    setCell(newx, newy, TileType::UpStairs);
                    state = 1;
                    break;
                }
            } else if (state == 1) {
                if (ways == 0) {
                    //state 1, place a "downstairs"
                    setCell(newx, newy, TileType::DownStairs);
                    state = 10;
                    break;
                }
            }
        }
    }

#ifdef VERBOSE
    //all done with the map generation, tell the user about it and finish
    cout << "# of objects made: \t" << currentFeatures << endl;
#endif

    return true;
}

int Dungeon::getXsize() const {
    return xsize;
}

void Dungeon::setXsize(int xsize) {
    Dungeon::xsize = xsize;
}

int Dungeon::getYsize() const {
    return ysize;
}

void Dungeon::setYsize(int ysize) {
    Dungeon::ysize = ysize;
}

