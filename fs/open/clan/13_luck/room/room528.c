inherit ROOM;
void create() {
	set( "short", "易水鴻門" );
	set( "object", ([
		"amount6"  : 1,
		"file4"    : "/obj/stone/powder",
		"amount7"  : 36,
		"amount3"  : 1,
		"file8"    : "/open/killer/obj/kill_yar_head",
		"file7"    : "/obj/stone/suipian",
		"amount8"  : 1,
		"amount2"  : 12,
		"file5"    : "/open/gblade/obj/sa-head",
		"file9"    : "/open/killer/obj/kill_yar_head",
		"file2"    : "/obj/stone/jiao",
		"amount5"  : 1,
		"file3"    : "/open/mogi/castle/obj/fire_book",
		"amount4"  : 158,
		"amount9"  : 1,
		"file6"    : "/open/mogi/castle/obj/leave",
	]) );
	set( "build", 10118 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room527",
		"east"      : "/open/clan/13_luck/room/room529.c",
	]) );
	set( "long", @LONG

    大門上面高高的懸著一塊琉璃黃金匾，上頭寫著『易水樓』四個斗
大的字，陽光照耀下，反射出耀眼的金光，朱紅色的大門開著，門上兩
個門環俱做獅頭狀，顯的氣派非凡。門兩旁各蹲著一個雕的栩栩如生的
石獅子，獅子旁站著兩名侍衛正盯著你瞧。在獅子的前面有一個佈告欄
(board)，上面好像寫了很重要的東西，讓你想仔細的觀看一翻。

LONG);
	setup();
	replace_program(ROOM);
}
