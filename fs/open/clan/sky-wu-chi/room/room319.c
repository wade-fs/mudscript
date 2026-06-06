inherit ROOM;
void create() {
	set( "short", "jtl 大樓1-2" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount7"  : 1,
		"file8"    : "/open/magic-manor/obj/wood-ball",
		"amount9"  : 1,
		"file7"    : "/open/killer/obj/dagger",
		"file5"    : "/open/gblade/obj/sa-head",
		"amount5"  : 1,
		"file9"    : "/open/capital/obj/chen_dagger",
		"amount8"  : 1,
		"amount6"  : 1,
		"file6"    : "/obj/gift/xiandan",
	]) );
	set( "light_up", 1 );
	set( "build", 10017 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room318",
	]) );
	set( "long", @LONG
這裡是miffy 大樓的第一層偏廳,這裡存放的東西是屬於比較普通的總類
而這裡又是稱為miffy 平常出去戰鬥時的換裝房,與他相同的另一個房
間則是miffy 大樓第一層之2
這裡正是miffy 在換裝時的第二房間,兩間房間加起來的eq 剛好就是一整套
的戰鬥裝..
LONG);
	setup();
	replace_program(ROOM);
}
