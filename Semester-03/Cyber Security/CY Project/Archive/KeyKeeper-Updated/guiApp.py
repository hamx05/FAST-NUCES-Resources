import os, re, struct
from math import gcd
import json
import tkinter as tk
from tkinter import messagebox
from tkinter.simpledialog import askstring

#############################################
#       Global Variables / FLAGS
#############################################

ENV_FILE = ".env"       # file path
EXIT_FLAG = False 
ACCESS_FLAG = False

#############################################
#               HASHING
#############################################

def simpleHash(key: str) -> str:
    """
    Manually hashes a string using a simple custom hashing algorithm.

    Args:
        key (str): The input string to hash.

    Returns:
        str: The hashed value as a hexadecimal string.
    """
    hash_value = 0
    for i, char in enumerate(key):
        # Basic hashing: weighted sum of ASCII values with prime multiplication
        hash_value += (i + 1) * ord(char) * 31  # Simple prime multiplier
    return hex(hash_value)[2:]  # Convert to hexadecimal and remove '0x'

def leftRotate(x: int, c: int) -> int:
    """
    Performs a circular left bitwise rotation on a 32-bit integer.

    This function rotates the bits of the input integer to the left by a 
    specified number of places, wrapping the overflowed bits back to the 
    right end. The operation is constrained to 32 bits.

    Args:
        x (int): The 32-bit integer to rotate.
        c (int): The number of bit positions to rotate.

    Returns:
        int: The result of the left rotation as a 32-bit integer.
    """
    return (x << c | x >> (32 - c)) & 0xFFFFFFFF

def md5(key: str) -> str:
    """
    Computes the MD5 hash of an input string.

    This function implements the MD5 hashing algorithm to produce 
    a 128-bit hash value represented as a 32-character hexadecimal 
    string for a given input string. 
    
    It performs padding, initializes state variables, processes data 
    in 512-bit chunks, and applies bitwise operations and transformations 
    to compute the hash.

    Args:
        key (str): The input string to hash.

    Returns:
        str: The resulting hash value as a hexadecimal string.
    """

    # Shift Amounts: number of bits to left-rotate in each step of the MD5 transformation
    S = [
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21,
    ]

    # K Constants: set of 64 precomputed constants used in the main MD5 algorithm loop
    K = [
        int(abs(struct.unpack("f", struct.pack("f", i))[0]) * 2**32) & 0xFFFFFFFF
        for i in range(1, 65)
    ]

    # Initial hash values
    A = 0x67452301
    B = 0xefcdab89
    C = 0x98badcfe
    D = 0x10325476
    
    # Preprocessing
    original_length = len(key) * 8
    key = bytearray(key, 'utf-8')
    key.append(0x80)
    
    while (len(key) * 8) % 512 != 448:
        key.append(0)
    
    key += struct.pack('<Q', original_length)
    
    # Process each 512-bit chunk
    for i in range(0, len(key), 64):
        chunk = key[i:i + 64]
        M = [struct.unpack('<I', chunk[j:j + 4])[0] for j in range(0, 64, 4)]
        
        a, b, c, d = A, B, C, D
        
        for i in range(64):
            if 0 <= i <= 15:
                f = (b & c) | (~b & d)
                g = i
            elif 16 <= i <= 31:
                f = (d & b) | (~d & c)
                g = (5 * i + 1) % 16
            elif 32 <= i <= 47:
                f = b ^ c ^ d
                g = (3 * i + 5) % 16
            elif 48 <= i <= 63:
                f = c ^ (b | ~d)
                g = (7 * i) % 16
            
            temp = (a + f + K[i] + M[g]) & 0xFFFFFFFF
            temp = leftRotate(temp, S[i])
            temp = (temp + b) & 0xFFFFFFFF
            a, b, c, d = d, temp, b, c
        
        A = (A + a) & 0xFFFFFFFF
        B = (B + b) & 0xFFFFFFFF
        C = (C + c) & 0xFFFFFFFF
        D = (D + d) & 0xFFFFFFFF
    
    # Produce the final hash value (little-endian)
    return ''.join(f'{x:02x}' for x in struct.pack('<4I', A, B, C, D))

#############################################
#               CIPHER
#############################################

