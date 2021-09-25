#include <ics46/factory/DynamicFactory.hpp>
#include <vector>
#include "HericMazeSolver.hpp"
#include "MazeException.hpp"
#include "MazeSolutionException.hpp"

ICS46_DYNAMIC_FACTORY_REGISTER(MazeSolver, HericMazeSolver, "Heric's Maze Solver (Required)")

void HericMazeSolver::solveMaze(const Maze& maze, MazeSolution& mazeSolution)
{
    mazeSolution.restart();
    std::size_t width = maze.getWidth();
    std::size_t height = maze.getHeight();
    this->visitedList = std::vector<std::vector<bool>>(height, std::vector<bool>(width, false));
    MazeDFSolverR(maze, mazeSolution, {mazeSolution.getStartingCell().second, mazeSolution.getStartingCell().first});
}

bool HericMazeSolver::allVisited()
{
    for (std::size_t i = 0; i < this->visitedList.size(); i ++)
    {
        for (std::size_t j = 0; j < this->visitedList.at(0).size(); j++)
        {
            if (this->visitedList.at(i).at(j) == false)
                return false;
            
        }
    }
    return true;
}

void HericMazeSolver::MazeDFSolverR(const Maze& maze, MazeSolution& mazeSolution, const Coordinate &cell)
{
    this->addVisited(cell);
    // base case: if is complete
    if (mazeSolution.isComplete() )
    {
        return;
    }
    else
    {
        // while(true)
        // {
            std::vector<Coordinate> newCells = this->getPossibleAdjacentCells(maze, cell);
            // if (newCells.size() == 0 || mazeSolution.isComplete())
            // {
            //     if (mazeSolution.isComplete())
            //     {
            //         // completed
            //         return;
            //     } else
            //     {
            //         // not complete but deadend
                    
            //         return;
            //     }
            // }
            for (auto newCell: newCells){
                
                // calculate the direction
                Direction direction = getDirection(cell, newCell);
                // add the step
                mazeSolution.extend(direction);
                // recursive call
                MazeDFSolverR(maze, mazeSolution, newCell);
                if (mazeSolution.isComplete())
                {
                    return;
                }
                mazeSolution.backUp();
            }
        // }
    }
    this->visitedList.at(cell.second).at(cell.first) = false;
}

std::vector<HericMazeSolver::Coordinate> HericMazeSolver::getPossibleAdjacentCells(const Maze& maze, const Coordinate &cell)
{
    long x1 = cell.first;
    long y1 = cell.second;
    std::vector<Coordinate> choices{};
    
    // getting all the unvisited 
    if ((x1 - 1) >= 0 && !this->isVisited(Coordinate{x1 - 1, y1}) && !maze.wallExists(x1, y1, Direction::left))
    {
        choices.push_back(Coordinate{x1 - 1, y1});
    } 
    if ((x1 + 1) < maze.getWidth() && !this->isVisited(Coordinate{x1 + 1, y1}) && !maze.wallExists(x1, y1, Direction::right))
    {
        choices.push_back(Coordinate{x1 + 1, y1});
    }
    if ((y1 - 1) >= 0 && !this->isVisited(Coordinate{x1, y1 - 1}) && !maze.wallExists(x1, y1, Direction::up))
    {
        choices.push_back(Coordinate{x1, y1 - 1});
    }
    if ((y1 + 1) < maze.getHeight() && !this->isVisited(Coordinate{x1, y1 + 1}) && !maze.wallExists(x1, y1, Direction::down))
    {
        choices.push_back(Coordinate{x1, y1 + 1});
    }    
       
    return choices;
    
    
}

Direction HericMazeSolver::getDirection(Coordinate cell1, Coordinate cell2)
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

bool HericMazeSolver::isVisited(Coordinate cell)
{
    return this->visitedList[cell.second][cell.first];
}

void HericMazeSolver::addVisited(Coordinate cell)
{   
    this->visitedList[cell.second][cell.first] = true;
}

