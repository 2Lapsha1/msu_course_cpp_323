#include <fstream>
#include <iostream>
#include <string>

#include "graph.hpp"
#include "graph_generating.hpp"
#include "graph_printing.hpp"
#include "logger.hpp"
#include "logging_helping.hpp"

using namespace uni_cpp_practice;

constexpr int GRAPHS_NUMBER = 0;
constexpr int INVALID_NEW_DEPTH = -1;
constexpr int INVALID_NEW_VERTICES_NUM = -1;
const std::string LOG_FILENAME = "temp/log.txt";

int main() {
  auto& logger = Logger::get_logger();
  logger.set_output(LOG_FILENAME);

  int graphs_quantity = GRAPHS_NUMBER;

  do {
    std::cout << "Enter amount of graphs to generate" << std::endl;
    std::cin >> graphs_quantity;
  } while (graphs_quantity < GRAPHS_NUMBER);

  int depth = INVALID_NEW_DEPTH;

  do {
    std::cout << "Enter generate graph depth from zero" << std::endl;
    std::cin >> depth;
  } while (depth <= INVALID_NEW_DEPTH);

  int new_vertices_num = INVALID_NEW_VERTICES_NUM;

  do {
    std::cout << "Enter new_vertices_num from zero" << std::endl;
    std::cin >> new_vertices_num;
  } while (new_vertices_num < INVALID_NEW_VERTICES_NUM);

  std::cout << "Depth of adding vertices: " << depth << std::endl;

  for (int graph_num = 0; graph_num < graphs_quantity; graph_num++) {
    Graph my_graph;
    my_graph.add_vertex();
    graph_generating::new_vertices_generation(my_graph, depth,
                                              new_vertices_num);
    graph_generating::paint_edges(my_graph);
    logging_helping::write_graph(my_graph, graph_num);
    logging_helping::write_log(my_graph, depth, new_vertices_num, graph_num,
                               logger);
  }

  return 0;
}