def modInverse(e: int, phi: int) -> int:
    """
    Finds the modular multiplicative inverse of e under modulo phi.
    Uses the Extended Euclidean Algorithm.

    Args:
        e (int): The number to find the inverse for.
        phi (int): The modulo.

    Returns:
        int: The modular inverse of e modulo phi.
    """
    t, new_t = 0, 1
    r, new_r = phi, e

    while new_r != 0:
        quotient = r // new_r
        t, new_t = new_t, t - quotient * new_t
        r, new_r = new_r, r - quotient * new_r

    if r > 1:
        raise ValueError("e is not invertible")
    if t < 0:
        t += phi

    return t

def generateRSAkeys() -> tuple[tuple[int, int], tuple[int, int]]:
    """
    Generates RSA keys manually.

    Returns:
        tuple: (public_key, private_key, n)
    """
    # Step 1: Choose two prime numbers
    # Example small prime numbers
    p = 61 
    q = 53 
    n = p * q  # Modulus
    phi = (p - 1) * (q - 1)  # Euler's Totient

    # Step 2: Choose e such that gcd(e, phi) = 1 and 1 < e < phi
    e = 17  # Commonly used public exponent
    if gcd(e, phi) != 1:
        raise ValueError("e and phi(n) are not coprime.")

    # Step 3: Compute d, the modular inverse of e
    d = modInverse(e, phi)

    public_key = (e, n)
    private_key = (d, n)

    return public_key, private_key

def RSAencrypt(plaintext: str, public_key: tuple) -> str:
    """
    Encrypts a plaintext string using RSA.

    Args:
        plaintext (str): The plaintext to encrypt.
        public_key (tuple): The public key (e, n).

    Returns:
        str: The encrypted message as a string of list of integers.
    """
    e, n = public_key
    encrypted = [(ord(char) ** e) % n for char in plaintext]
    encrypted = ",".join(map(str, encrypted)) # convert list of integers to a string of csv
    return encrypted

def RSAdecrypt(encrypted_message: str, private_key: tuple) -> str:
    """
    Decrypts an encrypted message using RSA.

    Args:
        encrypted_message (str): The encrypted message as a string of list of integers.
        private_key (tuple): The private key (d, n).

    Returns:
        str: The decrypted plaintext.
    """
    d, n = private_key
    encrypted_message = list(map(int, encrypted_message.split(','))) # revert to list of integers
    decrypted = ''.join([chr((char ** d) % n) for char in encrypted_message])
    return decrypted

def saveKeysToFile(public_key: int, private_key: int, public_key_file="public_key.txt", private_key_file="private_key.txt") -> None:
    """
    Saves RSA keys to files. (only for testing environment)

    Args:
        public_key (tuple): The public key (e, n).
        private_key (tuple): The private key (d, n).
        public_key_file (str): Path to save the public key.
        private_key_file (str): Path to save the private key.
    """

    return 

    with open(public_key_file, "w") as pub_file:
        pub_file.write(f"{public_key[0]},{public_key[1]}")

    with open(private_key_file, "w") as priv_file:
        priv_file.write(f"{private_key[0]},{private_key[1]}")

    print(f"Public key saved to {public_key_file}")
    print(f"Private key saved to {private_key_file}")

#############################################
#               STORAGE
#############################################

def initializeStorage() -> None:
    """Initializes a 'credentials.json' file with an empty array and an empty 'private_keys.txt' file."""

    with open("credentials.json", "w") as j:
        json.dump([], j, indent=4)

    with open("private_keys.txt", "w") as f:
        pass

def loadCredentials() -> list:
    """
    This function loads the existing JSON data from the file into a Python list.

    Returns:
        list: The list of credentials.

    """
    with open("credentials.json", "r") as json_file:
        return json.load(json_file)

def saveCredentials(credentials_list) -> None:
    """
    This function saves the modified list back to the JSON file.
    """
    with open("credentials.json", "w") as json_file:
        json.dump(credentials_list, json_file, indent=4)

def appendCredential(website: str, username: str, password: str, public_key: tuple[int], private_key: tuple[int]) -> None:
    """
    This function takes the new credential details as input, creates a new dictionary/object, appends it to the list, and saves the updated list.
    Then it saves the relevant private key to a text file.
    """
    encryption_key = public_key[0]
    decryption_key = private_key[0]
    modulusN = public_key[1]

    credentials_list = loadCredentials()
    new_credential = {
        "website": website,
        "username": username,
        "password": password,
        "publickey": encryption_key,
        "modulus": modulusN
    }
    credentials_list.append(new_credential)
    saveCredentials(credentials_list)
    # last_index = len(credentials_list) - 1 ### not needed since remove will change indexes which needs tracing on every delete 
    savePrivateKey(decryption_key)

