#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <stack>   
#include <queue>

class Graph{
    public:
    std::unordered_set<int> vertices;
    std::unordered_map<int, std::unordered_set<int>> neighbouringMap;

    Graph(const std::vector<std::vector<int>> data){
        for (const auto& line : data){
            vertices.insert(line[0]);
            neighbouringMap[line[0] ] = {};
            for(size_t i = 1; i < line.size(); ++i){
                neighbouringMap[line[0]].insert(line[i]);
            }
        }
    }

    void print() const{
        for (const auto& [vertex, friends] : neighbouringMap){
            std::cout << vertex << ": ";
            for (const auto& neighbour : friends){          // friends klicove slovo
                std::cout << neighbour << " ";
            }
            std::cout << std::endl;
        }
    }
};

void DFS(const Graph graph, const int start){
    std::stack<int> DFSstack;
    std::unordered_set<int> visited;

    DFSstack.push(start);
    visited.insert(start);

    while( not DFSstack.empty()){
        int currentVertex = DFSstack.top();
        DFSstack.pop();

        std::cout << currentVertex << " ";

        std::unordered_set<int> friends = graph.neighbouringMap.at(currentVertex);
        for (int item : friends){
            if(visited.find(item) == visited.end()){
                visited.insert(item);
                DFSstack.push(item);
            }
        }
    }
}


int main(){

    std::vector<std::vector<int>> data = {
        {1, 2, 3, 4},
        {2, 1, 3},
        {3, 1, 2},
        {4, 1},
        {99, 100, 2},
        {100, 101, 99},
        {101, 100}

    };
    Graph myGraph(data);

    myGraph.print();

    DFS(myGraph, 4);

    return 0;
}