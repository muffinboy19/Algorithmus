#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        val = val;
        left=right=nullptr;
    }
};


/*
here in this code we are oging to use the inorder taversal 
for finding the kth smllest elmetn 

*/



/*

ALGRORITHM:

inorder traversl usign the reccvursve apprcoh 
first you check if hte current noes is  null then return;
now call teh same fucntion for the lefft part of the tree

then push the value bcz now its trun of root to be pushed

now call the same fucntion ffor hte righ  part of the 
tree

now return;;




*/

void inorder(TreeNode* root,int& ksmall,int& k,int& counter){

    if(!root || counter>=k){
        return;
    }

    inorder(root->left,ksmall,k,counter);
    counter++;
    if(counter==k){

        ksmall = root->val;
        return;
    }

    inorder(root->right,ksmall,k,counter);



}
void postorder(TreeNO)
int findKth(TreeNode* root,int k){

    int ksmallest = INT_MIN;
    int ss = k;
    int counter= 0;
    inorder(root,ksmallest,k,counter);

    int kmax = INT_MAX;
    int ct =0;
    postorder(root,kmax,ss,counter);





    // 
}

