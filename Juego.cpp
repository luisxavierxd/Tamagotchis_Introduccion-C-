#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std;
class jugador;

///////////////////////////////////////// TAMAGOCHIS /////////////////////////////////////////////////////////////////////////////////////////////
class tamagochi {
    protected:
        string nombre;
        int felicidad, hambre, energia, higiene;
    public:
        tamagochi(string n): //inicializando dentro del constructor
            nombre(n),
            felicidad(10),
            hambre(10),
            energia(10),
            higiene(10)
            {}//cerrar el constructor
        void setFelicidad(int f){felicidad=f;}
        void setHambre(int h){hambre=h;}
        void setEnergia(int e){energia=e;}
        void setHigiene(int c){higiene=c;}

        string getNombre(){return nombre;}
        int getHambre(){return hambre;}
        int getFelicidad(){return felicidad;}
        int getEnergia(){return energia;}
        int getHigiene(){return higiene;}

        virtual ~tamagochi() = default;
        virtual void tiempo(){
        if (felicidad-1<=0){
            felicidad=0;
        }
        else{
            felicidad-=1;
        }
        if (hambre-1<=0){
            hambre=0;
        }
        else{
            hambre-=1;
        }
        if (energia-1<=0){
            energia=0;
        }
        else{
            energia-=1;
        }
        if (higiene-1<=0){
            higiene=0;
        }
        else{
            higiene-=1;
        }
         }
        virtual void dormir(){
            energia+=5;
            cout<<"Tu mascota "<<nombre<< " se siente con más energía" <<endl;
        }
        virtual void jugar(){
            felicidad+=5;
            cout<<"Tu mascota "<<nombre<< " se siente feliz :-)" <<endl;
        }
        virtual void alimentar(){
            hambre+=5;
            cout<<"Tu mascota "<<nombre<< " se siente llenito" <<endl;
        }
        virtual void bañar(){
            higiene+=5;
            cout<<"Tu mascota "<<nombre<< " se siente más limpio" <<endl;
        }

        virtual void reaccionJuguete(){
                cout<<"Tu tamagochi está feliz :U"<<endl;
                }

        virtual void estadoActual(){
            cout<<" "<<nombre<<" [Hambre: "<<hambre<<" Higiene: "<<higiene<<" Energía: "<<energia<<" Felicidad: "<<felicidad<<"]"<<endl;
        }
        virtual void nombreTamagochi(){
            cout<<" "<<nombre<<endl;

        }

        virtual string getEspecial(){
            return "Este tamagochi no tiene especial :c";           
        }
        virtual void usarEspecial(jugador& jugadorOwner, int idx) {
        cout << "No tiene especial para usar.\n"<<endl;
    }
        
};

/////////////////////////////////////////////////S U B C L A S E S/////////////////////////////////////////////////////////////////////

class conejo: public tamagochi{
    private:
    public:
        conejo(string n):
            tamagochi (n)
            {}

        void reaccionJuguete() override{
                cout<<"Tu conejo juega con su peluche :U"<<endl;
                }

        string getEspecial() override{
            return "Este tamagochi se puede reproducir por mitosis :D";           
        }

        void reproducirse(jugador& jugadorOwner);
        void usarEspecial(jugador& jugadorOwner, int idx) override; 

};
class tambor:public tamagochi{
private:
    
public:
    tambor(string n):
    tamagochi(n)
    {}
    
