inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$戰利品部屋$NOR$" );
	set( "object", ([
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount2"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-helmet",
	]) );
	set( "build", 10056 );
	set( "owner", "rayk" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room745",
	]) );
	set( "long", @LONG

    這裡是Ｒａｙｋ蒐集的戰利品存放之地，只要他打到的戰利品
都會拿到這邊來存放。只是他存放的方式，似乎....有點凌亂。讓
看的你眼花撩亂，目不暇給，亂成這副德行，真讓你不知道他存的
是戰利品，還是垃圾。

LONG);
	setup();
	replace_program(ROOM);
}
