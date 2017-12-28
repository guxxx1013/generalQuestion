//
//  mazequeue.cpp
//  Homework2
//
//  Created by Quanju Gu on 7/11/16.
//  Copyright © 2016 Jerry Gu. All rights reserved.
//

#include <string>
#include <iostream>
#include <queue>
using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const
    {
        return m_r;
    }
    int c() const
    {
        return m_c;
    }
private:
    int m_r;
    int m_c;
};

 bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    queue<Coord> coordQueue;
    coordQueue.push(Coord(sr, sc));

    //special case for start or end in 'X' which is impossible
    if(maze[sr][sc] == 'X' || maze[er][ec] == 'X')
        return false;
    if(maze[sr][sc] == '@' || maze[er][ec] == '@')
        return false;

    maze[sr][sc] = '1';//mark the point which has already search label "1"
    while (!coordQueue.empty())
    {
        int cr = coordQueue.front().r();
        int cc = coordQueue.front().c();
        //cerr << cr << cc << endl;
        coordQueue.pop();
        if (cr == er && cc == ec)
            return true;
        if (maze[cr - 1][cc] == '.')
        {
            //cerr << "North" << endl;
            coordQueue.push(Coord(cr - 1, cc));
            maze[cr - 1][cc] = '1';
            //cout << (cr - 1) << " " << cc << endl;
        }
        if (maze[cr][cc + 1] == '.')
        {
            //cerr << "East" << endl;
            coordQueue.push(Coord(cr, cc + 1));
            maze[cr][cc + 1] = '1';
            //cout << cr << " "<<(cc + 1) << endl;
        }
        if (maze[cr + 1][cc] == '.')
        {
            //cerr << "South" << endl;
            coordQueue.push(Coord(cr + 1, cc));
            maze[cr + 1][cc] = '1';
            //cout << (cr + 1) << " " << cc << endl;
        }
        if (maze[cr][cc - 1] == '.')
        {
            //cerr << "West" << endl;
            coordQueue.push(Coord(cr, cc - 1));
            maze[cr][cc - 1] = '1';
            //cout << cr << " " << (cc -1) << endl;
        }
    }
    return false;

}

/*
/////test case/////////////
int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X.......@X",
        "XX@X@@.XXX",
        "X..X.X...X",
        "X..X...@.X",
        "X....XXX.X",
        "X@X....XXX",
        "X..XX.XX.X",
        "X...X....X",
        "XXXXXXXXXX"
    };

    if (pathExists(maze, 10,10, 6,4, 4,4))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}
*/
