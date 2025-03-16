# C-exercises
Exercitii in C
Explicatie rezolvari:
Explicare rezolvare cerinte:

!Pe parcursul codului exista comentarii care noteaza functia adiacenta fiecarei
cerinte, in main fiind doar afisarea datelor prelucrate, de asemenea majoritatea
functiilor au numele subpunctului echivalent rezolvarii!

CERINTA 1
 -subpunct 1
   Citirea se face majoritar prin scanf-uri, cu exceptia citirii mesajelor
care sunt citite prin fgets deoarece sunt propozitii cu spatii. Alocarea
mesajelor se face prin alocare dinamica, initial folosind malloc, ulterior 
realoc pt alocare exacta a spatiului necesar.
   Datele sunt citite in 2 vectori de structuri, una a cartierelor (nrC[]
de la numarul cartierelor) si una a pachetelor (pac[]de la pachete).
 -subpunct 2
   Pentru rezolvarea celui de al doilea subpunct au fost necesar2 2 functii
adiacenta numite putere2 si transformare. Putere2 e folosita pentru calculul 
2^n care este utilizat pentru transformarea unui vector de 0 si 1 in baza 10
in functia transformare. Ulterior cele doua sunt folosite in functia adiacenta
subpunctului care imparte vectorul in trei vectori diferiti pe care ii transforma
in baza 10 si completeaza field-urile necesare cu informatiile prelucrate
(adica cartier strada si numar).
 -subpunct 3
   Pentru acest subpunct am creat vectorul de structuri al postasilor numit post[].
Functia le distribuie pe baza id-urilor postasilor si a id-urilor cartierelor.
Fiecare postas are vectorul dedistribuit[] unde se afla toate pachetele corespondente
lui. Vectorul dim[] tine numarul de pachete detinut de fiecare postas (de ex postasul
i are dim[i] pachete).
 -subpunct 4
   Avem 2 fuctii, una de swap care interschimba variabilele pentru un cod mai usor de citit
si cea care rezolva exercitiul. Sortarea pachetelor se face printr-un bubble sort modificat
pentru a tine cont de prioritate precum si de greutate. Swap-ul se face in cadrul vectorului
dedistribuit prin care se afiseaza pachetele.
 -subpunct 5
   Acest subpunct are 2 functii. Prima are rolul de a scoate toate semnele de punctuatie cu
ajutorul functiei ispunct din biblioteca ctype.h, si de a inversa ordinea cuvintelor. Modul
in care functioneaza este cautarea spatiilor dintre cuvinte si updatand inceputul si sfarsitul 
fiecarui cuvant, urmand sa le puna intr-un vector de cuvinte numit dup. Primul cuvant este pus
"manual" deoarece propozitia nu are spatiu la inceput. La final se face o eradicare a caracterelor
parazitare (adica spatii, endline-uri etc). A doua functie aplica formula pentru determinarea
codului fiecarui mesaj.

CERINTA 2
 -subpunct 1
   Este alcatuit din 3 funtii. Prima functie cauta ca macar o cifra din b sa se afle in a. A doua
functie creaza o lista de numere prime pana in 31 (deoarece cerinta mentioneza ca factorii mai)
mari de 31 sunt ignorati si verificare care dintre ei sunt factori primi ai nr-ului dat. Daca acestia
nu sunt, sunt transformati in 0, urmand ulterior sa fie copiati toate elementele care nu sunt 0 in 
vectorul div. A treia functie schimba bit-ul cerut prin utilizarea operatiei ^ si << (XOR respectiv
shiftare).
-cerinta 2
   Aceasta este singura cerinta care nu are o functie adiacenta, fiind usor facuta direct din afisare 
printr-o simpla verificare a egalitatii dintre coduri si calcularea punctajului.
