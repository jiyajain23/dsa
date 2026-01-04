/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
        int ans=-1;
        if(!root) return 0;
        // parent map
        unordered_map<Node*,Node*> parent;
        queue<Node*> q;
        q.push(root);
        Node* tar;
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            if(curr->data==target) tar=curr;
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
        unordered_set<Node*> visited;
        q.push(tar);
        visited.insert(tar);
        while(!q.empty()){
            int size=q.size();
            ++ans;
            for(int i=0;i<size;i++ ){
                Node* temp=q.front();
                q.pop();
                if(parent.find(temp)!=parent.end() && visited.find(parent[temp])==visited.end()){
                    q.push(parent[temp]);
                    visited.insert(parent[temp]);
                }
                if(temp->left && visited.find(temp->left)==visited.end()){
                q.push(temp->left);
                visited.insert(temp->left);
                }
                if(temp->right && visited.find(temp->right)==visited.end()){
                q.push(temp->right);
                visited.insert(temp->right);
                }
        }
        }
        return ans;
    }
};