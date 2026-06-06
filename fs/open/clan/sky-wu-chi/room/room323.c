inherit ROOM;
void create() {
	set( "short", "jtl 大樓2-3" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount1"  : 1,
		"file7"    : "/open/killer/obj/hate_knife",
		"amount2"  : 50000,
		"file5"    : "/open/killer/obj/hate_knife",
		"file4"    : "/open/killer/obj/hate_knife",
		"file9"    : "/open/mogi/castle/obj/sspill",
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"amount6"  : 50000,
		"amount3"  : 50000,
		"amount9"  : 200,
		"amount8"  : 1,
		"file3"    : "/open/killer/obj/hate_knife",
		"file10"   : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/killer/obj/hate_knife",
		"file6"    : "/open/killer/obj/hate_knife",
		"amount4"  : 50000,
		"amount5"  : 50000,
		"amount7"  : 50000,
		"amount10" : 200,
		"file1"    : "/open/magic-manor/obj/master_snake_head",
	]) );
	set( "build", 10164 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room321",
	]) );
	set( "long", @LONG
這裡是西房千古恨,這個房間的武器都是由miffy 和其他好友幫忙收集而成
因為千古恨的難以取得,所以更顯得此武器的難能可貴,而由此出去的武器
也都能夠發揮他其最大的功用,殺敵無數,因此此大樓的主人暗器技巧也是相當之高高到
絕世罕見的地步...
LONG);
	setup();
	replace_program(ROOM);
}
