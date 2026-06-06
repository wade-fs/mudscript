inherit ROOM;
void create() {
	set( "short", "魔法學徒-費納希雅" );
	set( "light_up", 1 );
	set( "object", ([
		"amount9"  : 1,
		"file2"    : "/obj/gift/bingtang",
		"file7"    : "/obj/gift/bingtang",
		"file9"    : "/obj/gift/lingzhi",
		"amount3"  : 1,
		"file8"    : "/obj/gift/lingzhi",
		"amount10" : 1,
		"amount1"  : 1,
		"file1"    : "/obj/gift/bingtang",
		"amount2"  : 1,
		"file5"    : "/obj/gift/lingzhi",
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/obj/gift/bingtang",
		"file4"    : "/obj/gift/lingzhi",
		"file6"    : "/obj/gift/bingtang",
		"amount8"  : 1,
		"amount4"  : 1,
		"file3"    : "/obj/gift/bingtang",
		"amount5"  : 1,
	]) );
	set( "build", 11142 );
	set( "owner", "ctx" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room506",
	]) );
	set( "long", @LONG
費納希雅, 卡敖奇王國的大魔導士之姪女,其人相當漂亮,甚
至在貝爾蒂娜以及索菲恩公主殿下都自嘆不如, 雖然表面上她並
不是4位魔法學徒試練生的同伴,但因為知其真正身分的人少之又
少,所以在大家眼裡,被認為與主角恩萊科為一對命運雙子星 ,兩
者命運息息相關,同時也跟恩萊科同為禁咒法師。

LONG);
	setup();
	replace_program(ROOM);
}
