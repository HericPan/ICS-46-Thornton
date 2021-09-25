#include <ics46/factory/DynamicFactory.hpp>

#include "MazeSolverDFS.hpp"
#include <iostream>

ICS46_DYNAMIC_FACTORY_REGISTER(MazeSolver, MazeSolverDFS,
                               "My DFS Maze Solver (Required)");

void MazeSolverDFS::solveMaze(
    const Maze& maze, MazeSolution& mazeSolution) {
    VisitedType visited(
        maze.getHeight(),
        std::vector<bool>(maze.getWidth(), false));
    int x = mazeSolution.getStartingCell().second;
    int y = mazeSolution.getStartingCell().first;

    solveMazeDFS(maze, mazeSolution, visited, x, y);
}

void MazeSolverDFS::solveMazeDFS(const Maze& maze, MazeSolution& mazeSolution, VisitedType& visited, int x, int y) {
    // complete search
    if (mazeSolution.isComplete()) {
        return;
    }

    const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    const Direction D[4] = {Direction::down, Direction::up, Direction::right, Direction::left};
    int height = maze.getHeight();
    int width = maze.getWidth();
    visited[x][y] = true;

    // search the current cell adjacent cells that have not yet been visited
    // and without wall.
    for (int i = 0; i < 4; ++i) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        if (nx >= 0 && nx < height &&
            ny >= 0 && ny < width &&
            !visited[nx][ny] &&
            !maze.wallExists(y, x, D[i])) {
            // extend the from current cell to solution.
            mazeSolution.extend(D[i]);
            // Recursively call, make the adjacent cell becoming the current cell.
            solveMazeDFS(maze, mazeSolution, visited, nx, ny);
            // if reaching the end cell, then return.
            if (mazeSolution.isComplete()) {
                return;
            }
            // remove the extend cell from solution.
            mazeSolution.backUp();
        }
    }
    visited[x][y] = false;
}
