#include <ics46/factory/DynamicFactory.hpp>
#include <cmath>
#include <iostream>
#include "HericMazeGenerator.hpp"
#include "MazeException.hpp"


// ICS46_DYNAMIC_FACTORY_REGISTER(MazeGenerator, HericMazeGenerator, "Heric's Algorithm (Required)")
ICS46_DYNAMIC_FACTORY_REGISTER(MazeGenerator, HericMazeGenerator, "Heric's Algorithm (Required)")


void HericMazeGenerator::generateMaze(Maze& maze)
{
    maze.removeAllWalls();
    // add all walls to the map
    maze.addAllWalls();
    // initialize the visitedList
    std::size_t width = maze.getWidth();
    std::size_t height = maze.getHeight();
    this->visitedList = std::vector<std::vector<bool>>(height, std::vector<bool>(width, false));
    // initialize the random engine
    this->rEngine = std::default_random_engine{this->rDevice()};
    // call the MazeDFGeneratorR function, starting at (0,0)
    MazeDFGeneratorR(maze, {0,0});

    
}

void HericMazeGenerator::MazeDFGeneratorR(Maze& maze, Coordinate cell)
{
    this->addVisited(cell);
    std::vector<Coordinate> newCells = this->getPossibleAdjacentCells(cell);
    // Coordinate newCell = 
    // 1. base case, if no adjacent random cell found (first == -1), 
    if (newCells.size() == 0)
    {
        return;
    } 
    else 
    // 2. recursion call
    {
        while(true){
            std::vector<Coordinate> newCells = this->getPossibleAdjacentCells(cell);
            if (newCells.size() == 0){
                return;
            }

            std::uniform_int_distribution<int> dist{0, static_cast<int>(newCells.size()-1)};
            std::size_t randomIndex = dist(this->rEngine);
            Coordinate newCell = newCells.at(randomIndex);
            // if (!this->isVisited(newCell)){
            Direction direction = this->getDirection(cell, newCell);
            maze.removeWall(cell.first, cell.second, direction);
            

            // call recursively on newCell
            MazeDFGeneratorR(maze, newCell);
            
            
        }
    }
    
}

bool HericMazeGenerator::isVisited(Coordinate cell)
{
    // std::cout << "visitedList"
    return this->visitedList.at(cell.second).at(cell.first);
}

void HericMazeGenerator::addVisited(Coordinate cell)
{   
    this->visitedList.at(cell.second).at(cell.first) = true;
}


std::vector<HericMazeGenerator::Coordinate> HericMazeGenerator::getPossibleAdjacentCells(Coordinate cell)
{
    long x1 = cell.first;
    long y1 = cell.second;
    std::vector<Coordinate> choices{};
    std::cout << "the current cell is " << x1 << ", " << y1 << std::endl;
    
    // getting all the unvisited 
    if ((x1 - 1) >= 0 && !this->isVisited(Coordinate{x1 - 1, y1}) )
    {
        choices.push_back(Coordinate{x1 - 1, y1});
    } 
    if ((x1 + 1) < this->getWidth() && !this->isVisited(Coordinate{x1 + 1, y1}) )
    {
        choices.push_back(Coordinate{x1 + 1, y1});
    }
    if ((y1 - 1) >= 0 && !this->isVisited(Coordinate{x1, y1 - 1}))
    {
        choices.push_back(Coordinate{x1, y1 - 1});
    }
    if ((y1 + 1) < this->getHeight() && !this->isVisited(Coordinate{x1, y1 + 1}) )
    {
        choices.push_back(Coordinate{x1, y1 + 1});
    }
    std::cout << "Size of choices: "<< choices.size() << std::endl;
    
       
    return choices;
    
    
}

Direction HericMazeGenerator::getDirection(Coordinate cell1, Coordinate cell2)
{
    long x1 = cell1.first;
    long y1 = cell1.second;
    long x2 = cell2.first;
    long y2 = cell2.second;

    // check if the two cells are adjacent, if not throw MazeException
    if (std::abs(static_cast<int>(x1-x2)) > 1 || std::abs(static_cast<int>(y1-y2)) > 1)
    {
        throw MazeException{"The given two cells are not adjacent, please check the validity of the algorithm."};
    } else if (std::abs(static_cast<int>(x1-x2)) == 1 && std::abs(static_cast<int>(y1-y2)) == 1)
    {
        throw MazeException{"The given two cells are not adjacent but on the diagonal line, please check the validity of the algorithm."};
    } else if (std::abs(static_cast<int>(x1-x2)) == 0 && std::abs(static_cast<int>(y1-y2)) == 0)
    {
        throw MazeException{"The given two cells are not adjacent but the same, please check the validity of the algorithm."};
    }

    // now check the direction, with the higher y to the lower row, the higher x to the right
    if (x2-x1 == 0 && y2-y1 == -1) // up direction
    {
        return Direction::up;

    } else if (x2-x1 == 0 && y2-y1 == 1) // down
    {
        return Direction::down;

    } else if (x2-x1 == 1 && y2-y1 == 0) // right
    {
        return Direction::right;
    } else if (x2-x1 == -1 && y2-y1 == 0) // left
    {
        return Direction::left;
    } else // unknown condition, throws for debug
    {
        throw MazeException{"The given two cells triggered the unknown conditional case, please check the vadility of function: getDirection()"};
    }
}

std::size_t HericMazeGenerator::getHeight()
{
    return this->visitedList.size();
}

std::size_t HericMazeGenerator::getWidth()
{
    return this->visitedList.at(0).size();
}