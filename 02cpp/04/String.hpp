class String {
private:
    char* str=nullptr;
    int size=0;

public:
    String();
    String(char *InputStr);
    String(const String &obj);
    ~ String();
    void printS();
    int GetSize(const String& obj) const;
    String& operator=(const String& obj);
    String& operator=(char* InputStr);
    String operator+(const String& obj) const;
    String operator+(char* InputStr) const;
    String& operator+=(const String& obj);
    bool operator==(const String& obj) const;
    bool operator==(char* InputStr) const;
    bool operator!=(const String& obj) const;
    bool operator!=(char* InputStr) const;
    bool operator<(const String& obj) const;
    bool operator>(const String& obj) const;
    bool operator<=(const String& obj) const;
    bool operator>=(const String& obj) const;
};

