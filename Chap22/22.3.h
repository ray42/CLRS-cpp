#ifndef ch22_3_h
#define ch22_3_h

#include "../print.h"
#include "Graph.h"

#define WHITE "WHITE"
#define GRAY "GRAY"
#define BLACK "BLACK"

// [Page 604]
//   DFS(G)
//   - Time: O(V + E)
//
//   DFS-VISIT(G, u)
//   - Time: O(E)

namespace CLRS {
namespace CH22 {
int time;
int iterationCounter = 0;

void printGraph(Graph& G) {
  iterationCounter++;
  if (iterationCounter == 1)
    cout << "(a) ";
  else if (iterationCounter == 2)
    cout << "(b) ";
  else if (iterationCounter == 3)
    cout << "(c) ";
  else if (iterationCounter == 4)
    cout << "(d) ";
  else if (iterationCounter == 5)
    cout << "(e) ";
  else if (iterationCounter == 6)
    cout << "(f) ";
  else if (iterationCounter == 7)
    cout << "(g) ";
  else if (iterationCounter == 8)
    cout << "(h) ";
  else if (iterationCounter == 9)
    cout << "(i) ";
  else if (iterationCounter == 10)
    cout << "(j) ";
  else if (iterationCounter == 11)
    cout << "(k) ";
  else if (iterationCounter == 12)
    cout << "(l) ";
  else if (iterationCounter == 13)
    cout << "(m) ";
  else if (iterationCounter == 14)
    cout << "(n) ";
  else if (iterationCounter == 15)
    cout << "(o) ";
  else if (iterationCounter == 16)
    cout << "(p) ";

  for (int i = 0; i < G.V.size(); i++) {
    if (iterationCounter > 16 && i == 0) cout << "    ";
    if (i > 0 && i % 3 == 0) cout << endl << "    ";
    cout << setw(5) << G.V[i]->color << " ";
    cout << G.V[i]->name << " ";

    if (G.V[i]->d == 0)
      cout << setw(2) << " ";
    else
      cout << setw(2) << G.V[i]->d;

    if (G.V[i]->d == 0 && G.V[i]->f == 0)
      cout << " ";
    else
      cout << "/";

    if (G.V[i]->f == 0)
      cout << setw(2) << " ";
    else
      cout << setw(2) << G.V[i]->f;
    cout << setw(2) << " ";
    if (i == G.V.size() - 1) cout << endl << endl;
  }
}

void dfsVisit(Graph& G, Vertex* u) {
  time++;
  u->d = time;
  u->color = GRAY;
  printGraph(G);
  for (Vertex* v : G.Adj[u]) {
    if (v->color == WHITE) {
      v->PI = u;
      dfsVisit(G, v);
    } else {
      printGraph(G);
    }
  }
  u->color = BLACK;
  time++;
  u->f = time;
  printGraph(G);
}

void dfs(Graph& G) {
  for (Vertex* u : G.V) {
    u->color = WHITE;
    u->PI = nullptr;
  }
  time = 0;
  for (Vertex* u : G.V)
    if (u->color == WHITE) dfsVisit(G, u);
}
}  // namespace CH22
}  // namespace CLRS

#endif