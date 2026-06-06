inherit ROOM;
void create() {
	set( "short", "武器室" );
	set( "owner", "blackdog" );
	set( "build", 10298 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room636",
	]) );
	set( "long", @LONG
經過一段時間的練習，ＭＯＩ對這個狂想的世界愈來愈了解了，不捨的
東西也愈來愈多了。為了回憶，也為了以後重生的後代著想，他決定將所收
藏的寶藏分門別類來收藏。在這裡，你可以看到各式的武器，雖然價值都不
高，但卻都有一定的實用性。

LONG);
	setup();
	replace_program(ROOM);
}
