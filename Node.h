#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <list>

template <class T>
class Node {
    private:
        T data_;
        std::list<Node<T>*> edge_list_;

        void copy_(const std::list<Node<T>*>& edge_list);
        typename std::list<Node<T>*>::iterator search_(Node<T>*& node);
    public:
        Node();
        Node(const T& data);
        Node(const T& data, const std::list<Node<T>*>& edge_list);
        Node(const Node<T>& other);
        ~Node();
        T& operator=(const Node<T>& other);
        T getData() const;
        std::list<Node<T>*> getEdgeList() const;
        void setData(const T& data);
        void setEdgeList(std::list<Node<T>*> edge_list);
        void addEdge(Node<T>*& node);
        void removeEdge(Node<T>*& node);
        bool contains(Node<T>*& node) const;
        bool empty() const;
        int size() const;
        void printEdgeList() const;
};

#endif