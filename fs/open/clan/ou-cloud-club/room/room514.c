inherit ROOM;
void create() {
	set( "short", "神魔亂世錄" );
	set( "light_up", 1 );
	set( "owner", "ctx" );
	set( "object", ([
		"file7"    : "/obj/gift/xiandan",
		"file1"    : "/obj/gift/xiandan",
		"file5"    : "/obj/gift/xiandan",
		"file8"    : "/obj/gift/xiandan",
		"amount3"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file9"    : "/obj/gift/xiandan",
		"file4"    : "/obj/gift/xiandan",
		"file10"   : "/obj/gift/xiandan",
		"amount4"  : 1,
		"amount9"  : 1,
		"file2"    : "/obj/gift/xiandan",
		"file6"    : "/obj/gift/xiandan",
		"amount1"  : 1,
		"amount7"  : 1,
		"file3"    : "/obj/gift/xiandan",
		"amount5"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 13115 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room511",
	]) );
	set( "long", @LONG
在一片交雜著黑暗與光明的虛無中, 新生與破滅之力彼此糾
纏不清,那是星辰的誕生之地,亦是星辰毀滅後的歸所。一位在魔
法學院學習魔法的少年, 因緣際會的闖入了神魔兩位公主的決鬥
空間中,意外造成了兩位公主受創致使雙方無法返回神魔兩界,而
幸運的少年更因為兩位公主的約定而成為兩位公主的主人, 一場
徹底改變少年的生活就此開始....

LONG);
	setup();
	replace_program(ROOM);
}
