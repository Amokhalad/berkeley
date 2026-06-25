/*
Group Members:
    Mokhalad Aljuboori
    Tina Shao
*/

#ifndef INC_05_AVL_TREE_AVL_TREE_H
#define INC_05_AVL_TREE_AVL_TREE_H

#include <memory>
using namespace std;

template <typename Key, typename Value = Key>
class AVLTree
{
public:
    class Node
    {
    public:
        Node(const Key &key, const Value &value) : key_{key}, value_{value}, balance_factor_{0}, left_{nullptr}, right_{nullptr} {}
        Node(const Key &key) : key_{key_}, balance_factor_{0}, left_{nullptr}, right_{nullptr} {}

        Node *left() const { return left_; }
        Node *right() const { return right_; }
        const Key &key() const { return key_; }
        const Value &value() const { return value_; }
        int balance_factor() const
        {

            int left_height = 0;
            int right_height = 0;
            if (left())
            {
                left_height = left()->height;
            }
            if (right())
            {
                right_height = right()->height;
            }
            return right_height - left_height;
        }

        void print(int depth = 0) const
        {
            if (left_ != nullptr)
            {
                left_->print(depth + 1);
            }
            for (int i = 0; i < depth; ++i)
            {
                cout << "   ";
            }
            cout << key_ << ": " << value_ << " (bf: " << balance_factor() << ")" << endl;
            if (right_ != nullptr)
            {
                right_->print(depth + 1);
            }
        }

    private:
        Key key_;
        Value value_;
        int balance_factor_;
        int height;
        Node *left_, *right_;

        friend class AVLTree<Key, Value>;
    };

public:
    void print()
    {
        if (root_ != nullptr)
        {
            root_->print();
        }
    }
    AVLTree() : size_{0}, root_{nullptr} {}
    ~AVLTree()
    {
        makeEmpty();
    }
    void makeEmpty()
    {
        return _makeEmpty(root_);
    }

    void _makeEmpty(Node *&cur)
    {
        if (cur != nullptr)
        {
            _makeEmpty(cur->left_);
            _makeEmpty(cur->right_);
            delete cur;
        }
        cur = nullptr;
    }
    int size() { return size_; }
    Node *root() { return root_; }
    void insert(const Key &key, const Value &value);
    void _insert(const Key &key, const Value &value, Node *&t);
    void balance(Node *&t);
    Value &operator[](const Key &key);
    int height(Node *t) const;
    void LL_Rotation(Node *&t);
    void RR_Rotation(Node *&t);
    void RL_Rotation(Node *&t);
    void LR_Rotation(Node *&t);

private:
    static const int ALLOWED_IMBALANCE = 1;
    int size_;
    Node *root_;
};

template <typename Key, typename Value>
void AVLTree<Key, Value>::insert(const Key &key, const Value &value)
{
    _insert(key, value, root_);
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::_insert(const Key &key, const Value &value, Node *&t)
{
    if (t == nullptr)
    {
        t = new Node(key, value);
        size_++;
    }
    else if (key < t->key())
    {
        _insert(key, value, t->left_);
    }
    else if (key > t->key())
    {
        _insert(key, value, t->right_);
    }
    balance(t);
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::balance(AVLTree::Node *&t)
{
    if (t == nullptr)
    {
        return;
    }
    if (height(t->left()) - height(t->right()) > ALLOWED_IMBALANCE)
    {
        if (height(t->left()->left()) >= height(t->left()->right()))
        {
            LL_Rotation(t);
        }
        else
        {
            RL_Rotation(t);
        }
    }
    else
    {
        if (height(t->right()) - height(t->left()) > ALLOWED_IMBALANCE)
        {
            if (height(t->right()->right()) >= height(t->right()->left()))
            {
                RR_Rotation(t);
            }
            else
            {
                LR_Rotation(t);
            }
        }
    }
    t->height = max(height(t->left_), height(t->right_)) + 1;
    t->balance_factor_ = height(t->left()) - height(t->right());
}

template <typename Key, typename Value>
int AVLTree<Key, Value>::height(AVLTree::Node *t) const
{
    if (t == nullptr)
    {
        return 0;
    }
    else
    {
        return t->height;
    }
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::LL_Rotation(AVLTree::Node *&k2)
{
    Node *k1 = k2->left();
    k2->left_ = k1->right();
    k1->right_ = k2;
    k2->height = max(height(k2->left()), height(k2->right())) + 1;
    k1->height = max(height(k1->left()), k2->height) + 1;
    k2 = k1;
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::RR_Rotation(AVLTree::Node *&k2)
{
    Node *k1 = k2->right_;
    k2->right_ = k1->left_;
    k1->left_ = k2;
    k2->height = max(height(k2->left_), height(k2->right_)) + 1;
    k1->height = max(height(k1->right_), k2->height) + 1;
    k2 = k1;
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::RL_Rotation(AVLTree::Node *&k3)
{
    RR_Rotation(k3->left_);
    LL_Rotation(k3);
}

template <typename Key, typename Value>
void AVLTree<Key, Value>::LR_Rotation(AVLTree::Node *&k3)
{
    LL_Rotation(k3->right_);
    RR_Rotation(k3);
}

template <typename Key, typename Value>
Value &AVLTree<Key, Value>::operator[](const Key &key)
{
    Node *cur;
    for (cur = root_; cur != nullptr; cur = key < cur->key_ ? cur->left_ : cur->right_)
    {
        if (key == cur->key_)
        {
            return cur->value_;
        }
    }
    insert(key, Value());

    return (*this)[key];
}

#endif //INC_05_AVL_TREE_AVL_TREE_H