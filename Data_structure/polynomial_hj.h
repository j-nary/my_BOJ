class Polynomial {
private:
    int n;
    int tempa,tempb;
    int arr[100]={0};
public:
    void LoadPolynomial(std::string& filename);
    void PrintPolynomial(); 
    void add(Polynomial a, Polynomial b);

};