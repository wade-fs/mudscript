inherit ROOM;
void create() {
	set( "short", "jtl 大樓2-4" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount10" : 1,
		"amount2"  : 1,
		"file4"    : "/open/mogi/castle/obj/sspill",
		"file9"    : "/open/prayer/obj/boris-hands",
		"amount9"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/killer/weapon/k_torch",
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"file10"   : "/open/wu/obj/armband",
		"file7"    : "/open/prayer/obj/boris-hat",
		"file2"    : "/open/wu/obj/ywsu",
		"file8"    : "/open/prayer/obj/kylin-belt",
		"amount8"  : 1,
	]) );
	set( "build", 10023 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room321",
	]) );
	set( "long", @LONG
這裡是南房滅神房,這個房間的武器都是由miffy 和其他好友幫忙收集而成
因為滅神匕的難以取得,所以更顯得此武器的難能可貴,而由此出去的武器
也都能夠發揮他其最大的功用,制敵機先,因此此大樓的主人武器技巧也是相當之高高到
絕世罕見的地步...

LONG);
	setup();
	replace_program(ROOM);
}
