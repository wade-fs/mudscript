inherit ROOM;
void create() {
	set( "short", "$HIG$廚房$NOR$" );
	set( "owner", "fisikiki" );
	set( "object", ([
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount1"  : 424,
		"file8"    : "/open/capital/guard/gring",
		"amount8"  : 1,
		"file2"    : "/open/mon/obj/thousand-nectar",
		"amount6"  : 245,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount5"  : 204,
		"file9"    : "/open/mon/obj/mon-pill",
		"amount4"  : 668,
		"amount10" : 165,
		"file3"    : "/obj/stone/powder",
		"file10"   : "/open/killer/obj/atman_pill",
		"amount2"  : 104,
		"amount9"  : 1729,
		"file1"    : "/open/mogi/castle/obj/sspill",
		"file7"    : "/open/fire-hole/obj/w-pill",
		"file6"    : "/open/fire-hole/obj/b-pill",
		"amount3"  : 219,
		"amount7"  : 196,
	]) );
	set( "build", 10176 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room74",
		"west"      : "/open/clan/time-limit/room/room43.c",
	]) );
	set( "long", @LONG
學生人數眾多,當然廚師也得要多而且要有一身的本事,才能滿足學生的胃,
走到廚房一看,卻看到數百位家庭小精靈忙著做菜和打掃,原來學校
的所有食物都是由家庭小精靈所完成,而小精靈們一看到你,馬上送上
奶油餡餅和南瓜汁,讓你心生邪惡的念頭,想偷偷帶兩個家庭小精靈回家

LONG);
	setup();
	replace_program(ROOM);
}
