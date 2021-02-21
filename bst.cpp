#include <iostream>
#include <fstream>
#include <sstream> 
#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}



// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    
    inorder(root->left);

    
    cout << root->key << " -> ";

    
    inorder(root->right);
  }
}


// Preorder traversal
void preorder(struct node *root) {
  if (root != NULL) {
  	 
    cout << root->key << " -> ";
    
    preorder(root->left);
    
    preorder(root->right);
  }
}

// Postorder traversal
void postorder(struct node *root) {
  if (root != NULL) {
  	
    
    postorder(root->left);
    
    postorder(root->right);
    
    cout << root->key << " -> ";
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  
  if (node == NULL) return newNode(key);

  
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}



struct node *minValueNode(struct node *node) {
  struct node *current = node;

  
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  
  if (root == NULL) return root;

  
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);


    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

 struct node *root = NULL;
 
void read()
{
    string myText;
    int n = 0;

    ifstream file;
    file.open("input.txt");
    
    int x = 0;

    while (getline(file, myText))
    {
    	stringstream integer(myText);
    	integer>>x;
		root = insert(root, x);
	
		
    }
    
    file.close();
}

// Driver code
int main() {
  //root = insert(root, 8);
  //root = insert(root, 3);
  //root = insert(root, 1);
  //root = insert(root, 6);
  //root = insert(root, 7);
  //root = insert(root, 10);
  //root = insert(root, 14);
  //root = insert(root, 4);
	read();
  cout << "Preorder traversal: ";
  
	preorder(root);
  cout << "\nAfter deleting 10\n";
  root = deleteNode(root, 10);
  cout << "Preorder traversal: ";
  preorder(root);
  
   cout <<endl<<endl<< "Postorder traversal: ";
  
	postorder(root);
  cout << "\nAfter deleting 3\n";
  root = deleteNode(root, 3);
  cout << "Postorder traversal: ";
  postorder(root);
  
   cout <<endl<<endl<< "Inorder traversal: ";
  
	inorder(root);
  cout << "\nAfter deleting 6\n";
  root = deleteNode(root, 6);
  cout << "Inorder traversal: ";
  inorder(root);
}
