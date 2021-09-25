#include "MazeSolver.hpp"
#include "MazeSolution.hpp"
#include "Maze.hpp"

class MazeSolverDFS : public MazeSolver {
public:
    virtual void solveMaze(
        const Maze& maze, MazeSolution& mazeSolution);
private:
    using VisitedType = std::vector<std::vector<bool>>;
    void solveMazeDFS(const Maze& maze, MazeSolution& mazeSolution, VisitedType& visited, int x, int y);
};
