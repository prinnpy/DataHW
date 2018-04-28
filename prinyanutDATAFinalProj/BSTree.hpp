//To be used in conjunction with BSTree.h and Node.h
//When you modify this, please add your name and list any changes that you made
//A few member functions have been left blank so you, the student can implemement

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#ifndef functions_hpp_include
#define functions_hpp_include

#include "BSTree.h"

// Constructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::BSTree() {
	root = nullptr;
}

// Destructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::~BSTree() {
    if (root !=nullptr)
        freeNode(root);
}

// Free the node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::freeNode(Node<DATATYPE, KEYTYPE> * leaf)
{
    //MY CODE:
    
    //delete
    if (root() == leaf)
        delete leaf;
    
	//check for null
    if (leaf == nullptr)
        return;
    
    //traverse left and right
    freeNode(leaf->Left());
    freeNode(leaf->Right());
    
    
}

// Add a node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, DATATYPE &data)
{
	if (Root() == nullptr)
	{
		Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
		newNodePtr->setKey(key);
		newNodePtr->setData(data);
		root = newNodePtr;
		root->setParent(root);

	}
	else
		addNode(key, root, data);
}

// Add a node (private)
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data) {
	
    //MY CODE: adding to left side
    if (key < leaf->Key()) {
        if (leaf->Left() != nullptr)
            addNode(key, leaf->Left(), data);
        else {
            Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
            newNodePtr->setKey(key);
            newNodePtr->setData(data);
            leaf->setLeft(newNodePtr);
            newNodePtr->setParent(leaf);
        }
    }
    
    //MY CODE: adding to right side
    if (key >= leaf->Key()) {
        if (leaf->Right() != nullptr)
            addNode(key, leaf->Right(), data);
        else {
            Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
            newNodePtr->setKey(key);
            newNodePtr->setData(data);
            leaf->setRight(newNodePtr);
            newNodePtr->setParent(leaf);
        }
    }
			
}

template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key)
{
	return findNode(key, root);
}

// Find a node
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node)
{
    //MY CODE:
    //return right node
    if (node == nullptr || node->Key() == key)
        return node;
    //check left
    if (node->Key() < key)
        return findNode(key, node->Right());
    
    //check right
    return findNode(key, node->Left());
	
}

//MY CODE: print for actor
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printActorInorder()
{
	printActorInorder(root);
}

//MY CODE: print for pictures
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printPicturesInorder()
{
    printPicturesInorder(root);
}

//MY CODE: print for actor
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printActorInorder(Node<DATATYPE, KEYTYPE> * node)
{
    //MY CODE: check for null
    if (node == nullptr)
        return;
    
    //MY CODE: go to left
    printActorInorder(node->Left());
    
    //MY CODE: print data
    printActor(cout, node->Data());
    
    //MY CODE: go to right
    printActorInorder(node->Right());

}

//MY CODE: print for pictures
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printPicturesInorder(Node<DATATYPE, KEYTYPE> * node)
{
    //MY CODE: check for null
    if (node == nullptr)
        return;
    
    //MY CODE: go to left
    printPicturesInorder(node->Left());
    
    //MY CODE: print data
    printPictures(cout, node->Data());
    
    //MY CODE: go to right
    printPicturesInorder(node->Right());
    
}

//MY CODE: print actor
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printActor(ostream & out, const DATATYPE & data)
{
	out << data.name << ", " << data.year << ", " << data.winner << ", " << data.award << ", " << data.film << endl;
}

//MY CODE: print pictures
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printPictures(ostream & out, const DATATYPE & data)
{
    out << data.name << ", " << data.year << ", " << data.nominations << ", " << data.rating << ", " << data.duration << ", " << data.genre1 << ", " << data.genre2 << ", " << data.release << ", " << data.metacritic << ", " << data.synopsis << endl << endl;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::deleteNode(KEYTYPE key)
{
    setRoot(deleteNode(Root(), key));
}

//deleteNode (Private)
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::deleteNode(Node<DATATYPE, KEYTYPE> * aRoot,KEYTYPE value)
{
   
	/* Given a binary search tree and a key, this function deletes the key
	and returns the new root */
	
	// base case
	if (aRoot == nullptr) return aRoot;

	// If the key to be deleted is smaller than the aRoot's key,
	// then it lies in left subtree
	if (value < aRoot->Key())
		aRoot->setLeft(deleteNode(aRoot->Left(), value));

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (value > aRoot->Key())
		aRoot->setRight(deleteNode(aRoot->Right(), value));

	// if key is same as root's key, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (aRoot->Left() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Right();
			delete aRoot;
			return temp;
		}
		else if (aRoot->Right() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Left();
			delete aRoot;
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		Node<DATATYPE, KEYTYPE> * temp = min(aRoot->Right());

		// Copy the inorder successor's content to this node
		aRoot->setKey(temp->Key());
		aRoot->setData(temp->Data());

		// Delete the inorder successor
		aRoot->setRight(deleteNode(aRoot->Right(), temp->Key()));
	}
	return aRoot;
}


// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::min(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * current = node;

	/* loop down to find the leftmost leaf */
	while (current->Left() != nullptr)
		current = current->Left();

	return current;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::max(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * tempNode = node;
	if (node == nullptr)
		tempNode = nullptr;
	else if (node->Right())
		tempNode = max(node->Right());
	else
		tempNode = node;

	return tempNode;
}

#endif /* functions_h */
