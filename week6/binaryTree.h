#include <iostream>
#include <cassert>

using namespace std;

#ifndef BINTREE_H
#define BINTREE_H

template <class elemType>
struct binaryTreeNode
{
   elemType info;
   binaryTreeNode<elemType> *llink;
   binaryTreeNode<elemType> *rlink;
};

template <class elemType>
class binaryTree {
private:
   binaryTreeNode<elemType> *root;
   int height(binaryTreeNode<elemType> *p) const;
   int max(int x, int y) const;
   void inorder(binaryTreeNode<elemType> *p) const;
   void preorder(binaryTreeNode<elemType> *p) const;
   void postorder(binaryTreeNode<elemType> *p) const;
   void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot, binaryTreeNode<elemType>* otherTreeRoot);
   void destroy(binaryTreeNode<elemType>* &p);
   void deleteFromTree(binaryTreeNode<elemType>* &p);
   
public:
   binaryTree();
   binaryTree(const binaryTree&);
   const binaryTree<elemType>& operator=(const binaryTree<elemType>&);
   bool isEmpty() const;
   void inorderTraversal() const;
   void preorderTraversal() const;
   void postorderTraversal() const;
   int treeHeight() const;
   bool search(const elemType& searchItem) const;
   void insert(const elemType& insertItem);
   void deleteNode(const elemType& deleteItem);
   void destroyTree();
   ~binaryTree();
};

#endif

template <class elemType>
binaryTree<elemType>::binaryTree()
{
   root = NULL;
}

template <class elemType>
binaryTree<elemType>::binaryTree(const binaryTree<elemType>& otherTree)
{
   if (otherTree.root == NULL) //otherTree is empty
      root = NULL;
   else
      copyTree(root, otherTree.root);
}

template <class elemType>
const binaryTree<elemType>& binaryTree<elemType>::operator=(const binaryTree<elemType>& otherTree)
{
   if (this != &otherTree) //avoid self-copy
   {
      if (root != NULL) //if the binary tree is not empty, destroy the binary tree
         destroy(root);
      if (otherTree.root == NULL) //otherTree is empty
         root = NULL;
      else
         copyTree(root, otherTree.root);
   }
   return *this;
}

template <class elemType>
void binaryTree<elemType>::copyTree(binaryTreeNode<elemType>* &copiedTreeRoot, binaryTreeNode<elemType>* otherTreeRoot)
{
   if (otherTreeRoot == NULL)
      copiedTreeRoot = NULL;
   else
   {
      copiedTreeRoot = new binaryTreeNode<elemType>;
      copiedTreeRoot->info = otherTreeRoot->info;
      copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
      copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
   }
} 

template <class elemType>
bool binaryTree<elemType>::isEmpty() const
{
   return(root == NULL);
}

template <class elemType> 
int binaryTree<elemType>::height(binaryTreeNode<elemType> *p) const
{
if (p == NULL)
   return 0;
else
    return 1 + max(height(p->llink), height(p->rlink));  
}

template <class elemType>
int binaryTree<elemType>::max(int x, int y) const
{
   if (x >= y)
      return x;
   else
      return y;
}

template <class elemType> 
int binaryTree<elemType>::treeHeight() const
{
   return height(root);
}

template <class elemType>
void binaryTree<elemType>::inorderTraversal() const
{
   inorder(root);
}

template <class elemType>
void binaryTree<elemType>::preorderTraversal() const
{
   preorder(root);
}

template <class elemType>
void binaryTree<elemType>::postorderTraversal() const
{
   postorder(root);
}

template <class elemType>
void binaryTree<elemType>::inorder(binaryTreeNode<elemType> *p) const
{
   if (p != NULL)
   {
      inorder(p->llink);
      cout << p->info << " ";
      inorder(p->rlink);
   }
}

template <class elemType>
void  binaryTree<elemType>::preorder(binaryTreeNode<elemType> *p) const
{
   if (p != NULL)
   {
      cout << p->info << " ";
      preorder(p->llink);
      preorder(p->rlink);
   }
}

template <class elemType>
void binaryTree<elemType>::postorder(binaryTreeNode<elemType> *p) const
{
   if (p != NULL)
   {
      postorder(p->llink);
      postorder(p->rlink);
   cout << p->info << " ";
   }
}

