inherit ROOM;
void create() {
	set( "short", "jtl 大樓1-1" );
	set( "owner", "panhermes" );
	set( "object", ([
		"file1"    : "/open/killer/obj/hate_knife",
		"file5"    : "/daemon/class/fighter/ywhand",
		"amount1"  : 87078,
		"file6"    : "/open/gsword/obj/yuskirt",
		"amount6"  : 1,
		"amount9"  : 1415,
		"file4"    : "/open/main/room/sp/stone",
		"file9"    : "/open/killer/obj/s_pill",
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10611 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room319.c",
		"out"       : "/open/clan/sky-wu-chi/room/room212",
		"up"        : "/open/clan/sky-wu-chi/room/room321.c",
		"west"      : "/open/clan/sky-wu-chi/room/room320.c",
	]) );
	set( "long", @LONG
這裡是miffy 大樓的第一層偏廳,這裡存放的東西是屬於比較普通的總類
而這裡又是稱為miffy 平常出去戰鬥時的換裝房,與他相同的另一個房
間則是miffy 大樓第一層之1
這裡正是miffy 在換裝時的第二房間,兩間房間加起來的eq 剛好就是一整套
的戰鬥裝..
LONG);
	setup();
	replace_program(ROOM);
}
