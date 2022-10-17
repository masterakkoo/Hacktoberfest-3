// algo
// 1.intitially we made a queue ;
// 2.then put inside it root and the null
// 3.start traversing in that queue // ROOT NULL
// 4.when we get a no. we will check for its left and right child if exist the push them in queue and pop the element
// 5.and if we get a NUll the we will check that if there is any elemnt in queue if yes then pop the null and push it in front;
// 6.if not then we can come out
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right;
    node *left;
    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
void flat(node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if (root->left != NULL)
    {
        flat(root->left);
        node *temp = root->right;
        root->right = root->left;
        root->left = NULL;
        node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp;
    }
    flat(root->right);
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    flat(root);
    cout << root->data << " " << root->right->data << " " << root->right->right->data << " " << root->right->right->right->data << " "<<root->right->right->right->right->data<<" "<<root->right->right->right->right->right->data  ;
    return 0;
}