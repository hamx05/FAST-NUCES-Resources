import tkinter as tk
from tkinter import messagebox
import os
import struct

# MD5 Hashing Function
def md5(key: str) -> str:
    S = [
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21,
    ]
    K = [
        int(abs(struct.unpack("f", struct.pack("f", i))[0]) * 2**32) & 0xFFFFFFFF
        for i in range(1, 65)
    ]
    A, B, C, D = 0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476
    
    def left_rotate(x, n):
        return ((x << n) | (x >> (32 - n))) & 0xFFFFFFFF

    original_length = len(key) * 8
    key = bytearray(key, 'utf-8')
    key.append(0x80)
    while (len(key) * 8) % 512 != 448:
        key.append(0)
    key += struct.pack('<Q', original_length)
    
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
            else:
                f = c ^ (b | ~d)
                g = (7 * i) % 16
            temp = (a + f + K[i] + M[g]) & 0xFFFFFFFF
            temp = left_rotate(temp, S[i])
            a, b, c, d = d, (temp + b) & 0xFFFFFFFF, b, c
        A, B, C, D = (A + a) & 0xFFFFFFFF, (B + b) & 0xFFFFFFFF, (C + c) & 0xFFFFFFFF, (D + d) & 0xFFFFFFFF
    return ''.join(f'{x:02x}' for x in struct.pack('<4I', A, B, C, D))

# File handling
def generate_filename(username):
    return f"{md5(username)}.txt"

def save_credentials(username, password):
    password_hash = md5(password)
    filename = generate_filename(username)
    with open(filename, 'w') as file:
        file.write(f"{username}\n{password_hash}")
    messagebox.showinfo("Success", "Account created successfully!")

def verify_credentials(username, password):
    filename = generate_filename(username)
    if not os.path.exists(filename):
        return False
    with open(filename, 'r') as file:
        stored_username = file.readline().strip()
        stored_password_hash = file.readline().strip()
    return stored_username == username and stored_password_hash == md5(password)

# Tkinter GUI
def login():
    username = username_entry.get()
    password = password_entry.get()
    if verify_credentials(username, password):
        messagebox.showinfo("Login Success", "Welcome!")
    else:
        messagebox.showerror("Login Failed", "Invalid username or password.")

def create_account():
    username = username_entry.get()
    password = password_entry.get()
    if not username or not password:
        messagebox.showerror("Error", "Username and password cannot be empty.")
        return
    if os.path.exists(generate_filename(username)):
        messagebox.showerror("Error", "Username already exists.")
    else:
        save_credentials(username, password)

root = tk.Tk()
root.title("Password Manager")

tk.Label(root, text="Username:").grid(row=0, column=0, padx=10, pady=10)
username_entry = tk.Entry(root)
username_entry.grid(row=0, column=1, padx=10, pady=10)

tk.Label(root, text="Password:").grid(row=1, column=0, padx=10, pady=10)
password_entry = tk.Entry(root, show="*")
password_entry.grid(row=1, column=1, padx=10, pady=10)

tk.Button(root, text="Login", command=login).grid(row=2, column=0, pady=10)
tk.Button(root, text="Create Account", command=create_account).grid(row=2, column=1, pady=10)

root.mainloop()
