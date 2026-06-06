inherit ROOM;
void create() {
	set( "short", "jtl 大樓1-3" );
	set( "owner", "panhermes" );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room318",
	]) );
	set( "object", ([
		"amount10" : 2000,
		"amount4"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/poison/obj/blue_key",
		"file1"    : "/open/snow/obj/snow_token",
		"amount2"  : 22000,
		"file2"    : "/open/killer/obj/bellstar",
		"file3"    : "/open/quests/snake/npc/obj/snake-key-1",
		"amount3"  : 1,
		"file10"   : "/open/killer/obj/s_pill",
		"file5"    : "/open/poison/obj/stonekey",
		"amount5"  : 1,
		"amount6"  : 40,
		"file6"    : "/open/doctor/pill/f_pill",
	]) );
	set( "light_up", 1 );
	set( "build", 11112 );
	set( "long", @LONG
這裡是miffy 大樓的第一層偏廳,這裡存放的東西是屬於比較普通的總類
而這裡又是稱為miffy 平常出去戰鬥時的換裝房,與他相同的另一個房
間則是miffy 大樓第一層之3
這裡正是miffy 在換裝時的第三房間,三間房間加起來的eq 剛好就是一整套
的戰鬥裝..
LONG);
	setup();
	replace_program(ROOM);
}
