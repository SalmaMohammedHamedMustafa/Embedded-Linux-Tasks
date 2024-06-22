import math

def circle_area(radius):
    area = math.pi * radius**2
    return area

r = float(input("Enter the radius: "))
print(f"The circle area is {circle_area(r)}")
