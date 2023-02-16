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
        int terms;

    public:
        Polynomial () {
            terms = 0;
            capacity = 0;
        }
        void LoadPolynomial(std::string& filename);
        void NewTerm(const int theCoef, const int theExp);
        void SortPolynomial();
        void PrintPolynomial();
        void add(Polynomial a, Polynomial b);
};
