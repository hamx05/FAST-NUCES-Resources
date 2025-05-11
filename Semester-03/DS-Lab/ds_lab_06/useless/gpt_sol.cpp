if (input[i] == ')') {
    flagRightParenthesis = true;
    // Keep popping until you find '('
    while (s1.peek() != '(') {
        output += s1.pop();
    }
    s1.pop(); // '(' pop out here
    continue;  // **Added this line**: To avoid further precedence checks after closing parenthesis.
}

// Set initial precedence and compare with the stack's top
int topPrecedence = 0;
int precedence = getPrecedence(input[i]);
if (s1.size != 0) {
    topPrecedence = getPrecedence(s1.peek());
}

// If the current operator has higher precedence, push it onto the stack
if (precedence > topPrecedence) {
    s1.push(input[i]);
} else {
    // **Fixed**: Continue popping while precedence is <= and size is not zero
    while (s1.size != 0 && precedence <= getPrecedence(s1.peek())) {
        output += s1.pop();
    }
    // **Push current operator onto the stack after popping**
    s1.push(input[i]);
}

// Rest of the code...
