inherit ROOM;
void create() {
	set( "short", "StarTrek-TNG" );
	set( "owner", "ctx" );
	set( "object", ([
		"amount4"  : 1,
		"amount10" : 1,
		"file1"    : "/open/ghost-hole/obj/light-spirit",
		"file6"    : "/open/ghost-hole/obj/light-spirit",
		"amount7"  : 1,
		"file5"    : "/open/ghost-hole/obj/light-spirit",
		"file2"    : "/open/ghost-hole/obj/light-spirit",
		"file3"    : "/open/ghost-hole/obj/light-spirit",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/ghost-hole/obj/fire-spirit",
		"file4"    : "/open/ghost-hole/obj/light-spirit",
		"amount8"  : 1,
		"file7"    : "/open/ghost-hole/obj/light-spirit",
		"file10"   : "/open/ghost-hole/obj/light-spirit",
		"amount3"  : 1,
		"file9"    : "/obj/gift/bingtang",
	]) );
	set( "build", 10173 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room545",
	]) );
	set( "long", @LONG
StarTrek的第二代作品，也是ctx最喜歡的一部,TNG即The N
ext Generation的縮寫，裡面講述者24世紀時畢凱艦長與其船員
在USS Enterprise D上的總總的故事，包括承接第一部與羅慕倫
人和克林貢人的故事,還有新種族像是半人半機械的Borg(博格人
)、能力近乎神的存在的Q族等，故事內容相當精采。

LONG);
	setup();
	replace_program(ROOM);
}
