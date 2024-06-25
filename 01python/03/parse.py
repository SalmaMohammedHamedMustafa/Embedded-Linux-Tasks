import re
import csv

def parse_header_file(file_path):
    """
    reads the function prototypes
    parameters:
    the path of the header file
    return:
    list of prototypes
    """
    with open(file_path, 'r') as file:
        content = file.read()

    pattern = r'\b(?:void|int|char|float|double|unsigned|long|short|struct\s+\w+)\s+\w+\s*\([^;]*\);'
    prototypes = re.findall(pattern, content)

    return prototypes




def write_to_csv(prototypes, output_path):
    """
    writes the proteype and unique id into the csv file
    parameters:
    the path of the csv file and the prototype list
    return:
    None
    """
    with open(output_path, 'w', newline='') as csvfile:
        csvwriter = csv.writer(csvfile)


        csvwriter.writerow(['Function Prototype', 'Unique ID'])

        for idx, prototype in enumerate(prototypes, start=1):
            unique_id = f'IDX{idx:03d}'
            csvwriter.writerow([prototype, unique_id])



if __name__ == "__main__":
    header_file_path = 'DIO_interface.h' 
    output_csv_path = 'function_prototypes.csv'

    prototypes = parse_header_file(header_file_path)
    write_to_csv(prototypes, output_csv_path)
