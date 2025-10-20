struct PolyNode
{
    double coef;
    int exp;
    PolyNode* next;
    PolyNode() :coef(0), exp(0), next(nullptr) {}
    PolyNode(double c, int e) {
        coef = c;
        exp = e;
        next = nullptr;
    }
};

class PolyList
{
public:
    PolyNode* head;
    PolyList() {
        head = new PolyNode();
    }
    ~PolyList() {
        PolyNode* pre = head;
        PolyNode* p = pre->next;
        while (p != nullptr) {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete pre;
    }
    void CreateList(const char* filename);
    void DispPoly() const;
    void Sort();
    void insertOrder(PolyNode* p);
    double value(double xValue);
};

void PolyAdd(const PolyList& A, const PolyList& B, PolyList& C);
void PolySubstract(const PolyList& A, const PolyList& B, PolyList& C);
void PolyMultiply(const PolyList& A, const PolyList& B, PolyList& C);
