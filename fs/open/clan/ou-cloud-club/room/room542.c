inherit ROOM;
void create() {
	set( "short", "玄幻書殿" );
	set( "owner", "ctx" );
	set( "object", ([
		"file9"    : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"amount5"  : 1,
		"file5"    : "/obj/gift/shenliwan",
		"amount2"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"file1"    : "/obj/gift/shenliwan",
		"file3"    : "/obj/gift/shenliwan",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount10" : 1,
		"file7"    : "/obj/gift/shenliwan",
		"file10"   : "/obj/gift/shenliwan",
		"amount4"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"file2"    : "/obj/gift/shenliwan",
		"file4"    : "/obj/gift/shenliwan",
		"amount9"  : 1,
		"file8"    : "/obj/gift/shenliwan",
	]) );
	set( "build", 10530 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room540",
	]) );
	set( "long", @LONG
這邊可是以簡體為主的奇幻文學網站，不過有別於繁體的中
文奇幻文學網站來說，這邊的更新速度可是相當的快，對於想看
第一手的新書來說，這邊是最適合的選擇了，像是魔法學徒等，
幾乎實體書上市沒幾天這邊就可以看到電子書的內文，想先目睹
為快者，錯過這裡是大大的浪費。

LONG);
	setup();
	replace_program(ROOM);
}
