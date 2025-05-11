import tkinter as tk
from tkinter import messagebox
import os
import struct
import json

# RSA Functions
def modInverse(e: int, phi: int) -> int:
    t, new_t = 0, 1
    r, new_r = phi, e
    while new_r != 0:
        quotient = r // new_r
        t, new_t = new_t, t - quotient * new_t
        r, new_r = new_r, r - quotient * new_r
    if t < 0:
        t += phi
    return t

def generateRSAkeys() -> tuple:
    p, q = 61, 53
    n = p * q
    phi = (p - 1) * (q - 1)
    e = 17
    d = modInverse(e, phi)
    return (e, n), (d, n)

def RSAencrypt(plaintext: str, public_key: tuple) -> str:
    e, n = public_key
    encrypted = [(ord(char) ** e) % n for char in plaintext]
    return ",".join(map(str, encrypted))

def RSAdecrypt(encrypted_message: str, private_key: tuple) -> str:
    d, n = private_key
    encrypted_message = list(map(int, encrypted_message.split(',')))
    decrypted = ''.join([chr((char ** d) % n) for char in encrypted_message])
    return decrypted

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

# RSA Keys Initialization
public_key, private_key = generateRSAkeys()

# File handling
def generate_filename(username):
    return f"{md5(username)}_data.json"

def save_credentials(username, password):
    encrypted_username = RSAencrypt(username, public_key)
    password_hash = md5(password)
    filename = generate_filename(username)
    if os.path.exists(filename):
        messagebox.showerror("Error", "Username already exists.")
        return
    user_data = {
        "username": encrypted_username,
        "password_hash": password_hash,
        "sites": []
    }
    with open(filename, 'w') as file:
        json.dump(user_data, file)
    messagebox.showinfo("Success", "Account created successfully!")

def verify_credentials(username, password):
    filename = generate_filename(username)
    if not os.path.exists(filename):
        return False
    with open(filename, 'r') as file:
        user_data = json.load(file)
    decrypted_username = RSAdecrypt(user_data["username"], private_key)
    stored_password_hash = user_data["password_hash"]
    return decrypted_username == username and stored_password_hash == md5(password)

def save_site_data(username, site_name, site_url, site_username, site_password):
    filename = generate_filename(username)
    if not os.path.exists(filename):
        messagebox.showerror("Error", "User data does not exist.")
        return
    
    encrypted_site_name = RSAencrypt(site_name, public_key)
    encrypted_site_url = RSAencrypt(site_url, public_key)
    encrypted_site_username = RSAencrypt(site_username, public_key)
    encrypted_site_password = RSAencrypt(site_password, public_key)
    
    with open(filename, 'r') as file:
        user_data = json.load(file)
    
    user_data["sites"].append({
        "site_name": encrypted_site_name,
        "site_url": encrypted_site_url,
        "site_username": encrypted_site_username,
        "site_password": encrypted_site_password
    })
    
    with open(filename, 'w') as file:
        json.dump(user_data, file)
    
    messagebox.showinfo("Success", "Site credentials saved successfully!")

def load_site_data(username):
    filename = generate_filename(username)
    if not os.path.exists(filename):
        messagebox.showerror("Error", "User data does not exist.")
        return []
    
    with open(filename, 'r') as file:
        user_data = json.load(file)
    
    sites = []
    for site in user_data["sites"]:
        decrypted_site_name = RSAdecrypt(site["site_name"], private_key)
        decrypted_site_url = RSAdecrypt(site["site_url"], private_key)
        decrypted_site_username = RSAdecrypt(site["site_username"], private_key)
        decrypted_site_password = RSAdecrypt(site["site_password"], private_key)
        sites.append({
            "site_name": decrypted_site_name,
            "site_url": decrypted_site_url,
            "site_username": decrypted_site_username,
            "site_password": decrypted_site_password
        })
    return sites

# Tkinter GUI for Login
def login():
    username = username_entry.get()
    password = password_entry.get()
    if verify_credentials(username, password):
        # Open a new window for managing sites and credentials
        manage_window(username)
        login_window.destroy()  # Close the login window (destroy it completely)
    else:
        messagebox.showerror("Login Failed", "Invalid username or password.")

def create_account():
    username = username_entry.get()
    password = password_entry.get()
    if not username or not password:
        messagebox.showerror("Error", "Username and password cannot be empty.")
        return
    save_credentials(username, password)

def manage_window(username):
    # Create a new window for managing site data after successful login
    manage_window = tk.Toplevel()
    manage_window.title("Manage Site Credentials")
    
    def save_site():
        site_name = site_name_entry.get()
        site_url = site_url_entry.get()
        site_username = site_username_entry.get()
        site_password = site_password_entry.get()
        if not all([site_name, site_url, site_username, site_password]):
            messagebox.showerror("Error", "All fields must be filled!")
            return
        save_site_data(username, site_name, site_url, site_username, site_password)
    
    def load_sites():
        sites = load_site_data(username)
        for site in sites:
            print(f"Site: {site['site_name']}, Username: {site['site_username']}, Password: {site['site_password']}")
    
    tk.Label(manage_window, text="Site Name:").grid(row=0, column=0, padx=10, pady=10)
    site_name_entry = tk.Entry(manage_window)
    site_name_entry.grid(row=0, column=1, padx=10, pady=10)

    tk.Label(manage_window, text="Site URL:").grid(row=1, column=0, padx=10, pady=10)
    site_url_entry = tk.Entry(manage_window)
    site_url_entry.grid(row=1, column=1, padx=10, pady=10)

    tk.Label(manage_window, text="Site Username:").grid(row=2, column=0, padx=10, pady=10)
    site_username_entry = tk.Entry(manage_window)
    site_username_entry.grid(row=2, column=1, padx=10, pady=10)

    tk.Label(manage_window, text="Site Password:").grid(row=3, column=0, padx=10, pady=10)
    site_password_entry = tk.Entry(manage_window, show="*")
    site_password_entry.grid(row=3, column=1, padx=10, pady=10)

    tk.Button(manage_window, text="Save Site", command=save_site).grid(row=4, column=0, pady=10)
    tk.Button(manage_window, text="Load Sites", command=load_sites).grid(row=4, column=1, pady=10)

# Tkinter GUI for Login Window
login_window = tk.Tk()
login_window.title("Login to Password Manager")

tk.Label(login_window, text="Username:").grid(row=0, column=0, padx=10, pady=10)
username_entry = tk.Entry(login_window)
username_entry.grid(row=0, column=1, padx=10, pady=10)

tk.Label(login_window, text="Password:").grid(row=1, column=0, padx=10, pady=10)
password_entry = tk.Entry(login_window, show="*")
password_entry.grid(row=1, column=1, padx=10, pady=10)

tk.Button(login_window, text="Login", command=login).grid(row=2, column=0, pady=10)
tk.Button(login_window, text="Create Account", command=create_account).grid(row=2, column=1, pady=10)

login_window.mainloop()
