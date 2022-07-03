#include "BST.cpp"

int main()
{

  BST<int> tree;

  tree.insert(63);
  tree.insert(41);
  tree.insert(74);
  tree.insert(16);
  tree.insert(53);
  tree.insert(65);
  tree.insert(25);
  tree.insert(46);
  tree.insert(55);
  tree.insert(64);
  tree.insert(70);

  tree.traverse(InOrder); // 16, 25, 41, 46, 53, 55, 63, 64, 65, 70, 74.
  cout << endl;

  tree.traverse(PreOrder); //  63, 41, 16, 25, 53, 46, 55, 74, 65, 64, 70.
  cout << endl;

  tree.traverse(PostOrder); // 25, 16, 46, 55, 53, 41, 64, 70, 65, 74, 63.
  cout << endl;

  tree.traverse(LevelOrder); // 63 41 74 16 53 65 25 46 55 64 70
  cout << endl;

  cout << tree.contain(55) << endl;  // 1 true
  cout << tree.contain(111) << endl; // 0 false

  cout << tree.getLevel(16) << endl;             // 2
  cout << tree.getHeight(tree.findNode(41)) << endl; // 2

  tree.remove(16);
  cout << tree.contain(16) << endl; // 0 false
}