# Here's a more comprehensive example of a shell script that includes variables, conditionals, loops, arrays, and functions:

#!/bin/bash

# Example Shell Script with Variables, Conditionals, Loops, Arrays, and Functions

# Declare and initialize variables
name="John"
age=30
marks=(90 85 95 78 89)
totalMarks=0

# Conditional statement
if [ $age -ge 18 ]; then
    echo "Hello $name! You are an adult."
else
    echo "Hello $name! You are a minor."
fi

# Loop through an array
echo "Marks obtained:"
for mark in "${marks[@]}"; do
    echo $mark
    totalMarks=$((totalMarks + mark))
done

# Calculate average marks
averageMarks=$((totalMarks / ${#marks[@]}))

echo "Total Marks: $totalMarks"
echo "Average Marks: $averageMarks"

# Function to check even or odd
checkEvenOdd() {
    local number=$1
    if ((number % 2 == 0)); then
        echo "$number is even."
    else
        echo "$number is odd."
    fi
}

# Call the function
checkEvenOdd 7
checkEvenOdd 12

# Save the above code in a file, let's say example.sh, and make it executable using chmod +x example.sh. Then, run the script using ./example.sh.

# This script declares and initializes variables, demonstrates a conditional statement to check if the age is greater than or equal to 18, uses a for loop to calculate total marks and average marks from an array, and defines a function to check if a number is even or odd. The script then calls the function with two different numbers and displays the result.