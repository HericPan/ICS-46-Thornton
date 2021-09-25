#include "MazeGeneratorDFS.hpp"

#include <ics46/factory/DynamicFactory.hpp>
#include <random>
#include <vector>
#include <iostream>

ICS46_DYNAMIC_FACTORY_REGISTER(MazeGenerator, MazeGeneratorDFS, "My DFS Maze Generator (Required)")

void MazeGeneratorDFS::generateMaze(Maze& maze) {
    maze.addAllWalls();
    VisitedType visited(
        maze.getHeight(),
        std::vector<bool>(maze.getWidth(), false));
    // std::cout << maze.getWidth() << std::endl;
    // std::cout << maze.getHeight() << std::endl;
    
    std::default_random_engine reng(std::random_device);
    dfsGenMaze(visited, maze, 0, 0);
}

void MazeGeneratorDFS::dfsGenMaze(VisitedType& visited, Maze& maze, int x, int y) {
    // Mark the current cell as visited
    visited[x][y] = true;

    // Four the direction.
    const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    const Direction D[4] = {Direction::down, Direction::up, Direction::right, Direction::left};

    int height = maze.getHeight();
    int width = maze.getWidth();
    while (true) {
        // search the current cell adjacent cells that have not yet been visited
        std::vector<int> choices;
        for (int i = 0; i < 4; ++i) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx >= 0 && nx < height && ny >= 0 && ny < width &&
                    !visited[nx][ny]) {
                // std::cout << "next: " << nx << "," << ny << std::endl;
                choices.push_back(i);
            }
        }

        // random choose one unvisited cell.
        // Remove the wall b
        if (choices.size() > 0) {
            // random choose one unvisited cell.
            std::default_random_engine eg(rd());
            std::uniform_int_distribution<int> ud(0, choices.size() - 1);
            int i = choices[ud(eg)];
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            // Remove the wall between the current cel and the cell just chosen.
            maze.removeWall(y, x, D[i]);
            // Recursively call, make the chosen cell becoming the current cell.
            dfsGenMaze(visited, maze, nx, ny);
        } else {
            break;
        }
    }

}
