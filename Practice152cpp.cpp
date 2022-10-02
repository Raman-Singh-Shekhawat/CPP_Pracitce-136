// 153. Structurally identical: Given two generic trees, return true if they are structurally identical. Otherwise return false.

/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return NULL;
    }
    if (root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL)
    {
        return NULL;
    }
    if (root1->children.size() != root2->children.size())
    {
        return false;
    }

    for (int i = 0; i < root1->children.size(); i++)
    {
        bool ans = areIdentical(root1->children[i], root2->children[i]);
        if (ans == false)
        {
            return ans;
        }
    }
    return true;
}