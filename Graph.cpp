#include "Graph.h"

/*****************************************************************************
    Constructors/Destructor
*****************************************************************************/
// Time Complexity: O(1)
template <class T>
Graph<T>::Graph() {}

// Time Complexity: O(NM), where N is the number of nodes in the adjacency list and M is the number of edges in the edge list
template <class T>
Graph<T>::Graph(const std::list<Node<T>*>& adjacency_list) {
    copy_(adjacency_list);
}

// Time Complexity: O(NM), where N is the number of nodes in the adjacency list and M is the number of edges in the edge list in other
template <class T>
Graph<T>::Graph(const Graph<T>& other) {
    copy_(other.adjacency_list_);
}

// Time Complexity: O(N), where N is the number of nodes in the adjacency list
template <class T>
Graph<T>::~Graph() {
    for (typename std::list<Node<T>*>::iterator it = adjacency_list_.begin(); it != adjacency_list_.end(); ++it) {
        delete (*it);
    }

    adjacency_list_.clear();
}

/*****************************************************************************
    Operator Overload
*****************************************************************************/
// Time Complexity: O(NM), where N is the number of nodes in the adjacency list and M is the number of edges in the edge list in other
template <class T>
T& Graph<T>::operator=(const Graph<T>& other) {
    copy_(other.adjacency_list_);
}

/*****************************************************************************
    Data Manipulation
*****************************************************************************/
// Time Complexity: O(N), where N is the number of nodes in the adjacency list
template <class T>
void Graph<T>::insertVertex(const T& data) {
    if (contains(data)) {
        return;
    }

    Node<T>* new_node = new Node<T>(data);
    adjacency_list_.push_back(new_node);
}

// Time Complexity: O(NM), where N is the number of nodes in the adjacency list and M is the number of edges in the edge list
template <class T>
void Graph<T>::removeVertex(const T& data) {
    if (!contains(data)) {
        return;
    }

    typename std::list<Node<T>*>::iterator it = search_(data);
    Node<T>* node_ptr = (*it);

    erase_neighbors_(node_ptr);
    delete (*it);
    adjacency_list_.erase(it);
}

// Time Complexity: O(N), where N is the number of nodes in the adjacency list
template <class T>
void Graph<T>::addEdge(const T& data1, const T& data2) {
    if (!contains(data1) || !contains(data2)) {
        return;
    }

    typename std::list<Node<T>*>::iterator data1_it = search_(data1);
    typename std::list<Node<T>*>::iterator data2_it = search_(data2);

    Node<T>* data2_node_ptr = (*data2_it);
    (*data1_it)->addEdge(data2_node_ptr);
}

// Time Complexity: O(N), where N is the number of nodes in the adjacency list
template <class T>
void Graph<T>::removeEdge(const T& data1, const T& data2) {
    if (!contains(data1) || !contains(data2)) {
        return;
    }

    typename std::list<Node<T>*>::iterator data1_it = search_(data1);
    typename std::list<Node<T>*>::iterator data2_it = search_(data2);

    Node<T>* data2_node_ptr = (*data2_it);
    (*data1_it)->removeEdge(data2_node_ptr);
}

/*****************************************************************************
    Data Observation
*****************************************************************************/
// Time Complexity: O(1)
template <class T>
std::list<Node<T>*> Graph<T>::getAdjacencyList() const {
    return adjacency_list_;
}

// Time Complexity: O(N), where N is the number of nodes in the adjacency list
template <class T>
bool Graph<T>::contains(const T& data) const {
    if (empty()) {
        return false;
    }

    for (typename std::list<Node<T>*>::const_iterator it = adjacency_list_.cbegin(); it != adjacency_list_.cend(); ++it) {
        if ((*it)->getData() == data) {
            return true;
        }
    }

    return false;
}

// Time Complexity: O(1)
template <class T>
bool Graph<T>::empty() const {
    return adjacency_list_.empty();
}

// Time Complexity: O(1)
template <class T>
int Graph<T>::size() const {
    return adjacency_list_.size();
}

// Time Complexity: O(NM), where N is the number of nodes in the adjacency list and M is the number of edges in the edge list
template <class T>
void Graph<T>::printAdjacencyList() const {
    for (typename std::list<Node<T>*>::const_iterator it = adjacency_list_.cbegin(); it != adjacency_list_.cend(); ++it) {
        std::cout << (*it)->getData() << ": ";
        (*it)->printEdgeList();
    }
}

/*****************************************************************************
    Private Functions
*****************************************************************************/
// Time Complexity: O(N), where N is the number of nodes in the adjacency list
template <class T>
typename std::list<Node<T>*>::iterator Graph<T>::search_(const T& data) {
    typename std::list<Node<T>*>::iterator it = adjacency_list_.begin();
    for (; it != adjacency_list_.end(); ++it) {
        if ((*it)->getData() == data) {
            return it;
        }
    }

    return it;
}

// Time Complexity: O(NM), where N is the number of nodes in the adjacency list and M is the number of edges in the edge list
template <class T>
void Graph<T>::copy_(const std::list<Node<T>*>& adjacency_list) {
    for (typename std::list<Node<T>*>::const_iterator it = adjacency_list.cbegin(); it != adjacency_list.cend(); ++it) {
        Node<T>* new_node = new Node<T>((*it)->getData(), (*it)->getEdgeList());
        adjacency_list_.push_back(new_node);
    }
}

// Time Complexity: O(NM), where N is the number of nodes in the adjacency list and M is the number of edges in the edge list
template <class T>
void Graph<T>::erase_neighbors_(Node<T>*& node) {
    for (typename std::list<Node<T>*>::iterator it = adjacency_list_.begin(); it != adjacency_list_.end(); ++it) {
        if ((*it)->contains(node)) {
            (*it)->removeEdge(node);
        }
    }
}
