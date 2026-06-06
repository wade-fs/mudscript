inherit ROOM;
void create() {
	set( "short", "花園東邊一" );
	set( "owner", "roariv" );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room626",
		"west"      : "/open/clan/13_luck/room/room628.c",
	]) );
	set( "long", @LONG

    這邊是花園的東邊，四週充滿了鳥語花香與種植著許多的花朵與樹木
，園裡的奇花異草，還有許多珍禽異獸，讓你忍不住停下腳步，欣賞眼前
的美景‧裡面就是詩劍山莊專屬酒莊，詩劍山莊裡的酒莊可是聞名全武林
的，想喝酒就快進去吧，晚了就沒酒喝了。

LONG);
	setup();
	replace_program(ROOM);
}
