# SingleItemLotSizing
Résolution du problème de Single Item Lot Sizing Problem

###Principe
A chaque période, on souhaite satisfaire une demande d d'item i. On ne peut produire qu'un seul type d'item par période, la production d'un item a un coût p, le lancement de la production a un coût f.

![PL](http://www.sciweavers.org/tex2img.php?eq=%5Csum_%7Bt%3D0%7D%5ET%20%5Csum_%7Bi%3D0%7D%5En%20x_%7Bit%7D%20p_%7Bit%7D%20%2B%20y_%7Bit%7D%20f_%7Bit%7D%0A%0A%5Cbegin%7Balign%2A%7D%0A%5Csum_%7Bi%3D0%7D%5En%20y_%7Bit%7D%20%26%20%5Cleq%201%20%26%20%5Cforall%20t%20%5C%5C%0Ax_%7Bit%7D%20%26%20%5Cleq%20d_%7Bit%7D%20y_%7Bit%7D%20%26%20%5Cforall%20i%2Ct%20%5C%5C%0A%5Csum_%7B%20%5Ctau%20%3D%200%7D%5Et%20x_%7Bi%5Ctau%7D%20%26%20%5Cgeq%20d_%7Bit%7D%20%26%20%5Cforall%20i%2Ct%20%5C%5C%0A%26%20y_%7Bit%7D%20%5Cin%20%5C%7B0%2C1%5C%7D%2C%20x_%7Bit%7D%20%5Cgeq%200%20%26%20%5Cforall%20i%2Ct%20%5C%5C%0A%5Cend%7Balign%2A%7D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0%22%20align=%22center%22%20border=%220%22%20alt=%22\sum_{t=0}^T%20\sum_{i=0}^n%20x_{it}%20p_{it}%20+%20y_{it}%20f_{it}\begin{align*}\sum_{i=0}^n%20y_{it}%20&%20\leq%201%20&%20\forall%20t%20\\x_{it}%20&%20\leq%20d_{it}%20y_{it}%20&%20\forall%20i,t%20\\\sum_{%20\tau%20=%200}^t%20x_{i\tau}%20&%20\geq%20d_{it}%20&%20\forall%20i,t%20\\&%20y_{it}%20\in%20\{0,1\},%20x_{it}%20\geq%200%20&%20\forall%20i,t%20\\\end{align*})

>Pas de coût de stockage

### Git
Client git Windows/Mac : <https://desktop.github.com/>

Commandes Git : <http://rogerdudler.github.io/git-guide/index.fr.html> (pour bien demarrer)

> On travaille tous sur la branche master, pas la peine d'en créer.

### Bon usage de git

Avant toute modification sur les fichiers du dépot local, il faut faire `git pull`.

#### Git add
On n'ajoute pas les exécutables, les fichiers objets  (.gitignore fichier qui recense les extensions de fichier à ignorer), 
les instances crées (on garde uniquement play/test) et le code qui ne compile pas (le commenter, expliquer ce que l'on veut faire et ce qui ne fonctionne pas).

#### Git commit
Lorsqu'on a fini d'implémenter une fonctionnalité

####Git push
Pour partager

