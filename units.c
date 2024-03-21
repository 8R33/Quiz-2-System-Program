#!/bin/bash
//#!/bin/bash specifies the interpreter for the script, and # starts comments that are ignored when the script runs.
# Prompt the user for customer details
//The script prompts the user to enter the customer ID, customer name, and units consumed, storing the input in variables customer_id, customer_name, and units_consumed, respectively.
read -p "Enter Customer ID: " customer_id
read -p "Enter Customer Name: " customer_name
read -p "Enter Units Consumed: " units_consumed

# Apply charging rates based on units consumed
//The if statement applies different charging rates based on the units consumed:
if [[ $units_consumed -le 199 ]]; then  //If units_consumed is less than or equal to 199, the charge per unit is Ksh 120.
  charge_per_unit=120
elif [[ $units_consumed -lt 400 ]];  //If units_consumed is between 200 (exclusive) and 400 (exclusive), the charge per unit is Ksh 150.

  charge_per_unit=150
elif [[ $units_consumed -lt 600 ]]; then //If units_consumed is between 400 (exclusive) and 600 (exclusive), the charge per unit is Ksh 180.

  charge_per_unit=180 
else
  charge_per_unit=200   //If units_consumed is 600 or more, the charge per unit is Ksh 200.

fi

# Calculate the base bill amount
base_bill=$(echo "$units_consumed * $charge_per_unit" | bc)

# Add surcharge (assuming no surcharge is mentioned, set to 0 for now) //surcharge=0 sets the surcharge to 0 (modify this line if a surcharge needs to be applied).
surcharge=0

# Calculate the total bill amount
total_bill=$(echo "$base_bill + $surcharge" | bc)

# Display the bill details
//The script prints the customer details, units consumed, charge per unit, base bill amount, surcharge (if any), and the total bill amount.
echo "Customer ID: $customer_id"
echo "Customer Name: $customer_name"
echo "Units Consumed: $units_consumed"
echo "Charge per Unit: Ksh $charge_per_unit"
echo "Base Bill Amount: Ksh $base_bill"
echo "Surcharge: Ksh $surcharge"
echo "Total Bill Amount: Ksh $total_bill"
