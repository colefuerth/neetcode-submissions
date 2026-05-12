class LinkedList {
   private:
    struct Node {
        struct Node* next;
        int val;
    }* head;

   public:
    LinkedList() : head(nullptr) {}

    int get(int index) {
        cout << "get " << index << endl;
        for (struct Node* i = head; i != nullptr; i = i->next) {
            if (index-- == 0) {
                return i->val;
            }
        }
        return -1;
    }

    void insertHead(int val) {
        cout << "insertHead " << val << endl;
        struct Node* h = (struct Node*)calloc(1, sizeof(struct Node));
        h->next = head;
        head = h;
        head->val = val;
    }

    void insertTail(int val) {
        cout << "insertTail " << val << endl;
        if (head == nullptr) {
            insertHead(val);
            return;
        }
        struct Node* i = head;
        for (; i->next != nullptr; i = i->next);
        i->next = (struct Node*)calloc(1, sizeof(struct Node));
        i->next->val = val;
    }

    bool remove(int index) {
        cout << "remove " << index << endl;
        if (head == nullptr) {
            return false;
        }
        if (index == 0) {
            struct Node* h = head->next;
            free(head);
            head = h;
            return true;
        }
        for (struct Node* i = head; i->next != nullptr && index > 0; i = i->next) {
            if (index-- == 1) {
                struct Node* p = i->next;
                i->next = i->next->next;
                free(p);
                return true;
            }
        }
        return false;
    }

    vector<int> getValues() {
        cout << "getValues" << endl;
        vector<int> v;
        for (struct Node* i = head; i != nullptr; i = i->next) {
            v.push_back(i->val);
        }
        return v;
    }
};
