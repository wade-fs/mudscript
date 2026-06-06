inherit ROOM;
void create() {
	set( "short", "天靈丹藥櫃" );
	set( "object", ([
		"amount8"  : 1,
		"file3"    : "/open/center/obj/mechoufen-head",
		"file4"    : "/obj/poison/dark_poison",
		"file5"    : "/obj/poison/faint_poison",
		"file7"    : "/obj/poison/five_poison",
		"amount6"  : 717,
		"amount5"  : 388,
		"file9"    : "/open/poison/obj/pkingbook",
		"amount2"  : 1,
		"amount1"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/poison/obj/pbasebook",
		"file1"    : "/open/wu/obj/ya-head",
		"file2"    : "/open/center/obj/mechoufen-head",
		"amount3"  : 1,
		"amount4"  : 690,
		"amount7"  : 976,
		"file6"    : "/obj/poison/rose_poison",
	]) );
	set( "light_up", 1 );
	set( "build", 10024 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room293",
	]) );
	set( "long", @LONG
這裡是AMEI擺三種救命丹藥之中的天靈丹的地方，他的最大功效
就是能恢復所有的狀態，不過要是碰上一些奇奇怪怪的狀態他
就沒辦法了，這是他唯一的缺點但是自從長沙鎮的超級仙丹停售時
他卻變成了最搶手的丹藥O，假如你凍傷或灼傷想要趕快好記得來
跟AMEI拿點天靈丹去吃吧！
LONG);
	setup();
	replace_program(ROOM);
}
