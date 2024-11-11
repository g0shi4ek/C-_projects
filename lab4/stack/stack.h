#ifndef MyStack_h           // защита от повторной компиляции
#define MyStack_h           // модуль подключен

// Шаблонный класс ListNode (узел односвязного списка)
template<class INF, class FRIEND>
class ListNode{              // узел списка
   private:
    INF d;                  // информационная часть узла
    ListNode *next;         // указатель на следующий узел списка
    ListNode(void) { next = nullptr; } //конструктор
    friend FRIEND;
};
// Шаблонный класс MyStack на основе односвязного списка.
template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node *top;
public:
    MyStack(void) {
        top = nullptr;
    };           // конструктор

    MyStack(MyStack &st) {
        MyStack<INF> *temp = nullptr;
        while (!this->empty()) {
            temp->push(this->top_inf());
            this->pop();
        }
        while (!temp->empty()) {
            st.push(temp->top_inf());
            this->push(temp->top_inf());
            this->pop();
        }
    };

    ~MyStack(void){
        while (!this->empty()) {
            this->pop();
        }
        delete this->top;
    };          // освободить динамическую память


    bool empty(void) {
        return top == nullptr;
    };        // стек пустой?


    bool push(INF n) {
        Node *new_node = new Node;
        new_node->d = n;
        new_node->next = top;
        top = new_node;
        return true;
    };        // добавить узел в вершину стека
    bool pop(void) {
        if (top != nullptr) {
            Node *del_node = top;
            top= del_node->next;
            delete del_node;
            return true;
        }
        return false;
    };        // удалить узел из вершины стека

    INF top_inf(void) {
        return top->d;
    };      // считать информацию из вершины стека

};
#endif