#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int opc,n,i,pos,nf,region=16,BuscarFecha,k=1;
char nombre[20][20], ocupacion[20][20],BuscarNombre[20];
int rut[100],fecha[100],etapa[100],casosnuevos[100];
float UCIr[100],positividad[100],casosaislados[100],contactoscuarentena[100],seguimiento[100];

void opcion_1();
void opcion_2();
void opcion_3();
void opcion_4();
void opcion_5();
void siempre_vigente();
void cumplimiento_toquequeda_aduana();
void cuarentena_75();
void ProhibicionTraslado_RestriccionMovilidad();
void restriccion_de_operacion();
void cuarentena_ELEAM();
void restricciones_sectoriales();
void suspension_clase1();
void suspension_clase2();

int main() {
	do{
		system("cls");
		printf("Menu de navegacion COVID 19\n\n");
		printf("1.- Registro de usuario\n");
		printf("2.- Gestion de usuario\n");
		printf("3.- Gestion del plan paso a paso y medidas sanitarias  \n");
		printf("4.- Gestion de Medidas Sanitarias \n");
		printf("5.- Salir\n");
		printf("Opcion a escoger: ");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				opcion_1();
				break;
			case 2:
				opcion_2();
				break;
			case 3 :
				opcion_3();
				break;
			case 4:
				opcion_4();
				break;	
			case 5:
				opcion_5();
				break;	
			default:	
				system("cls");
				printf("La opcion que ingreso es incorrecta.\n");
				printf("Ingrese un valor de 1 a 5.");
				getch();
				break;
					
		}
	}while(opc !=5);
	
	return 0;
}

