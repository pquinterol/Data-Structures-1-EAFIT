#include "fileReader.h"

fileReader::fileReader(){

//Se inicilizan los maximos y minimos en 0.0 ya que estos iran cambiando a medida que se leen las coordenadas del archivo.
    maxX = 0.0;
    minX = 0.0;
    maxY = 0.0;
    minY = 0.0;
    maxZ = 0.0;
    minZ = 0.0;
}

void fileReader::maxLim(double& num1, double& num2){

    
    if(num1==0.0){
        num1 = num2;
    }else{

        if(num1<num2){
            num1 = num2;
        }

    }

}

void fileReader::minLim(double& num1, double& num2){

    if(num1 == 0.0){
        num1 = num2;
    }else{

        if(num1>num2){
            num1 = num2;
        }
    }

}

//Este codigo lo escribi de manera opcional por si en algun momento se desea escribir los resultados en un archivo de texto.
//Fue de Prueba.
void fileReader::write(){

    ofstream file;
    string name, text;

    cout<<"Enter your name"<<endl;
    getline(cin,name);

    file.open(name.c_str(),std::ofstream::out);

    if(file.fail()){
        cout<<"The file cant be open!"<<endl;

        exit(1);
    }

    cout<<"Write the txt you wanna save"<<endl;
    getline(cin, text);

    file<<text;

    file.close();

}

//Metodo encargado de leer el archivo de texto. Recive como parametro la ubicacion del archivo.

void fileReader::read(string path){

    ifstream file;
    string data,limit;
    double x,z,y;

    file.open(path,ios::in);

    while(file.fail()){

       std::cout<<"Ubicacion o archivo invalido. Digite de nuevo"<<endl;
       getline(cin,path);
       file.open(path,ios::in);

    }

    getline(file,data);
    clock_t start = clock();
    int cont=0;

    while(!file.eof()){

        getline(file,data);

        if(!file.eof()){

            //Se optiene la posicion de la primera "," en la linea que se esta leyendo.
            size_t last = data.find_last_of(',');

            limit = data.substr(0,data.find(','));
            x = (::stod(limit)+SUMX)*111111;
            maxLim(maxX,x);
            minLim(minX,x);

            limit = data.substr(last+1);

            z = ::stod(limit);
            maxLim(maxZ,z);
            minLim(minZ,z);

            y = (::stod(data.substr(data.find(',')+1,10))-SUMY)*111111;
            maxLim(maxY,y);
            minLim(minY,y);

            Circle* c = new Circle(x,y,z);
            lA.push_back(new Bees(x,y,z,c));

            

        }else{

            break;

        }

        
        cont++;
    }


    printf("Time taken: %.2fs\n", (double)(clock() - start)/CLOCKS_PER_SEC);

    file.close();
    

}

/*
El metodo check se encarga de ingresar las abejas obtenidas del metodo de lectura read al quadtree que se crea con la max y minimos generados por esta.
Este codigo tambien es el encargado de llamar a la funcion query de Quadtree, la cual analiza por cada abeja cuales estan en su rango.
*/

void fileReader::check(){

  cout<<lA.size()<<endl;
  system("pause");

  clock_t start = clock();

  //Se crea el cuadrado padre, del cual partira el quadtree.
  Square* c = new Square(minX,minY,maxX,maxY);
  Quadtree* quad = new Quadtree(c,bcollided);

//Se inserta cada abeja en el cuadtree y se analiza si colisiona con alguna.
  for(itLA = lA.begin();itLA!=lA.end();itLA++){

     (*quad).insert((*itLA));

     (*quad).query((*itLA),bcollided);


  }
   printf("Time taken: %.2fs\n", (double)(clock() - start)/CLOCKS_PER_SEC);

  cout<<bcollided.size()<<endl;

}

//El metodo printCol hace un llamado por cada abeja a la funcion printList de cada abeja para imprimir las colisiones de cada una.
void fileReader::printCol(){
    for(itLA=lA.begin();itLA!=lA.end();itLA++){
        (*itLA)->printList();
        system("pause");
    }
}