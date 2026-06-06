inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$３樓中庭$NOR$" );
	set( "object", ([
		"amount3"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-armband",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount10" : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount2"  : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount7"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-belt",
	]) );
	set( "build", 10014 );
	set( "owner", "rayk" );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room627",
		"west"      : "/open/clan/ou-cloud-club/room/room748.c",
		"south"     : "/open/clan/ou-cloud-club/room/room749",
		"north"     : "/open/clan/ou-cloud-club/room/room747.c",
		"east"      : "/open/clan/ou-cloud-club/room/room746.c",
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
