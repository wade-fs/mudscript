inherit ROOM;
void create() {
	set( "short", "$HIR$華麗$HIW$與$HIY$污痕$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount2"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount6"  : 1,
		"amount10" : 1,
	]) );
	set( "owner", "car" );
	set( "build", 10759 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room51",
	]) );
	set( "long", @LONG
這是斜角巷唯一的一間書店,除了販賣霍格華茲的學生用書,也有賣奇怪的書籍,
一位店員穿著手套正努力將兩本咬在一起的怪獸的怪獸書分開,
另一本書則咬到他的手臂,讓他痛的大叫,書架上陳列各式的符咒書,
你的眼睛則被一本名為死亡前兆的書所吸引,書的封面有著一隻黑狗的頭,
也就是所謂的狗靈,具巫師的說法,看到狗靈後不久就會死去,
你也開始擔心自己是否也看到狗靈了,趕緊移開視線

LONG);
	setup();
	replace_program(ROOM);
}
