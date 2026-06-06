inherit ROOM;
void create() {
	set( "short", "星月殿大門" );
	set( "owner", "mill" );
	set( "object", ([
		"amount4"  : 7,
		"amount9"  : 1,
		"file6"    : "/open/fire-hole/obj/y-pill",
		"file9"    : "/open/area/fortress/npc/obj/token",
		"file3"    : "/open/fire-hole/obj/k-pill",
		"amount8"  : 5,
		"amount5"  : 4,
		"file1"    : "/open/mon/obj/thousand-nectar",
		"amount6"  : 13,
		"amount7"  : 42,
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount2"  : 3,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 9,
		"file7"    : "/open/fire-hole/obj/r-pill",
		"file5"    : "/open/mogi/castle/obj/sspill",
		"file8"    : "/open/fire-hole/obj/b-pill",
		"amount3"  : 90,
	]) );
	set( "build", 10201 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room499",
		"south"     : "/open/clan/13_luck/room/room85.c",
	]) );
	set( "long", @LONG

　　你走到這裡，眼前一亮，原來已來到星月殿的大門，莊嚴的大門
反映著內部的高深莫測，大門上的匾額寫著 『富貴乞丐』 四個大字
。兩旁寫著一副對聯︰

      『  丐幫義氣礡天高  好漢俠義永流傳  』 

江湖上為數眾多的丐幫，堪稱為天下第一幫，勢力之大難以估計。

LONG);
	setup();
	replace_program(ROOM);
}
