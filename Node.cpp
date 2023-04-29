#include "Node.h"

/*****************************************************************************
    Constructors/Destructor
*****************************************************************************/
// Time Complexity: O(1)
template <class T>
Node<T>::Node() : data_(T()) {}

// Time Complexity: O(1)
template <class T>
Node<T>::Node(const T& data) : data_(data) {}

// Time Complexity: O(N), where N is the number of edges in the edge list
template <class T>
Node<T>::Node(const T& data, const std::list<Node<T>*>& edge_list) : data_(data) {
    copy_(edge_list);
}

// Time Complexity: O(N), where N is the number of edges in the edge list in other
template <class T>
Node<T>::Node(const Node<T>& other) : data_(other.data_) {
    copy_(other.edge_list_);
}

// Time Complexity: O(N), where N is the number of edges in the edge list
template <class T>
Node<T>::~Node() {
    edge_list_.clear();
}

/*****************************************************************************
    Operator Overload
*****************************************************************************/
// Time Complexity: O(N), where N is the number of edges in the edge list in other
template <class T>
T& Node<T>::operator=(const Node<T>& other) {
    data_ = other.data_;
    copy_(other.edge_list_);
}

/*****************************************************************************
    Data Manipulation
*****************************************************************************/
// Time Complexity: O(1)
template <class T>
void Node<T>::setData(const T& data) {
    data_ = data;
}

// Time Complexity: O(1)
template <class T>
void Node<T>::setEdgeList(std::list<Node<T>*> edge_list) {
    edge_list_ = edge_list;
}


// Time Complexity: O(N), where N is the number of edges in the edge list
template <class T>
void Node<T>::addEdge(Node<T>*& node) {
    if (contains(node)) {
        return;
    }

    edge_list_.push_back(node);
}

// Time Complexity: O(N), where N is the number of edges in the edge list
template <class T>
void Node<T>::removeEdge(Node<T>*& node) {
    if (!contains(node)) {
        return;
    }

    typename std::list<Node<T>*>::iterator it = search_(node);
    edge_list_.erase(it);   //Erase via iterator;
}

/*****************************************************************************
    Data Observation
*****************************************************************************/
// Time Complexity: O(1)
template <class T>
T Node<T>::getData() const {
    return data_;
}

// Time Complexity: O(1)
template <class T>
std::list<Node<T>*> Node<T>::getEdgeList() const {
    return edge_list_;
}

// Time Complexity: O(N), where N is the number of edges in the edge list
template <class T>
bool Node<T>::contains(Node<T>*& node) const {
    if (empty()) {
        return false;
    }

    for (typename std::list<Node<T>*>::const_iterator it = edge_list_.begin(); it != edge_list_.end(); ++ it) {
        if ((*it)->getData() == node->getData()) {
            return true;
        }
    }

    return false;
}

// Time Complexity: O(1)
template <class T>
bool Node<T>::empty() const {
    return edge_list_.empty();
}

// Time Complexity: O(1)
template <class T>
int Node<T>::size() const {
    return edge_list_.size();
}

// Time Complexity: O(N), where N is the number of edges in the edge list
template <class T>
void Node<T>::printEdgeList() const {
    for (typename std::list<Node<T>*>::const_iterator it = edge_list_.begin(); it != edge_list_.end(); ++it) {
        std::cout << (*it)->getData() << ", ";
    }
    std::cout << '\n';
}

/*****************************************************************************
    Private Functions
*****************************************************************************/
// Time Complexity: O(N), where N is the number of edges in the edge list
template <class T>
typename std::list<Node<T>*>::iterator Node<T>::search_(Node<T>*& node) {
    typename std::list<Node<T>*>::iterator it = edge_list_.begin();
    for (; it != edge_list_.end(); ++it) {
        if ((*it)->getData() == node->getData()) {
            return it;
        }
    }

    return it;
}

// Time Complexity: O(N), where N is the number of edges in the edge list
template <class T>
void Node<T>::copy_(const std::list<Node<T>*>& edge_list) {
    for (typename std::list<Node<T>*>::const_iterator it = edge_list.begin(); it != edge_list.end(); ++it) {
        edge_list_.push_back((*it));
    }
}