    void tocarMelodia() {
        constexpr int REST = 0;

        // Notas (frecuencias en Hz)
        constexpr int NOTE_B0 = 31;
        constexpr int NOTE_C1 = 33;
        constexpr int NOTE_CS1 = 35;
        constexpr int NOTE_D1 = 37;
        constexpr int NOTE_DS1 = 39;
        constexpr int NOTE_E1 = 41;
        constexpr int NOTE_F1 = 44;
        constexpr int NOTE_FS1 = 46;
        constexpr int NOTE_G1 = 49;
        constexpr int NOTE_GS1 = 52;
        constexpr int NOTE_A1 = 55;
        constexpr int NOTE_AS1 = 58;
        constexpr int NOTE_B1 = 62;
        constexpr int NOTE_C2 = 65;
        constexpr int NOTE_CS2 = 69;
        constexpr int NOTE_D2 = 73;
        constexpr int NOTE_DS2 = 78;
        constexpr int NOTE_E2 = 82;
        constexpr int NOTE_F2 = 87;
        constexpr int NOTE_FS2 = 93;
        constexpr int NOTE_G2 = 98;
        constexpr int NOTE_GS2 = 104;
        constexpr int NOTE_A2 = 110;
        constexpr int NOTE_AS2 = 117;
        constexpr int NOTE_B2 = 123;
        constexpr int NOTE_C3 = 131;
        constexpr int NOTE_CS3 = 139;
        constexpr int NOTE_D3 = 147;
        constexpr int NOTE_DS3 = 156;
        constexpr int NOTE_E3 = 165;
        constexpr int NOTE_F3 = 175;
        constexpr int NOTE_FS3 = 185;
        constexpr int NOTE_G3 = 196;
        constexpr int NOTE_GS3 = 208;
        constexpr int NOTE_A3 = 220;
        constexpr int NOTE_AS3 = 233;
        constexpr int NOTE_B3 = 247;
        constexpr int NOTE_C4 = 262;
        constexpr int NOTE_CS4 = 277;
        constexpr int NOTE_D4 = 294;
        constexpr int NOTE_DS4 = 311;
        constexpr int NOTE_E4 = 330;
        constexpr int NOTE_F4 = 349;
        constexpr int NOTE_FS4 = 370;
        constexpr int NOTE_G4 = 392;
        constexpr int NOTE_GS4 = 415;
        constexpr int NOTE_A4 = 440;
        constexpr int NOTE_AS4 = 466;
        constexpr int NOTE_B4 = 494;
        constexpr int NOTE_C5 = 523;
        constexpr int NOTE_CS5 = 554;
        constexpr int NOTE_D5 = 587;
        constexpr int NOTE_DS5 = 622;
        constexpr int NOTE_E5 = 659;
        constexpr int NOTE_F5 = 698;
        constexpr int NOTE_FS5 = 740;
        constexpr int NOTE_G5 = 784;
        constexpr int NOTE_GS5 = 831;
        constexpr int NOTE_A5 = 880;
        constexpr int NOTE_AS5 = 932;
        constexpr int NOTE_B5 = 988;
        constexpr int NOTE_C6 = 1047;
        constexpr int NOTE_CS6 = 1109;
        constexpr int NOTE_D6 = 1175;
        constexpr int NOTE_DS6 = 1245;
        constexpr int NOTE_E6 = 1319;
        constexpr int NOTE_F6 = 1397;
        constexpr int NOTE_FS6 = 1480;
        constexpr int NOTE_G6 = 1568;
        constexpr int NOTE_GS6 = 1661;
        constexpr int NOTE_A6 = 1760;
        constexpr int NOTE_AS6 = 1865;
        constexpr int NOTE_B6 = 1976;
        constexpr int NOTE_C7 = 2093;
        constexpr int NOTE_CS7 = 2217;
        constexpr int NOTE_D7 = 2349;
        constexpr int NOTE_DS7 = 2489;
        constexpr int NOTE_E7 = 2637;
        constexpr int NOTE_F7 = 2794;
        constexpr int NOTE_FS7 = 2960;
        constexpr int NOTE_G7 = 3136;
        constexpr int NOTE_GS7 = 3322;
        constexpr int NOTE_A7 = 3520;
        constexpr int NOTE_AS7 = 3729;
        constexpr int NOTE_B7 = 3951;
        constexpr int NOTE_C8 = 4186;
        constexpr int NOTE_CS8 = 4435;
        constexpr int NOTE_D8 = 4699;
        constexpr int NOTE_DS8 = 4978;

        // Tempo (pulsos por minuto)
        const int tempo = 150;

        // Melody array: pares de (nota, duración)
        int melody[] = {
        NOTE_D4,4, NOTE_A4,4, NOTE_A4,4,
        REST,8, NOTE_E4,8, NOTE_B4,2,
        NOTE_F4,4, NOTE_C5,4, NOTE_C5,4,
        REST,8, NOTE_E4,8, NOTE_B4,2,
        NOTE_D4,4, NOTE_A4,4, NOTE_A4,4,
        REST,8, NOTE_E4,8, NOTE_B4,2,
        NOTE_F4,4, NOTE_C5,4, NOTE_C5,4,
        REST,8, NOTE_E4,8, NOTE_B4,2,
        NOTE_D4,8, NOTE_F4,8, NOTE_D5,2,
        
        NOTE_D4,8, NOTE_F4,8, NOTE_D5,2,
        NOTE_E5,-4, NOTE_F5,8, NOTE_E5,8, NOTE_E5,8,
        NOTE_E5,8, NOTE_C5,8, NOTE_A4,2,
        NOTE_A4,4, NOTE_D4,4, NOTE_F4,8, NOTE_G4,8,
        NOTE_A4,-2,
        NOTE_A4,4, NOTE_D4,4, NOTE_F4,8, NOTE_G4,8,
        NOTE_E4,-2,
        NOTE_D4,8, NOTE_F4,8, NOTE_D5,2,
        NOTE_D4,8, NOTE_F4,8, NOTE_D5,2,

        NOTE_E5,-4, NOTE_F5,8, NOTE_E5,8, NOTE_E5,8,
        NOTE_E5,8, NOTE_C5,8, NOTE_A4,2,
        NOTE_A4,4, NOTE_D4,4, NOTE_F4,8, NOTE_G4,8,
        NOTE_A4,2, NOTE_A4,4,
        NOTE_D4,1,
        };

        int notes = sizeof(melody) / sizeof(melody[0]) / 2;

        
            // Calcular duración de la nota entera (whole note) en ms
        int wholenote = (60000 * 4) / tempo;

        
        int tiempo_acumulado = 0;
        const int tiempo_maximo = 7000; // 10 segundos en ms

    for (int i = 48; i < notes * 2; i += 2) {
        int note = melody[i];
        int durationDivisor = melody[i + 1];
        int noteDuration;
        if (durationDivisor > 0) {
            noteDuration = wholenote / durationDivisor;
        } else {
            noteDuration = wholenote / std::abs(durationDivisor);
            noteDuration = int(noteDuration * 1.5);
        }

        if (tiempo_acumulado + noteDuration > tiempo_maximo) {
            // Si la nota excede el tiempo, cortar la duración para no pasar 10s
            noteDuration = tiempo_maximo - tiempo_acumulado;
            if (noteDuration <= 0) break;
        }

        if (note == REST) {
            Sleep(noteDuration);
        } else {
            Beep(note, noteDuration * 9 / 10);
            Sleep(noteDuration / 10);
        }

        tiempo_acumulado += noteDuration;
        if (tiempo_acumulado >= tiempo_maximo) break;
        }
    }

            
  

