#ifndef HERICMAZEGENERATOR_HPP
#define HERICMAZEGENERATOR_HPP

#include <vector>
#include <random>
#include <utility>
#include "MazeGenerator.hpp"
#include "Direction.hpp"
#include "Maze.hpp"

class HericMazeGenerator : public MazeGenerator
{
public:
    virtual void generateMaze(Maze& maze) override;
private:
    using Coordinate = std::pair<std::size_t, std::size_t>;
    void MazeDFGeneratorR(Maze& maze, Coordinate cell);
    bool isVisited(Coordinate cell);
    void addVisited(Coordinate cell);
    std::vector<Coordinate> getPossibleAdjacentCells(Coordinate cell); // returns first:x, second:y, if no adjacent, first = -1, second = -1
    Direction getDirection(Coordinate cell1, Coordinate cell2);
    std::size_t getHeight();
    std::size_t getWidth();

    std::vector<std::vector<bool>> visitedList;
    std::random_device rDevice;
    std::default_random_engine rEngine;
};

#endif