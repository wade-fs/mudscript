inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$戰利品部屋$NOR$" );
	set( "owner", "rayk" );
	set( "object", ([
		"amount9"  : 1,
		"file6"    : "/open/ghost-hole/obj/fire-spirit",
		"file2"    : "/open/ghost-hole/obj/fire-spirit",
		"amount8"  : 1,
		"amount10" : 1,
		"file3"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/ghost-hole/obj/fire-spirit",
		"amount6"  : 1,
		"file1"    : "/open/ghost-hole/obj/light-spirit",
		"amount7"  : 1,
		"file5"    : "/open/ghost-hole/obj/light-spirit",
		"file7"    : "/open/ghost-hole/obj/light-spirit",
		"amount5"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/ghost-hole/obj/light-spirit",
		"file8"    : "/open/ghost-hole/obj/light-spirit",
		"file10"   : "/obj/gift/bingtang",
	]) );
	set( "build", 10002 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room627",
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