def deleteCredential(index) -> None:
    """
    This function takes the index of the credential to be deleted, removes it from the list, and saves the updated list.
    """
    credentialsList = loadCredentials()
    del credentialsList[index]
    saveCredentials(credentialsList)
    
    privateKeysList = readPrivateKeys()
    del privateKeysList[index]
    savePrivateKeys(privateKeysList)

def savePrivateKey(private_key, private_keys_file="private_keys.txt") -> None:
    with open(private_keys_file, "a") as key_file:
        key_file.write(f"{private_key}\n")

def readPrivateKeys(file_path="private_keys.txt") -> list[int]:
    """Reads lines of individual private keys from a text file and returns them as a list.

    Args:
    file_path: The path to the text file.

    Returns:
    A list of lines from the file.
    """

    with open(file_path, 'r') as file:
        lines = file.readlines()
        lines = [int(line.strip()) for line in lines]  # Remove leading/trailing whitespace
        
    return lines

def savePrivateKeys(keys_list: list[int], file_path="private_keys.txt") -> None:
    """
    This function saves the modified list of private keys back to the text file.
    Args:
        keys_list (list[int]): The list of private keys to be saved.
        file_path: The path to the text file.
    """
    with open(file_path, 'w') as file:
        for key in keys_list:
            file.write(str(key) + '\n')

#############################################
#               UTILS
#############################################

def storeHash(key: str, env_var_name: str = "HASH") -> None:
    """
    Hashes the given key and stores the hash in a .env file and a text file.

    Args:
        key (str): The key to hash.
        env_var_name (str): The variable name to use for storing the hash in the .env file.
    """
    # Hash the key
    hashed_key = md5(key) ### simple_hash(key)

    # Store in the .env file
    try:
        with open(ENV_FILE, 'w') as env_file:
            env_file.write(f"{env_var_name}={hashed_key}\n")
        print(f"*** ALERT: Hashed key stored as {env_var_name} in {ENV_FILE}.")
    except IOError as e:
        print(f"*** ERROR: Failed to write to {ENV_FILE}. {e}")
        exit()

def readHash(env_var_name: str = "HASH") -> str:
    """
    Reads the hash from the .env file.

    Args:
        env_var_name (str): The variable name to fetch.

    Returns:
        str: The hash value or None if not found.
    """
    try:
        # Read from the .env file
        with open(ENV_FILE, 'r') as env_file:
            for line in env_file:
                if line.startswith(f"{env_var_name}="):
                    hashed_key = line.strip().split("=", 1)[1]
                    return hashed_key
        print("*** ALERT: No hash found in the .env file.")
    except FileNotFoundError:
        print(f"*** ERROR: {ENV_FILE} not found.")
    except IOError as e:
        print(f"*** ERROR: Failed to read from {ENV_FILE}. {e}")
    return None

def userSetup() -> None:
    """
    Function that handles the logic to setup the user on the first program run.
    
    It stores a hashed key after validating it. 
    
    It runs when the .env file doesn't exist.
    """

    print("*** ALERT: User doesn't exist. Proceeding to user setup.")

    while True:
        key_to_store = input("Enter the passkey: ")
        if validatePasskey(key_to_store):
            print("*** ALERT: Passkey is valid.")
            storeHash(key_to_store)
            initializeStorage()
            print("*** ALERT: Passkey stored. Please restart the program to proceed.")
            exit()  # Exit after initializing the passkey
            break
        else:
            print("*** ALERT: Please try again.")

def validatePasskey(passkey: str) -> bool:
    """
    Validates a passkey based on the following criteria:
    - Minimum length: 8 characters
    - Maximum length: 15 characters
    - At least one uppercase letter
    - At least one number
    - At least one special character

    Args:
        passkey (str): The passkey to validate.

    Returns:
        bool: True if the passkey is valid, False otherwise.
    """
    # Check length
    if not (8 <= len(passkey) <= 15):
        print("Passkey must be between 8 and 15 characters.")
        return False

    # Check for at least one uppercase letter
    if not any(char.isupper() for char in passkey):
        print("Passkey must include at least one uppercase letter.")
        return False

    # Check for at least one digit
    if not any(char.isdigit() for char in passkey):
        print("Passkey must include at least one number.")
        return False

    # Check for at least one special character
    if not re.search(r"[!@#$%^&*(),.?\":{}|<>]", passkey):
        print("Passkey must include at least one special character.")
        return False

    return True