    void reaccionJuguete() override{
                cout<<"Tu tambor rueda y toca música :U"<<endl;
                }

    void tocarMúsica(){
        cout << "Tu tambor toca una canción genial :D" << endl;
        std::thread hiloMusica(&tambor::tocarMelodia, this);
        hiloMusica.detach();  // Se ejecuta en paralelo sin bloquea
    }

    string getEspecial() override{
            return "Este tamagochi toca música :D";          
        }
    void usarEspecial(jugador& jugadorOwner, int idx) override {
        tocarMúsica();
    }
//afinacion
};

class estrella:public tamagochi{
    private:
        int cantidad_parpadeos,estabilidad,color;
    public:
        estrella(string n):
        tamagochi(n)
        {}

        void setCantidad_parpadeos(int capa){cantidad_parpadeos=capa;}
        void setEstabilidad(int est){estabilidad=est;}
        void setColor(int ce){color=ce;}

        int getCantidad_parpadeos(){return cantidad_parpadeos;}
        int getEstabilidad(){return estabilidad;}
        int getColor(){return color;}

        //destructor

        void reaccionJuguete() override{
                cout<<"Tu estrella destruye un planeta :U"<<endl;
                }

        void parpadeos(){
            cout << "\033[41;30m";
            cout << string(2000, ' '); // "Llena" la pantalla con rojo
            cout.flush();//pa que salgan al mismo tiempo
            cout << "\033[0m";
        }

