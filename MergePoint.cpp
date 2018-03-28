#include <unordered_set>


int FindMergeNode(Node *headA, Node *headB)
{
   
    unordered_set<Node*> myset;
    while(headA != NULL && headB != NULL){
        if(headA == headB)
            return headA->data;
        if(myset.find(headA) != myset.end())
            return headA->data;
        if(myset.find(headB)!= myset.end())
            return headB->data;
        myset.insert(headA);
        myset.insert(headB);
        headA = headA->next;
        headB = headB->next;
    }
    while(headA != NULL){
        if(myset.find(headA) != myset.end())
            return headA->data;
        headA = headA->next;
    }
    while(headB != NULL){
        if(myset.find(headB) != myset.end())
            return headB->data;
        headB = headB->next;
    }
    return -1;
}


