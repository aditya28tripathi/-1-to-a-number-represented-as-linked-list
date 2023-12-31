class Solution
{
    public:
    
    Node *reverse(Node *head){
        Node *next=NULL;
        Node *prev = NULL;
        Node *cur=head;
        
        while(cur!=NULL){
            next = cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        
        return prev;
    }
    Node* addOne(Node *head) 
    {
       head = reverse(head);
       bool f = true;
       
       Node * cur = head;
       while(cur!=NULL && f==true){
           if(cur->next==NULL and cur->data==9){
               cur->data=1;
               Node *temp = new Node(0);
               temp->next=head;
               head=temp;
               cur=cur->next;
           }
           
           else if(cur->data==9){
               cur->data=0;
               cur=cur->next;
           }
           
           else{
               cur->data=cur->data+1;
               cur = cur->next;
               f = false;
           }
       }
       
       head = reverse(head);
       return head;
       
    }
};
