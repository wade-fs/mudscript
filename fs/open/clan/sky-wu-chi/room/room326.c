inherit ROOM;
void create() {
	set( "short", "jtl 大樓2-6" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount1"  : 1,
		"file5"    : "/open/quests/snake/npc/obj/snake-key-1",
		"file1"    : "/open/killer/obj/blood",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/quests/snake/npc/obj/snake-key-1",
		"file3"    : "/open/quests/snake/npc/obj/snake-key-1",
	]) );
	set( "light_up", 1 );
	set( "build", 11406 );
	set( "exits", ([
		"southeast" : "/open/clan/sky-wu-chi/room/room321",
	]) );
	set( "long", @LONG
這裡是西北房雜物房,這個房間的東西都是由miffy 和其他好友幫忙收集而成
因為這些雜物難以取得,所以更顯得此雜物的難能可貴,而由此出去的雜物
也都能夠發揮他其最大的功用,合成轉換,因此此大樓的主人藝術也是相當之高高到
絕世罕見的地步...
LONG);
	setup();
	replace_program(ROOM);
}
