#include "dialetto.h"
#include <iostream>
#include <fstream>
#include <random>
#include <string>

// Strutura par el magnar
paco_de_roba Piato {
    frase nome;
    beo_preciso prezzo;
    numero disponibiita;
};

frase messaggio_benvegnuo sensa_argomenti fa
    ciapaqua "Benvegnuo all'Osteria C++! Qua te poi magnar e bevar fin che te vol!" ;
bon

frase messaggio_saluti argomenti frase nome_cliente ebasta fa
    ciapaqua "Grazie de esser vegnu, " + nome_cliente + "! Torna quando te vol!" ;
bon

programma fa

    no_cambia numero MAX_ORDINI = 5;
    Piato menu[3] = fa 
        {"Bigoli in salsa", 12.50, 10},
        {"Baccala mantecato", 15.00, 5},
        {"Ombra de vin", 1.50, 100}
    bon;

    numero sielta;
    beo_preciso conto_total = 0.0;
    vero_falso continua = vero;

    scrivi << messaggio_benvegnuo sensa_argomenti << acapo
    frase nome_cliente;
    scrivi << "Come te ciami? ";
    leggi >> nome_cliente;


    finche (continua) fa
        scrivi << "1. Varda el menu" << acapo
        scrivi << "2. Ordina qualcosa" << acapo
        scrivi << "3. Paga el conto e va casa" << acapo
        scrivi << "Sielta: ";
        leggi >> sielta;

        controea (sielta) fa
            se_xe 1:
                par_ogni (numero i = 0; i < 3; i++) fa
                    scrivi << i << ": " << menu[i].nome << " - " << menu[i].prezzo << " euro" << acapo
                bon
                scrivi << "----------------------------" << acapo
                fermite
            
            se_xe 2:
                numero indice;
                scrivi << "Cossa vuto magnar? (numero): ";
                leggi >> indice;

                se (indice >= 0 e_anca indice < 3) fa
                    se (menu[indice].disponibiita > 0) fa
                        conto_total zontighe menu[indice].prezzo;
                        menu[indice].disponibiita = menu[indice].disponibiita - 1;
                        scrivi << "Ghe vegne su un bel piato de " << menu[indice].nome << acapo
                    bon
                    senno fa
                        scrivi << "Finio tuto, te si riva tardi!" << acapo
                    bon
                bon
                senno fa
                    scrivi << "No sta inventar piati che no esiste!" << acapo
                bon
                fermite

            se_xe 3:
                continua = mia_vero;
                fermite

            altrimenti:
                scrivi << "Sito mato? Schicia i tasti giusti!" << acapo
                fermite
        bon
    bon

    // Risultato finae
    scrivi << "----------------------------" << acapo
    se (conto_total > 50.0) fa
        scrivi << "Te ghe magna come un bueo, te devi pagar: " << conto_total << "  euro" << acapo
    bon
    senno se (conto_total == 0.0)fa
        scrivi << "Te si vegnu solo par far do ciacole? Va via!" << acapo
    bon
    senno fa
        scrivi << "Conto onesto: " << conto_total << "  euro" << acapo
    bon

    scrivi << messaggio_saluti argomenti nome_cliente ebasta << acapo
    ciapaqua 0;
fine