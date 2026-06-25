#ifndef INC_04_BAG_OF_BUGS_BAG_H
#define INC_04_BAG_OF_BUGS_BAG_H
#include <memory>
#include <cassert>
#include <iostream>
using namespace std;


namespace cs2c {

    template <typename Value>
    class Bag {
    public:
        class Node {
        public:
            static Node * findMin( Node *t ) {
                if( t == nullptr )
                    return nullptr;
                if( t->left_ == nullptr )
                    return t;
                return findMin( t->left_ );
            }

            int _dupCount() {
                return duplicateCount;
            }


            static Node * findMax( Node *t ) {
                if( t != nullptr )
                    while( t->right != nullptr )
                        t = t->right;
                return t;
            }

            bool insert(const Value& new_value) {
                if (new_value == value_) {
                    this->duplicateCount++;
                    return true;
                } else if (new_value < value_) {  // Need to insert to the left
                    if (left_ == nullptr) {
                        left_ = new Node(new_value);
                        return true;
                    } else {
                        return left_->insert(new_value);
                    }
                } else { // if (new_value > value)  Need to insert to the right
                    if (right_ == nullptr) {
                        right_ = new Node(new_value);
                        return true;
                    } else {
                        return right_->insert(new_value);
                    }
                }
            }
            Node* largest_node() {
                Node *largest;
                for (largest = this; largest->right_ != nullptr; largest = largest->right_) { }
                return largest;
            }
            Node* smallest_node() {
                Node *smallest;
                for (smallest = this; smallest->left_ != nullptr; smallest = smallest->left_) { }
                return smallest;
            }

            // TODO: this method does not work properly
            static int _remove(const Value& value, Node ** root) {
                Node* node = *root;
                if (node == nullptr) {
                    return 0;
                }
                if (value < node->value_) {
                    return _remove(value, &node->left_);
                } else if(value > node->value_) {
                    return _remove(value, &node->right_);
                } else {
                    if (node->left_ == nullptr && node->right_ == nullptr) {
                        int numOfNodes = 1 + (*root)->duplicateCount;
                        *root = nullptr;
                        delete node;
                        return numOfNodes;
                    } else if (node->left_ == nullptr) {
                        // the node wer are deleting is root and node
                        int numOfNodes = 1 + (*root)->duplicateCount;
                        *root = node->right_;
                        delete node;
                        return numOfNodes;
                    } else if (node->right_ == nullptr) {
                        int numOfNodes = 1 + (*root)->duplicateCount;
                        *root = node->left_;
                        delete node;
                        return numOfNodes;
                    } else {  // node->left and node->right aren't nullptr
                        Node* largest = node->left_->largest_node();
                        int numItemsDeleted = 1 + node->duplicateCount;

                        node->value_ = largest->value_;
                        node->duplicateCount = largest->duplicateCount;
                        _remove(largest->value_, &node->left_);
                        return numItemsDeleted;
                    }
                }

            } // oh, it passed my unit tests but I don;t think it passed grade oven, my unit tests are also faulty cuz that failed

            friend class Bag<Value>;

            void print(int depth = 0) {
                if (left_ != nullptr) {
                    left_->print(depth + 1);
                }
                for (int i = 0; i < depth; ++i) {
                    cout << "  ";
                }
                cout << value_ << endl;
                if (right_ != nullptr) {
                    right_->print(depth + 1);
                }
            }

            static int _contains(Node *cur, const Value& value) {
                if (cur == nullptr) {
                    return 0;
                } else if (value == cur->value_) {
                    return 1 + _contains(cur->left_, value) + _contains(cur->right_, value);
                } else if (value < cur->value_) {
                    return _contains(cur->left_, value);
                } else {
                    return _contains(cur->right_, value);
                }
            }

            Node* left() const {
                return left_;
            }

            Node* right() const {
                return right_;
            }


            const Value& value() const {
                return value_;
            }
        private:
            static Node* extract_greatest_in_left_subtree(Node *cur) {
                Node* greatest = findMax(cur);
                Node::_remove(greatest->value_, greatest);
                return greatest;
            }
            static Node* extract_least_in_right_subtree(Node *cur) {
                Node* least = findMin(cur);
                Node::_remove(least->value_, least);
                return least;
            }

            static int count(Node *cur, const Value& value) {
                if (cur == nullptr) {
                    return 0;
                } else if (value == cur->value_) {
                    return cur->duplicateCount + 1;
                } else if (value < cur->value_) {
                    return count(cur->left_, value);
                } else {
                    return count(cur->right_, value);
                }
            }

            Value value_;
            Node* left_, *right_;
            int duplicateCount;
            explicit Node(const Value& value) : value_(value), left_(nullptr), right_(nullptr), duplicateCount(0) {}
        };

        Bag() : size_(0), root_(nullptr) {}
        ~Bag() {
            makeEmpty();
        }
        void makeEmpty() {
            return _makeEmpty(root_);
        }

        void _makeEmpty(Node *& cur) {
            if (cur != nullptr) {
                _makeEmpty(cur->left_);
                _makeEmpty(cur->right_);
                delete cur;
            }
            cur = nullptr;
        }

        int remove(const Value& value) {
            int numOfNodesDeleted = Node::_remove(value, &root_);
            size_ -= numOfNodesDeleted;

            return numOfNodesDeleted;
        }

        void insert(const Value& value) {
            if (root_ == nullptr) {
                root_ = new Node(value);
                size_++;
            } else {
                if (root_->insert(value)){
                    size_++;
                }
            }

        }

//        void insert(const Value& new_value) {
//            Node* cur = root_;
//            if (root_ == nullptr) {
//                root_ = new Node(new_value);
//                ++size_;
//                return;
//            }
//            while (cur != nullptr) {
//                if (new_value == cur->value_) {
//                    cur->duplicateCount++;
//                    ++size_;
//                    return;
//                } else if (new_value < cur->value_) {
//                    if (cur->left_ == nullptr) {
//                        cur->left_ = new Node(new_value);
//                        ++size_; // I can't I don't have the previous version
//                        return;
//                    } else {
//                        cur = cur->left_;
//                    }
//                } else if (new_value > cur->value_) {
//                    if (cur->right_ == nullptr) {
//                        cur->right_ = new Node(new_value);
//                        ++size_;
//                        return;
//                    } else {
//                        cur = cur->right_;
//                    }
//                }
//            }
//        }





        // TODO not part of assignment
        void print() {
            if (root_ != nullptr) {
                root_->print();
            }
        }

        bool contains(const Value& value) const {
            return Node::_contains(root_, value);
        }

        int size() {
            return size_;
        }

        int count(const Value& value) {
            return Node::count(root_, value);
        }

        // TODO: this returns a weird address and you canoot dereference it. Is that okay?
        Node *root() {
            return root_;
        }




    private:
        Node* root_;
        int size_;
    };

} // namespace cs2c

#endif