template <class elemType>
bool binaryTree<elemType>::search(const elemType& searchItem) const
{
   binaryTreeNode<elemType> *current;
   bool found = false;
   if (root == NULL)
      cerr << "Cannot search the empty tree." << endl;
   else
   {
      current = root;
      while (current != NULL && !found)
      {
         if (current->info == searchItem)
            found = true;
         else if (current->info > searchItem)
            current = current->llink;
         else
         current = current->rlink;
      }
   }
   return found;
}

template <class elemType>
void binaryTree<elemType>::insert(const elemType& insertItem)
{
   binaryTreeNode<elemType> *current; //pointer to traverse the tree
   binaryTreeNode<elemType> *trailCurrent; //pointer behind current
   binaryTreeNode<elemType> *newNode; //pointer to create the node
   
   newNode = new binaryTreeNode<elemType>;
   assert(newNode != NULL);
   newNode->info = insertItem;
   newNode->llink = NULL;
   newNode->rlink = NULL;
   
   if (root == NULL)
      root = newNode;
   else
   {
      current = root;
      while (current != NULL)
      {
         trailCurrent = current;
         if (current->info == insertItem)
         {
            cerr << "The insert item is already in the list-";
            cerr << "duplicates are not allowed." << insertItem << endl;
            return;
         }
      else if (current->info > insertItem)
         current = current->llink;
      else
         current = current->rlink;
      }
      if (trailCurrent->info > insertItem)
         trailCurrent->llink = newNode;
      else
         trailCurrent->rlink = newNode;
   }
}

template <class elemType>
void binaryTree<elemType>::destroy(binaryTreeNode<elemType>* &p)
{
   if (p != NULL)
   {
      destroy(p->llink);
      destroy(p->rlink);
      delete p;
      p = NULL;
   }
}

template <class elemType>
void binaryTree<elemType>::destroyTree()
{
   destroy(root);
}

template <class elemType>
binaryTree<elemType>::~binaryTree()
{
   destroy(root);
}

template <class elemType>
void binaryTree<elemType>::deleteFromTree(binaryTreeNode<elemType>* &p)
{
   binaryTreeNode<elemType> *current;//pointer to traverse the tree
   binaryTreeNode<elemType> *trailCurrent; //pointer behind current
   binaryTreeNode<elemType> *temp; //pointer to delete the node
   
   if (p == NULL)
      cerr << "Error: The node to be deleted is NULL." << endl;
   else if(p->llink == NULL && p->rlink == NULL)
   {
      temp = p;
      p = NULL;
      delete temp;
   }
   else if(p->llink == NULL)
   {
      temp = p;
      p = temp->rlink;
      delete temp;
   }
   else if(p->rlink == NULL)
   {
      temp = p;
      p = temp->llink;
      delete temp;
   }
   else
   {
      current = p->llink;
      trailCurrent = NULL;
      while (current->rlink != NULL)
      {
         trailCurrent = current;
         current = current->rlink;
      }//end while
      p->info = current->info;
      if (trailCurrent == NULL) //current did not move; current == p->llink; adjust p
         p->llink = current->llink;
      else
         trailCurrent->rlink = current->llink;
      delete current;
   }
}

template <class elemType>
void binaryTree<elemType>::deleteNode(const elemType& deleteItem)
{
   binaryTreeNode<elemType> *current; //pointer to traverse the tree
   binaryTreeNode<elemType> *trailCurrent; //pointer behind current
   bool found = false;
   if (root == NULL)
      cout << "Cannot delete from the empty tree." << endl;
   else
   {
      current = root;
      trailCurrent = root;
      while (current != NULL && !found)
      {
         if (current->info == deleteItem)
            found = true;
         else
         {
            trailCurrent = current;
            if (current->info > deleteItem)
               current = current->llink;
            else
               current = current->rlink;
         }
      }//end while
      if (current == NULL)
         cout << "The delete item is not in the tree." << endl;
      else if (found)
      {
         if (current == root)
            deleteFromTree(root);
         else if (trailCurrent->info > deleteItem)
            deleteFromTree(trailCurrent->llink);
         else
            deleteFromTree(trailCurrent->rlink);
      }
   }
}