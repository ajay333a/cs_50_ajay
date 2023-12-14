from pyfiglet import Figlet
import random
import sys

figlet = Figlet()

if len(sys.argv) == 1:
    isRandomFont = True
elif len(sys.argv) == 3 and (sys.argv[1] == "-f" or sys.argv[1] == "--f"):
    isRandomFont = False
else:
    sys.exit(1)


figlet.getFonts()

if isRandomFont == False:
    try:
        figlet.setFont(font = sys.argv[2])
    except:
        print("Inavalid usage")
        sys.exit(1)
else:
    f = random.choice(figlet.getFonts())
    figlet.setFont(font = f)

text = input("Input: ")

print(f"Output:\n {figlet.renderText(text)}")


