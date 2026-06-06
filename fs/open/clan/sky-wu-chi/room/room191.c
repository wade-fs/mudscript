inherit ROOM;
void create() {
	set( "short", "$HIG$卡$HIG$卡$HIG$西$NOR$的小套房 " );
	set( "object", ([
		"amount3"  : 3283,
		"amount9"  : 1,
		"file5"    : "/obj/poison/rose_poison",
		"file1"    : "/open/mon/obj/ghost-cloak",
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"amount10" : 1,
		"amount1"  : 1,
		"amount5"  : 2685,
		"amount4"  : 1712,
		"amount6"  : 1,
		"amount8"  : 1,
		"file4"    : "/obj/poison/faint_poison",
		"file10"   : "/u/f/frequency/evil_book",
		"file8"    : "/daemon/class/blademan/obj/shield",
		"amount2"  : 2373,
		"file2"    : "/obj/poison/dark_poison",
		"file3"    : "/obj/poison/five_poison",
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount7"  : 1,
		"file7"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "build", 10023 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room193",
	]) );
	set( "long", @LONG
卡卡西是木葉隱第一高手
擁有過人的速度及實力和帥氣的外型
鍛鍊$HIW$忍術，$HIC$體術$NOR$和$HIY$幻術$NOR$是忍者最重要的課題
不過要當上火影也需要過人的智慧，所以努力求學是非常重要的
期待有一天卡卡西能成為忍界的第一高手
LONG);
	setup();
	replace_program(ROOM);
}
