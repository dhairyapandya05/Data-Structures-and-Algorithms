class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        Node* dummy=new Node();
        Node* curr=dummy;
        for(auto& it:arr){
            Node* newNode = new Node(it);
            curr->next=newNode;
            curr=curr->next;
        }
        return dummy->next;
    }
};
// link:https://www.geeksforgeeks.org/problems/introduction-to-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-linked-list
