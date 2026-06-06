inherit ROOM;
void create() {
	set( "short", "蠻荒地帶" );
	set( "object", ([
		"file7"    : "/open/mon/obj/ghost-cloak",
		"amount4"  : 12,
		"amount5"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"amount2"  : 8,
		"file4"    : "/obj/stone/suipian",
		"amount3"  : 48,
		"file8"    : "/open/mon/obj/ghost-helmet",
		"file2"    : "/obj/stone/jiao",
		"amount8"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"file9"    : "/obj/gift/xisuidan",
		"file1"    : "/open/fire-hole/obj/b-pill",
		"file10"   : "/open/mon/obj/ghost-claw",
		"amount1"  : 16,
		"file3"    : "/obj/stone/powder",
		"file6"    : "/open/mon/obj/ghost-legging",
	]) );
	set( "build", 10046 );
	set( "owner", "none" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room181",
	]) );
	set( "long", @LONG
  
    光源不夠,裡面那些動物撲向中間有日光的地方,陰影中隱隱約約
看到一些形體,看起來比人類大一倍左右,應該是類似獅虎之類的生物
,裡面的野獸越來越是騷動,示威性的低吼聲不斷的從四面傳出,看來看
去也認不出是什動物,只能確定有頭有尾四足著地,身上的紅光較藍綠
光色多,突然間裡面的動物同時激動了起來,讓你的心中一時毛了起來,
只想趕快走出去

LONG);
	setup();
	replace_program(ROOM);
}
