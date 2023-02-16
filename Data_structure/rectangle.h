class Rectangle
{
    private:
        int width;
        int height;
    
    public:
        Rectangle() {
            width = 0;
            height = 0;
        }
        Rectangle(int a = 0, int b = 0) {
            if ( a < 0 ) a = 0;
            if ( b < 0 ) b = 0;
            width = a;
            height = b;
        }
        int area();
        int perimeter();
};
