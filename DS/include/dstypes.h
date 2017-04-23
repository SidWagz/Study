#ifndef DSTYPES_H
#define DSTYPES_H

typedef int bool;
#define true 1
#define false 0

// Define new node definition
// Store void type data
// next is pointer to next node in chain
typedef struct SingleNode SingleNode;
struct SingleNode
{
	void* val;
	SingleNode* next;
};

// Define new node struct type
// with void value type
// for two way access on list
typedef struct DoubleNode DoubleNode;
struct DoubleNode
{
	void *val;
	DoubleNode *prev;
	DoubleNode *next;
};

// Define new node struct type
// for basic binary tree
typedef struct BasicBinaryTreeNode BasicBinaryTreeNode;
struct BasicBinaryTreeNode
{
	void *val;
	BasicBinaryTreeNode *left;
	BasicBinaryTreeNode *right;
};

#endif