        string getEspecial() override{
            return "Este tamagochi IMPLOSIONA :D";           
        }

        void usarEspecial(jugador& jugadorOwner, int idx) override;
    
};

///////////////////////////////////////// J U G A D O R /////////////////////////////////////////////////////////////////////////////////////////////

class jugador{
public:
    vector<tamagochi*>tamagochis;

    void eliminarTamagochi(int idx) {
        if (idx >= 0 && idx < (int)tamagochis.size()) {
            delete tamagochis[idx];
            tamagochis.erase(tamagochis.begin() + idx);
        }
    }

    ~jugador() {
        for (auto t : tamagochis)
            delete t;
        tamagochis.clear();
    }

    int cantidad_comida=0;
    int cantidad_juguetes=0;
    int cantidad_jabones=0;
    
    void adoptar(tamagochi*t){
        tamagochis.push_back(t);
    }
    void tiempo_todos(){
    for (auto t:tamagochis)
        t->tiempo();
    }
};

////////////////////////////////////////////////////                 I T E M S                              ////////////////////////////////////////////////////////////////////////////////////////

class item{
    protected:
        string nombre;
    public:
        item(string _nombre):
            nombre(_nombre)
            {}
        virtual ~item(){}
        virtual void usarItem(tamagochi*t)=0;//tamagochi[t] lista y la t es como si fuera el indice duh
        string getNombre() {return nombre;}
};

class comida:public item{
public:
    comida(): item("Comida"){}
    void usarItem(tamagochi*t)override{
        t->setHambre(t->getHambre()+4);
        cout<<"Tu mascota ya comió"<<endl;
    }
};

class juguete:public item{
public:
    juguete(): item("Juguete"){}
    void usarItem(tamagochi*t)override{
        t->setFelicidad(t->getFelicidad()+3);
        t->reaccionJuguete();
    }
};

class jabon:public item{
public:
    jabon(): item("Jabón"){}
    void usarItem(tamagochi*t)override{
        t->setHigiene(t->getHigiene()+3);
        cout<<"Tu tamagochi está más limpio ^^"<<endl;
    }
};

////////////////////////////////////////// E S P E C I A L   E S T R E L L A //////////////////////////////////////////////////////////////////////////////////////////////////
void estrella::usarEspecial(jugador& jugadorOwner, int idx) {
    estrella::parpadeos();
    cout << "\nImplosiona xP\n";
    jugadorOwner.eliminarTamagochi(idx);

}

void conejo::reproducirse(jugador& jugadorOwner){
            string nuevo_n;
        cout<<"Nombra a tu nuevo conejito ^^: ";
        cin>>nuevo_n;
        cout<<"¡¡Tienes una nueva mascota llamada: "<<nuevo_n<<" y es un conejo!!:D"<<endl;
        jugadorOwner.adoptar(new conejo(nuevo_n));
        }
void conejo::usarEspecial(jugador& jugadorOwner, int idx){
    reproducirse(jugadorOwner);
}

