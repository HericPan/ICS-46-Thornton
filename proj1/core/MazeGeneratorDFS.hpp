#ifndef MAZE_GENERATOR_DFS_H_
#define MAZE_GENERATOR_DFS_H_ 

#include "MazeGenerator.hpp"
#include "Maze.hpp"

#include <random>
#include <vector>

class MazeGeneratorDFS : public MazeGenerator {
public:
    virtual void generateMaze(Maze& maze);
private:
    std::random_device rd;
    using VisitedType = std::vector<std::vector<bool>>;
    void dfsGenMaze(VisitedType& visited, Maze& maze, int x, int y);
};
#endif /* ifndef MAZE_GENERATOR_DFS_H_ */
