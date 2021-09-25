#ifndef HERICMAZESOLVER_HPP
#define HERICMAZESOLVER_HPP
#include <utility>
#include "Maze.hpp"
#include "MazeSolver.hpp"
#include "MazeSolution.hpp"
#include "Direction.hpp"

class HericMazeSolver : public MazeSolver
{
public:
    void solveMaze(const Maze& maze, MazeSolution& mazeSolution) override;

private:
    using Coordinate = std::pair<long, long>;
    void MazeDFSolverR(const Maze& maze, MazeSolution& mazeSolution, const Coordinate &cell);
    Direction getDirection(Coordinate cell1, Coordinate cell2);
    std::vector<Coordinate> getPossibleAdjacentCells(const Maze& maze, const Coordinate &cell);
    bool isVisited(Coordinate cell);
    void addVisited(Coordinate cell);
    bool allVisited();

    std::vector<std::vector<bool>> visitedList;
};

#endif