//////////////////////////////////////////// M A I N //////////////////////////////////////////////////////////////////////////////////////////////
void leerEntero(int &apruebademensos) {//el cosito este & es para cambiarle a int
    while (true) {
        cin >> apruebademensos;

        if (!cin.fail()) {// te regresa true si falla
            cin.ignore(10000, '\n');
            return;
        }

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ingresa un entero valido: ";
    }
}
int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int dinero=0;
    int opcion;
    bool jugando=true;
    jugador Jugador;
    Jugador.adoptar(new conejo("Conejo"));
    Jugador.adoptar(new estrella("Estrella"));
    Jugador.adoptar(new tambor("Tambor"));
    Jugador.cantidad_comida++;
    Jugador.cantidad_juguetes++;
    comida comida_objeto;
    juguete juguete_objeto;
    jabon jabon_objeto;


    while (jugando==true){
        regresar_menu:;
        
        dinero++;

        cout<<"---------------  T A M A G O C H I  ---------------"<<endl;
        cout<<"                                Dinero Actual: $ "<<dinero<<endl;
        cout<<"1. Ver stats tamagochis"<<endl;
        cout<<"2. Dormir a tu tamagochi"<<endl;
        cout<<"3. Jugar con el tamagochi"<<endl;
        cout<<"4. Alimentar al tamagochi"<<endl;
        cout<<"5. Bañar al tamagochi"<<endl;
        cout<<"6. Ver inventario y usar items"<<endl;
        cout<<"7. Comprar items"<<endl;
        cout<<"8. Especial del tamagochi :)"<<endl;
        cout<<"9. Pasar el tiempo con tu tamagochi"<<endl;
        cout<<"10. Adoptar"<<endl;
        cout<<"11. Abandonar"<<endl;
        cout<<"12. Salir"<<endl;
        cout<<"Ingresa el número de la opción: ";
        leerEntero(opcion);

        if (opcion==1){

            cout<<"-------------- T U S  T A M A G O C H I S --------------"<<endl;
            for (int i=0; i<Jugador.tamagochis.size();i++){
                cout<<i<<")";
                Jugador.tamagochis[i]-> estadoActual();
            }
            dinero--;
        }
        else if (opcion==2){
            int idxT=-1;
            cout<<"-------------- T U S  T A M A G O C H I S --------------\n";
            for (int i=0; i<Jugador.tamagochis.size(); i++){
                cout<<i<<") ";
                Jugador.tamagochis[i]->nombreTamagochi();
            }
            cout<<"Ingresa el número de la mascota a dormir: ";
            leerEntero(idxT);
            while(true){
                if(idxT == -1){
                cout<<"Acción cancelada.\n";
                goto regresar_menu;
                }
                if(idxT >= 0 && idxT < Jugador.tamagochis.size()){
                break;
                }
                cout<<"Ese tamagochi no existe. Escoge otro: ";
                leerEntero(idxT);
                }
            Jugador.tamagochis[idxT]->dormir();
            Jugador.tiempo_todos();
            }
        else if (opcion==3){
            int idxT=-1;
            cout<<"-------------- T U S  T A M A G O C H I S --------------\n";
            for (int i=0; i<Jugador.tamagochis.size(); i++){
                cout<<i<<") ";
                Jugador.tamagochis[i]->nombreTamagochi();
            }
            cout<<"Ingresa el número de la mascota para jugar: ";
            leerEntero(idxT);
            while(true){
                if(idxT == -1){
                cout<<"Acción cancelada.\n";
                goto regresar_menu;
                }
                if(idxT >= 0 && idxT < Jugador.tamagochis.size()){
                break;
                }
                cout<<"Ese tamagochi no existe. Escoge otro: ";
                leerEntero(idxT);
                }
            Jugador.tamagochis[idxT]->jugar();
            Jugador.tiempo_todos();
            }
        else if (opcion==4){
            int idxT=-1;
            cout<<"-------------- T U S  T A M A G O C H I S --------------\n";
            for (int i=0; i<Jugador.tamagochis.size(); i++){
                cout<<i<<") ";
                Jugador.tamagochis[i]->nombreTamagochi();
            }
            cout<<"Ingresa el número de la mascota a alimentar: ";
            leerEntero(idxT);
            while(true){
                if(idxT == -1){
                cout<<"Acción cancelada.\n";
                goto regresar_menu;
                }
                if(idxT >= 0 && idxT < Jugador.tamagochis.size()){
                break;
                }
                cout<<"Ese tamagochi no existe. Escoge otro: ";
                leerEntero(idxT);
                }
            Jugador.tamagochis[idxT]->alimentar();
            Jugador.tiempo_todos();
            }
        else if (opcion==5){
            int idxT=-1;
            cout<<"-------------- T U S  T A M A G O C H I S --------------\n";
            for (int i=0; i<Jugador.tamagochis.size(); i++){
                cout<<i<<") ";
                Jugador.tamagochis[i]->nombreTamagochi();
            }
            cout<<"Ingresa el número de la mascota a bañar: ";
            leerEntero(idxT);
            while(true){
                if(idxT == -1){
                cout<<"Acción cancelada.\n";
                goto regresar_menu;
                }
                if(idxT >= 0 && idxT < Jugador.tamagochis.size()){
                break;
                }
                cout<<"Ese tamagochi no existe. Escoge otro: ";
                leerEntero(idxT);
                }
            Jugador.tamagochis[idxT]->bañar();
            Jugador.tiempo_todos();
            }
        else if (opcion==6){
            int usar_item = 0;
            int mascota_item = -1;
            int item_usar = 0;
            if (Jugador.cantidad_comida==0 && Jugador.cantidad_juguetes==0 && Jugador.cantidad_jabones==0){
                cout<<"No tienes items :c nuv"<<endl;
                continue;
            }
            cout<<"------------------- I N V E N T A R I O -------------------\n";
            cout<<"Comida disponible: "<<Jugador.cantidad_comida<<"\n";
            cout<<"Juguetes disponibles: "<<Jugador.cantidad_juguetes<<"\n";
            cout<<"Jabones disponibles: "<<Jugador.cantidad_jabones<<"\n";

            // Preguntar si quiere usar algo
            while(usar_item != 1 && usar_item != 2){
                cout<<"¿Quieres usar algún item?\n1) Sí\n2) No\nOpción: ";
                leerEntero(usar_item);
                if(usar_item != 1 && usar_item != 2){
                    cout<<"Opción inválida.\n";
                }
            }

            if(usar_item == 2){
                continue; // regresa al menú principal
            }

            // ==================== SELECCIÓN DE MASCOTA ====================

            cout<<"-------------- T U S  T A M A G O C H I S --------------\n";
            for (int i=0; i<Jugador.tamagochis.size(); i++){
                cout<<i<<") ";
                Jugador.tamagochis[i]->nombreTamagochi();
            }

            cout<<"Elige un tamagochi (o -1 para cancelar): ";
            leerEntero(mascota_item);

            while(true){
                if(mascota_item == -1){
                    cout<<"Acción cancelada.\n";
                    goto regresar_menu;
                }
                if(mascota_item >= 0 && mascota_item < Jugador.tamagochis.size()){
                    break; // válido
                }
                cout<<"Ese tamagochi no existe. Escoge otro: ";
                leerEntero(mascota_item);
            }

            // ==================== SELECCIÓN DE ITEM ====================

            while(true){
                cout<<"¿Qué item quieres usar?\n";
                cout<<"1) Comida ("<<Jugador.cantidad_comida<<")\n";
                cout<<"2) Juguete ("<<Jugador.cantidad_juguetes<<")\n";
                cout<<"3) Jabón ("<<Jugador.cantidad_jabones<<")\n";
                cout<<"4) Salir\n";
                leerEntero(item_usar);

                if(item_usar == 4){
                    break;     // sale del menú y NO repite nada
                }

                if(item_usar == 1){
                    if(Jugador.cantidad_comida == 0){
                        cout<<"No tienes comida.\n";
                        continue;
                    }
                    comida_objeto.usarItem(Jugador.tamagochis[mascota_item]);
                    Jugador.cantidad_comida--;
                    break;
                }

                if(item_usar == 2){
                    if(Jugador.cantidad_juguetes == 0){
                        cout<<"No tienes juguetes.\n";
                        continue;
                    }
                    juguete_objeto.usarItem(Jugador.tamagochis[mascota_item]);
                    Jugador.cantidad_juguetes--;
                    break;
                }

                if(item_usar == 3){
                    if(Jugador.cantidad_jabones == 0){
                        cout<<"No tienes jabón.\n";
                        continue;
                    }
                    jabon_objeto.usarItem(Jugador.tamagochis[mascota_item]);
                    Jugador.cantidad_jabones--;
                    break;
                }

                cout<<"Opción inválida.\n";
            }
        }

        else if (opcion==7){
            int item_escogido=1;
            
            while (item_escogido !=4 ){
                inicio_tienda:;
                cout<<" ------------ T I E N D A ------------"<<endl;
                cout<<"Dinero Actual: $ "<<dinero<<endl;
                cout<<"1) Comida $ 4"<<endl;
                cout<<"2) Juguete a $5"<<endl;
                cout<<"3) Jabón $3"<<endl;
                cout<<"4) Salir"<<endl;
                leerEntero(item_escogido);

                if(item_escogido==4){
                    break;
                }
                else if (item_escogido==1){
                    if(dinero<4){
                        cout<<"No tienes suficiente dinero :c\n";
                        goto inicio_tienda;
                    }
                    Jugador.cantidad_comida++;
                    dinero-=4;
                    cout<<"Compraste una comida, tienes " <<Jugador.cantidad_comida<<" comidas" <<endl;
                }
                  else if (item_escogido==2){
                    if(dinero<5){
                        cout<<"No tienes suficiente dinero :c\n";
                        goto inicio_tienda;
                    }
                    Jugador.cantidad_juguetes++;
                    dinero-=5;
                    cout<<"Compraste un juguete, tienes " <<Jugador.cantidad_juguetes<<" juguetes" <<endl;
                }
                  else if (item_escogido==3){
                    if(dinero<3){
                        cout<<"No tienes suficiente dinero :c\n";
                        goto inicio_tienda;
                    }
                    Jugador.cantidad_jabones++;
                    dinero-=3;
                    cout<<"Compraste un jabón, tienes " <<Jugador.cantidad_jabones<<" jabones" <<endl;
                }
                else{
                    cout<<"Item Invalido"<<endl;
                }
            }
        }

        else if (opcion==8){
            int idxT=-1;
            cout<<"-------------- T U S  T A M A G O C H I S --------------\n";
            for (int i=0; i<Jugador.tamagochis.size(); i++){
                cout<<i<<") ";
                Jugador.tamagochis[i]->nombreTamagochi();
            }
            cout<<"Ingresa el número de la mascota a realizar la opcion especial: ";
            leerEntero(idxT);
            while(true){
                if(idxT == -1){
                cout<<"Acción cancelada.\n";
                goto regresar_menu;
                }
                if(idxT >= 0 && idxT < Jugador.tamagochis.size()){
                break;
                }
                cout<<"Ese tamagochi no existe. Escoge otro: ";
                leerEntero(idxT);
                }
            cout<<Jugador.tamagochis[idxT]->getEspecial()<<endl;
            cout<<"Quieres usar el especial"<<endl;
            int usar_especial=0;
            cout<<"1) Sí"<<endl;
            cout<<"2) No"<<endl;
            especial:;
            leerEntero(usar_especial);
            if (usar_especial==1){
                Jugador.tamagochis[idxT]->usarEspecial(Jugador, idxT);
            }
            else if (usar_especial==2){
                cout<<"No usaste el especial"<<endl;
            }
            else{
                cout<<"Opción inválida: "<<endl;
                goto especial;
            }
            
            Jugador.tiempo_todos();
            }

        else if (opcion==9){
            cout<<"⧗ Está pasando el tiempo ⧗"<<endl;
            Jugador.tiempo_todos();
        }

        else if (opcion==10){
            int especie = -1;
            std::string nombre;

            while (true) {
                cout << "Selecciona la especie para adoptar:"<<endl;
                cout << "1) Conejo"<<endl;
                cout << "2) Estrella"<<endl;
                cout << "3) Tambor"<<endl;
                cout << "0) Cancelar y regresar al menú"<<endl;
                cout << "Elige una opción: ";
                leerEntero(especie);

                if (especie == 0) {
                    cout << "Adopción cancelada. Regresando al menú principal.\n";
                    break;
                }
                if (especie < 1 || especie > 3) {
                    cout << "Opción inválida, selecciona 1, 2, 3 o 0 para cancelar.\n";
                    continue;
                }
                // especie válida, salir del loop
                break;
            }

            if (especie == 0) {
                goto regresar_menu;
            }

            while (true) {
                cout << "Ingresa el nombre para tu nuevo tamagochi (0 para cancelar): ";
                std::getline(std::cin, nombre);

                if (nombre.empty()) {
                    std::getline(std::cin, nombre);
                }

                if (nombre == "0") {
                    cout << "Adopción cancelada. Regresando al menú principal.\n";
                    goto regresar_menu;
                }

                if (nombre.empty()) {
                    cout << "El nombre no puede estar vacío.\n";
                    continue;
                }

                break;
            }

            if (especie == 1) {
                Jugador.adoptar(new conejo(nombre));
                cout << "¡Has adoptado un nuevo Conejo llamado " << nombre << "!\n";
            }
            else if (especie == 2) {
                Jugador.adoptar(new estrella(nombre));
                cout << "¡Has adoptado una nueva Estrella llamada " << nombre << "!\n";
            }
            else if (especie == 3) {
                Jugador.adoptar(new tambor(nombre));
                cout << "¡Has adoptado un nuevo Tambor llamado " << nombre << "!\n";
            }
        }

        else if (opcion == 11) {  // Opción para abandonar tamagochi
            if (Jugador.tamagochis.empty()) {
                cout << "No tienes tamagochis para abandonar.\n";
                continue;
            }

            int idxAbandonar;
            cout << "-------------- T U S  T A M A G O C H I S --------------\n";
            for (int i = 0; i < Jugador.tamagochis.size(); i++) {
                cout << i << ") ";
                Jugador.tamagochis[i]->nombreTamagochi();
            }
            cout << "Ingresa el número del tamagochi que quieres abandonar (-1 para cancelar): ";

            while (true) {
                leerEntero(idxAbandonar);

                if (idxAbandonar == -1) {
                    cout << "Abandono cancelado. Regresando al menú principal.\n";
                    break;
                }
                if (idxAbandonar >= 0 && idxAbandonar < (int)Jugador.tamagochis.size()) {
                    // Confirmación
                    cout << "¿Seguro que quieres abandonar a " << Jugador.tamagochis[idxAbandonar]->getNombre() << "? (1 = Sí, 2 = No): ";
                    int confirm;
                    while (true) {
                        leerEntero(confirm);
                        if (confirm == 1) {
                            Jugador.eliminarTamagochi(idxAbandonar);
                            cout << "Has abandonado a tu tamagochi.\n";
                            break;
                        } else if (confirm == 2) {
                            cout << "Abandono cancelado. Regresando al menú principal.\n";
                            break;
                        } else {
                            cout << "Opción inválida. Ingresa 1 para Sí o 2 para No: ";
                        }
                    }
                    break;
                } else {
                    cout << "Número inválido. Ingresa un índice válido o -1 para cancelar: ";
                }
            }
        }

        else if (opcion==12){
            cout<<"( ﾟдﾟ)つ Bye"<<endl;
            jugando=false;

        }

    }
    return 0;
}
    return 0;
}
