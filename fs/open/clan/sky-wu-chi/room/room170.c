inherit ROOM;
void create() {
	set( "short", "$HIC$咩 咩 小 築$NOR$" );
	set( "owner", "roboo" );
	set( "object", ([
		"amount2"  : 1,
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"amount1"  : 1,
		"file2"    : "/daemon/class/blademan/obj/shield",
	]) );
	set( "light_up", 1 );
	set( "build", 10042 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"west"      : "/open/clan/sky-wu-chi/room/room25.c",
	]) );
	set( "long", @LONG

    .  .     ☆   .     Z   ☆   .   ★       .    ☆      .  ☆    .
    Z         .   Z       .  ★       .  Z     ☆     ★     .   .   ★.
  .     ☆ .   ☆      Z    .  .  ☆    Z .       ★       Z   ☆   .
               .  .     ☆   .     Z   ☆   .   ★       .    ☆
                                                   ☆   .   ★
  .     ☆ .   ☆                                        ★       Z
.  ★       .          咩  咩  咩  咩  咩         .           ☆    .
 ☆     ★     .                                          .  ★       .
 .  ★       .                   ★     .   .   ★.
                                                                                 ◢◣
         ◢◣                                       ◢█◣
        ◢█◣               ◢◣                  ◢██◣
 ◢◣  ◢██◣    ◢◣     ◢█◣                ◢███◣           ◢◣
◢█◣◢███◣  ◢█◣   ◢██◣              ◢████◣         ◢█◣
████████████████████████████████i[0█████
████████████████████████████████
LONG);
	setup();
	replace_program(ROOM);
}
