#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
    /** YOUR CODE HERE
    * vector<int> preorderTraversal(TreeNode* root) {
    *
    * }
    *
    * int leafNodesSum(TreeNode* root) {
    *
    * }
    *
    *
    */

    // Constructs the tree and returns a pointer on root
    TreeNode* constructTree(vector<int>& input) {
        if (input.empty()) {
        return nullptr;
        }

        TreeNode* root = new TreeNode(input[0]);

    // use a Queue to know what is the next node to construct
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < input.size()) {
            TreeNode* current = q.front();
            q.pop();

            if (input[i] != -1) {
                current->left = new TreeNode(input[i]);
                q.push(current->left);
            }
            i++;

            if (i < input.size() && input[i] != -1) {
                current->right = new TreeNode(input[i]);
                q.push(current->right);
            }
            i++;
        }
        return root;
    }
};

int main() {
    Solution solution;
    string inp;
    getline(cin, inp);
    istringstream iss(inp);
    vector<int> input;
    int num;

    while (iss >> num) {
        input.push_back(num);
    }

    TreeNode* root = solution.constructTree(input);

    /** YOUR CODE HERE
    * ?? = solution.preorderTraversal(root);
    * Print the traversal, integers separated by space
    *
    *
    */

    return 0;
}
