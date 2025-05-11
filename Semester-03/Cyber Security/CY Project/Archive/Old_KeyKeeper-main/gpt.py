import tkinter as tk
from tkinter import messagebox, simpledialog
import json
import os
import re
from hashlib import sha256

CREDENTIALS_FILE = "user_credentials.json"

# Initialize storage for user credentials
def initialize_user_storage():
    if not os.path.exists(CREDENTIALS_FILE):
        with open(CREDENTIALS_FILE, 'w') as f:
            json.dump({}, f, indent=4)

def load_user_credentials():
    with open(CREDENTIALS_FILE, 'r') as f:
        return json.load(f)

def save_user_credentials(credentials):
    with open(CREDENTIALS_FILE, 'w') as f:
        json.dump(credentials, f, indent=4)

def hash_password(password: str) -> str:
    return sha256(password.encode()).hexdigest()

def create_account():
    username = simpledialog.askstring("Create Account", "Enter a username:")
    if not username:
        messagebox.showerror("Error", "Username is required.")
        return
    
    password = simpledialog.askstring("Create Account", "Enter a password:", show="*")
    if not validate_password(password):
        return
    
    credentials = load_user_credentials()
    if username in credentials:
        messagebox.showerror("Error", "Username already exists.")
        return
    
    credentials[username] = hash_password(password)
    save_user_credentials(credentials)
    messagebox.showinfo("Success", "Account created successfully!")

def login():
    username = simpledialog.askstring("Login", "Enter your username:")
    if not username:
        messagebox.showerror("Error", "Username is required.")
        return
    
    password = simpledialog.askstring("Login", "Enter your password:", show="*")
    credentials = load_user_credentials()
    if username in credentials and credentials[username] == hash_password(password):
        messagebox.showinfo("Success", "Login successful!")
        show_main_interface()
    else:
        messagebox.showerror("Error", "Invalid username or password.")

def validate_password(password: str) -> bool:
    if not password or len(password) < 8:
        messagebox.showerror("Error", "Password must be at least 8 characters.")
        return False
    if not re.search(r"[A-Z]", password):
        messagebox.showerror("Error", "Password must contain at least one uppercase letter.")
        return False
    if not re.search(r"\d", password):
        messagebox.showerror("Error", "Password must contain at least one number.")
        return False
    if not re.search(r"[!@#$%^&*()]", password):
        messagebox.showerror("Error", "Password must contain at least one special character.")
        return False
    return True

# GUI setup
root = tk.Tk()
root.title("Password Manager")

tk.Button(root, text="Create Account", command=create_account).pack(pady=5)
tk.Button(root, text="Login", command=login).pack(pady=5)

def show_main_interface():
    # Hide the login window and show the main window
    for widget in root.winfo_children():
        widget.destroy()
    tk.Label(root, text="Welcome to the Password Manager").pack()

initialize_user_storage()
root.mainloop()