def userValidation() -> None:
    """
    Validates the user by requiring a passkey input.
    Checks against a global EXIT_FLAG to terminate early if needed.
    Allows a limited number of attempts.

    Uses:
        isUserValid (function): Function to validate the user passkey.
        kickUser (function): Function to handle user lockout after failed attempts.
        exit (function): Function to handle program exit.

    Globals:
        EXIT_FLAG (bool): Global flag to control termination.
        ACCESS_FLAG (bool): Global flag to control access.

    """

    print("*** ALERT: User exists. Proceeding to user validation.")

    # read the global variables 
    global EXIT_FLAG 
    global ACCESS_FLAG 

    VALID_TRIES = 5  # Maximum number of attempts allowed

    while VALID_TRIES > 0 and not EXIT_FLAG:
        key_to_access = input(f"Passkey ({VALID_TRIES} tries left): ")
        if isUserValid(key_to_access):
            print("*** ALERT: User validated successfully.")
            ACCESS_FLAG = True # User successfully validated
            return  
        else:
            VALID_TRIES -= 1
            print(f"*** ALERT: Incorrect passkey. {VALID_TRIES} tries remaining.")

    if VALID_TRIES == 0:
        print("*** ALERT: Too many failed attempts.")
        kickUser()  # Handle user lockout
        exit() 

    return

def isUserValid(entered_key: str) -> bool:
    """
    Function to validate the user by hashing the entered passkey 
    and comparing it with the hashed key stored in .env

    Args:
        passkey (str): The passkey to validate.

    Returns:
        bool: True if the passkey matches, False otherwise.
    """
    # Read the stored hashed passkey from the .env file
    stored_hashed_key = readHash()
    
    if stored_hashed_key is None:
        print("*** ALERT: No hashed passkey found in the .env file.")
        return False
    
    # Hash the entered passkey and compare with the stored hashed passkey
    entered_hashed = md5(entered_key)
    
    return entered_hashed == stored_hashed_key

def checkPasswordStrength(password) -> str:
    # Policies
    min_length = 8
    ideal_length = 15
    common_passwords = {"123456", "password", "123456789", "qwerty", "abc123", "letmein"} # can extend it as per use in future
    
    # Checks
    length = len(password)
    contains_upper = bool(re.search(r'[A-Z]', password))
    contains_lower = bool(re.search(r'[a-z]', password))
    contains_digit = bool(re.search(r'[0-9]', password))
    contains_special = bool(re.search(r'[!@#$%^&*(),.?":{}|<>]', password))
    is_common = password in common_passwords
    
    # Classification
    if is_common:
        return "Weak (commonly used password)"
    elif length < min_length:
        return "Weak (too short)"
    elif length < ideal_length and (not contains_upper or not contains_special or not contains_digit):
        return "Average (short with minimal complexity)"
    elif length >= ideal_length and (contains_upper or contains_special or contains_digit):
        return "Strong (long and complex)"
    else:
        return "Average (improved but could be stronger)"

def analyzePasswords() -> str:
    """Decrypts passwords and analyzes their strength."""
    credentials = loadCredentials()
    if not credentials:
        messagebox.showinfo("No Credentials", "No credentials found.")
        return

    privKeys = readPrivateKeys()
    if not privKeys:
        messagebox.showinfo("No Private Keys", "No Private Key found.")
        return
    
    weak_passwords = []
    average_passwords = []
    strong_passwords = []

    for i, cred in enumerate(credentials):
        decrypted_password = RSAdecrypt(cred['password'], (privKeys[i], cred['modulus']))
        strength = checkPasswordStrength(decrypted_password)
        
        if "Weak" in strength:
            weak_passwords.append(i + 1)  # 1-based index for readability
        elif "Average" in strength:
            average_passwords.append(i + 1)
        elif "Strong" in strength:
            strong_passwords.append(i + 1)

    # Formatting the message
    message_parts = []
    if weak_passwords:
        message_parts.append(f"Weak passwords at: {', '.join(map(str, weak_passwords))}")
    if average_passwords:
        message_parts.append(f"Average passwords at: {', '.join(map(str, average_passwords))}")
    if strong_passwords:
        message_parts.append(f"Strong passwords at: {', '.join(map(str, strong_passwords))}")

    message = "\n".join(message_parts) if message_parts else "All passwords are strong!"
    messagebox.showinfo("Password Strength Analysis", message)

