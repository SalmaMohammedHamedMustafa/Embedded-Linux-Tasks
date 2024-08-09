class String {
    char* str=nullptr;
    int size;

public:
    String(char *input_str);
    String(const String &obj);
    ~ String();
    void printS();
    String& operator=(const String& obj);
    String& operator=(char* input_str);
};

