#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "bst.h"
#include "structs.h"

struct Node
{
    TYPE value;
    struct Node* left;
    struct Node* right;
};

struct BSTree
{
    struct Node* root;
    int count;
};


/*----------------------------------------------------------------------------*/
//BINARY SEARCH TREE FUNCTIONS GO HERE
/*----------------------------------------------------------------------------*/

struct BSTree* newBSTree()						// Allocates and initializes the BST
{
    //printf("in new tree\n\n");
    struct BSTree* head=(BSTree*)malloc(sizeof(head));
    head->count=1;
    head->root=NULL;
    return head;
}

void inorder_delete(Node *node)
{
    if (node)
    {
        inorder_delete(node->left);
        inorder_delete(node->right);
        free(node);
    }
}

void inorder_print(Node* node)
{
    if(node)
    {
        inorder_print(node->left);
        //printf("%d ",*(int *)(node->value));
        print_type(node->value);
        inorder_print(node->right);
    }
}

void deleteBSTree(BSTree* myTree)				// Deallocate nodes in BST and deallocate the BST structure
{
    if(myTree->root)
        inorder_delete(myTree->root);
    free(myTree);
}

int isEmptyBSTree(BSTree* myTree)				// Returns "1" if the BST is empty or "0" if not
{
    if(myTree->count == 1)
        return 1;
    else
        return 0;

}
int sizeBBSTree(BSTree* myTree)				// Returns the size of the BST
{
    return myTree->count;
}
void addBSTree(BSTree* myTree, TYPE value)		// Adds an element into the BST
{
    //printf("in add\n\n");
    struct Node *node=(Node*)malloc(sizeof(node));
    node->value=value;
    node->left=NULL;
    node->right=NULL;
    if(!myTree->root)
    {
        myTree->root=node;
        return ;
    }
    struct Node *tmp=myTree->root;
    while(1)
    {
        if(compare(tmp->value, value)==-1)
        {
            if(tmp->right==NULL)
            {
                tmp->right=node;
                myTree->count+=1;
                break;
            }
            else
                tmp=tmp->right;
        }
        else if(compare(tmp->value, value)==1 || compare(tmp->value, value)==0)
        {
            if(tmp->left==NULL)
            {
                tmp->left=node;
                myTree->count+=1;
                break;
            }
            else
                tmp=tmp->left;
        }
    }
}
int containsBSTree(BSTree* myTree, TYPE value)	// Returns "1" if the BST contains the specified element or "0" if not
{
    struct Node *tmp=myTree->root;
    while(tmp!=NULL)
    {
        if(compare(tmp->value, value)==-1)
        {
            tmp=tmp->right;
        }
        else if(compare(tmp->value, value)==1)
        {
            tmp=tmp->left;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
TYPE minBSTree(BSTree* myTree)					// Returns the minimum value in the BST
{
    struct Node *tmp=myTree->root;
    while(tmp->left!=NULL)
        tmp=tmp->left;
    return tmp->value;
}
TYPE maxBSTree(BSTree* myTree)					// Returns the maximum value in the BST
{
    struct Node *tmp=myTree->root;
    while(tmp->right!=NULL)
        tmp=tmp->right;
    return tmp->value;
}

struct Node* deleteNode(struct Node* root, TYPE value)
{
    // base case
    //printf("%d  left:%d right:%d\n",*(int*)root->value,root->left,root->right);
    if (root == NULL)
        return root;

    if (compare(root->value, value)==1)
        root->left = deleteNode(root->left, value);
    else if (compare(root->value,value)==-1)
        root->right = deleteNode(root->right, value);
    else
    {
        if (root->right == NULL)
        {
            struct Node* tmp = root->left;
            free(root);
            return tmp;
        }
        else if (root->left == NULL)
        {
            struct Node* tmp = root->right;
            free(root);
            return tmp;
        }

        struct Node *tmp=root->left;
        while(tmp->right!=NULL)
            tmp=tmp->right;

        root->value = tmp->value;
        root->left = deleteNode(root->left, tmp->value);
    }
    return root;
}

void removeBSTree(BSTree *tree, TYPE value)	// Remove the specific element from the BST
{
    struct Node *tmp=tree->root;
    if(tmp->left==NULL && tmp->right==NULL)
    {
        if(compare(tree->root->value,value)==0)
        {
            free(tree->root);
            tree->root=NULL;
        }
    }
    if(containsBSTree(tree,value))
        tree->count--;
    tmp=deleteNode(tmp, value);

}
void printBSTree(BSTree* myTree)				// Prints the values in the BST.
{
    if(myTree->root)
    {
        inorder_print(myTree->root);
        printf("\n");
    }
    else
        printf("The tree is empty.\n");

}


/*----------------------------------------------------------------------------*/

// Test value stuff -----

struct TestValues
{
    struct data* values;
    int n;
};

void initValue(struct data* value, int number, const char* name)
{
    value->number = number;
    value->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(value->name, name);
}

void freeValue(struct data* value)
{
    free(value->name);
}

struct TestValues* createValues()
{
    struct TestValues* values = malloc(sizeof(struct TestValues));
    values->n = 4;
    values->values = malloc(values->n * sizeof(struct data));

    initValue(&(values->values[0]), 50, "rooty");
    initValue(&(values->values[1]), 13, "lefty");
    initValue(&(values->values[2]), 110, "righty");
    initValue(&(values->values[3]), 10, "lefty of lefty");

    return values;
}

void destroyValues(struct TestValues* values)
{
    for (int i = 0; i < values->n; ++i)
    {
        freeValue(&(values->values[i]));
    }
    free(values->values);
    free(values);
}

// -----

void printTestResult(int predicate, char *nameTestFunction, char *message)
{
    if (predicate)
        printf("%s(): PASS %s\n",nameTestFunction, message);
    else
        printf("%s(): FAIL %s\n",nameTestFunction, message);
}

/**
 * Tests adding 4 nodes to the BST.
 */
void testAddNode()
{
    struct TestValues* tv = createValues();
    struct BSTree *tree	= newBSTree();

    // Add all values to the tree
    for (int i = 0; i < tv->n; ++i)
    {
        addBSTree(tree, &(tv->values[i]));
        if (tree->count != i + 1)
        {
            printf("%d %d\n",tree->count,i+1);
            printf("addNode() test: FAIL to increase count when inserting\n");
            return;
        }
    }

    // Check that root node is root
    if (tree->root->value != &(tv->values[0]))
    {
        printf("addNode() test: FAIL to insert 50 as root\n");
        return;
    }
    else
    {
        printf("addNode() test: PASS when adding 50 as root\n");
    }

    if (tree->root->left->value != &(tv->values[1]))
    {
        printf("addNode() test: FAIL to insert 13 as left child of root\n");
        return;
    }
    else
    {
        printf("addNode() test: PASS when adding 13 as left of root\n");
    }

    if (tree->root->right->value != &(tv->values[2]))
    {
        printf("addNode() test: FAIL to insert 110 as right child of root\n");
        return;
    }
    else
    {
        printf("addNode() test: PASS when adding 110 as right of root\n");
    }

    if (tree->root->left->left->value != &(tv->values[3]))
    {
        printf("addNode() test: FAIL to insert 10 as left child of left of root\n");
        return;
    }
    else
    {
        printf("addNode() test: PASS when adding 10 as left of left of root\n");
    }

    deleteBSTree(tree);
    destroyValues(tv);
}

/**
 * Tests that the BST contains the added elements,
 * and that it does not contain an element that was not added.
 */
void testContainsBSTree()
{
    struct TestValues* tv = createValues();
    struct BSTree *tree	= newBSTree();

    // Create value not added to the tree
    struct data notInTree;
    notInTree.number = 111;
    notInTree.name = "not in tree";

    // Add all other values to the tree
    for (int i = 0; i < tv->n; ++i)
    {
        addBSTree(tree, &(tv->values[i]));
    }

    printTestResult(containsBSTree(tree, &(tv->values[0])), "containsBSTree", "when test containing 50 as root");
    printTestResult(containsBSTree(tree, &(tv->values[1])), "containsBSTree", "when test containing 13 as left of root");
    printTestResult(containsBSTree(tree, &(tv->values[2])), "containsBSTree", "when test containing 110 as right of root");
    printTestResult(containsBSTree(tree, &(tv->values[3])), "containsBSTree", "when test containing 10 as left of left of root");

    printTestResult(!containsBSTree(tree, &notInTree), "containsBSTree", "when test containing 111, which is not in the tree");

    deleteBSTree(tree);
    destroyValues(tv);
}

/**
 * Tests leftMost.
 */
void testMinMax()
{
    struct TestValues* tv = createValues();
    BSTree* tree	= newBSTree();

    for (int i = 0; i < tv->n; ++i)
    {
        addBSTree(tree, &(tv->values[i]));
    }

    if(compare(minBSTree(tree), &(tv->values[3])) == 0)
        printf("Test minBSTree(): PASS\n");
    else
        printf("Test minBSTree(): FAIL\n");

    if(compare(maxBSTree(tree), &(tv->values[2])) == 0)
        printf("Test maxBSTree(): PASS\n");
    else
        printf("Test maxBSTree(): FAIL\n");

    deleteBSTree(tree);
    destroyValues(tv);
}



/**
 * Tests removal of all nodes.
 */
void testRemoveBSTree()
{
    struct TestValues* tv = createValues();
    BSTree *tree= newBSTree();

    for (int i = 0; i < tv->n; ++i)
    {
        addBSTree(tree, &(tv->values[i]));
    }
    printf("Original tree:\n");
    printBSTree(tree);

    removeBSTree(tree, &tv->values[3]);
    printf("The tree below should not contain the value 10\n");
    printBSTree(tree);

    removeBSTree(tree, &tv->values[2]);
    printf("The tree below should not contain the value 110\n");
    printBSTree(tree);

    removeBSTree(tree, &tv->values[1]);
    printf("The tree below should not contain the value 13\n");
    printBSTree(tree);

    removeBSTree(tree, &tv->values[0]);
    printf("The tree below should be empty\n");
    printBSTree(tree);

    deleteBSTree(tree);
    destroyValues(tv);
}


// Main function for testing

int main(int argc, char *argv[])
{

    /* After implementing your code, you must uncomment the following calls to the test functions and test your code. Otherwise, you will not receive any
    points */

    testAddNode();

    testContainsBSTree();

    testMinMax();

    testRemoveBSTree();

    return 0;
}
