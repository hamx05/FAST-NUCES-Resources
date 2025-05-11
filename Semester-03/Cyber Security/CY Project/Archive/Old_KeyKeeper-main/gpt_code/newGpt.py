import tkinter as tk
from tkinter import messagebox, ttk
import json
import os
import re
from hashlib import sha256

CREDENTIALS_FILE = "user_credentials.json"
PASSWORD_DATA_FILE = "password_data.json"

# Initialize storage for user credentials and password data
def initialize_storage():
    if not os.path.exists(CREDENTIALS_FILE):
        with open(CREDENTIALS_FILE, 'w') as f:
            json.dump({}, f, indent=4)
    if not os.path.exists(PASSWORD_DATA_FILE):
        with open(PASSWORD_DATA_FILE, 'w') as f:
            json.dump({}, f, indent=4)

def load_user_credentials():
    with open(CREDENTIALS_FILE, 'r') as f:
        return json.load(f)

def save_user_credentials(credentials):
    with open(CREDENTIALS_FILE, 'w') as f:
        json.dump(credentials, f, indent=4)

def load_password_data():
    with open(PASSWORD_DATA_FILE, 'r') as f:
        return json.load(f)

def save_password_data(data):
    with open(PASSWORD_DATA_FILE, 'w') as f:
        json.dump(data, f, indent=4)

def hash_password(password: str) -> str:
    return sha256(password.encode()).hexdigest()

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

def create_account(username, password):
    credentials = load_user_credentials()
    if username in credentials:
        messagebox.showerror("Error", "Username already exists.")
        return
    if not validate_password(password):
        return
    
    credentials[username] = hash_password(password)
    save_user_credentials(credentials)
    messagebox.showinfo("Success", "Account created successfully!")

def login(username, password):
    credentials = load_user_credentials()
    if username in credentials and credentials[username] == hash_password(password):
        messagebox.showinfo("Success", "Login successful!")
        show_main_interface(username)
    else:
        messagebox.showerror("Error", "Invalid username or password.")

# GUI setup
root = tk.Tk()
root.title("Password Manager")

def show_login_form():
    for widget in root.winfo_children():
        widget.destroy()

    tk.Label(root, text="Username").pack(pady=5)
    username_entry = tk.Entry(root)
    username_entry.pack(pady=5)

    tk.Label(root, text="Password").pack(pady=5)
    password_entry = tk.Entry(root, show="*")
    password_entry.pack(pady=5)

    tk.Button(root, text="Login", command=lambda: login(username_entry.get(), password_entry.get())).pack(pady=5)
    tk.Button(root, text="Create Account", command=lambda: create_account(username_entry.get(), password_entry.get())).pack(pady=5)

def show_main_interface(username):
    for widget in root.winfo_children():
        widget.destroy()

    tk.Label(root, text=f"Welcome, {username}!").pack(pady=5)
    tk.Button(root, text="Logout", command=show_login_form).pack(pady=5)

    def add_password():
        site = site_entry.get()
        site_password = password_entry.get()
        if not site or not site_password:
            messagebox.showerror("Error", "All fields are required.")
            return
        
        data = load_password_data()
        data[username][site] = site_password
        save_password_data(data)
        messagebox.showinfo("Success", "Password saved.")
        site_entry.delete(0, tk.END)
        password_entry.delete(0, tk.END)

    tk.Label(root, text="Site").pack(pady=5)
    site_entry = tk.Entry(root)
    site_entry.pack(pady=5)
    
    tk.Label(root, text="Password").pack(pady=5)
    password_entry = tk.Entry(root)
    password_entry.pack(pady=5)
    
    tk.Button(root, text="Save Password", command=add_password).pack(pady=5)

initialize_storage()
show_login_form()
root.mainloop()
