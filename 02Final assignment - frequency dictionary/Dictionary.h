#pragma once
#include <iostream>
#include <queue>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include "Exception.h"

using namespace std;

bool cmp_test(const pair<string, int>& a, const pair<string, int>& b);

class Dictionary {
private:
  struct Node {

    string key;
    int frequency;
    Node* left;
    Node* right;

    Node(string key) {
      this->key = key;
      this->left = this->right = NULL;
      this->frequency = 1;
    }
    Node(Node* node) {
      this->key = node->key;
      this->right = node->right;
      this->left = node->left;
      this->frequency = node->frequency;
    }
    Node() :key(""), frequency(1), left(nullptr), right(nullptr) { }

    void printWord() const
    {
      std::cout << " Word:  " << key << setw(30) << " Frequency: " << frequency << '\n';
    }
  };

  Node* root;
  int count;
  vector< pair<string, int> > VecForNode; //for Frequency sort

public:
  Dictionary() {
    root = NULL;
    count = 0;
  }
  ~Dictionary() {
    destroy(root);
  }

  int size() {
    return count;
  }

  bool isEmpty() {
    return count == 0;
  }

  void insert(string key) {
    if (key != "")
      root = insert(root, key);
  }

  void preOrderPrint() {
    preOrderPrint(root);
  }

  void search(string key) {
    search(root, key);
  }

  bool isContain(string key) {
    return isContain(root, key);
  }
  int getFrequency(string key) {
    return getFrequency(root, key);
  }
  void removeMin() {
    if (root != NULL) {
      root = removeMin(root);
    }
  }
  void remove(string key) {
    root = remove(root, key);
    cout << "Successfully removed.\n";
  }

  void interactiveGetModes()
  {
    levelSort(root);
    cout << "How many modes(appear most) do you want? \n";
    int size;
    cin >> size;
    if (!cin) 
    {
      throw Exception("Input is not a number,can't get the result.\n");
    }
    if (size > count)
    {
        throw Exception("Overflow.Number is too big.\n");
    }

    for (int i = 0; i < size; i++) 
    {
      cout << "Top " << i + 1 << ": \t" << VecForNode[i].first;
      cout << " Frequency: " << VecForNode[i].second << '\n';
    }
    cout << "Print Top " << size << " finished.\n";
  }

  void printList()
  {
    levelSort(root);
    cout << "Words' count:\t" << VecForNode.size() << std::endl;
    cout << "----------------------Frequency List--------------------------" << endl;
    for (auto it = VecForNode.begin(); it != VecForNode.end(); it++)
    {
      cout << "|  Word: " << std::setw(30) << it->first
        << " |  Frequency:\t" << it->second << setw(5) << " |" << endl;
    }
    cout << "--------------------------------------------------\n";
  }

private:

  Node* insert(Node*& node, string key)
  {
    if (node == NULL)
    {
      count++;
      return new Node(key);
    }

    if (key.compare(node->key) > 0) {
      node->right = insert(node->right, key);
    }
    else if (key.compare(node->key) < 0) {
      node->left = insert(node->left, key);
    }
    else
    {
      node->frequency++;
    }
    return node;
  }

  void preOrderPrint(Node* node) {
    if (node != NULL) {
      node->printWord();
      preOrderPrint(node->left);
      preOrderPrint(node->right);
    }
  }

  void levelSort(Node* node)
  {
    VecForNode.clear();
    queue<Node*>que;
    que.push(node);

    while (!que.empty()) {
      Node* p = que.front();
      que.pop();

      pair<string, int> temp_pair = make_pair(p->key, p->frequency);
      VecForNode.push_back(temp_pair);

      if (p->left != NULL) {
        que.push(p->left);
      }
      if (p->right != NULL) {
        que.push(p->right);
      }
    }
    sort(VecForNode.begin(), VecForNode.end(), cmp_test);
  }

  void search(Node* node, string key) 
  {
    if (node != NULL)
    {
      if (node->key == key) {
        cout << "Word is found:\n";
        node->printWord();
        return;
      }
      else if (node->key > key) {
        return search(node->left, key);
      }
      else
      {
        return search(node->right, key);
      }
    }
    else
      throw Exception("No such word exists in your dictionary.\n");

  }

  int getFrequency(Node* node, string key) 
  {
    if (node != NULL)
    {
      if (node->key == key) {
        return node->frequency;
      }
      else if (node->key > key) {
        return getFrequency(node->left, key);
      }
      else
      {
        return getFrequency(node->right, key);
      }
    }
    else
      throw Exception("No such word exists in your dictionary.\n");
  }

  bool isContain(Node* node, string key) 
  {
    if (node != NULL)
    {
      if (node->key == key) {
        return true;
      }
      else if (node->key > key) {
        return isContain(node->left, key);
      }
      else {
        return isContain(node->right, key);
      }
    }
    return false;
  }

  void destroy(Node* node) 
  {
    if (node != NULL) {
      destroy(node->left);
      destroy(node->right);
      delete node;
      count--;
    }
  }

  Node* minimun(Node* node) {
    if (node->left == NULL) {
      return node;
    }
    return minimun(node->left);
  }

  Node* maxmun(Node* node) {
    if (node->right == NULL) {
      return node;
    }
    return maxmun(node->right);
  }

  Node* removeMin(Node* node) {
    if (node->left == NULL) {
      Node* rightNode = node->right;
      delete node;
      count--;
      return rightNode;
    }
    else
    {
      node->left = removeMin(node->left);
      return node;
    }
  }
  Node* remove(Node* node, string key) 
  {
    if (node == NULL) {
      throw Exception("No such word contains.\n");
    }
    if (node->key == key) {
      if (node->left == NULL) {
        Node* rightNode = node->right;
        delete node;
        count--;
        return rightNode;
      }
      if (node->right == NULL) {
        Node* leftNode = node->left;
        delete node;
        count--;
        return leftNode;
      }
      Node* s = new Node(minimun(node->right));
      count++;
      s->right = removeMin(node->right);
      s->left = node->left;
      delete node;
      count--;
      return s;
    }
    else if (node->key > key) {
      node->left = remove(node->left, key);
      return node;
    }
    else {
      node->right = remove(node->right, key);
      return node;
    }
  }
};

bool cmp_test(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}
