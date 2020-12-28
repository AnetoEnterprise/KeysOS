# KeysOS
Un systeme de traitement des clés chiffré utilisable avec ou sans connexion internet.

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
DOMAINNAME="www.keysos.cd"
}
SECURITY{
LEVEL=1
}
RECEIVE{
FROM="https://www.keysos.cd/getLicenceKeys.php"
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
