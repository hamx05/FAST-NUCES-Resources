for (i=0; i<N; i++) { // Loop chalana ha to show all the pets, uske baad user se poochunga k konsa pet lena ha usko
                cout<<"\tDetails for Pet " << i+1 << endl;
                cout<< "Pet name: " << adoptedPetRecords[i].getName() << endl;
                cout<< "Pet specie: " << adoptedPetRecords[i].getSpecies() << endl;
                cout<< "Pet health status: " << adoptedPetRecords[i].getHealthStatus() << endl;
                for (int j=0; j<3; j++) {
                    cout<< "Pet special skills:  " << adoptedPetRecords[i].getSpecialSkill(j) << endl;
                }

                
            }