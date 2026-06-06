inherit ROOM;
void create() {
	set( "short", "jtl 大樓2-8" );
	set( "owner", "panhermes" );
	set( "object", ([
		"file1"    : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 16,
		"file5"    : "/open/ping/obj/poison_pill",
		"amount3"  : 14,
		"file3"    : "/open/fire-hole/obj/r-pill",
		"amount5"  : 11,
		"amount2"  : 15,
	]) );
	set( "light_up", 1 );
	set( "build", 10716 );
	set( "exits", ([
		"northwest" : "/open/clan/sky-wu-chi/room/room321",
	]) );
	set( "long", @LONG
這裡是東南房救命神丹房,這個房間的丹藥都是由miffy 和其他好友幫忙收集而成
因為救命神丹的難以取得,所以更顯得此神丹的難能可貴,而由此出去的神丹
也都能夠發揮他其最大的功用,起死回生,因此此大樓的主人煉藥也是相當之高高到
絕世罕見的地步...
LONG);
	setup();
	replace_program(ROOM);
}
