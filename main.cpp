#include <iostream>
struct list{
    int field;
    struct list *next;
    struct list *prev;
};

struct list * init(list* lst, int a) {
    lst->field = a;
    lst->next = lst;
    lst->prev = lst;
    return(lst);
}
struct list* addelem(list *lst, int number){
    struct list *temp, *p;
    temp = (struct list*)malloc(sizeof(list));
    p = lst->next;
    lst->next = temp;
    temp->field = number;
    temp->next = p;
    temp->prev = lst;
    p->prev = temp;
    return(temp);
}

struct list* deletelem(list *lst){
    struct list *prev, *next;
    prev = lst->prev;
    next = lst->next;
    prev->next = lst->next;
    next->prev = lst->prev;
    free(lst);
    return(prev);
}

void listprint(list *lst){
    struct list *p;
    p = lst;
    do {
        printf("%d ", p->field);
        p = p->next;
    } while (p != lst);
}

void listprintr(list *lst){
    struct list *p;
    p = lst;
    do {
        p = p->prev;
        printf("%d ", p->field);
    } while (p != lst);
}
int main() {
    list* lst = new list;
    init(lst,10);
    addelem(lst,11);
    addelem(lst->next,12);
    addelem(lst->next->next,9);

    listprint(lst);
    std::cout << std::endl;

    deletelem(lst->next);
    listprint(lst);
    std::cout << std::endl;

    listprintr(lst);


    return 0;
}
