/*****************************************************************************
*    Brian Chairez                                                           *
*    Goal: Implementation of Graph using a list of lists                     *
*    Progess: Basic implementation and methods complete                      *
*****************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include "Node.cpp"

template <class T>
class Graph {
    private:
        std::list<Node<T>*> adjacency_list_;

        typename std::list<Node<T>*>::iterator search_(const T& data);
        void copy_(const std::list<Node<T>*>& adjacency_list);
        void erase_neighbors_(Node<T>*& node);
    public:
        Graph();
        Graph(const std::list<Node<T>*>& adjacency_list);
        Graph(const Graph<T>& other);
        ~Graph();
        T& operator=(const Graph<T>& other);
        std::list<Node<T>*> getAdjacencyList() const;
        void insertVertex(const T& data);
        void removeVertex(const T& data);
        void addEdge(const T& data1, const T& data2);
        void removeEdge(const T& data1, const T& data2);
        bool contains(const T& data) const;
        bool empty() const;
        int size() const;
        void printAdjacencyList() const;
};

#endif