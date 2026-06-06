inherit ROOM;
void create() {
	set( "short", "$HIB$望月心閣$NOR$" );
	set( "object", ([
		"file4"    : "/open/capital/guard/gring",
		"file1"    : "/daemon/class/bonze/puty_pullium",
		"amount3"  : 1,
		"file2"    : "/open/gsword/obj/may_ring",
		"amount6"  : 1,
		"file8"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount8"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
	]) );
	set( "build", 10091 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room452",
		"west"      : "/open/clan/sky-wu-chi/room/room438.c",
	]) );
	set( "long", @LONG

西城楊柳弄春柔 動離憂 淚難收
猶憶多情 曾為繫歸舟
碧野朱橋當日事 人不見 水空流

韶華不為少年留 恨悠悠 幾時休
飛絮落花時候 一登樓
便做春江都是淚 流不盡 許多愁

小槽春酒滴珠紅 莫匆匆 滿金鐘
飲散落花流水 各西東
後會不知何處是 煙浪遠 暮雲重

LONG);
	setup();
	replace_program(ROOM);
}