def kickUser() -> None:
    """
    Launches kick notification before exiting.
    """
    print(f"*** ALERT: User kicked.") 

def exit() -> None:
    """
    Updates the EXIT_FLAG and exits the program.
    """
    global EXIT_FLAG
    EXIT_FLAG = True  # Update the flag before exiting
    print("*** ALERT: Exiting program.")

#############################################
# GUI FUNCTIONS
#############################################

def validate_user() -> None:
    """Handles user validation through the GUI."""
    entered_passkey = askstring("Passkey", "Enter your passkey:", show="*")
    if isUserValid(entered_passkey):
        messagebox.showinfo("Success", "User validated successfully.")
        show_main_interface()
        analyzePasswords()
    else:
        messagebox.showerror("Error", "Invalid passkey.")

def setup_user() -> None:
    """Handles user setup through the GUI."""
    passkey = askstring("Setup", "Set your passkey (8-15 chars, uppercase, number, special):", show="*")
    if passkey and validatePasskey(passkey):
        storeHash(passkey)
        initializeStorage()
        messagebox.showinfo("Setup Complete", "Passkey set up successfully. Restart to log in.")
        root.destroy()  # Close the setup window
    else:
        messagebox.showerror("Error", "Invalid passkey. Try again.")

def add_credential() -> None:
    """Adds a new credential."""
    website = askstring("Add Credential", "Enter website:")
    username = askstring("Add Credential", "Enter username:")
    password = askstring("Add Credential", "Enter password:", show="*")
    
    if not (website and username and password):
        messagebox.showerror("Error", "All fields are required.")
        return
    
    passwordStrength = checkPasswordStrength(password)

    if "Strong" not in passwordStrength:
        messagebox.showerror("Alert", f"Password remarks: {passwordStrength}")
    
    public_key, private_key = generateRSAkeys()
    encrypted_password = RSAencrypt(password, public_key)
    appendCredential(website, username, encrypted_password, public_key, private_key)
    messagebox.showinfo("Success", "Credential added successfully.")

def view_credentials() -> None:
    """Displays all saved credentials."""
    credentials = loadCredentials()
    if not credentials:
        messagebox.showinfo("No Credentials", "No credentials found.")
        return

    privKeys = readPrivateKeys()
    if not privKeys:
        messagebox.showinfo("No Private Keys", "No Private Key found.")
        return

    credential_list = "\n".join(
        [f"{i+1}. Website: {cred['website']}, Username: {cred['username']}, Password: {RSAdecrypt(cred['password'], (privKeys[i],cred['modulus']))}" for i, cred in enumerate(credentials)]
    )
    messagebox.showinfo("Saved Credentials", credential_list)

def delete_credential() -> None:
    """Deletes a credential by index."""
    index = askstring("Delete Credential", "Enter credential index to delete:")
    try:
        index = int(index) - 1
        deleteCredential(index)
        messagebox.showinfo("Success", "Credential deleted successfully.")
    except (ValueError, IndexError):
        messagebox.showerror("Error", "Invalid index.")

def show_main_interface() -> None:
    """Displays the main interface after user validation."""
    main_window = tk.Toplevel(root)
    main_window.title("Credential Manager")

    tk.Button(main_window, text="Add Credential", command=add_credential).pack(pady=5)
    tk.Button(main_window, text="View Credentials", command=view_credentials).pack(pady=5)
    tk.Button(main_window, text="Delete Credential", command=delete_credential).pack(pady=5)
    tk.Button(main_window, text="Exit", command=main_window.destroy).pack(pady=20)

#############################################
# APPLICATION ENTRY POINT
#############################################

root = tk.Tk()
root.title("User Validation System")

if not os.path.exists(ENV_FILE):
    tk.Label(root, text="No user detected. Please set up a new passkey.").pack(pady=10)
    tk.Button(root, text="Set Up User", command=setup_user).pack(pady=20)
else:
    tk.Label(root, text="User detected. Please log in.").pack(pady=10)
    tk.Button(root, text="Log In", command=validate_user).pack(pady=20)

root.mainloop()
