/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* Reverse(Node* head)
{
    // Here we need two pointers to keep track of current and prev 
    // Locations of the Nodes to swap the prev & next pointers inside node.
    if(head == NULL)
        return head;
    Node* walk = NULL;
    while(head != NULL){
        walk = head;
        head = head->next;
        Node* temp = walk->next;
        walk->next  = walk->prev;
        walk->prev = temp;
    }
    return walk;
}
