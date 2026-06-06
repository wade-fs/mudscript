inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$戰利品部屋$NOR$" );
	set( "object", ([
		"amount3"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount1"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount8"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount5"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount4"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-boots",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount9"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount7"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount10" : 1,
	]) );
	set( "build", 10038 );
	set( "owner", "rayk" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room745",
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
