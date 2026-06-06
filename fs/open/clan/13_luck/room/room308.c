inherit ROOM;
void create() {
	set( "short", "幻蛇鞭室" );
	set( "owner", "tomorrow" );
	set( "object", ([
		"file1"    : "/open/capital/obj/4-2",
		"amount1"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 11997 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room264",
	]) );
	set( "long", @LONG

    蛇鞭壯陽，不對那是虎鞭才對，現在沒super pill丹了，所以一見
到蛇郎君大家都遠離這個災難，他一身武功尤以定人最強，加上萬鞭歸
一，更是高招，常打的解amulet的人毫無招架之力，所以我們幫派世間
道不存whip，要就自己去打，不是懶，是怕麻煩。

LONG);
	setup();
	replace_program(ROOM);
}
