inherit ROOM;
void create() {
	set( "short", "$HIR$幫主$HIY$丹藥$HIM$房1$NOR$" );
	set( "owner", "auo" );
	set( "object", ([
		"file2"    : "/open/mon/obj/mon-pill",
		"amount6"  : 1,
		"amount4"  : 406,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/obj/gift/shenliwan",
		"file1"    : "/open/mogi/castle/obj/sspill",
		"file3"    : "/open/killer/obj/atman_pill",
		"amount1"  : 482,
		"amount2"  : 423,
		"amount3"  : 660,
	]) );
	set( "build", 10688 );
	set( "exits", ([
		"up"        : "/open/clan/time-limit/room/hall",
		"east"      : "/open/clan/time-limit/room/room192",
		"north"     : "/open/clan/time-limit/room/room194.c",
		"south"     : "/open/clan/time-limit/room/room193.c",
	]) );
	set( "long", @LONG
牆壁上大大小小的藥櫃上擺滿了幫主東征西討的戰利品,許多珍貴的丹藥在這裡都
可以找到,白色的藥櫃上放著千年靈芝仙丹,具有回復精氣神的功效,是對付神秘劍
客的必備藥品,黃色的藥櫃則是放著魔界的療傷聖藥九轉熊蛇丸,能夠瞬間補滿氣血
,而紅色的藥櫃存放的是靈藥生生造化丹,除了補滿氣血外,還能消除異常狀態,並將
內力回復到內力最大值,有了這些丹藥就能無往不利

LONG);
	setup();
	replace_program(ROOM);
}
