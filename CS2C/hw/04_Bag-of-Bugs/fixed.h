#ifndef INC_04_BAG_OF_BUGS_FIXED_H
#define INC_04_BAG_OF_BUGS_FIXED_H

#include <memory>
#include <cassert>

namespace cs2c {

    template <typename T>
    class Bag {
    public:
        class Node {
        private:
            T value_;
            std::unique_ptr<Node> left_, right_;
            Node(const T& value) : value_(value) {}

        public:
            ~Node() {
                left_.release();
                right_.release();
            }
            // left getter
            Node *left() {
                return left_.get();
            }

            Node *right() {
                return right_.get();
            }
            // value getter
            const T& value() const {
                return value_;
            }

            friend class Bag<T>;
        };

    private:
        std::unique_ptr<Node> root_;
        int size_;

        int count(Node *cur, const T& value) const {
            if (cur == nullptr) {
                return 0;
            } else if (value == cur->value_) {
                return count(cur->left_, value) + count(cur->right_, value);
            } else if (value < cur->value_) {
                return count(cur->left_, value);
            } else {
                return count(cur->right_, value);
            }
        }

        // Remove the node with the greatest value in the left subtree and return a
        // unique_ptr to it.
        static std::unique_ptr<Node> extract_greatest_in_left_subtree(Node *cur) {
            std::unique_ptr<Node> greatest;
            Node *c, *p;  // previous and current pointers
            for (p = cur, c = cur->left_.get();
                 c->right_ != nullptr;
                 p = c, c = c->right_.get());
            if (p->left_.get() == c) {
                greatest.reset(p->left_.release());
                p->left_.reset(c->left_.release());
            } else {
                greatest.reset(p->right_.release());
                p->right_.reset(c->left_.release());
            }
            return greatest;
        }

        // Remove the node with the smallest value in the right subtree and return a
        // unique_ptr to it.
        static std::unique_ptr<Node> extract_least_in_right_subtree(Node *cur) {
            std::unique_ptr<Node> least;
            Node *c, *p;  // previous and current pointers
            for (p = cur, c = cur->right_.get();
                 c->left_ != nullptr;
                 p = c, c = c->left_.get());
            if (p->left_.get() == c) {
                least.reset(p->left_.release());
                p->left_.reset(c->right_.release());
            } else {
                least.reset(p->right_.release());
                p->right_.reset(c->right_.release());
            }
            return least;
        }

        int remove(Node *prev, Node *cur, const T& value) {
            if (cur == nullptr) {
                return 0;  // base case
            } else if (value == cur->value_) {
                // We need to remove cur and any children  with the same value...
                int num_removed = (
                        remove(cur, cur->left_.get(), value) +
                        remove(cur, cur->right_.get(), value));

                // Find a replacement leaf node, unless cur is a leafnode.
                std::unique_ptr<Node> replacement;
                if (cur->left_ == nullptr) {
                    replacement = extract_least_in_right_subtree(cur);
                } else if (cur->right_ == nullptr) {
                    replacement = extract_greatest_in_left_subtree(cur);
                }

                // If there is a replacement, then move cur's children to the replacement
                if (replacement != nullptr) {
                    assert(replacement->left_ == nullptr);
                    assert(replacement->right_ == nullptr);
                    replacement->left_.reset(cur->left_.release());
                    replacement->right_.reset(cur->right_.release());
                }

                // Make cur's parent node (prev) point to the replacement
                if (prev == nullptr) {
                    root_.reset(replacement.release());
                } else if (prev->left_.get() == cur) {
                    prev->left_.reset(replacement.release());
                } else {  // if (prev->right_.get() == cur)
                    prev->right_.reset(replacement.release());
                }
                assert(replacement == nullptr);
                return num_removed;
            } else if (value < cur->value_) {
                return remove(cur, cur->left_.get(), value);
            } else {  // if (value > cur->value_)
                return remove(cur, cur->right_.get(), value);
            }
        }

    public:
        Bag() : size_(0) {}

        void insert(const T& value) {
            std::unique_ptr<Node> *cur;
            for (cur = &root_;
                 cur->get() != nullptr;
                 cur = value < (*cur)->value_ ? &(*cur)->left_ : &(*cur)->right_);
            cur->reset(new Node(value));  // actually insert the value
        }

        int remove(const T& value) {
            return remove(nullptr, root_.get(), value);
        }

        int count(const T& value) {
            return count(root_.get(), value);
        }

        bool contains(const T& value) const {
            return count(value);
        }

        int size() {
            return size_;
        }

        Node *root() {
            return root_.get();
        }
    };

} // namespace cs2c
#endif //INC_04_BAG_OF_BUGS_BAG_H