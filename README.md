# KeysOS
Un systeme de traitement des clés chiffré utilisable avec ou sans connexion internet.

# Manuel d'utilisation et de l’utilisation

Ce manuel d’utilisation et de l’installation est spécifiquement pour les amoureux de la commande. Nous allons voir comment installer KeysOS sous Windows 8.1 et Ubuntu 18.4. Pour d’autres versions les méthodes d’installation sont similaires.

# Windows 8.1 :
Premièrement vous devez lancer la console en tant qu’un administrateur. Pour procéder, allez sur la barre de recherche de Windows et tapez la commande CMD. Une liste des applications apparaissent et faites un clic droit sur l’application de la console et sélectionner : Exécuter comme administrateur. La console va s’exécuter en tant qu’administrateur comme l’image ci-après :

IMAGE ICI

Une fois que vous avez l’invité de commande (Console) a votre portée, dezipper le fichier téléchargé depuis : https://github.com/AnetoEnterprise/KeysOS/archive/main.zip/
Et tapez la commande :
cd D:/KeysOS/Windows

cp ./keysos.exe C:/Windows/System32/keysos.exe

clear


# Ubuntu 18.4 :
Même procédure d’installation depuis la plate-forme linux, tapez les commandes suivante :

tar xpf main.zip

cd /Final/Linux

cp ./keysos /usr/bin/

reset

# Liste des commandes et exemples :

/* -------------------SIMPLE------------------- */

CREATE KEYS{

SOCIETY{

NAME="MySociety",

DOMAINNAME="www.mysociety.com"

}

SECURITY{

LEVEL=1				/* From 1 To 4 */

}
EXPIRATION{

DATE=CURRENT_DATE,			/* CURRENT_DATE Or text date format */

TIME="07:50"				/* CURRENT_TIME Or text date format (A bien specifié l'heure de la region du destinateur et non seule de votre systeme.) */

}

FIND{

DATA="test data"

}
};




/* -------------------AVANCER------------------- */

CREATE KEYS{

SOCIETY{

NAME="MySociety",

DOMAINNAME="www.mysociety.com",	

KEYS=TRUE						/* True Or False (By default is False) */

}

VERIFY{

ACTION=TRUE,						/* True Or False (By default is False) */

URLCONFIRM="https://www.yoursite.cd/getconfirm.php",

DESTINATION="yourmail@yoursite.com",			/* E-mail Or Phone Number */

CONFIRM=AUTO						/* Auto, Manuel or user */

}

SECURITY{

LEVEL=1							/* From 2GB RAM, PROCESOR 1 (1 To 4) */

}

FIND{

DATA="test data"					/* Text data Or FILE("./myfile") */

}

RUN{

SOCKET=TRUE						/* True Or False (By default is False) */

}

};

/* Fin création de la clé */







/* Début génération de la clé de licénce */

CREATE LICENCEKEYS{

SOCIETY{

NAME="KeysOS",

DOMAINNAME="www.keysos.org"

}

SECURITY{

LEVEL=1

}

RECEIVE{

FROM="https://www.keysos.org/getLicenceKeys.php"
}

};

/* Fin génération de la clé de licénce */







/* Début verification de la clé */

SELECT KEYS{

CRYPTO="Your generated keys here.",

GET=FREE

};


/* OR */


SELECT KEYS{CRYPTO='Your generated keys here.', GET=LICENCEKEYS('/usr/bin/mylicencekeys.ls')};

/* Fin verification de la clé */






/* Début lancer socket pour confirmer le code */

sudo keysos port code "GET=LICENCEKEYS('/usr/bin/mylicencekeys.ls')" "votre clé ici"

/* Début lancer socket pour confirmer le code */
