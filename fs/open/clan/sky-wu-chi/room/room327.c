inherit ROOM;
void create() {
	set( "short", "jtl 大樓2-7" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount5"  : 5000,
		"file4"    : "/open/killer/obj/s_pill",
		"file2"    : "/open/killer/obj/s_pill",
		"file5"    : "/open/killer/obj/s_pill",
		"amount4"  : 4000,
		"amount3"  : 2000,
		"file3"    : "/open/killer/obj/s_pill",
		"amount2"  : 5000,
		"file1"    : "/open/killer/obj/s_pill",
		"amount1"  : 2000,
	]) );
	set( "light_up", 1 );
	set( "build", 10080 );
	set( "exits", ([
		"southwest" : "/open/clan/sky-wu-chi/room/room321",
	]) );
	set( "long", @LONG
這裡是東北房丹藥房,這個房間的丹藥都是由miffy 和其他好友幫忙收集而成
因為丹藥的難以取得,所以更顯得此丹藥的難能可貴,而由此出去的丹藥
也都能夠發揮他其最大的功用,救贖萬物,因此此大樓的主人醫術也是相當之高高到
絕世罕見的地步...
LONG);
	setup();
	replace_program(ROOM);
}
