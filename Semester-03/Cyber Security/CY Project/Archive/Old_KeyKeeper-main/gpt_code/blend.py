import os
import json
import hashlib
import tkinter as tk
from tkinter import messagebox
from tkinter.simpledialog import askstring


# File paths
ENV_FILE = ".env"
CREDENTIALS_FILE = "credentials.json"
EXIT_FLAG = False
ACCESS_FLAG = False

# MD5 Hash function
def md5(key: str) -> str:
    return hashlib.md5(key.encode()).hexdigest()


# Storage management functions
def initializeStorage():
    if not os.path.exists(CREDENTIALS_FILE):
        with open(CREDENTIALS_FILE, "w") as f:
            json.dump([], f, indent=4)

def loadCredentials():
    with open(CREDENTIALS_FILE, "r") as f:
        return json.load(f)

def saveCredentials(credentials_list):
    with open(CREDENTIALS_FILE, "w") as f:
        json.dump(credentials_list, f, indent=4)

def appendCredential(website, username, password):
    credentials_list = loadCredentials()
    new_credential = {"website": website, "username": username, "password": password}
    credentials_list.append(new_credential)
    saveCredentials(credentials_list)


# User authentication functions
def storeHash(key):
    hashed_key = md5(key)
    with open(ENV_FILE, "w") as env_file:
        env_file.write(f"HASH={hashed_key}\n")

def readHash():
    try:
        with open(ENV_FILE, "r") as env_file:
            for line in env_file:
                if line.startswith("HASH="):
                    return line.strip().split("=", 1)[1]
    except FileNotFoundError:
        return None

def isUserValid(entered_key):
    stored_hashed_key = readHash()
    if stored_hashed_key is None:
        return False
    entered_hashed = md5(entered_key)
    return entered_hashed == stored_hashed_key

def userSetup():
    passkey = askstring("Setup", "Enter your passkey (8-15 chars, uppercase, number, special):", show="*")
    if passkey and validatePasskey(passkey):
        storeHash(passkey)
        initializeStorage()
        messagebox.showinfo("Setup Complete", "Passkey set up successfully. Restart the application to log in.")
        exit()

def validatePasskey(passkey):
    if not (8 <= len(passkey) <= 15):
        messagebox.showerror("Error", "Passkey must be between 8 and 15 characters.")
        return False
    if not any(char.isupper() for char in passkey):
        messagebox.showerror("Error", "Passkey must include at least one uppercase letter.")
        return False
    if not any(char.isdigit() for char in passkey):
        messagebox.showerror("Error", "Passkey must include at least one number.")
        return False
    if not any(char in "!@#$%^&*(),.?\":{}|<>" for char in passkey):
        messagebox.showerror("Error", "Passkey must include at least one special character.")
        return False
    return True

def userValidation():
    passkey = askstring("Login", "Enter your passkey:", show="*")
    if isUserValid(passkey):
        messagebox.showinfo("Success", "User validated successfully.")
        return True
    else:
        messagebox.showerror("Error", "Invalid passkey.")
        return False


# GUI Functions
def add_credential():
    website = askstring("Add Credential", "Enter website:")
    username = askstring("Add Credential", "Enter username:")
    password = askstring("Add Credential", "Enter password:")
    
    if not (website and username and password):
        messagebox.showerror("Error", "All fields are required.")
        return
    
    appendCredential(website, username, password)
    messagebox.showinfo("Success", "Credential added successfully.")

def view_credentials():
    credentials = loadCredentials()
    if not credentials:
        messagebox.showinfo("No Credentials", "No credentials saved.")
        return
    cred_list = "\n".join([f"Website: {cred['website']}, Username: {cred['username']}" for cred in credentials])
    messagebox.showinfo("Credentials", cred_list)


def main():
    if not os.path.exists(ENV_FILE):
        userSetup()
    
    root = tk.Tk()
    root.title("Password Manager")
    
    # Frame for buttons
    frame = tk.Frame(root)
    frame.pack(pady=20)

    # Buttons for actions
    add_button = tk.Button(frame, text="Add Credential", command=add_credential)
    add_button.pack(padx=10, pady=5)

    view_button = tk.Button(frame, text="View Credentials", command=view_credentials)
    view_button.pack(padx=10, pady=5)

    exit_button = tk.Button(frame, text="Exit", command=root.quit)
    exit_button.pack(padx=10, pady=5)

    if userValidation():
        root.mainloop()

if __name__ == "__main__":
    main()
