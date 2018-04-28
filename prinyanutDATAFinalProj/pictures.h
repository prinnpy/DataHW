/*
 Name: Prinn Prinyanut
 Class: CSCI 2421
 Description: Oscar's Database final project
 Due Date: May 2 2018
 */

#ifndef pictures_h
#define pictures_h

//includes
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Node.h"
#include "BSTree.h"
#include "BSTree.hpp"
#include "extraFunctions.h"

//add (worked!)
void picturesAdd(BSTree<PictureData, string> *pictureTree);
//modify (worked!)
void picturesModify(BSTree<PictureData, string> *pictureTree);
//delete (worked!)
void picturesDelete(BSTree<PictureData, string> *pictureTree);
//sort (worked!)
void picturesSort(BSTree<PictureData, string> *pictureTree);
void bstToVector(Node<PictureData, string> *pictureNode, vector<PictureData> &v);
//complete (worked!)
void picturesCompleteSearch(BSTree<PictureData, string> *pictureTree);
void foundCompleteIntSearch(Node<PictureData, int> *pictureNode, vector<PictureData> &v, int value);
void foundCompleteDoubleSearch(Node<PictureData, double> *pictureNode, vector<PictureData> &v, double value);
void foundCompleteStringSearch(Node<PictureData, string> *pictureNode, vector<PictureData> &v, string value);
void secondCompleteSearch(vector<PictureData> &v);
//partial search (worked!)
void picturesPartialSearch(BSTree<PictureData, string> *pictureTree);
void foundPartialIntSearch(Node<PictureData, int> *pictureNode, vector<PictureData> &v, int value);
void foundPartialDoubleSearch(Node<PictureData, double> *pictureNode, vector<PictureData> &v, double value);
void foundPartialStringSearch(Node<PictureData, string> *pictureNode, vector<PictureData> &v, string value);
void secondPartialSearch(vector<PictureData> &v);
//print to file (worked!)
void writePicturesDatabase(BSTree<PictureData, string> *pictureTree);

#endif /* pictures_h */
