#include "Graph.h"

/*****************************************************************************
    Constructors/Destructor
*****************************************************************************/
template <class T>
Graph<T>::Graph() {}

template <class T>
Graph<T>::Graph(const std::list<Node<T>*>& adjacency_list) {
    copy_(adjacency_list);
}

template <class T>
Graph<T>::Graph(const Graph<T>& other) {
    copy_(other.adjacency_list_);
}

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
template <class T>
T& Graph<T>::operator=(const Graph<T>& other) {
    copy_(other.adjacency_list_);
}

/*****************************************************************************
    Data Manipulation
*****************************************************************************/
template <class T>
void Graph<T>::insertVertex(const T& data) {
    if (contains(data)) {
        return;
    }

    Node<T>* new_node = new Node<T>(data);
    adjacency_list_.push_back(new_node);
}

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
template <class T>
std::list<Node<T>*> Graph<T>::getAdjacencyList() const {
    return adjacency_list_;
}

template <class T>
bool Graph<T>::contains(const T& data) const {
    if (empty()) {
        return false;
    }

    for (typename std::list<Node<T>*>::const_iterator it = adjacency_list_.begin(); it != adjacency_list_.end(); ++it) {
        if ((*it)->getData() == data) {
            return true;
        }
    }

    return false;
}

template <class T>
bool Graph<T>::empty() const {
    return adjacency_list_.empty();
}

template <class T>
int Graph<T>::size() const {
    return adjacency_list_.size();
}

template <class T>
void Graph<T>::printAdjacencyList() const {
    for (typename std::list<Node<T>*>::const_iterator it = adjacency_list_.begin(); it != adjacency_list_.end(); ++it) {
        std::cout << (*it)->getData() << ": ";
        (*it)->printEdgeList();
    }
}

/*****************************************************************************
    Private Functions
*****************************************************************************/
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

template <class T>
void Graph<T>::copy_(const std::list<Node<T>*>& adjacency_list) {
    for (typename std::list<Node<T>*>::const_iterator it = adjacency_list.begin(); it != adjacency_list.end(); ++it) {
        Node<T>* new_node = new Node<T>((*it)->getData(), (*it)->getEdgeList());
        adjacency_list_.push_back(new_node);
    }
}

template <class T>
void Graph<T>::erase_neighbors_(Node<T>*& node) {
    for (typename std::list<Node<T>*>::iterator it = adjacency_list_.begin(); it != adjacency_list_.end(); ++it) {
        if ((*it)->contains(node)) {
            (*it)->removeEdge(node);
        }
    }
}