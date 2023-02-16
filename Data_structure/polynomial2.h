class Polynomial;
class Term {
    friend Polynomial;
    private:
        int coef;
        int exp;
};
class Polynomial {
    private:
        Term *termArray;
        int capacity;
    public:
        void LoadPolynomial(std::string& filename);
        void SortPolynomial();
        void PrintPolynomial();
};
