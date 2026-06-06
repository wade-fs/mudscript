inherit ROOM;
void create() {
	set( "short", "$BRED$活米村$BGRN$一景$NOR$" );
	set( "owner", "woodsword" );
	set( "object", ([
		"amount8"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"amount7"  : 1,
		"amount10" : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount6"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 10062 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room8.c",
		"west"      : "/open/clan/time-limit/room/room4.c",
		"east"      : "/open/clan/time-limit/room/room6.c",
		"south"     : "/open/clan/time-limit/room/room11",
	]) );
	set( "long", @LONG
這裡是活米村的中心,也是最熱鬧的地方,一旁的三根掃帚門庭若市,
而蜂蜜公爵的糖果則是讓學生們愛不釋手,郵局前一堆貓頭鷹,
有的正在打盹,有的正準備出發寄信,有些小孩子將積雪堆成一個雪人,
有些在一旁打起雪仗來了,前方不遠處就是霍格華茲,最有名的魔法學校

LONG);
	setup();
	replace_program(ROOM);
}
