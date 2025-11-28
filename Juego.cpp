#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std;

//Creado por Luis Xavier García Pimentel Ascencio

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

        virtual ~tamagochi(){}
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

        virtual void reaccionJuguete(){
                cout<<"Tu tamagochi está feliz :U"<<endl;
                }

        virtual void estadoActual(){
        cout<<" "<<nombre<<" [Hambre: "<<hambre<<" Higiene: "<<higiene<<" Energía: "<<energia<<" Felicidad: "<<felicidad<<"]"<<endl;
        }
        virtual void nombreTamagochi(){
        cout<<" "<<nombre<<endl;

        }
};

/////////////////////////////////////////////////S U B C L A S E S/////////////////////////////////////////////////////////////////////

class conejo: public tamagochi{
    private:
        string colorPelo;
        char genero;
        int longitudPelo;
    public:
        conejo(string n):
            tamagochi (n),
            colorPelo("Blanco"),
            genero('F'),
            longitudPelo(1)
            {}
            void setColorPelo(string cp){colorPelo=cp;}
            void setGenero(char g){genero=g;}
            void setLongitudPelo(int l){longitudPelo=l;}

            string getColorPelo(){return colorPelo;}
            char getGenero(){return genero;}
            int getLongitudPelo(){return longitudPelo;}

            //falta destructor

        void reaccionJuguete() override{
                cout<<"Tu conejo juega con su peluche :U"<<endl;
                }

        void moverCola(){
            cout<<nombre<<"movió la cola :p"<<endl;
            felicidad++;
        }
        void reproducirse(){
            string nuevo_n;
            cout<<"Nombra a tu nuevo conejito ^^: ";
            cin>>nuevo_n;
            cout<<"¡¡Tienes una nueva mascota llamada: "<<nuevo_n<<"y es un conejo!!:D"<<endl;
        }
        void cortarPelo(){
            longitudPelo-=3;
        }
        void tenirPelo(){
            int nuevo_c;
            nuevo_c=0;
            while (nuevo_c<=4){
                cout<<"¿De qué color quieres teñirle el pelo a tu conejo?:"<<endl;
                cout<<"1-Rosa";
                cout<<"2-Azul";
                cout<<"3-Morado";
                cout<<"4-Verde";
                cout<<"Ingresa el color por su número: ";
                while(true) {
                    cin >>nuevo_c;

                    if (!cin.fail()) {// te regresa true si falla
                        cin.ignore(10000, '\n');
                        return;
                    }

                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Ingresa un entero valido: ";
    }

                if (nuevo_c==1){
                    colorPelo="Rosa";
                    break;
                    }
                else if (nuevo_c==2){
                    colorPelo="Azul";
                    break;
                }
                else if (nuevo_c==3){
                    colorPelo="Morado";
                    break;
                }
                else if (nuevo_c==4){
                    colorPelo="Verde";
                    break;
                }
                else{
                    cout<<"Opción inválida, vuélvelo a ingresar: "<<endl;
                    cout<<"Ingresa el color por su número: ";
                    while (true) {
                        cin >> nuevo_c;
                        if (!cin.fail()) {// te regresa true si falla
                            cin.ignore(10000, '\n');
                            return;
                        }

                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Ingresa un entero valido: ";
    }
            }
        }
        }

};
class tambor:public tamagochi{
private:
    int tempo, cantidad_uso;
    bool afinacion;
public:
    tambor(string n):
    tamagochi(n),
    tempo(120),
    cantidad_uso(0),
    afinacion(true)
    {}
    void setTempo(int t){tempo=t;}
    void setCantidad_uso(int cu){cantidad_uso=cu;}
    void setAfinacion(bool a){afinacion=a;}

    int getTempo(){return tempo;}
    int getCantidad_uso(){return cantidad_uso;}
    bool getAfinacion(){return afinacion;}
//destructor

    void reaccionJuguete() override{
                cout<<"Tu tambor rueda y toca música :U"<<endl;
                }

    void tocarM1(){
    cout<<"Se tocó esta canción"<<endl;
    cantidad_uso++;
    }
    void tocarM2(){
    cout<<"Se tocó otra canción"<<endl;
    cantidad_uso++;
    }
    void tocarM3(){
    cout<<"Se tocó otra canción"<<endl;
    cantidad_uso++;
    }
//afinacion
};

class estrella:public tamagochi{
    private:
        int cantidad_parpadeos,estabilidad,color;
    public:
        estrella(string n):
        tamagochi(n),
        cantidad_parpadeos(0),
        estabilidad(10),
        color(47)
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
        cout << "\033[47;30m";
        cout << string(2000, ' '); // "Llena" la pantalla con rojo
        cout.flush();//pa que salgan al mismo tiempo
        cout << "\033[0m";
        }

        void hoyo_negro(){
        cout<<"Implosiona xP"<<endl;
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

///////////////////////////////////////// J U G A D O R /////////////////////////////////////////////////////////////////////////////////////////////

class jugador{
public:
    vector<tamagochi*>tamagochis;
    int cantidad_comida=0;
    int cantidad_juguetes=0;
    int cantidad_jabones=0;
    ~jugador(){
        for (auto t:tamagochis)delete t;
    }
    void adoptar(tamagochi*t){
    tamagochis.push_back(t);
    }
    void tiempo_todos(){
    for (auto t:tamagochis)
        t->tiempo();
    }
};

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
        cout<<"3. Ver inventario y usar items"<<endl;
        cout<<"4. Comprar items"<<endl;
        cout<<"5. Pasar el tiempo con tu tamagochi"<<endl;
        cout<<"6. Salir"<<endl;
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

        else if (opcion==4){
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
                    cout<<"Compraste una comida, tienes " <<Jugador.cantidad_comida<<" comidas" <<endl;
                }
                  else if (item_escogido==2){
                    if(dinero<5){
                        cout<<"No tienes suficiente dinero :c\n";
                        goto inicio_tienda;
                    }
                    Jugador.cantidad_juguetes++;
                    cout<<"Compraste un juguete, tienes " <<Jugador.cantidad_juguetes<<" juguetes" <<endl;
                }
                  else if (item_escogido==3){
                    if(dinero<3){
                        cout<<"No tienes suficiente dinero :c\n";
                        goto inicio_tienda;
                    }
                    Jugador.cantidad_jabones++;
                    cout<<"Compraste un jabón, tienes " <<Jugador.cantidad_jabones<<" jabones" <<endl;
                }
                else{
                    cout<<"Item Invalido"<<endl;
                }
            }
        }

        else if (opcion==5){
            cout<<"⧗ Está pasando el tiempo ⧗"<<endl;
            Jugador.tiempo_todos();
        }

        else if (opcion==6){
            cout<<"( ﾟдﾟ)つ Bye"<<endl;
            jugando=false;

        }

    }
    return 0;
}
