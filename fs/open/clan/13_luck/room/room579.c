inherit ROOM;
void create() {
	set( "short", "易水鴻門" );
	set( "owner", "roarii" );
	set( "object", ([
		"amount9"  : 1,
		"amount7"  : 1,
		"amount5"  : 35,
		"amount4"  : 184,
		"file9"    : "/open/ping/obj/cloud_fan",
		"file4"    : "/obj/stone/powder",
		"file1"    : "/open/fire-hole/obj/g-pill",
		"amount8"  : 25,
		"amount2"  : 260,
		"file3"    : "/open/fire-hole/obj/w-pill",
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 300,
		"file6"    : "/open/killer/obj/s_pill",
		"file7"    : "/obj/gift/unknowdan",
		"amount3"  : 49,
		"amount1"  : 59,
		"file8"    : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/fire-hole/obj/r-pill",
	]) );
	set( "build", 10252 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room578",
		"east"      : "/open/clan/13_luck/room/room102",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
大門上面高高的懸著一塊琉璃黃金匾，上頭寫著『易水樓』四個斗
大的字，陽光照耀下，反射出耀眼的金光，朱紅色的大門開著，門上兩
個門環俱做獅頭狀，顯的氣派非凡。門兩旁各蹲著一個雕的栩栩如生的
石獅子，獅站著兩名侍衛正盯著你瞧。
LONG);
	setup();
	replace_program(ROOM);
}
