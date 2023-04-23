#include "Node.h"

/*****************************************************************************
    Constructors/Destructor
*****************************************************************************/
template <class T>
Node<T>::Node() : data_(T()) {}

template <class T>
Node<T>::Node(const T& data) : data_(data) {}

template <class T>
Node<T>::Node(const T& data, const std::list<Node<T>*>& edge_list) : data_(data) {
    copy_(edge_list);
}

template <class T>
Node<T>::Node(const Node<T>& other) : data_(other.data_) {
    copy_(other.edge_list_);
}

template <class T>
Node<T>::~Node() {
    edge_list_.clear();
}

/*****************************************************************************
    Operator Overload
*****************************************************************************/
template <class T>
T& Node<T>::operator=(const Node<T>& other) {
    data_ = other.data_;
    copy_(other.edge_list_);
}

/*****************************************************************************
    Data Manipulation
*****************************************************************************/
template <class T>
void Node<T>::setData(const T& data) {
    data_ = data;
}

template <class T>
void Node<T>::setEdgeList(std::list<Node<T>*> edge_list) {
    edge_list_ = edge_list;
}

template <class T>
void Node<T>::addEdge(Node<T>*& node) {
    if (contains(node)) {
        return;
    }

    edge_list_.push_back(node);
}

template <class T>
void Node<T>::removeEdge(Node<T>*& node) {
    if (!contains(node)) {
        return;
    }

    typename std::list<Node<T>*>::iterator it = search_(node);

    //Erase via iterator; std::list internally handles shifting
    edge_list_.erase(it);
}

/*****************************************************************************
    Data Observation
*****************************************************************************/
template <class T>
T Node<T>::getData() const {
    return data_;
}


template <class T>
std::list<Node<T>*> Node<T>::getEdgeList() const {
    return edge_list_;
}

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

template <class T>
bool Node<T>::empty() const {
    return edge_list_.empty();
}

template <class T>
int Node<T>::size() const {
    return edge_list_.size();
}

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
template <class T>
void Node<T>::copy_(const std::list<Node<T>*>& edge_list) {
    for (typename std::list<Node<T>*>::const_iterator it = edge_list.begin(); it != edge_list.end(); ++it) {
        edge_list_.push_back((*it));
    }
}

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
