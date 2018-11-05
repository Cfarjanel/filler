# DOING (!)

- tester conditions count & somme

 - ft_count pour une étoile en commun et la somme des cases de map->numbers

# TO-DO (x)

- parcours la map à la recherche de count == 1, récupère ret pour le stocker dans
	prev si ret < prev. À la fin de la boucle, set coord = prev.coord;

# DONE (✓)

- transformation de map->shape en map->numbers
- parsing piece, map && number player

--------------------------------------------------------------------------------

# TESTS

- ft_putendl_fd("test", 2);

# PREV
```
ft_putendl_fd("prev :\n", 2);
ft_putnbr_fd(piece->prev.x, 2);
ft_putendl_fd("\n", 2);
ft_putnbr_fd(piece->prev.y, 2);
ft_putendl_fd("\n", 2);
```
# START
```
ft_putendl_fd("start", 2);
ft_putnbr_fd(map->start_bot.x, 2);
ft_putstr_fd("\n", 2);
ft_putnbr_fd(map->start_bot.y, 2);
ft_putstr_fd("\n", 2);
ft_putnbr_fd(map->start_player.x, 2);
ft_putstr_fd("\n", 2);
ft_putnbr_fd(map->start_player.y, 2);
ft_putstr_fd("\n", 2);
ft_putnbr_fd(map->start_j1.x, 2);
ft_putstr_fd("\n", 2);
ft_putnbr_fd(map->start_j1.y, 2);
ft_putstr_fd("\n", 2);
ft_putnbr_fd(map->start_j2.x, 2);
ft_putstr_fd("\n", 2);
ft_putnbr_fd(map->start_j2.y, 2);
ft_putstr_fd("\n", 2);
```

# COORD
```
ft_putendl_fd("coord", 2);
ft_putnbr_fd(piece->coord.x, 2);
ft_putstr_fd("\n", 2);
ft_putnbr_fd(piece->coord.y, 2);
ft_putstr_fd("\n", 2);
```
# CLOSE
```
ft_putendl_fd("close (p, b)", 2);
ft_putnbr_fd(piece->close.player.x, 2);
ft_putstr_fd("\n", 2);
ft_putnbr_fd(piece->close.player.y, 2);
ft_putstr_fd("\n", 2);
ft_putnbr_fd(piece->close.bot.x, 2);
ft_putstr_fd("\n", 2);
ft_putnbr_fd(piece->close.bot.y, 2);
```

# PIECE SIZE
```
ft_putendl_fd("\npiece x :", 2);
ft_putnbr_fd(piece->size.x, 2);
ft_putendl_fd("\npiece y :", 2);
ft_putnbr_fd(piece->size.y, 2);
```

# PIECE SHAPE
```
int z = 0;
while (z < piece->size.x)
{
	ft_putendl_fd(piece->shape[z], 2);
	z++;
}
```

# MAP SIZE
```
ft_putendl_fd("\nmap x :", 2);
ft_putnbr_fd(map->size.x, 2);
ft_putendl_fd("\nmap y :", 2);
ft_putnbr_fd(map->size.y, 2);
```

# MAP SHAPE
```
int z = 0;
while (z < map->size.x)
{
	ft_putendl_fd(map->shape[z], 2);
	z++;
}
```
-------------------------------------------------------------------------------

- executable créé à la compilation : cfarjane.filler
- makefile
- variables globales interdites
- write, malloc, free, read, perror, strerror
- une pièce ne peut être posée que si elle à uniquement une case en commun avec
	une pièce précédante et qu'elle ne dépasse pas de la map
- la partie est finie si une pièce a été mal poséeée ou ne peut pas être posée
- pour la dernière pièce posée par l'adversaire, la pièce sera représentée
	par des o ou des x (et non O pour j2 ou X pour j1 comme les autres)
- une pièce est un tableau x/y dont le vide est représenté par des . et la
	pièce en elle même par des *
- notre programme est passé en paramètre à la vm
- à chaque tour : lecture de la map et des pièces sur l'entrée standard;
	écrire les coordonnées (X Y\n) de la nouvelle pièce sur la sortie standard
	attention ! écrire les coordonnées de la pièce, non de la forme

-------------------------------------------------------------------------------

start_player & start_bot à utiliser dans closest ou trying
```
init =
	number->player = 0;
	number->bot = 0;
	map->size.x = 0;
	map->size.y = 0;
	map->start_player.x = 0;
	map->start_player.y = 0;
	map->start_bot.x = 0;
	map->start_bot.y = 0;
	map->last_piece.x = 0;
	map->last_piece.y = 0;
	piece->size.x = 0;
	piece->size.y = 0;
	piece->coord.x = 0;
	piece->coord.y = 0;
	piece->close.player.x = 0;
	piece->close.player.y = 0;
	piece->close.bot.x = 0;
	piece->close.bot.y = 0;
	piece->ret.x = 0;
	piece->ret.y = 0;
```