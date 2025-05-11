import string

def caesar_cipher_decrypt(ciphertext):
    # Helper function to determine if a given text is likely English
    def is_probable_english(text):
        common_words = {"the", "be", "to", "of", "and", "a", "in", "that", "have", "i"}
        words = set(text.lower().split())
        return len(words.intersection(common_words)) > 0

    # Remove spaces and make the ciphertext lowercase for processing
    ciphertext = ''.join(ciphertext.split()).lower()
    letters = string.ascii_lowercase
    n = len(letters)

    for key in range(1, n):
        decrypted_text = ''
        for char in ciphertext:
            if char in letters:
                decrypted_text += letters[(letters.index(char) - key) % n]
            else:
                decrypted_text += char  # retain non-alphabet characters
        
        # Check if the decrypted text contains probable English words
        if is_probable_english(decrypted_text):
            return decrypted_text, key

    return None, None  # If no valid decryption is found

# Example usage
ciphertext = input("Enter the ciphertext: ")
plaintext, key = caesar_cipher_decrypt(ciphertext)

if plaintext:
    print(f"Decrypted plaintext: {plaintext}")
    print(f"Key used: {key}")
else:
    print("Unable to determine the correct plaintext and key.")
