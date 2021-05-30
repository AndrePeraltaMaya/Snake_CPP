#include<iostream>
#include<windows.h> //usar funciones de ventana
#include<conio.h> //para las funciones de tiempos
#include<stdlib.h>
#include<time.h>

using namespace std;

//definimos nuestras constantes:
#define ARRIBA 72
#define IZQUIERDA 75
#define ABAJO 80
#define DERECHA 77
#define ESC 27

char tecla;
int cuerpo[200][2];
int n=1;
int tam = 3;
int x=10, y=12;
int dir=3;
int xc=30, yc=20;
int Puntos=0;
int xxc= 40, yyc=18;
int d;
int dif;
double tiempo = 0;

void dificultad(){

	while(TRUE){
        cout<<"\nSnake \n Elija una dificultad : \n 1: facil \n 2: media \n 3: dificil"<<endl;
        cin >> d;
        switch(d){
            case 1:
                dif=80;
                break;
            case 2:
                dif=60;
                break;
            case 3:
                dif=35;
                break;
            default:
                dif = FALSE;
        }
        if(dif != FALSE){
            break;
        }
        else{
            cout << "Esa dificultad no existe, elija de nuevo";
        }


	}
	system("cls");
}
/**---------------  VENTANA -------------------**/
void gotoxy(int x,int y){
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;

	SetConsoleCursorPosition(hCon,dwPos);
}
/**---------------  PINTAR EN VENTANA -------------------**/
void pintar(){
    /*
    Pinta en pantalla
    */

    //LINEAS HORIZONTALES
    for(int i=2; i<78;i++){
		gotoxy(i,3);cout<<(char)205;
		gotoxy(i,23);cout<<(char)205;
	}
	//LINEAS VERTICALES
	for(int i=4;i<23;i++){
		gotoxy(2,i); cout<<(char)186;
		gotoxy(77,i); cout<<(char)186;
	}
	//ESQUINAS
	gotoxy(2,3);cout<<(char)201;
	gotoxy(2,23);cout<<(char)200;
	gotoxy(77,3);cout<<(char)187;
	gotoxy(77,23);cout<<(char)188;

}
/**-------------- DIBUJA LA SERPIENTE EN PANTALLA --------------**/
void dibujarcuerpo(){

	for(int i=1; i<tam;i++){
		gotoxy(cuerpo[i][0],cuerpo[i][1]); cout<<"*";
	}
}

void guardarposicion(){

	cuerpo[n][0]=x;
	cuerpo[n][1]=y;
	n++;
	if (n==tam){n=1;}
	dibujarcuerpo();
}

/**----------  ILUCION DE MOVIMIENTO  --------**/
void borrarcuerpo(){

		gotoxy(cuerpo[n][0],cuerpo[n][1]); cout<<" ";
		guardarposicion();
	}

/**----------  TECLAS  --------**/
void Teclear(){

	if (kbhit()){

		tecla=getch();

		switch(tecla){
			case ARRIBA:
			if (dir !=2){dir=1;}
			break;
			case ABAJO:
			if(dir != 1 ){dir=2;}
			break;
			case IZQUIERDA:
			if (dir != 3){dir=4;}
			break;
			case DERECHA:
			if (dir != 4){dir=3;}
			break;
		}
	}

}
/**----------  SI COME SE AGRANDA  --------**/
void comida(){

	if (x==xc && y==yc) {
		srand((unsigned)time(NULL));
		xc=(rand()% 73)+4;
		srand((unsigned)time(NULL));
		yc=(rand()% 19)+4;
		tam++;
		gotoxy(xc,yc); cout<<(char)4;
		Puntos++;
		gotoxy(50,2);cout<<Puntos;
	}

}
/**----------  GAME OVER  --------**/
bool gameover(){

	if (y==3 || y== 23 || x==2 || x==77)
        return false;

	for (int j=tam-1; j>0;j--){
		if(cuerpo[j][0]==x && cuerpo [j][1]==y)
            return false;
	}
	return true;
}

void puntosx(){

	tiempo=tiempo+0.05;
	int tiempo2=tiempo;
	gotoxy(35,2);cout<<tiempo;
	if (x==xxc && y== yyc){
		srand((unsigned)time(NULL));
		xxc=(rand()%73)+4;
		srand((unsigned)time(NULL));
		yyc=(rand()%19)+4;
		Puntos=Puntos+5;
        gotoxy(50,2);cout<<Puntos;
	}
	if (tiempo2 %10==0){
	    gotoxy(xxc,yyc); cout<<(char)6;
	} else if (tiempo2 %15==0){
		gotoxy(xxc,yyc); cout<<" ";
		srand((unsigned)time(NULL));
		xxc=(rand()%73)+4;
		srand((unsigned)time(NULL));
		yyc=(rand()%19)+4;
	}
}

void proceso(){

	borrarcuerpo();
	comida();
	puntosx();
	Teclear();
	Teclear();
	if (dir==1){y--;}
	if (dir==2){y++;}
	if (dir==3){x++;}
	if (dir==4){x--;}
	Sleep(dif);
}

/**-----------MAIN-------------**/

int main(){

    dificultad();
    gotoxy(50,2);cout<<Puntos;
    pintar();
    gotoxy(xc,yc);cout<<(char)4;

    while(tecla != ESC  ){
        proceso();

        if ( !gameover()){
            system("cls");
            cout << "Has perdido";
            cout << "Volver a jugar? \n Sí: 1 \n No: 2 \n";
            int regreso;
            cin >> regreso;
            if(regreso == 2){
                break;
            }else{

                cuerpo[200][2];
                n=1;
                tam = 3;
                x=10, y=12;
                dir=3;
                xc=30, yc=20;
                Puntos=0;
                xxc= 40, yyc=18;
                d;
                dif;
                tiempo = 0;

                dificultad();
                gotoxy(50,2);cout<<Puntos;
                pintar();
                gotoxy(xc,yc);cout<<(char)4;

            }
        }

    }
        system("pause>NULL");
        return 0;

}
