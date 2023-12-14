def main():
    text = input("Text: ")

    letters, words, sentences = count_letters_words_sentences(text)  # counting all the letters, words, sentences
    L = (letters / words) * 100

    S = (sentences / words) * 100

    index = 0.0588 * L - 0.296 * S - 15.8  # Substituting values into formula
    index = round(index)

    if index < 1:
        print("Before Grade 1")
    elif 1 <= index <= 15:
        print(f"Grade {index}")
    else:
        print("Grade 16+")


def count_letters_words_sentences(text):
    text = text.lower()
    letters = 0
    words = 1  # last word doesn't have any space so intialising words at 1
    sentences = 0

    for letter in text:
        if letter.isalpha():   # counting each letter
            letters += 1
        if letter.isspace():   # counting each word as every word has space after
            words += 1
        if letter in [".", "?", "!"]:  # counting sentences as every sentence ends with '.' or "?" or "!"
            sentences += 1
    return letters, words, sentences


main()
