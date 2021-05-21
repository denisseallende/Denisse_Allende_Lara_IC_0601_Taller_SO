#!/bin/bash
ROOT_UID=0
SUCCESS=0

#Comprobar si se esta ingresando como un usuario root
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe ingresar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo del listado con Nombres de usuarios a ingresar..."
   exit 1
fi

crearUsuario(){
	eval nombreUsuario="$1"
	eval passwd="$2"
	eval userid="$3"
	eval groupid="$4"
	eval userinf="$5"
	eval hdirectory="$6"
	eval cshell="$7"
	
	if grep -q "${nombreUsuario}" /etc/passwd
	then
		echo "El usuario [$nombreUsuario] ya existe..."
	else
		if grep -q "${groupid}" /etc/group
		then
			if [ $? -eq $SUCCESS ];
			then
				useradd "${nombreUsuario}" -p "${passwd}" -u "${userid}" -g "${groupid}" -c "${userinf}" -d "${hdirectory}" -m -s "${cshell}" 
				echo "$nombreUsuario:$passwd" | chpasswd --md5
				passwd --expire "${nombreUsuario}"
				echo "----------------USUARIO [${userid}]'${nombreUsuario}'----------------"
				echo "Grupo utilizado: ${groupid}"
				echo "Directorio Home: ${hdirectory}"
				echo "SHELL utilizado: ${cshell}"
				echo "Password: ${passwd}"
				echo "---> Usuario [${nombreUsuario}] agregado correctamente..."
			else
				echo "---> Usuario [${nombreUsuario}] No se pudo agregar..."
			fi
		else
			echo "Error para [${nombreUsuario}]]: No existe el grupo [${groupid}] "
		fi
	fi
}


while IFS=":" read -r f1 f2 f3 f4 f5 f6 f7
do
	crearUsuario "\${f1}" "${f2}" "${f3}" "${f4}" "${f5}" "${f6}" "${f7}"
done < ${file}

exit 0
