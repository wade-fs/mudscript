inherit ROOM;
void create() {
	set( "short", "花園中間" );
	set( "owner", "roariv" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room630.c",
		"north"     : "/open/clan/13_luck/room/room625",
		"east"      : "/open/clan/13_luck/room/room628",
	]) );
	set( "long", @LONG

    你通過了女子練武的場地，讓你深深覺得詩劍山莊不是浪得虛名，
這邊鳥語花香種植著許多的花朵與樹木，原來你到了詩劍山莊的花園了
，園裡的奇花異草，還有許多珍禽異獸，讓你忍不住停下腳步，欣賞眼
前的美景‧

LONG);
	setup();
	replace_program(ROOM);
}
