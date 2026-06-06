inherit ROOM;
void create() {
	set( "short", "花園東邊" );
	set( "owner", "roariv" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room627",
		"west"      : "/open/clan/13_luck/room/room629.c",
	]) );
	set( "long", @LONG

    這邊是花園的東邊，四週充滿了鳥語花香與種植著許多的花朵與樹木
花園裡的奇花異草，還有許多珍禽異獸，讓你忍不住停下腳步，欣賞眼前
的美景‧不遠之處飄來了陣陣的酒香，詩劍山莊裡的酒莊可是聞名全武林
的，快順著酒香，往前邁進吧。

LONG);
	setup();
	replace_program(ROOM);
}
