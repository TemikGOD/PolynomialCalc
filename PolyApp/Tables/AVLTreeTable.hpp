#pragma once
#include "TableInterface.hpp"
#include "../Containers/Vector.h"
#include "MyExcepions.hpp"

template <typename Key, typename Value>
class AVLTreeTable : public TableInterface<typename Key, typename Value>
{
public:
 AVLTreeTable();
  ~AVLTreeTable();
  void add(const Key& key, Value* const pol) override;
  void erase(const Key& key) override;
  Value search(const Key& key) override;
  Value getValue(int index) override;
  Key getKey(int index) override;
  size_t size() override;
private:
  struct TreeNode {
    TreeNode() : pol(nullptr), left(nullptr), right(nullptr) { };
    Key key;
    Value* pol;
    int height;
    TreeNode* left;
    TreeNode* right;
  };
  TreeNode* root;
  void inorderTraversal(TreeNode* node, ad::Vector<std::pair<Key, Value*>>& pairs);
  void visit(ad::Vector<std::pair<Key, Value*>>& _pairs, Key key) const;
  size_t size(TreeNode* node) const;
  void clearTreeHelper(TreeNode*& treeptr);
  TreeNode* add(TreeNode* _TreeNode, Key _key, Value* _pol);
  TreeNode* erase(TreeNode* _TreeNode, Key _key);
  TreeNode* findMin(TreeNode* _TreeNode);
  TreeNode* findMax(TreeNode* _TreeNode);
  int getHeight(TreeNode* _TreeNode);
  int getBalanceFactor(TreeNode* _TreeNode);
  void updateHeight(TreeNode* _TreeNode);
  TreeNode* rotateRight(TreeNode* _TreeNode);
  TreeNode* rotateLeft(TreeNode* _TreeNode);
  TreeNode* balance(TreeNode* _TreeNode);
};

template <typename Key, typename Value>
AVLTreeTable<Key, Value>::AVLTreeTable() {
  root = nullptr;
}

template <typename Key, typename Value>
void AVLTreeTable<Key, Value>::clearTreeHelper(TreeNode*& treeptr)
{
  if (treeptr != nullptr)
  {
    clearTreeHelper(treeptr->left);
    clearTreeHelper(treeptr->right);
    delete treeptr->pol;
    delete treeptr;
    treeptr = nullptr;
  }
}

template <typename Key, typename Value>
size_t AVLTreeTable<Key, Value>::size() {
  return size(root);
}

template <typename Key, typename Value>
size_t AVLTreeTable<Key, Value>::size(TreeNode* node) const {
  if (node == nullptr) {
    return 0;
  }
  return 1 + size(node->left) + size(node->right);
}

template <typename Key, typename Value>
AVLTreeTable<Key, Value>::~AVLTreeTable()
{
  clearTreeHelper(root);
}

template <typename Key, typename Value>
void AVLTreeTable<Key, Value>::visit(ad::Vector<std::pair<Key, Value*>>& _pairs, Key key) const
{
  _pairs.push_back(std::make_pair(key, nullptr));
}

template <typename Key, typename Value>
void AVLTreeTable<Key, Value>::inorderTraversal(TreeNode* node, ad::Vector<std::pair<Key, Value*>>& pairs) {
  if (node != nullptr) {
    inorderTraversal(node->left, pairs);
    visit(pairs, node->key);
    inorderTraversal(node->right, pairs);
  }
}

template <typename Key, typename Value>
Value AVLTreeTable<Key, Value>::getValue(int index) {
  ad::Vector<std::pair<Key, Value*>> pairs;
  inorderTraversal(root, pairs);

  return *pairs[index].second;
}

template <typename Key, typename Value>
Key AVLTreeTable<Key, Value>::getKey(int index) {
  ad::Vector<std::pair<Key, Value*>> pairs;
  inorderTraversal(root, pairs);
  return pairs[index].first;
}

template <typename Key, typename Value>
void AVLTreeTable<Key, Value>::add(const Key& _key, Value* const _pol) {
  root = add(root, _key, _pol);
}

template <typename Key, typename Value>
typename AVLTreeTable<Key, Value>::TreeNode* AVLTreeTable<Key, Value>::add(TreeNode* _TreeNode, Key _key, Value* _pol) {
  if (_TreeNode == nullptr) {
    _TreeNode = new TreeNode;
    _TreeNode->key = _key;
    _TreeNode->pol = _pol;
    _TreeNode->height = 1;
    _TreeNode->left = nullptr;
    _TreeNode->right = nullptr;
    return _TreeNode;
  }
  if (_key < _TreeNode->key) {
    _TreeNode->left = add(_TreeNode->left, _key, _pol);
  }
  else if (_key > _TreeNode->key) {
    _TreeNode->right = add(_TreeNode->right, _key, _pol);
  }
  else {
    throw AddException("This key is already in table");
  }
  return balance(_TreeNode);
}

