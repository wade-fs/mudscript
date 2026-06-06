inherit ROOM;
void create() {
	set( "short", "$HIR$禁忌$HIG$森林1$NOR$" );
	set( "owner", "firefan" );
	set( "object", ([
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
	]) );
	set( "build", 10652 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room65.c",
		"west"      : "/open/clan/time-limit/room/room64",
		"east"      : "/open/clan/time-limit/room/room66.c",
		"north"     : "/open/clan/time-limit/room/room69.c",
	]) );
	set( "long", @LONG
一踏進森林地帶,黑暗如潮水般將你淹沒,四周的一草一木如同有生命
一般張牙舞爪,任何的風吹草動都讓你心跳加速,森林裡有什麼猛獸
你也不清楚,你小心翼翼的往前走,深怕吵醒正在熟睡中的猛獸,
而成為牠的點心,地上的樹枝和石頭讓你前進更加困難

LONG);
	setup();
	replace_program(ROOM);
}
