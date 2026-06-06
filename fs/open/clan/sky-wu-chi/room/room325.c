inherit ROOM;
void create() {
	set( "short", "jtl 大樓2-5" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount1"  : 1,
		"file7"    : "/open/ping/npc/zhang-z-head",
		"amount2"  : 1,
		"file5"    : "/open/capital/obj/chen_dagger",
		"file4"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file9"    : "/open/mogi/castle/obj/sspill",
		"file8"    : "/open/ping/obj/ra-head",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount9"  : 200,
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file10"   : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/firedancer/npc/eq/r_pants",
		"file6"    : "/open/ping/obj/liu-head",
		"amount4"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"amount10" : 200,
		"file1"    : "/open/firedancer/npc/eq/r_shield",
	]) );
	set( "build", 10014 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room321",
	]) );
	set( "long", @LONG
這裡是北房絕世匕房,這個房間的武器都是由miffy 和其他好友幫忙收集而成
因為絕世匕的難以取得,所以更顯得此武器的難能可貴,而由此出去的武器
也都能夠發揮他其最大的功用,毀滅萬物,因此此大樓的主人殺氣也是相當之高高到
絕世罕見的地步...
LONG);
	setup();
	replace_program(ROOM);
}
