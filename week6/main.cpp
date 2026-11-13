//
//  main.cpp
//  Exercise6.12_BST_Search_Insert
//
//  Created by Fettah KIRAN on 10/28/21.
//

#include <iostream>
#include "binaryTree.h"

using namespace std;

int main()
{
   //use this code for test case or change for your own testing
   binaryTree<int> test;
   
   cout << test.treeHeight() << endl;
   
   if(test.isEmpty())
      cout << "Tree is empty." << endl;
      
   // test.insert(1);
   // test.insert(2);
   // test.insert(3);
   // test.insert(4);
   // test.insert(5);
   // test.insert(6);



   // Insert in order: 15, 10, 20, 8, 12, 17, 25

   test.insert(15);
   test.insert(10);
   test.insert(20);
   test.insert(8);
   test.insert(12);
   test.insert(17);
   test.insert(25);

   // test.deleteNode(10);
   
   cout << "preorderTraversal" << endl;
   test.preorderTraversal();

   cout << "\ninorderTraversal" << endl;
   test.inorderTraversal();

   cout << "\npostorderTraversal" << endl;
   test.postorderTraversal();
   
   return 0;
}
