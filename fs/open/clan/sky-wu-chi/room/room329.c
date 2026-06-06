inherit ROOM;
void create() {
	set( "short", "jtl 大樓2-9" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount2"  : 1,
		"file1"    : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/mon/obj/ghost-claw",
		"file3"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "light_up", 1 );
	set( "build", 11040 );
	set( "exits", ([
		"northeast" : "/open/clan/sky-wu-chi/room/room321",
	]) );
	set( "long", @LONG
這裡是西南房雜器房,這個房間的武器都是由miffy 和其他好友幫忙收集而成
因為雜器的難以取得,所以更顯得此武器的難能可貴,而由此出去的武器
也都能夠發揮他其最大的功用,巧妙組合,因此此大樓的主人頭腦也是相當之高高到
絕世罕見的地步...
LONG);
	setup();
	replace_program(ROOM);
}
