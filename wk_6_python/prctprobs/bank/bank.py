def main():
    greeting = get_input()
    print(f"${money(greeting)}")

def get_input():
    greeting = input("Greeting: ")
    return greeting

def money(greeting):
    greeting = greeting.lower().strip()

    if "hello" in greeting:
        return 0
    elif "h" in greeting[0]:
        return 20
    else:
        return 100

main()