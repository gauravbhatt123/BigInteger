#include "biginteger.h"
struct BigInteger initialize(char *a)
{
    struct BigInteger head;
    head.data = a[0] - '0';
    head.next = NULL;

    struct BigInteger *itr = &head;

    int i = 1;
    int value;

    while (i != strlen(a))
    {
        value = a[i] - '0';

        struct BigInteger *temp = (struct BigInteger *)malloc(sizeof(struct BigInteger));
        temp->data = value;
        temp->next = NULL;

        itr->next = temp;
        itr = temp;

        i++;
    }
    // printf("%d   ",i);

    struct BigInteger *temp = &head;
    // printf("%d",head.data);
    while(temp->data==0&&temp->next!=NULL)
    {
        temp=temp->next;
    }
    // if(!temp)
    // {
    //       struct BigInteger *temp1 = (struct BigInteger *)malloc(sizeof(struct BigInteger));
    //     temp1->data = 0;
    //     temp1->next = NULL;
    //     return *temp1;

    // }

    // display(*temp);

    // temp = reverse(&temp);
    // display(*temp);
    // temp = reverse(&temp);

    return *temp;
}

struct BigInteger *initializeq(char *a)
{
    struct BigInteger *head = NULL;

    int i = 0;
    int value;
    while (i != strlen(a))
    {
        value = a[i] - '0';
        struct BigInteger *temp = (struct BigInteger *)malloc(sizeof(struct BigInteger));
        temp->data = value;
        temp->next = NULL;
        if (!head)
        {
            head = temp;
            i++;
            continue;
        }
        struct BigInteger *itr = head;
        while (itr->next != NULL)
        {
            itr = itr->next;
        }
        itr->next = temp;
        i++;
    }


    return head;
}

void displayq(struct BigInteger *head)
{
    struct BigInteger *itr = head;
    while (itr)
    {
        printf("%d", itr->data);
        itr = itr->next;
    }
    printf("\n");
}
struct BigInteger *sumq(struct BigInteger *n1, struct BigInteger *n2)
{
    struct BigInteger *result = NULL;
    // display(n1);
    // display(n2);

    int carry = 0;

    int l1 = length(n1);
    int l2 = length(n2);
    if (l1 < l2)
    {

        result = sumq(n2, n1);
        return result;
    }
    struct BigInteger *itr;
    struct BigInteger *ptr1 = n1;
    struct BigInteger *ptr2 = n2;

    reverse(&n1);
    reverse(&n2);
    //   display(n1);
    // display(n2);

    ptr1 = n1;
    ptr2 = n2;
    // display(ptr2);