template <typename Key, typename Value>
void AVLTreeTable<Key, Value>::erase(const Key& _key) {
  root = erase(root, _key);
}

template <typename Key, typename Value>
typename AVLTreeTable<Key, Value>::TreeNode* AVLTreeTable<Key, Value>::erase(TreeNode* _TreeNode, Key _key) {
  if (_TreeNode == nullptr) {
    throw NothingFoundException("There is no such key in the table");
  }
  if (_key < _TreeNode->key) {
    _TreeNode->left = erase(_TreeNode->left, _key);
  }
  else if (_key > _TreeNode->key) {
    _TreeNode->right = erase(_TreeNode->right, _key);
  }
  else
    if (_key == _TreeNode->key) {
      TreeNode* left = _TreeNode->left;
      TreeNode* right = _TreeNode->right;
      delete _TreeNode;
      if (right == nullptr) {
        return left;
      }
      TreeNode* min = findMin(right);
      min->right = findMax(right);
      min->left = left;
      return balance(min);
    }
  return balance(_TreeNode);
}

template <typename Key, typename Value>
Value AVLTreeTable<Key, Value>::search(const Key& _key) {
  TreeNode* _TreeNode = root;
  while (_TreeNode != nullptr) {
    if (_key < _TreeNode->key) {
      _TreeNode = _TreeNode->left;
    }
    else if (_key > _TreeNode->key) {
      _TreeNode = _TreeNode->right;
    }
    else {
      return *_TreeNode->pol;
    }
  }
  throw NothingFoundException("Nothing found");
}

template <typename Key, typename Value>
typename AVLTreeTable<Key, Value>::TreeNode* AVLTreeTable<Key, Value>::findMin(TreeNode* _TreeNode) {
  while (_TreeNode->left != nullptr) {
    _TreeNode = _TreeNode->left;
  }
  return _TreeNode;
}

template <typename Key, typename Value>
typename AVLTreeTable<Key, Value>::TreeNode* AVLTreeTable<Key, Value>::findMax(TreeNode* _TreeNode) {
  while (_TreeNode->right != nullptr) {
    _TreeNode = _TreeNode->right;
  }
  return _TreeNode;
}

template <typename Key, typename Value>
int AVLTreeTable<Key, Value>::getHeight(TreeNode* _TreeNode) {
  if (_TreeNode == nullptr) {
    return 0;
  }
  return _TreeNode->height;
}

template <typename Key, typename Value>
int AVLTreeTable<Key, Value>::getBalanceFactor(TreeNode* _TreeNode) {
  return getHeight(_TreeNode->right) - getHeight(_TreeNode->left);
}

template <typename Key, typename Value>
void AVLTreeTable<Key, Value>::updateHeight(TreeNode* _TreeNode) {
  int leftHeight = getHeight(_TreeNode->left);
  int rightHeight = getHeight(_TreeNode->right);
  _TreeNode->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

template <typename Key, typename Value>
typename AVLTreeTable<Key, Value>::TreeNode* AVLTreeTable<Key, Value>::rotateRight(TreeNode* _TreeNode) {
  TreeNode* left = _TreeNode->left;
  _TreeNode->left = left->right;
  left->right = _TreeNode;
  updateHeight(_TreeNode);
  updateHeight(left);
  return left;
}

template <typename Key, typename Value>
typename AVLTreeTable<Key, Value>::TreeNode* AVLTreeTable<Key, Value>::rotateLeft(TreeNode* _TreeNode) {
  TreeNode* right = _TreeNode->right;
  _TreeNode->right = right->left;
  right->left = _TreeNode;
  updateHeight(_TreeNode);
  updateHeight(right);
  return right;
}

template <typename Key, typename Value>
typename AVLTreeTable<Key, Value>::TreeNode* AVLTreeTable<Key, Value>::balance(TreeNode* _TreeNode) {
  updateHeight(_TreeNode);
  if (getBalanceFactor(_TreeNode) == 2) {
    if (getBalanceFactor(_TreeNode->right) < 0) {
      _TreeNode->right = rotateRight(_TreeNode->right);
    }
    return rotateLeft(_TreeNode);
  }
  if (getBalanceFactor(_TreeNode) == -2) {
    if (getBalanceFactor(_TreeNode->left) > 0) {
      _TreeNode->left = rotateLeft(_TreeNode->left);
    }
    return rotateRight(_TreeNode);
  }
  return _TreeNode;
}


