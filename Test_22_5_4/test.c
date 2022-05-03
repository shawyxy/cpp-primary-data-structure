//
// Created by 肖越 on 2022/5/3.
//
#include <stdio.h>
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    struct ListNode* cur1 = headA;
//    struct ListNode* cur2 = headB;
//    struct ListNode* cur11 = headA;
//    struct ListNode* cur22 = headB;
//    if (headA == NULL || headB == NULL)
//    {
//        return NULL;
//    }
//    int len1 = 0, len2 = 0;
//    //计算链表的长度
//    while (cur1)
//    {
//        len1++;
//        cur1 = cur1->next;
//    }
//    while (cur2)
//    {
//        len2++;
//        cur2 = cur2->next;
//    }
//    int k = abs(len1 - len2);//得出链表长度之差的绝对值
//    if (len1 > len2)
//    {
//        while (k--)
//        {
//            cur11 = cur11->next;
//        }
//    }
//    else
//    {
//        while (k--)
//        {
//            cur22 = cur22->next;
//        }
//    }
//    printf("%d\n", len1);
//    printf("%d\n", len2);
//
//    printf("%d\n", (cur11->val));
//    printf("%d\n", (cur22->val));
//
//    //此时两链表处于同一起始点（距离交点的长度）
//    while (cur11 && cur22)
//    {
//        if (cur11 != cur22)
//        {
//            cur11 = cur11->next;
//            cur22 = cur22->next;
//        }
//        else
//        {
//            return cur22;
//        }
//    }
//    return NULL;
//}
#include <stdio.h>
#define swap(n) (((n) & 0x55555555) << 1 | ((n) & 0xaaaaaaaa) >> 1)
int main()
{
    int n = 8888;
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", 1 & (n >> i));
    }
    printf("\n");
    int k = swap(n);
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", 1 & (k >> i));
    }
    printf("\n");
    return 0;
}