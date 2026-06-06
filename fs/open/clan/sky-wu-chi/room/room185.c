inherit ROOM;
void create() {
	set( "short", "寒雪冰霜的小套房" );
	set( "owner", "roboo" );
	set( "object", ([
		"file2"    : "/obj/gift/unknowdan",
		"file3"    : "/obj/gift/xisuidan",
		"amount2"  : 1,
		"file4"    : "/obj/gift/unknowdan",
		"amount10" : 1,
		"file10"   : "/obj/gift/lingzhi",
		"amount9"  : 1,
		"amount8"  : 1,
		"file1"    : "/obj/gift/xisuidan",
		"file9"    : "/obj/gift/lingzhi",
		"amount6"  : 1,
		"file6"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"amount7"  : 1,
		"file5"    : "/obj/gift/unknowdan",
		"file8"    : "/obj/gift/bingtang",
		"amount5"  : 1,
		"file7"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"amount4"  : 1,
	]) );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room16",
	]) );
	set( "build", 10207 );
	set( "light_up", 1 );
	set( "long", @LONG
走進房間裡，你可以看到寒雪冰霜正在忙著打掃環境呢。旁邊的音響正撥放著悠揚的古典音樂，在小茶几上還擺放著一束美麗的玫瑰花，令你覺得整個人都輕鬆了起來。當你坐下來的時候，你注意到在桌上有一張寒雪冰霜和他女朋友的合照，照片裡的他看起來十分的幸福呢。
LONG);
	setup();
	replace_program(ROOM);
}
