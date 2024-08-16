#ifndef DRAWABLE_H
#define DRAWABLE_H

class Drawable 
{
public:
    virtual void draw() = 0;    
};

class Circle : public Drawable
{
public:
    void draw() override;
};

class Square : public Drawable
{
public:
    void draw() override;
};

class Triangle : public Drawable
{
public:
    void draw() override;
};
#endif // DRAWABLE_H