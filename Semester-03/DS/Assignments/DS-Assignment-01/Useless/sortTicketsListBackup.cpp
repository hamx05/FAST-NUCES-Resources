void sortTickets(Ticket tickets[], int n) {

            ifstream inputFromFile;
            inputFromFile.open("config.txt");

            if (!inputFromFile) {
                cout<< "Error opening the file." << endl;
                return;
            }

            char ch;
            cout << "\nEnter sorting criteria (p for Priority, n for Name, t for Ticket Open Time): ";
            cin >> ch;

            if (ch != 'p' && ch != 'n' && ch != 't') {
                cout << "Tickets' sorting failed. Invalid sorting selection." << endl;
                return;
            }

            string algoChoice;
            getline(inputFromFile, algoChoice);

            if (algoChoice == "bubblesort") bubbleSortTickets(tickets, n, ch);
            else if (algoChoice == "insertionsort") insertionSortTickets(tickets, n, ch);
            else if (algoChoice == "selectionsort") selectionSortTickets(tickets, n, ch);
            else if (algoChoice == "quicksort") quickSortTickets(tickets, 0, n-1, ch, n);
            else if (algoChoice == "mergesort") mergeSortTickets(tickets, 0, n-1, ch, n);
            else cout << "Invalid sorting choice in the config file." << endl;
        }

        // Bubble Sort
        void bubbleSortTickets(Ticket tickets[], int n, char ch) {
            for (int i = 0; i < n - 1; i++) {
                bool flagSwap = false;
                for (int j = 0; j < n - i - 1; j++) {
                    bool condition;
                    if (ch == 'p') {
                        condition = tickets[j].getPriority() < tickets[j + 1].getPriority();
                    } else if (ch == 'n') {
                        condition = tickets[j].getCustomerName() > tickets[j + 1].getCustomerName();
                    } else {
                        condition = tickets[j].getTicketOpenTime() > tickets[j + 1].getTicketOpenTime();
                    }

                    if (condition) {
                        swap(tickets[j], tickets[j + 1]);
                        flagSwap = true;
                    }
                }
                if (!flagSwap) break;
            }
            updateTicketList(tickets, n);
        }
        
        // Insertion Sort
        void insertionSortTickets(Ticket tickets[], int n, char ch) {
            for (int i = 1; i < n; i++) {
                Ticket temp = tickets[i];
                int j = i - 1;
                
                while (j >= 0) {
                    bool condition;
                    if (ch == 'p') {
                        condition = temp.getPriority() > tickets[j].getPriority();
                    } else if (ch == 'n') {
                        condition = temp.getCustomerName() < tickets[j].getCustomerName();
                    } else {
                        condition = temp.getTicketOpenTime() < tickets[j].getTicketOpenTime();
                    }

                    if (!condition) break;
                    
                    tickets[j + 1] = tickets[j];
                    j--;
                }
                tickets[j + 1] = temp;
            }
            updateTicketList(tickets, n);
        }

        // Selection
        void selectionSortTickets(Ticket tickets[], int n, char ch) {
            for (int i = 0; i < n - 1; i++) {
                int minIndex = i;

                for (int j = i + 1; j < n; j++) {
                    bool condition;
                    if (ch == 'p') {
                        condition = tickets[j].getPriority() > tickets[minIndex].getPriority();
                    } else if (ch == 'n') {
                        condition = tickets[j].getCustomerName() < tickets[minIndex].getCustomerName();
                    } else {
                        condition = tickets[j].getTicketOpenTime() < tickets[minIndex].getTicketOpenTime();
                    }

                    if (condition) minIndex = j;
                }
                if (minIndex != i) swap(tickets[i], tickets[minIndex]);
            }
            updateTicketList(tickets, n);
        }

        // Quick Sort
        int partitionTickets(Ticket tickets[], int low, int high, char ch) {
            Ticket pivot = tickets[low];
            int start = low, end = high;

            while (start < end) {
                bool condition;
                while (start <= high) {
                    if (ch == 'p') condition = tickets[start].getPriority() >= pivot.getPriority();
                    else if (ch == 'n') condition = tickets[start].getCustomerName() <= pivot.getCustomerName();
                    else condition = tickets[start].getTicketOpenTime() <= pivot.getTicketOpenTime();

                    if (!condition) break;
                    start++;
                }
                while (end >= low) {
                    if (ch == 'p') condition = tickets[end].getPriority() < pivot.getPriority();
                    else if (ch == 'n') condition = tickets[end].getCustomerName() > pivot.getCustomerName();
                    else condition = tickets[end].getTicketOpenTime() > pivot.getTicketOpenTime();

                    if (!condition) break;
                    end--;
                }
                if (start < end) swap(tickets[start], tickets[end]);
            }
            swap(tickets[low], tickets[end]);
            return end;
        }

        void quickSortTickets(Ticket tickets[], int low, int high, char ch, int n) {
            if (low < high) {
                int pIndex = partitionTickets(tickets, low, high, ch);
                quickSortTickets(tickets, low, pIndex - 1, ch, n);
                quickSortTickets(tickets, pIndex + 1, high, ch, n);
                updateTicketList(tickets, n);
            }
        }

        // Merge Sort
        void mergeTickets(Ticket tickets[], int left, int mid, int right, char ch) {
            int n1 = mid - left + 1, n2 = right - mid;
            Ticket* leftArr = new Ticket[n1];
            Ticket* rightArr = new Ticket[n2];

            for (int i = 0; i < n1; i++) leftArr[i] = tickets[left + i];
            for (int j = 0; j < n2; j++) rightArr[j] = tickets[mid + 1 + j];

            int i = 0, j = 0, k = left;
            while (i < n1 && j < n2) {
                bool condition;
                if (ch == 'p') condition = leftArr[i].getPriority() > rightArr[j].getPriority();
                else if (ch == 'n') condition = leftArr[i].getCustomerName() <= rightArr[j].getCustomerName();
                else condition = leftArr[i].getTicketOpenTime() <= rightArr[j].getTicketOpenTime();

                if (condition) tickets[k++] = leftArr[i++];
                else tickets[k++] = rightArr[j++];
            }

            while (i < n1) tickets[k++] = leftArr[i++];
            while (j < n2) tickets[k++] = rightArr[j++];

            delete[] leftArr;
            delete[] rightArr;
        }

        void mergeSortTickets(Ticket tickets[], int left, int right, char ch, int n) {
            if (left < right) {
                int mid = left + (right - left) / 2;
                mergeSortTickets(tickets, left, mid, ch, n);
                mergeSortTickets(tickets, mid + 1, right, ch, n);
                mergeTickets(tickets, left, mid, right, ch);
                updateTicketList(tickets, n);
            }
        }

        // Update the Linked List with sorted tickets array
        void updateTicketList(Ticket tickets[], int n) {
            Node *temp = head;
            for (int i = 0; i < n; i++) {
                temp->ticket = tickets[i];
                temp = temp->next;
            }
        }

        // using shell sort; some flaws were fixed by gpt
        void shellSortTickets(Ticket tickets[], int n, char ch) {
            if (ch != 'p' && ch != 'n' && ch != 't') {
                cout << "Tickets' sorting failed. Invalid sorting selection." << endl;
                return;
            }

            for (int gap = n / 2; gap > 0; gap /= 2) {
                for (int i = gap; i < n; i++) {
                    Ticket temp = tickets[i];
                    int j;

                    for (j = i; j >= gap; j -= gap) {
                        bool condition;
                        if (ch == 'p') { // sort by priority (higher priority comes first)
                            condition = temp.getPriority() > tickets[j - gap].getPriority();
                        } else if (ch == 'n') { // sort by customer name in lexicographical order
                            condition = temp.getCustomerName() < tickets[j - gap].getCustomerName();
                        } else { // sort by time (earliest comes first)
                            condition = temp.getTicketOpenTime() < tickets[j - gap].getTicketOpenTime();
                        }

                        if (condition) tickets[j] = tickets[j - gap];
                        else break;
                    }
                    tickets[j] = temp;
                }
            }
            updateTicketList(tickets, n);
        }