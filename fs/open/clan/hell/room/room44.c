inherit ROOM;
void create() {
	set( "short", "$HIC$kalin$HIW$的$HIG$雞絲頭3$NOR$" );
	set( "object", ([
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount6"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/mon/obj/ghost-legging",
		"file8"    : "/open/mon/obj/ghost-legging",
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount10" : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"file10"   : "/open/mon/obj/ghost-legging",
		"amount9"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"file7"    : "/open/mon/obj/ghost-legging",
	]) );
	set( "owner", "blur" );
	set( "build", 10177 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room136",
		"north"     : "/open/clan/hell/room/room4.c",
		"east"      : "/open/clan/hell/room/room63.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

由於各界大老忘不了kalin之前的雄風,
一直鼓動kalin復出....kalin思考了許久...
嗯...
嗯.......
嗯...........
嗯...............
z.....zz......zzzzz.....ZZZZZZ

kalin終於決定復出了!!
在周公的建議下... kalin決定附身在一個有正義感的小夥子身上,
這各小夥子平常以開計程車維生........
但只要他一感覺到有邪惡的力量入侵..殘害弱小....
他就會馬上找電話亭...化身為勇猛的戰士...


並口中喃喃道..惡魔!讓我代替月亮來懲罰你吧!!
LONG);
	setup();
	replace_program(ROOM);
}
