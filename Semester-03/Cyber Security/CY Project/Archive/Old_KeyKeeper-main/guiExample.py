"""
Can you make me python tkinter code that takes password input on first frame, 
after button click checks the password, 
if matches it opens second frame where it loads a list of dicts one be one in form of a table with delete button in front of them that deletes them from the list
if it doesn't matches then it gives it five tries and terminates/closes window itself or removes/disables the button
"""

import tkinter as tk
from tkinter import messagebox

# Define the correct password
CORRECT_PASSWORD = "secure123"

# Define the data
data_list = [
    {"ID": 1, "Name": "Alice", "Age": 25},
    {"ID": 2, "Name": "Bob", "Age": 30},
    {"ID": 3, "Name": "Charlie", "Age": 35},
]

class PasswordApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Password Validator")
        self.attempts = 5

        # Frame 1 for password input
        self.frame1 = tk.Frame(self.root)
        self.frame1.pack()

        self.label = tk.Label(self.frame1, text="Enter Password:")
        self.label.grid(row=0, column=0, pady=5, padx=5)

        self.password_entry = tk.Entry(self.frame1, show="*")
        self.password_entry.grid(row=0, column=1, pady=5, padx=5)

        self.submit_button = tk.Button(self.frame1, text="Submit", command=self.check_password)
        self.submit_button.grid(row=1, column=0, columnspan=2, pady=10)

        # Frame 2 for displaying data
        self.frame2 = tk.Frame(self.root)

    def check_password(self):
        entered_password = self.password_entry.get()
        if entered_password == CORRECT_PASSWORD:
            self.show_table()
        else:
            self.attempts -= 1
            if self.attempts > 0:
                messagebox.showerror("Error", f"Incorrect Password! {self.attempts} attempts left.")
            else:
                messagebox.showerror("Error", "Too many incorrect attempts! Exiting...")
                self.submit_button.config(state=tk.DISABLED)
                self.root.after(2000, self.root.destroy)

    def show_table(self):
        # Hide Frame 1
        self.frame1.pack_forget()

        # Show Frame 2
        self.frame2.pack()

        # Create table headers
        tk.Label(self.frame2, text="ID").grid(row=0, column=0, padx=5, pady=5)
        tk.Label(self.frame2, text="Name").grid(row=0, column=1, padx=5, pady=5)
        tk.Label(self.frame2, text="Age").grid(row=0, column=2, padx=5, pady=5)
        tk.Label(self.frame2, text="Actions").grid(row=0, column=3, padx=5, pady=5)

        # Populate the table
        self.update_table()

    def update_table(self):
        for widget in self.frame2.winfo_children():
            if isinstance(widget, tk.Button) and widget["text"] == "Delete":
                widget.destroy()

        for idx, item in enumerate(data_list):
            tk.Label(self.frame2, text=item["ID"]).grid(row=idx + 1, column=0, padx=5, pady=5)
            tk.Label(self.frame2, text=item["Name"]).grid(row=idx + 1, column=1, padx=5, pady=5)
            tk.Label(self.frame2, text=item["Age"]).grid(row=idx + 1, column=2, padx=5, pady=5)
            delete_button = tk.Button(self.frame2, text="Delete", command=lambda i=idx: self.delete_row(i))
            delete_button.grid(row=idx + 1, column=3, padx=5, pady=5)

    def delete_row(self, idx):
        del data_list[idx]
        self.update_table()

# Run the app
if __name__ == "__main__":
    root = tk.Tk()
    app = PasswordApp(root)
    root.mainloop()
