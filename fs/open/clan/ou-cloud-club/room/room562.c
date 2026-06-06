inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$後院$NOR$" );
	set( "owner", "rayk" );
	set( "object", ([
		"amount4"  : 492,
		"amount8"  : 483,
		"file4"    : "/open/fire-hole/obj/p-pill",
		"file9"    : "/obj/stone/powder",
		"amount3"  : 3,
		"amount10" : 14,
		"file10"   : "/obj/stone/suipian",
		"amount9"  : 100,
		"file8"    : "/open/fire-hole/obj/y-pill",
		"file5"    : "/open/fire-hole/obj/b-pill",
		"file7"    : "/open/fire-hole/obj/w-pill",
		"amount2"  : 1356,
		"file6"    : "/open/fire-hole/obj/k-pill",
		"amount6"  : 465,
		"amount7"  : 1364,
		"file2"    : "/open/fire-hole/obj/r-pill",
		"file3"    : "/obj/stone/jiao",
		"amount5"  : 445,
		"amount1"  : 1333,
		"file1"    : "/open/fire-hole/obj/g-pill",
	]) );
	set( "build", 10006 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room430",
	]) );
	set( "long", @LONG

    這裡是Ｒａｙｋ的後院，種著一些奇奇怪怪的花草。偶爾他也會
到這裡來看看花，種種草，調劑調劑戰鬥疲憊的身心。咦！沒想到Ｒ
ａｙｋ連天山雪蓮，千年靈芝，高麗人蔘都有，看來Ｒａｙｋ真的是
個藥罐子啊！！

LONG);
	setup();
	replace_program(ROOM);
}
