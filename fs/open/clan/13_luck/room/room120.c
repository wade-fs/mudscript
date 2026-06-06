inherit ROOM;
void create() {
	set( "short", "歹勇仔藥丸室" );
	set( "owner", "biob" );
	set( "object", ([
		"file10"   : "/open/mon/obj/mon-pill",
		"amount10" : 408,
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount8"  : 141,
		"amount4"  : 1,
		"amount5"  : 284,
		"file6"    : "/open/fire-hole/obj/w-pill",
		"amount7"  : 115,
		"amount3"  : 117,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 234,
		"file1"    : "/open/mon/obj/mon-pill",
		"file8"    : "/open/ping/obj/poison_pill",
		"file2"    : "/open/fire-hole/obj/r-pill",
		"amount2"  : 182,
		"file7"    : "/open/fire-hole/obj/g-pill",
		"file4"    : "/open/quests/snake/npc/obj/snake-key-2",
		"amount6"  : 226,
		"amount9"  : 241,
	]) );
	set( "build", 11076 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room59.c",
		"north"     : "/open/clan/13_luck/room/room108",
		"moon"      : "/open/clan/13_luck/room/hall.c",
		"south"     : "/open/clan/13_luck/room/room694.c",
		"east"      : "/open/clan/13_luck/room/room126.c",
	]) );
	set( "long", @LONG
這裡是歹勇仔儲存藥品的地方, 只見各式各樣的
仙丹靈藥放滿了整個房間, 任您要回氣補血, 增強內
力, 解毒療傷, 甚至可以增加一甲子功力的丹藥都有
其中九轉熊蛇丸乃是古堡白虎室耗時檢來的, 更有打
七魔將得來不易的生生造化丹, 幻界六色龍的精元,
甚至殺雪蒼弟子換取不易的百花清心露等, 皆是歹勇
仔, 辛辛苦苦收集來的, 也許跟他要顆吃吃可以保證
不掉替身也不一定.......
LONG);
	setup();
	replace_program(ROOM);
}
