inherit ROOM;
void create() {
	set( "short", "jtl 大樓2-2" );
	set( "owner", "panhermes" );
	set( "object", ([
		"file7"    : "/open/killer/obj/bellstar",
		"amount9"  : 50000,
		"amount8"  : 50000,
		"file4"    : "/open/killer/obj/bellstar",
		"file3"    : "/open/killer/obj/dagger",
		"file9"    : "/open/killer/obj/bellstar",
		"file8"    : "/open/killer/obj/bellstar",
		"amount10" : 1,
		"amount7"  : 49923,
		"file5"    : "/open/killer/obj/bellstar",
		"amount4"  : 50000,
		"amount2"  : 50000,
		"file10"   : "/open/killer/obj/dagger",
		"amount6"  : 1,
		"amount5"  : 50000,
		"amount1"  : 50000,
		"file1"    : "/open/killer/obj/bellstar",
		"amount3"  : 1,
		"file6"    : "/open/killer/obj/dagger",
		"file2"    : "/open/killer/obj/bellstar",
	]) );
	set( "build", 10077 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room321",
	]) );
	set( "long", @LONG
這裡是東房殺意錐房,這個房間的武器都是由miffy 和其他好友幫忙收集而成
因為殺意錐的難以取得,所以更顯得此武器的難能可貴,而由此出去的武器
也都能夠發揮他其最大的功用,吸取殺氣,因此此大樓的主人殺氣也是相當之高高到
絕世罕見的地步...
LONG);
	setup();
	replace_program(ROOM);
}
