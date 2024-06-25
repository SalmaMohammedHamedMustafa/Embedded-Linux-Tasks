# Lambda function to set a bit
set_bit = lambda reg, bit: reg | (1 << bit)

# Lambda function to clear a bit
clear_bit = lambda reg, bit: reg & ~(1 << bit)

input = 0
output = 1

def GPIO_PORT_dir(pin, dir):
    """
    changes the direction of a pin in PORTA in ATmega32
    Parameters:
    pin number - required pin direction 
    returns:
    None
    """
    global DDRA

    if dir == output:
        DDRA = set_bit(DDRA,pin)

    else:
        DDRA = clear_bit(DDRA,pin)

    



if __name__ == "__main__":
    DDRA = 0x00
    print(f"DDRA before {bin(DDRA)}")
    GPIO_PORT_dir(1,input)
    GPIO_PORT_dir(2,output)
    print(f"DDRA after {bin(DDRA)}")

