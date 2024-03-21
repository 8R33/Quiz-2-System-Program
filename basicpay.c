#!/bin/bash
//specifies the interpreter for the script, and # starts comments that are ignored when the script runs.
# Get employee name, hours worked, and rate per hour
read -p "Enter employee name: " name
read -p "Enter hours worked: " hours
read -p "Enter rate per hour (e.g., 15.50): " rate //The script prompts the user to enter the employee's name, hours worked, and rate per hour, storing the input in variables name, hours, and rate, respectively.

# Calculate basic pay
basic_pay=$(echo "$hours * $rate" | bc) //The script prompts the user to enter the employee's name, hours worked, and rate per hour, storing the input in variables name, hours, and rate, respectively.

# Calculate tax
#The if statement checks the basic pay to determine the tax rate based on the provided tax table.

if [[ $basic_pay -gt 70000 ]]; then//If basic_pay is greater than 70000, the tax rate is 25%.
  tax_rate=0.25
elif [[ $basic_pay -gt 15000 ]]; then//If basic_pay is between 15000 and 70000, the tax rate is 15%.Otherwise, the tax rate is 0%.
  tax_rate=0.15 //tax=$(echo "$basic_pay * $tax_rate" | bc) calculates the tax amount using the tax rate and stores it in tax.
else
  tax_rate=0  //net_pay=$(echo "$basic_pay - $tax" | bc) calculates the net pay by subtracting the tax from the basic pay and stores the result in net_pay.
fi

tax=$(echo "$basic_pay * $tax_rate" | bc)

# Calculate net pay
net_pay=$(echo "$basic_pay - $tax" | bc)

# Display results
echo "Employee Name: $name"
echo "Basic Pay: $$basic_pay"
echo "Tax: $$tax"
echo "Net Pay: $$net_pay"