void opcion_1(){
	system("cls");
	printf("Ingrese cantidad de Personas a registrar: ");
	scanf("%i",&n);
				
	for(i=0;i<n;i++){
		printf("Ingrese Nombre numero %i: ",i+1);
		scanf("%s",nombre[i]);
	}
	for(i=0;i<n;i++){
		printf("Ingrese Ocupacion (Intendente/Seremi/Alcalde/Epidemiologico) de %s: ",nombre[i]);
		scanf("%s",ocupacion[i]);
	}
	for(i=0;i<n;i++){
		printf("ingrese rut de %s. Sin puntos y sin guion. Si termina en k reemplazar por 0: ",nombre[i]);
		scanf("%i",&rut[i]);
	}
				
	for(i=0;i<n;i++){
		printf("Ingrese fecha DIA/MES/ANIO en la que %s ingreso: ",nombre[i]);
		scanf("%i",&fecha[i]);
	}
	getch();
}
void opcion_2(){
	system("cls");
	while(k==1){
		printf("desea realizar la busqueda de usuario por (1)nombre o (2)fecha?: ");
		scanf("%d",&nf);
			if(nf==1){
				printf("Ingrese Nombre a buscar : ");
				scanf("%s",BuscarNombre);
							
				printf("Nombre a buscar: %s \n",BuscarNombre);
							
				for(i=0;i<n;i++){
								
					if(strcmp (BuscarNombre,nombre[i])==0){
						pos=i;
									
						printf("Rut: %d \n",rut[pos]);
						printf("Ocupacion: %s\n",ocupacion[pos]);
						printf("fecha: %i \n",fecha[pos]);
							
					}
							
				}
							
			}
			if (nf==2){
				printf("Ingrese la fecha a buscar : ");
				scanf("%i",&BuscarFecha);
							
				printf("Fecha a buscar: %d \n",BuscarFecha);
							
				for(i=0;i<n;i++){
					if(fecha[i]==BuscarFecha){
						pos=i;
									
						printf("Nombre: %s \n",nombre[pos]);
						printf("Ocupacion: %s.\n",ocupacion[pos]);
						printf("Rut : %i \n",rut[pos]);
							
					}	
							
				}
			}
			printf("Desea realizar otra busqueda: 1: SI / 2: NO : ");
			scanf("%i",&k);	
	}
	getch();
}
void opcion_3(){
	system("cls");
	printf("Etapas Covid 19 (1)Cuarentena (2)Transicion (3)Preparacion (4)Apertura incial (5)Apertura avanzada\n");
	for(i=0;i<region;i++){
		printf("Ingrese etapa en que se encuentra la region %i\n:",i+1);
		scanf("%i",&etapa[i]);
	}
	printf("----------------------------------------------------------------------------------------------------------------\n");
	printf("Ingrese sus valores epidemiologicos en que se encuentra cada region\n");
	for(i=0;i<region;i++){
		printf("Ingrese el porcentaje de ocupacion UCI de la region %i\n:",i+1);
		scanf("%f",&UCIr[i]);
	}
	printf("----------------------------------------------------------------------------------------------------------------\n");
	printf("Ingrese la tasa de casos nuevos cada 100.000 habitantes\n");
	for(i=0;i<region;i++){
		printf("Ingrese la tasa de casos nuevos de la region %i\n:",i+1);
		scanf("%i",&casosnuevos[i]);
	}
	printf("----------------------------------------------------------------------------------------------------------------\n");
	printf("Ingrese el porcentaje de positividad en los ultimos 7 dias\n");
	for(i=0;i<region;i++){
		printf("Ingrese el porcentaje de la region %i\n:",i+1);
		scanf("%f",&positividad[i]);
	}
	printf("----------------------------------------------------------------------------------------------------------------\n");
	printf("Ingrese el porcentaje casos aislados desde la notificacion de sospecha en las ultimas 48 horas\n");
	for(i=0;i<region;i++){
		printf("Ingrese el porcentaje de la region %i\n:",i+1);
		scanf("%f",&casosaislados[i]);
	}
	printf("----------------------------------------------------------------------------------------------------------------\n");
	printf("Ingrese el porcentaje de contactos en cuarentena desde el diagnostico del caso confirmado en las ultimas 48 horas\n");
	for(i=0;i<region;i++){
		printf("Ingrese el porcentaje de la region %i\n:",i+1);
		scanf("%f",&contactoscuarentena[i]);
	}
	printf("----------------------------------------------------------------------------------------------------------------\n");
	printf("Ingrese el porcentaje de casos nuevos que vienen de contactos en seguimiento\n");
	for(i=0;i<region;i++){
		printf("Ingrese el porcentaje de la region %i\n:",i+1);
		scanf("%f",&seguimiento[i]);
	}
	system("cls");			
	for(i=0;i<region;i++){
		
		//cuarentena a transicion---------------------------------------------------------------------------------------------------------------------------------------------------
		if (etapa[i]==1 && UCIr[i]<=85 && casosnuevos[i]<=10 && positividad[i]<=10 && casosaislados[i]<80 && contactoscuarentena[i]<60 && seguimiento[i]<60){
			printf("----------------------------------------------------------------------------------------------------------------\n");			
			printf("La region %i pasa de cuarentena a transicion, ya que se cumplen los requisitos de la tabla de indicadores.\n",i+1);
			siempre_vigente();
			cumplimiento_toquequeda_aduana();
			cuarentena_75();
			printf("-Prohibicion de traslado a residencia diferente a la habitual\n\n");
			printf("-Restriccion de movilidad personal, permisos exclusivos para actividades esenciales\n\n");
			restriccion_de_operacion();	
			printf("-Prohibicion de actividades deportivas (Permitidas solo en lugares abiertos y sin lugares comunes. Sin publico. Deportes colectivos con maximo 10 personas.)\n\n");
			printf("-Prohibicion de eventos, reuniones sociales y recreativas (Vigente los fines de semana y festivos. Maximo 20 personas en lugares abiertos y 10 personas en lugares cerrados. Prohibidos durante toque de queda.)\n\n");	
			cuarentena_ELEAM();
			printf("-Cuarentena Centros SENAME: Residentes pueden salir hasta 3 veces/semana, con autorizacion y supervision. Visitas de vinculos significativos permitidas.\n\n ");
			restricciones_sectoriales();
			suspension_clase1();
		}
		else if (etapa[i]==1 && (UCIr[i]>85 || casosnuevos[i]>10 || positividad[i]>10 || casosaislados[i]>=80 || contactoscuarentena[i]>=60 || seguimiento[i]>=60)){
			printf("----------------------------------------------------------------------------------------------------------------\n");			
			printf("La region %i se mantiene en cuarentena, ya que uno o mas requisitos no se cumple de la tabla de indicadores.\n",i+1);
			siempre_vigente();
			printf("-Cumplimiento del Toque Queda\n\n");
			printf("-Cumplimiento de aduanas y cordones sanitarios\n\n");
			printf("-Cuarentena obligatoria para mayores de 75 años Vigente. Pueden salir a caminar hasta 1 hora (entre 10 y 12 o 15 y 17 hrs.) los lunes, jueves y sabados. 200 m. a la redonda de la residencia.\n\n");
			printf("-Prohibicion de traslado a residencia diferente a la habitual\n\n");
			printf("-Restriccion de movilidad personal, permisos exclusivos para actividades esenciales\n\n");
			restriccion_de_operacion();
			printf("-Prohibicion de actividades deportivas (Vigente, por restriccion a la movilidad. Solo permiso unico colectivo para entrenamientos definidos)\n\n");
			printf("-Prohibicion de eventos, reuniones sociales y recreativas\n\n");
			printf("-Cuarentena Centros ELEAM (y prohibicion visitas)\n\n");
			printf("-Cuarentena Centros SENAME: Residentes pueden usar permiso especial para salidas de ninos y adolescentes.\n\n ");
			restricciones_sectoriales();
			printf("-Suspension clases presenciales establecimientos de educacion escolar y parvularia\n\n");
		
		}
		//transicion a preparacion
		if (etapa[i]==2 && UCIr[i]<=85 && casosnuevos[i]<=10 && positividad[i]<=8 && casosaislados[i]<80 && contactoscuarentena[i]<70 && seguimiento[i]<60){
			printf("----------------------------------------------------------------------------------------------------------------\n");			
			printf("La region %i pasa de transicion a preparacion, ya que se cumplen los requisitos de la tabla de indicadores.\n",i+1);
			siempre_vigente();
			cumplimiento_toquequeda_aduana();
			cuarentena_75();
			ProhibicionTraslado_RestriccionMovilidad();
			printf("-Prohibicion de funcionamiento Clubes de Adultos Mayores y Centros de dia\n\n");
			printf("-Prohibicion de funcionamiento de cines, teatros y lugares analogos (Pueden tenerfunciones pero sin publico.)\n\n");
			printf("-Prohibicion de atencion de publico en restaurantes y cafe (Pueden funcionar solo en terrazas o espacios abiertos, con distancia minima de 2 m. entre mesas)\n\n");
			printf("-Prohibicion de funcionamiento de pubs, discotecas y analogos\n\n");
			printf("-Prohibicion de funcionamiento de gimnasios abiertos al publico\n\n");
			printf("-Prohibicion de actividades deportivas (Permitidas. Deportes colectivos con max. 5 personas en lugares cerrados (excepto gimnasios) y 25 en lugares abiertos. Sin publico)\n\n");
			printf("-Prohibicion de eventos, reuniones sociales y recreativas (Maximo 50 personas en lugares abiertos y 25 personas en lugares cerrados. Prohibidos durante toque de queda.)\n\n");
			cuarentena_ELEAM();
			printf("-Cuarentena Centros SENAME: Residentes pueden salir hasta 5 veces/semana, con supervision. Permitidas visitas de vinculos significativos permitidas y salidas con fines laborales.\n\n ");
			restricciones_sectoriales();
			suspension_clase1();
		}
		else if (etapa[i]==2 && UCIr[i]>85 && casosnuevos[i]>10 && positividad[i]>8 && casosaislados[i]>=80 && contactoscuarentena[i]>=70 && seguimiento[i]>=60){
			printf("----------------------------------------------------------------------------------------------------------------\n");			
			printf("La region %i retrocede a cuarentena, ya que no se cumplen los requisitos de la tabla de indicadores para manternerse.\n",i+1);
			siempre_vigente();
			printf("-Cumplimiento del Toque Queda\n\n");
			printf("-Cumplimiento de aduanas y cordones sanitarios\n\n");
			printf("-Cuarentena obligatoria para mayores de 75 años Vigente. Pueden salir a caminar hasta 1 hora (entre 10 y 12 o 15 y 17 hrs.) los lunes, jueves y sabados. 200 m. a la redonda de la residencia.\n\n");
			printf("-Prohibicion de traslado a residencia diferente a la habitual\n\n");
			printf("-Restriccion de movilidad personal, permisos exclusivos para actividades esenciales\n\n");
			restriccion_de_operacion();
			printf("-Prohibicion de actividades deportivas (Vigente, por restriccion a la movilidad. Solo permiso unico colectivo para entrenamientos definidos)\n\n");
			printf("-Prohibicion de eventos, reuniones sociales y recreativas\n\n");
			printf("-Cuarentena Centros ELEAM (y prohibicion visitas)\n\n");
			printf("-Cuarentena Centros SENAME: Residentes pueden usar permiso especial para salidas de ninos y adolescentes.\n\n ");
			restricciones_sectoriales();
			printf("-Suspension clases presenciales establecimientos de educacion escolar y parvularia\n\n");
		}
		else if (etapa[i]==2 && (UCIr[i]>85 || casosnuevos[i]>10 || positividad[i]>8 || casosaislados[i]>=80 || contactoscuarentena[i]>=70 || seguimiento[i]>=60)){
			printf("----------------------------------------------------------------------------------------------------------------\n");			
			printf("La region %i se mantiene en transicion, ya que uno o mas requisitos no se cumple de la tabla de indicadores\n",i+1);
			siempre_vigente();
			cumplimiento_toquequeda_aduana();
			cuarentena_75();
			printf("-Prohibicion de traslado a residencia diferente a la habitual\n\n");
			printf("-Restriccion de movilidad personal, permisos exclusivos para actividades esenciales (Rige solo sabados, domingos y festivos)\n\n");
			restriccion_de_operacion();
			printf("-Prohibicion de actividades deportivas (Permitidas solo en lugares abiertos y sin lugares comunes. Sin publico. Deportes colectivos con maximo 10 personas.)\n\n");
			printf("-Prohibicion de eventos, reuniones sociales y recreativas (Vigente los fines de semana y festivos. Maximo 20 personas en lugares abiertos y 10 personas en lugares cerrados. Prohibidos durante toque de queda.)\n\n");
			cuarentena_ELEAM();
			printf("-Cuarentena Centros SENAME: Residentes pueden salir hasta 3 veces/semana, con autorizacion y supervision. Visitas de vinculos significativos permitidas.\n\n ");
			restricciones_sectoriales();
			suspension_clase1();
		}
		//preparacion a apertura inicial-----------------------------------------------------------------------------------------------------------------------------------------------
		if (etapa[i]==3 && UCIr[i]<=80 && casosnuevos[i]<=5 && positividad[i]<=4 && casosaislados[i]<90 && contactoscuarentena[i]<80 && seguimiento[i]<70){
			printf("----------------------------------------------------------------------------------------------------------------\n");			
			printf("La region %i pasa de preparacion a apertura inicial, ya que se cumplen los requisitos de la tabla de indicadores.\n",i+1);
			siempre_vigente();
			cumplimiento_toquequeda_aduana();
			cuarentena_75();
			ProhibicionTraslado_RestriccionMovilidad();
			printf("-Prohibicion de funcionamiento Clubes de Adultos Mayores y Centros de dia (Pueden funcionar solo Centros de dia.)\n\n");
			printf("-Prohibicion de funcionamiento de cines, teatros y lugares analogos (Pueden funcionar con maximo 50% de su capacidad y al menos 1 m. entre asistentes. Sin consumo de bebidas y alimentos)\n\n");
			printf("-Prohibicion de atencion de publico en restaurantes y cafe (Pueden funcionar con maximo 50% de su capacidad, o guardando distancia de 2 m. entre mesas.)\n\n");
			printf("-Prohibicion de funcionamiento de pubs, discotecas y analogos\n\n");
			printf("-Prohibicion de funcionamiento de gimnasios abiertos al publico (Pueden funcionar con horarios diferidos y estadia maxima de 1 hora, distancia de 2m. entre maquinas y aforo maximo de 1 persona cada 10m2. Sin camarines.)\n\n");
			printf("-Prohibicion de actividades deportivas (Permitidas. Deportes colectivos con maximo 10 personas en lugares cerrados(excepto gimnasios) y 50 en lugares abiertos. Sin publico)\n\n");
			printf("-Prohibicion de eventos, reuniones sociales y recreativas (Maximo 100 personas en lugares abiertos y 50 personas en lugares cerrados. Prohibidos durante toque de queda.)\n\n");
			cuarentena_ELEAM();
			printf("-Cuarentena Centros SENAME: Salidas permitidas con autorizacion y supervision. Permitidas visitas de vinculos significativos permitidas y salidas con fines laborales y educacionales.\n\n ");
			restricciones_sectoriales();
			suspension_clase2();
		}
		else if (etapa[i]==3 && UCIr[i]>80 && casosnuevos[i]>5 && positividad[i]>4 && casosaislados[i]>=90 && contactoscuarentena[i]>=80 && seguimiento[i]>=70){
			printf("----------------------------------------------------------------------------------------------------------------\n");			
			printf("La region %i retrocede a transicion, ya que no se cumplen los requisitos de la tabla de indicadores para manternerse.\n",i+1);
			siempre_vigente();
			cumplimiento_toquequeda_aduana();
			cuarentena_75();
			printf("-Prohibicion de traslado a residencia diferente a la habitual\n\n");
			printf("-Restricción de movilidad personal, permisos exclusivos para actividades esenciales (Rige solo sabados, domingos y festivos)\n\n");
			restriccion_de_operacion();
			printf("-Prohibicion de actividades deportivas (Permitidas solo en lugares abiertos y sin lugares comunes. Sin publico. Deportes colectivos con maximo 10 personas.)\n\n");
			printf("-Prohibicion de eventos, reuniones sociales y recreativas (Vigente los fines de semana y festivos. Maximo 20 personas en lugares abiertos y 10 personas en lugares cerrados. Prohibidos durante toque de queda.)\n\n");
			cuarentena_ELEAM();
			printf("-Cuarentena Centros SENAME: Residentes pueden salir hasta 3 veces/semana, con autorizacion y supervision. Visitas de vinculos significativos permitidas.\n\n ");
			restricciones_sectoriales();
			suspension_clase1();
		}
		else if (etapa[i]==3 && (UCIr[i]>80 || casosnuevos[i]>5 || positividad[i]>4 || casosaislados[i]>=90 || contactoscuarentena[i]>=80 || seguimiento[i]>=70)){
			printf("----------------------------------------------------------------------------------------------------------------\n");			
			printf("La region %i se mantiene en preparacion, ya que uno o mas requisitos no se cumple de la tabla de indicadores\n",i+1);
			siempre_vigente();
			cumplimiento_toquequeda_aduana();
			cuarentena_75();
			ProhibicionTraslado_RestriccionMovilidad();
			printf("-Prohibicion de funcionamiento Clubes de Adultos Mayores y Centros de dia\n\n");
			printf("-Prohibicion de funcionamiento de cines, teatros y lugares analogos (Pueden tener funciones pero sin publico.)\n\n");
			printf("-Prohibicion de atencion de publico en restaurantes y cafe (Pueden funcionar solo en terrazas o espacios abiertos, con distancia minima de 2 m. entre mesas)\n\n");
			printf("-Prohibicion de funcionamiento de pubs, discotecas y analogos\n\n");
			printf("-Prohibicion de funcionamiento de gimnasios abiertos al publico\n\n");
			printf("-Prohibicion de actividades deportivas (Permitidas. Deportes colectivos con max. 5 personas en lugares cerrados (excepto gimnasios) y 25 en lugares abiertos. Sin publico)\n\n");
			printf("-Prohibicion de eventos, reuniones sociales y recreativas (Maximo 50 personas en lugares abiertos y 25 personas en lugares cerrados. Prohibidos durante toque de queda.)\n\n");
			cuarentena_ELEAM();
			printf("-Cuarentena Centros SENAME: Residentes pueden salir hasta 5 veces/semana, con supervision. Permitidas visitas de vinculos significativos permitidas y salidas con fines laborales.\n\n ");
			restricciones_sectoriales();
			suspension_clase1();
		}
		//apertura inicial a apertura avanzada
		if (etapa[i]==4 && UCIr[i]<=80 && casosnuevos[i]<=2 && positividad[i]<=2 && casosaislados[i]<90 && contactoscuarentena[i]<90 && seguimiento[i]<80){
			printf("----------------------------------------------------------------------------------------------------------------\n");			
			printf("La region %i pasa de apertura inicial a apertura avanzada, ya que se cumplen los requisitos de la tabla de indicadores.\n",i+1);
			siempre_vigente();
			cumplimiento_toquequeda_aduana();
			cuarentena_75();
			ProhibicionTraslado_RestriccionMovilidad();
			printf("-Prohibicion de funcionamiento Clubes de Adultos Mayores y Centros de dia (Pueden funcionar Centros de dia, clubes y uniones comunales)\n\n");
			printf("-Prohibicion de funcionamiento de cines, teatros y lugares analogos (Pueden funcionar con maximo 75 porciento de su capacidad.)\n\n");
			printf("-Prohibicion de atencion de publico en restaurantes y cafe (Pueden funcionar con máximo 75 porciento de su capacidad.)\n\n");
			printf("-Prohibicion de funcionamiento de pubs, discotecas y analogos (Pueden funcionar con hasta 50 porciento de su capacidad. Tope maximo definido por eventos)\n\n");
			printf("-Prohibicion de funcionamiento de gimnasios abiertos al publico (Pueden funcionar con hasta 50 porciento capac.)\n\n");
			printf("-Prohibicion de actividades deportivas (Se levanta la restriccion, rige protocolo. Publico maximo de 50 porciento de la capacidad.)\n\n");
			printf("-Prohibicion de eventos, reuniones sociales y recreativas (Maximo 200 personas en lugares abiertos y 100 personas en lugares cerrados. Prohibidos durante toque de queda.)\n\n");
			printf("-Cuarentena Centros ELEAM (y prohibicion visitas): Se levanta la restriccion, rige protocolo de visita\n\n");
			printf("-Cuarentena Centros SENAME (Se levanta la restriccion.)\n\n ");
			restricciones_sectoriales();
			suspension_clase2();
		}
		else if (etapa[i]==4 && UCIr[i]>80 && casosnuevos[i]>2 && positividad[i]>2 && casosaislados[i]>=90 && contactoscuarentena[i]>=90 && seguimiento[i]>=80){
			printf("----------------------------------------------------------------------------------------------------------------\n");			
			printf("La region %i se retrocede a preparacion, ya que no se cumplen los requisitos de la tabla de indicadores para manternerse.\n",i+1);
			siempre_vigente();
			cumplimiento_toquequeda_aduana();
			cuarentena_75();
			ProhibicionTraslado_RestriccionMovilidad();
			printf("-Prohibicion de funcionamiento Clubes de Adultos Mayores y Centros de dia\n\n");
			printf("-Prohibicion de funcionamiento de cines, teatros y lugares analogos (Pueden tenerfunciones pero sin publico.)\n\n");
			printf("-Prohibicion de atencion de publico en restaurantes y cafe (Pueden funcionar solo en terrazas o espacios abiertos, con distancia minima de 2 m. entre mesas)\n\n");
			printf("-Prohibicion de funcionamiento de pubs, discotecas y analogos\n\n");
			printf("-Prohibicion de funcionamiento de gimnasios abiertos al publico\n\n");
			printf("-Prohibicion de actividades deportivas (Permitidas. Deportes colectivos con max. 5 personas en lugares cerrados (excepto gimnasios) y 25 en lugares abiertos. Sin publico)\n\n");
			printf("-Prohibicion de eventos, reuniones sociales y recreativas (Maximo 50 personas en lugares abiertos y 25 personas en lugares cerrados. Prohibidos durante toque de queda.)\n\n");
			cuarentena_ELEAM();
			printf("-Cuarentena Centros SENAME: Residentes pueden salir hasta 5 veces/semana, con supervision. Permitidas visitas de vinculos significativos permitidas y salidas con fines laborales.\n\n ");
			restricciones_sectoriales();
			suspension_clase1();
		}
		else if (etapa[i]==4 && (UCIr[i]>80 || casosnuevos[i]>2 || positividad[i]>2 || casosaislados[i]>=90 || contactoscuarentena[i]>=90 || seguimiento[i]>=80)){
			printf("----------------------------------------------------------------------------------------------------------------\n");			
			printf("La region %i se mantiene en apertura inicial, ya que uno o mas requisitos no se cumple de la tabla de indicadores\n",i+1);
			siempre_vigente();
			cumplimiento_toquequeda_aduana();
			cuarentena_75();
			ProhibicionTraslado_RestriccionMovilidad();
			printf("-Prohibicion de funcionamiento Clubes de Adultos Mayores y Centros de dia (Pueden funcionar solo Centros de dia.)\n\n");
			printf("-Prohibicion de funcionamiento de cines, teatros y lugares analogos (Pueden funcionar con maximo 50% de su capacidad y al menos 1 m. entre asistentes. Sin consumo de bebidas y alimentos)\n\n");
			printf("-Prohibicion de atencion de publico en restaurantes y cafe (Pueden funcionar con maximo 50% de su capacidad, o guardando distancia de 2 m. entre mesas.)\n\n");
			printf("-Prohibicion de funcionamiento de pubs, discotecas y analogos\n\n");
			printf("-Prohibicion de funcionamiento de gimnasios abiertos al publico (Pueden funcionar con horarios diferidos y estadia maxima de 1 hora, distancia de 2m. entre maquinas y aforo maximo de 1 persona cada 10m2. Sin camarines.)\n\n");
			printf("-Prohibicion de actividades deportivas (Permitidas. Deportes colectivos con maximo 10 personas en lugares cerrados(excepto gimnasios) y 50 en lugares abiertos. Sin publico)\n\n");
			printf("-Prohibicion de eventos, reuniones sociales y recreativas (Maximo 100 personas en lugares abiertos y 50 personas en lugares cerrados. Prohibidos durante toque de queda.)\n\n");
			cuarentena_ELEAM();
			printf("-Cuarentena Centros SENAME: Salidas permitidas con autorizacion y supervision. Permitidas visitas de vinculos significativos permitidas y salidas con fines laborales y educacionales.\n\n ");
			restricciones_sectoriales();
			suspension_clase2();
		}
		//apertura avanzada
		if (etapa[i]==5 && UCIr[i]<=80 && casosnuevos[i]<=2 && positividad[i]<=2 && casosaislados[i]<90 && contactoscuarentena[i]<90 && seguimiento[i]<80){
			printf("----------------------------------------------------------------------------------------------------------------\n");			
			printf("La region %i se mantiene en apertura avanzada\n",i+1);
			siempre_vigente();
			cumplimiento_toquequeda_aduana();
			cuarentena_75();
			ProhibicionTraslado_RestriccionMovilidad();
			printf("-Prohibicion de funcionamiento Clubes de Adultos Mayores y Centros de dia (Pueden funcionar Centros de dia, clubes y uniones comunales)\n\n");
			printf("-Prohibicion de funcionamiento de cines, teatros y lugares analogos (Pueden funcionar con maximo 75 porciento de su capacidad.)\n\n");
			printf("-Prohibicion de atencion de publico en restaurantes y cafe (Pueden funcionar con máximo 75 porciento de su capacidad.)\n\n");
			printf("-Prohibicion de funcionamiento de pubs, discotecas y analogos (Pueden funcionar con hasta 50 porciento de su capacidad. Tope maximo definido por eventos)\n\n");
			printf("-Prohibicion de funcionamiento de gimnasios abiertos al publico (Pueden funcionar con hasta 50 porciento capac.)\n\n");
			printf("-Prohibicion de actividades deportivas (Se levanta la restriccion, rige protocolo. Publico maximo de 50 porciento de la capacidad.)\n\n");
			printf("-Prohibicion de eventos, reuniones sociales y recreativas (Maximo 200 personas en lugares abiertos y 100 personas en lugares cerrados. Prohibidos durante toque de queda.)\n\n");
			printf("-Cuarentena Centros ELEAM (y prohibicion visitas): Se levanta la restriccion, rige protocolo de visita\n\n");
			printf("-Cuarentena Centros SENAME (Se levanta la restriccion.)\n\n ");
			restricciones_sectoriales();
			suspension_clase2();
		}
		else if (etapa[i]==5 && UCIr[i]>80 && casosnuevos[i]>2 && positividad[i]>2 && casosaislados[i]>=90 && contactoscuarentena[i]>=90 && seguimiento[i]>=80){
			printf("----------------------------------------------------------------------------------------------------------------\n");			
			printf("La region %i se retrocede a apertura inicial, ya que no se cumplen los requisitos de la tabla de indicadores para manternerse.\n",i+1);
			siempre_vigente();
			cumplimiento_toquequeda_aduana();
			cuarentena_75();
			ProhibicionTraslado_RestriccionMovilidad();
			printf("-Prohibicion de funcionamiento Clubes de Adultos Mayores y Centros de dia (Pueden funcionar solo Centros de dia.)\n\n");
			printf("-Prohibicion de funcionamiento de cines, teatros y lugares analogos (Pueden funcionar con maximo 50% de su capacidad y al menos 1 m. entre asistentes. Sin consumo de bebidas y alimentos)\n\n");
			printf("-Prohibicion de atencion de publico en restaurantes y cafe (Pueden funcionar con maximo 50% de su capacidad, o guardando distancia de 2 m. entre mesas.)\n\n");
			printf("-Prohibicion de funcionamiento de pubs, discotecas y analogos\n\n");
			printf("-Prohibicion de funcionamiento de gimnasios abiertos al publico (Pueden funcionar con horarios diferidos y estadia maxima de 1 hora, distancia de 2m. entre maquinas y aforo maximo de 1 persona cada 10m2. Sin camarines.)\n\n");
			printf("-Prohibicion de actividades deportivas (Permitidas. Deportes colectivos con maximo 10 personas en lugares cerrados(excepto gimnasios) y 50 en lugares abiertos. Sin publico)\n\n");
			printf("-Prohibicion de eventos, reuniones sociales y recreativas (Maximo 100 personas en lugares abiertos y 50 personas en lugares cerrados. Prohibidos durante toque de queda.)\n\n");
			cuarentena_ELEAM();
			printf("-Cuarentena Centros SENAME: Salidas permitidas con autorizacion y supervision. Permitidas visitas de vinculos significativos permitidas y salidas con fines laborales y educacionales.\n\n ");
			restricciones_sectoriales();
			suspension_clase2();
		}
		else if (etapa[i]==5 && (UCIr[i]>80 || casosnuevos[i]>2 || positividad[i]>2 || casosaislados[i]>=90 || contactoscuarentena[i]>=90 || seguimiento[i]>=80)){
			printf("----------------------------------------------------------------------------------------------------------------\n");			
			printf("La region %i se mantiene en apertura avanzada, ya que uno o mas requisitos no se cumple de la tabla de indicadores\n",i+1);
			siempre_vigente();
			cumplimiento_toquequeda_aduana();
			cuarentena_75();
			ProhibicionTraslado_RestriccionMovilidad();
			printf("-Prohibicion de funcionamiento Clubes de Adultos Mayores y Centros de dia (Pueden funcionar Centros de dia, clubes y uniones comunales)\n\n");
			printf("-Prohibicion de funcionamiento de cines, teatros y lugares analogos (Pueden funcionar con maximo 75 porciento de su capacidad.)\n\n");
			printf("-Prohibicion de atencion de publico en restaurantes y cafe (Pueden funcionar con máximo 75 porciento de su capacidad.)\n\n");
			printf("-Prohibicion de funcionamiento de pubs, discotecas y analogos (Pueden funcionar con hasta 50 porciento de su capacidad. Tope maximo definido por eventos)\n\n");
			printf("-Prohibicion de funcionamiento de gimnasios abiertos al publico (Pueden funcionar con hasta 50 porciento capac.)\n\n");
			printf("-Prohibicion de actividades deportivas (Se levanta la restriccion, rige protocolo. Publico maximo de 50 porciento de la capacidad.)\n\n");
			printf("-Prohibicion de eventos, reuniones sociales y recreativas (Maximo 200 personas en lugares abiertos y 100 personas en lugares cerrados. Prohibidos durante toque de queda.)\n\n");
			printf("-Cuarentena Centros ELEAM (y prohibicion visitas): Se levanta la restriccion, rige protocolo de visita\n\n");
			printf("-Cuarentena Centros SENAME (Se levanta la restriccion.)\n\n ");
			restricciones_sectoriales();
			suspension_clase2();
		}
	}								
	getch();
}
void opcion_4(){
	system("cls");
	printf("Gestion de Medidas Sanitarias (Agregar y eliminar medidas segun fase)\n");
	getch();
}
void opcion_5(){
}
void siempre_vigente(){
	printf("La medidas sanitarias a seguir son: \n\n");
	printf("-Aislamiento obligatorio para: casos confirmados, sospechosos y probables.\n\n");
	printf("-Cuarentena para contactos estrechos de casos confirmados.\n\n");
	printf("-Cuarentena obligatoria para quienes ingresan al pais.\n\n");
	printf("-Uso de mascarilla en lugares cerrados y abiertos urbanos, y transporte publico y privado.\n\n");
	printf("-Mantener en todo momento undistanciamiento fisico minimo de 1 m.\n\n");
	printf("-Realizar limpieza y desinfeccion permanente.\n\n");
	printf("-Entregar informacion de aformaximo, obligaciones y recomendaciones de autocuidado.\n\n");
}
void cumplimiento_toquequeda_aduana(){
	printf("-Cumplimiento del Toque Queda (Se mantiene vigente hasta que la autoridad indique modificacion)\n\n");
	printf("-Cumplimiento de aduanas y cordones sanitarios (Se mantiene vigente hasta que la autoridad indique modificacion)\n\n");
}
void cuarentena_75(){
	printf("-Se levanta la restriccion Cuarentena obligatoria para mayores de 75 años.\n\n");

}
void ProhibicionTraslado_RestriccionMovilidad(){
	printf("-Prohibicion de traslado a residencia diferente a la habitual: Se permiten desplazamientos entre localidades que esten en los Pasos 3, 4 y 5.\n\n");
	printf("-Restriccion de movilidad personal, permisos exclusivos para actividades esenciales: Se permiten desplazamientos entre localidades que estén en los Pasos 3, 4 y 5.\n\n");
}
void restriccion_de_operacion(){
	printf("-Prohibicion de funcionamiento Clubes de Adultos Mayores y Centros de dia\n\n");
	printf("-Prohibicion de funcionamiento de cines, teatros y lugares analogos\n\n");
	printf("-Prohibicion de atencion de publico en restaurantes y cafe\n\n");
	printf("-Prohibicion de funcionamiento de pubs, discotecas y analogos\n\n");
	printf("-Prohibicion de funcionamiento de gimnasios abiertos al publico\n\n");

}
void cuarentena_ELEAM(){
	printf("-Cuarentena Centros ELEAM (y prohibicion visitas): Residentes pueden salir a caminar 2 veces/semana por maximo 2 horas y 200 m. a la redonda. Pueden recibir visita de 2 personas, 2 veces/semana.\n\n");

}
void restricciones_sectoriales(){
	printf("-Cierre de fronteras terrestres y areas (Se mantiene vigente hasta que la autoridad indique modificacion)\n\n");
	printf("-Postergacion cirugias electivas no criticas, excepto cirugia mayor ambulatoria y con hospitalizacion maximo 1 noche (Se mantiene vigente hasta que la autoridad indique modificacion)\n\n");
	printf("-Prohibicion recalada cruceros (Se mantiene vigente hasta que la autoridad indique modificacion)\n\n");
}
void suspension_clase1(){
	printf("-Suspension clases presenciales establecimientos de educacion escolar y parvularia (Solo excepciones solicitadas por el sostenedor y previa factibilidad sanitaria informada por el MINSAL.)\n\n");

}
void suspension_clase2(){
	printf("-Suspension clases presenciales establecimientos de educacion escolar y parvularia (Plan MINEDUC de retorno gradual a clases presenciales)\n\n");

}
