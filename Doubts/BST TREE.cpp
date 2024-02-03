//Write an algorithm to check whether the given binary tree is BST or not.
bool BSTorNot(Node *p)
{
    if(!(p->data > p->left) && p->left)
        return false;
    if(!(p->data < p->right) && p->right)
        return false;
    BSTorNot(p->left);
    BSTorNot(p->right);
    return true;
}

//Given a BST and a positive integer k, where k ≤ number of elements of the given BST. Write an algorithm 
// to find the kth -smallest element in the given BST. For example, the 4th smallest node in the following BST 
// is 15, and the 6th smallest is 20. The 8th smallest node does not exist
int k_ele(Node *p, int count)
{
    if(p)
    {
        k_ele(p->left, count);
        count--;
        k_ele(p->right, count);
    }
    else
        return -1;
    if (count == 0)
        return p->data;
}