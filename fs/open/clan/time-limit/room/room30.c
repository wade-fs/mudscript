inherit ROOM;
void create() {
	set( "short", "$BRED$豬頭$BCYN$酒吧$NOR$" );
	set( "owner", "car" );
	set( "object", ([
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
	]) );
	set( "build", 10816 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room11",
	]) );
	set( "long", @LONG
酒吧上頭掛著一塊木頭,木頭上畫著豬頭,裡面正是怪胎的聚集地,
不過也因為怪胎多,使得常人不喜歡到這裡來,因此生意沒有三根掃帚來的好,
門口貼著幾張魔法部的通緝傳單,其中一張正是頭號通緝犯'天狼星-布萊克',
裡頭的照片正對著你張牙舞爪,進入酒吧裡,一堆人全身包的緊緊的,
幾個人偷偷摸摸的說話,幾個人抽著煙,煙霧彌漫整個酒吧

LONG);
	setup();
	replace_program(ROOM);
}
