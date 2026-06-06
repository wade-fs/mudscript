inherit ROOM;
void create() {
	set( "short", "天蠶絲帶室" );
	set( "owner", "amdxp" );
	set( "object", ([
		"file1"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount7"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount5"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount4"  : 1,
		"amount1"  : 1,
	]) );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room281",
		"south"     : "/open/clan/13_luck/room/room297.c",
	]) );
	set( "build", 10065 );
	set( "light_up", 1 );
	set( "long", @LONG

    傳說中的門派，變態舞者手中的防具，一身法術無人能敵，尤其是
玄冰護體，比移花接木，借力使力還要厲害，只要兩三下，就可以收一
收，好去陰間報到了，所以此物品不是隨便就可以打到的，是經過大家
的努力而成功打來的。

LONG);
	setup();
	replace_program(ROOM);
}