    while (ptr2 != NULL)
    {
        //   display(n1);
        //   display(n2);

        struct BigInteger *temp = (struct BigInteger *)malloc(sizeof(struct BigInteger));
        temp->data = ptr1->data + ptr2->data + carry;
        temp->next = NULL;
        carry = 0;
        if (temp->data > 9)
        {
            carry = 1;
            temp->data = temp->data - 10;
        }
        if (temp->data < 0)
        {
            temp->data += 10;
            carry = -1;
        }

        if (!result)
        {
            result = temp;
            itr = temp;
        }
        else
        {
            itr->next = temp;
            itr = temp;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    //   display(n1);
    // display(n2);

    if (ptr1)
    {
        while (ptr1 != NULL)
        {
            struct BigInteger *temp = (struct BigInteger *)malloc(sizeof(struct BigInteger));
            temp->data = ptr1->data + carry;
            temp->next = NULL;
            carry = 0;
            if (temp->data > 9)
            {
                carry = 1;
                temp->data = temp->data - 10;
            }
            if (temp->data < 0)
            {
                temp->data += 10;
                carry = -1;
            }
            itr->next = temp;
            itr = temp;
            ptr1 = ptr1->next;
        }
    }

    if (carry == 1)
    {
        struct BigInteger *temp = (struct BigInteger *)malloc(sizeof(struct BigInteger));
        temp->data = 1;
        temp->next = NULL;
        itr->next = temp;
    }
    //   display(n1);
    // display(n2);

    reverse(&n1);
    reverse(&n2);
    //   display(n1);
    // display(n2);

    reverse(&result);
    // display(result);
    return result;
}
struct BigInteger *sign(struct BigInteger *n1)
{
    struct BigInteger *itr = n1;
    while (itr != NULL)
    {

        itr->data = itr->data * (-1);
        itr = itr->next;
    }

    return n1;
}

void reverse(struct BigInteger **n1)
{
     
    //   printf("%d",(*n1)->data);
    if (!(*n1) || (*n1)->next == NULL)
    {
        return;
    }
    // printf("%d",(*n1)->data);
    // printf("hi");
    struct BigInteger *pre = *n1;
    struct BigInteger *curr = (*n1)->next;
    while (curr != NULL)
    {
        struct BigInteger *aft = curr->next;
        curr->next = pre;
        pre = curr;
        curr = aft;
    }
    (*n1)->next = NULL;
    (*n1) = pre;
    //   printf("hi1");
    // printf("%d",(*n1)->data);
    //   display(pre);
}

struct BigInteger *subq(struct BigInteger *n1, struct BigInteger *n2)
{
    struct BigInteger *result = NULL;
    int sign1;
    struct BigInteger *tempn1 = n1;
    struct BigInteger *tempn2 = n2;
    //   display(n1);
    //   display(n2);

    int l1 = length(n1);

    int l2 = length(n2);
    // printf("%d   %d\n",l1,l2);
    if (l1 > l2)
    {
        //  printf("TOH YE kuch   ");
        sign1 = 1;
    }
    else if (l1 < l2)
    {
        // printf("TOH YE");
        sign1 = -1;
    }
    else
    {
        // printf("TOH YE hoga ab fir\n");
        while (tempn1 != NULL)
        {
            if(tempn1->data == tempn2->data)
            {

            }
            else if (tempn1->data > tempn2->data)
            {
                sign1 = 1;
                break;
            }
            else if (tempn1->data < tempn2->data)
            {
                sign1 = -1;
                break;
            }
            tempn1 = tempn1->next;
            tempn2 = tempn2->next;
        }
        // printf("%d", sign1);
    }

    if (l1 > l2)
    {

        n2 = sign(n2);

        result = sumq(n1, n2);

        n2 = sign(n2);
    }
    else if (l2 < l1)
    {
        //    display(n1);

        n1 = sign(n1);
        // display(n1);

        result = sumq(n2, n1);

        n1 = sign(n1);
        // display(result);
    }
    else
    {
        if (sign1 == -1)
        {
            //    display(n1);

            n1 = sign(n1);
            // display(n1);

            result = sumq(n2, n1);

            n1 = sign(n1);
            // display(result);
        }
        else
        {
            //    display(n1);
            //   display(n2);
            // printf("HI");
            n2 = sign(n2);
            //  display(n1);
            //   display(n2);

            result = sumq(n1, n2);
            // display(result);

            n2 = sign(n2);
        }
    }
    while (result->data == 0&&result->next!=NULL)
    {
        result = result->next;
    }

    if (sign1 == -1)
    {
        result->data = -1 * result->data;
    }
    //   display(result);

    return result;
}

int length(struct BigInteger *n1)
{
    struct BigInteger *temp = n1;
    int num = 0;
    while (temp != NULL)
    {
        num++;
        temp = temp->next;
    }

    return num;
}

struct BigInteger *mulq(struct BigInteger *n1, struct BigInteger *n2)
{
    // Initialize the result with zero
    struct BigInteger *result = initializeq("0");
    if (n1->data == 0 || n2->data == 0)
    {
        return result;
    }

    struct BigInteger *temp2 = n2;
    int position = 0;
    // display(temp2);

    while (temp2 != NULL)
    {
        int digit = temp2->data;

        // Multiply n1 by a single digit from n2
        struct BigInteger *partialProduct = multiplyByDigit(n1, digit);

        // Display the intermediate result after each multiplication
        // display(partialProduct);

        // Shift the partial product left by the appropriate number of positions
        if (result)
        {
            struct BigInteger *zero = (struct BigInteger *)malloc(sizeof(struct BigInteger));
            zero->data = 0;

            struct BigInteger *itre = result;
            while (itre->next != NULL)
            {
                itre = itre->next;
            }
            itre->next = zero;
            zero->next = NULL;
        }

        // Add the partial product to the result
        result = sumq(result, partialProduct);

        // Move to the next digit in n2
        temp2 = temp2->next;

        // Increment the position
        position++;
    }
    // display(result);
    while (result->data == 0)
    {
        result = result->next;
    }
    return result;
}

// Function to multiply a big integer by a single digit
struct BigInteger *multiplyByDigit(struct BigInteger *n1, int digit)
{
    struct BigInteger *result = NULL;
    int carry = 0;
    //   display(n1);
    reverse(&n1);
    // display(n1);
    struct BigInteger *itr = n1;
    struct BigInteger *temp;

    while (itr != NULL)
    {
        struct BigInteger *newnode = (struct BigInteger *)malloc(sizeof(struct BigInteger));
        newnode->data = (digit * itr->data) + carry;
        carry = 0;
        if (newnode->data > 9)
        {
            carry = newnode->data / 10;
            newnode->data = newnode->data % 10;
        }
        itr = itr->next;
        if (!result)
        {
            result = newnode;
            temp = newnode;
            continue;
        }

        temp->next = newnode;
        temp = newnode;
    }
    if (carry > 0)
    {
        struct BigInteger *newnode = (struct BigInteger *)malloc(sizeof(struct BigInteger));
        newnode->data = carry;
        newnode->next = NULL;
        temp->next = newnode;
    }
    else
    {
        temp->next = NULL;
    }
    //     display(n1);
    reverse(&n1);
    reverse(&result);

    //   display(result);
    // display(n1);
    return result;
}

struct BigInteger* div1q(struct BigInteger* dividend, struct BigInteger* divisor) 
{
    if (!dividend || !divisor||divisor->data==0) {
        struct BigInteger *temp=(struct BigInteger *)malloc(sizeof(struct BigInteger));
        temp->data=0;
        temp->next=NULL;
        return temp;
    }

   long long int dividend_value = 0;
    long long int divisor_value = 0;

    while (dividend) {
        dividend_value = dividend_value * 10 + dividend->data;
        dividend = dividend->next;
    }

    while (divisor) {
        divisor_value = divisor_value * 10 + divisor->data;
        divisor = divisor->next;
    }

   long long int quotient = dividend_value / divisor_value;

    struct BigInteger *quotient_head = NULL;
    struct BigInteger *current = NULL;

    if (quotient == 0) {
        quotient_head = (struct BigInteger *)malloc(sizeof(struct BigInteger));
        quotient_head->data = 0;
        quotient_head->next = NULL;
        return quotient_head;
    }

    while (quotient > 0) {
      long long  int digit = quotient % 10;
        struct BigInteger *new_node = (struct BigInteger *)malloc(sizeof(struct BigInteger));
        new_node->data= digit;
        new_node->next = current;
        current = new_node;
        quotient /= 10;
    }

    return current;
}
struct BigInteger sub(struct BigInteger n1, struct BigInteger n2)
{
    struct BigInteger *out = subq(&n1, &n2);
    return *out;
}
struct BigInteger add(struct BigInteger n1, struct BigInteger n2)
{
    struct BigInteger *out = sumq(&n1, &n2);
    return *out;
}
void display(struct BigInteger n1)
{
    displayq(&n1);
}
int lengthq(struct BigInteger n1)
{
    int num = length(&n1);
    return num;
}
struct BigInteger signq(struct BigInteger n1)
{
    struct BigInteger *n2 = sign(&n1);
    return *n2;
}

void reverseq(struct BigInteger *head)
{
   
    reverse(&head);
    //  display(head);
}
struct BigInteger mul(struct BigInteger n1, struct BigInteger n2)
{
    struct BigInteger *out = mulq(&n1, &n2);
    return *out;
}
struct BigInteger multiplyByDigitq(struct BigInteger n1, int digit)
{
    struct BigInteger *out = multiplyByDigit(&n1, digit);
    return *out;
}


struct BigInteger div1(struct BigInteger n1, struct BigInteger n2)
{
    struct BigInteger *out =div1q(&n1,&n2);
    return *out;

}

struct BigInteger mod(struct BigInteger n1,struct BigInteger n2)
{
    struct BigInteger *out = modq(&n1,&n2);
    
    return *out;
}
struct BigInteger *modq(struct BigInteger *n1,struct BigInteger *n2)
{
    struct BigInteger *abc=div1q(n1,n2);
    // display(abc);
    struct BigInteger *pqr=mulq(abc,n2);
    // display(n1);
    //    display(pqr);
       

    struct BigInteger *out=subq(n1,pqr);
    // display(out);
    if(out->data<0)
    {
        out->data=-1*out->data;
        out=subq(n1,out);
        
    }
    // if(out->data==0)
    // {
    //     struct BigInteger *alt=(struct BigInteger *)malloc(sizeof(struct BigInteger));
    //     alt->data=0;
    //     alt->next=NULL;
    //     return alt;
    // }
    return out;
}