#include <iostream>

const int TABLE_SIZE = 10;

class Node{
public:
		
    int key;
    int value;  
    Node* next;

    Node(int k, int v){
        key = k;
        value = v;
        next = NULL;
    }
};

class hash_table{
public:
    Node* table[TABLE_SIZE];

    hash_table(){
        for(int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

    int hash(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key, int value) {
        int index = hash(key);
        Node* newNode = new Node(key, value);

        if(table[index] == NULL) {
            table[index] = newNode;
            std::cout << "Inserted " << key << " with Value " << value << " at Index " << index << std::endl;
        } 
		else{
            Node* current = table[index];
            while(current != NULL) {
                current = current->next;
            }

            newNode->next = table[index];
            table[index] = newNode;
            std::cout << "Inserted " << key << " with Value " << value << " at Index " << index << " (Collision Handled)" << std::endl;
        }
    }

    void search(int key) {
        int index = hash(key);
        Node* current = table[index];

        while(current != NULL) {
            if(current->key == key) {
                std::cout << std::endl << key << " Found in Hash Table\n"; 
				return; 
            }
            current = current->next;
        }
        std::cout << std::endl << key << " not Found in Hash Table\n";  
    }

    void delete_ht(int key) {
        int index = hash(key);
        Node* current = table[index];
        Node* prev = NULL;

        while(current != NULL) {
            if(current->key == key) {
                if(prev == NULL) {
                    table[index] = current->next;
                } 
                else{
                    prev->next = current->next;
                }
                delete current;
                std::cout << "Deleted key " << key << " from Index " << index << std::endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        std::cout << std::endl << "Key " << key << " not Found in Hash Table" << std::endl;
    }

    void print_table(){
        for(int i = 0; i < TABLE_SIZE; i++) {
            std::cout << i << ": ";
            Node* current = table[i];
            
            while(current != NULL){
                std::cout << "(" << current->key << ", " << current->value << ") -> ";
                current = current->next;
            }
            std::cout << "NULL" << std::endl;
        }
    }
};

int main() {
    hash_table hash_table;
    
    hash_table.insert(20, 100);
    hash_table.insert(34, 200);
    hash_table.insert(45, 300);
    hash_table.insert(70, 400);
    hash_table.insert(56, 500);

    std::cout << "Hash Table After Insertion: " << std::endl;
    hash_table.print_table();

    hash_table.search(34);
    
    hash_table.delete_ht(34);
    hash_table.delete_ht(70);
    hash_table.delete_ht(100); 

    std::cout << std::endl << "Hash Table After Deletions: " << std::endl;
    hash_table.print_table();

    return 0;
}

