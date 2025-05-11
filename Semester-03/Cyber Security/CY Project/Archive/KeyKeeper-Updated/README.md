# KeyKeeper
***This password manager provides a secure and convenient way to store and manage your sensitive information. It uses advanced encryption algorithms to protect your passwords, usernames, and other credentials. By creating a secure account, you can access your encrypted data from any device. The user-friendly interface allows you to easily add, edit, and delete entries.***

## Overview
This project implements a secure passkey validation and storage system with basic hashing and validation functionalities. It allows users to:
1. Set up a passkey securely on first use.
2. Store the hashed passkey in a `.env` file for future validation.
3. Validate user input against the stored hashed passkey.
4. Perform secure MD5-like hashing using a custom implementation.

## Features
- **Custom MD5 Hash Implementation**: Implements a simplified version of the MD5 hashing algorithm to securely hash the passkey.
- **Secure Passkey Validation**: Validates user input passkeys against criteria (length, uppercase, digit, special character).
- **Environment-Based Storage**: Stores the hashed passkey in a `.env` file, ensuring sensitive information is not exposed.
- **User Validation**: Authenticates users by comparing input passkeys with stored hashes.
- **Error Handling**: Handles file-related and validation errors gracefully.
- **Kick Mechanism**: Notifies and exits the program after multiple failed authentication attempts.

## Requirements
- Python 3.6 or higher
- `os`, `re`, `struct` modules (built-in Python libraries)

## Installation
1. Clone the repository:
    ```bash
    git clone https://github.com/hxxmz/KeyKeeper.git
    cd KeyKeeper
    ```
2. Ensure Python is installed on your system.

## Usage
1. **First Run**:
    - On the first run, the program prompts the user to set up a secure passkey.
    - Passkey criteria:
        - Length: 8–15 characters.
        - Contains at least one uppercase letter.
        - Contains at least one digit.
        - Contains at least one special character (`!@#$%^&*(),.?":{}|<>`).
2. **Subsequent Runs**:
    - The program validates user input against the stored hashed passkey.
    - Users are given up to 5 attempts to enter the correct passkey.
3. **Failed Attempts**:
    - After 5 failed attempts, the user is "kicked," and the program exits.

## Example Workflow
- First run:
```
Enter the passkey: StrongPass1!
*** ALERT: Passkey is valid.
*** ALERT: Passkey stored. Please restart the program to proceed.
```
- Subsequent runs:
```
Passkey (5 tries left): StrongPass1!
*** ALERT: User validated successfully.
*** ALERT: Access granted.
```
- Failed attempts:
```
Passkey (1 try left): wrongPass
*** ALERT: Incorrect passkey. 0 tries remaining.
*** ALERT: Too many failed attempts.
*** ALERT: User kicked.
```

## Key Functions
- `simple_hash`: Implements a basic hashing algorithm (currently unused, can be replaced with md5).
- `md5`: Custom implementation of the MD5 hashing algorithm.
- `store_hashed_key`: Stores the hashed passkey in a .env file.
- `read_hashed_key`: Reads the stored hash from the .env file.
- `validate_passkey`: Validates the format of a passkey.
- `validate_user`: Verifies user input against the stored hashed passkey.
- `kickUser`: Notifies and exits after failed attempts.
- `exit`: Updates exit flags and safely shuts down the program.

## Security Notes
- **Hashing**: This project uses a custom MD5 implementation for hashing, primarily for learning purposes. For production-grade applications, use established cryptographic libraries like `hashlib` with algorithms such as SHA-256.
- **Environment File**: Ensure `.env` is properly secured and excluded from version control by adding it to `.gitignore`.

## Improvements
Potential enhancements for future versions:

- Encrypt the `.env` file for additional security.
- Implement rate-limiting to mitigate brute-force attempts.
- Replace the custom MD5 implementation with a more secure, tested library.

## Author
Developed by Me.

Let me know if you need to modify or add specific details!