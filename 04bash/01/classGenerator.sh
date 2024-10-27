#!/bin/bash

# Prompt for class name
read -r -p "Please enter your class name: " class_name
read -r -p "Do you want a namespace? (y/n): " want_namespace

# Initialize namespace variable
namespace=""

# If user wants a namespace, prompt for it
if [ "$want_namespace" = "y" ]; then
    read -r -p "Please enter your namespace: " namespace
fi

# Generate the class header
if [ -n "$namespace" ]; then
    class_header=$(cat <<EOF
#ifndef ${class_name}_HPP
#define ${class_name}_HPP

namespace ${namespace} {

class ${class_name} {
public:
    ${class_name}();
    ~${class_name}();
};

} // namespace ${namespace}

#endif // ${class_name}_HPP
EOF
    )
else
    class_header=$(cat <<EOF
#ifndef ${class_name}_HPP
#define ${class_name}_HPP

class ${class_name} {
public:
    ${class_name}();
    ~${class_name}();
};

#endif // ${class_name}_HPP
EOF
    )
fi

# Generate the class implementation
if [ -n "$namespace" ]; then
    class_implementation=$(cat <<EOF
#include "${class_name}.hpp"

namespace ${namespace} {

${class_name}::${class_name}() {
    // Constructor implementation
}

${class_name}::~${class_name}() {
    // Destructor implementation
}

} // namespace ${namespace}
EOF
    )
else
    class_implementation=$(cat <<EOF
#include "${class_name}.hpp"

${class_name}::${class_name}() {
    // Constructor implementation
}

${class_name}::~${class_name}() {
    // Destructor implementation
}
EOF
    )
fi

# Create a directory named after the class
mkdir -p "$class_name"

# Optionally, write to header and implementation files inside the new directory
read -r -p "Do you want to save the header and implementation to files? (y/n): " save_to_file
if [ "$save_to_file" = "y" ]; then
    echo "$class_header" > "${class_name}/${class_name}.hpp"
    echo "$class_implementation" > "${class_name}/${class_name}.cpp"
    echo "Class header saved to ${class_name}/${class_name}.hpp"
    echo "Class implementation saved to ${class_name}/${class_name}.cpp"
fi