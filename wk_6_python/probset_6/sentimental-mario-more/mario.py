from cs50 import get_int


def main():
    height = get_height()

    pyramid(height)


def get_height():
    height = get_int("Height: ")  # getting initial height
    while (height > 8 or height < 1):  # prompting again for height
        height = int(input("Height: "))
    return height


def pyramid(height):
    for i in range(height):
        for j in range(1, height+1):
            space = " " * (height - (i + 1))  # creating spaces that should be printed
            ash = "#" * j  # creating # that should be printed
            print(f"{space}{ash}  {ash}")
            height -= 1


main()