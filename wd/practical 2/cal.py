def calculate_simple_interest(principal, rate, time):
    interest = (principal * rate * time) / 100
    return interest

def calculate_compound_interest(principal, rate, time, periods):
    amount = principal * (1 + rate / periods) ** (periods * time)
    interest = amount - principal
    return interest

def calculate_npv(initial_investment, cashflows, discount_rate):
    npv = -initial_investment
    for i, cashflow in enumerate(cashflows):
        npv += cashflow / (1 + discount_rate) ** (i + 1)
    return npv

def main():
    print("Welcome to the Financial Calculator!")
    print("1. Simple Interest")
    print("2. Compound Interest")
    print("3. Net Present Value (NPV)")

    choice = input("Enter your choice (1/2/3): ")

    if choice == '1':
        principal = float(input("Enter principal amount: "))
        rate = float(input("Enter interest rate (per annum): "))
        time = float(input("Enter time (in years): "))
        interest = calculate_simple_interest(principal, rate, time)
        print(f"Simple Interest: {interest}")

    elif choice == '2':
        principal = float(input("Enter principal amount: "))
        rate = float(input("Enter interest rate (per annum): "))
        time = float(input("Enter time (in years): "))
        periods = int(input("Enter number of compounding periods per year: "))
        interest = calculate_compound_interest(principal, rate, time, periods)
        print(f"Compound Interest: {interest}")

    elif choice == '3':
        initial_investment = float(input("Enter initial investment amount: "))
        cashflows = []
        while True:
            cashflow = float(input("Enter cashflow for year {}: (Enter 0 to stop) ".format(len(cashflows) + 1)))
            if cashflow == 0:
                break
            cashflows.append(cashflow)
        discount_rate = float(input("Enter discount rate (per annum): "))
        npv = calculate_npv(initial_investment, cashflows, discount_rate)
        print(f"Net Present Value (NPV): {npv}")

    else:
        print("Invalid choice. Please enter 1, 2, or 3.")

if __name__ == "__main__":
    main()

