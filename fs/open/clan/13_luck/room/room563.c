inherit ROOM;
void create() {
	set( "short", "練武場" );
	set( "owner", "roarii" );
	set( "object", ([
		"amount3"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10061 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room564",
		"west"      : "/open/clan/13_luck/room/room562",
	]) );
	set( "long", @LONG
　　耳邊傳來的盡是絡繹不絕的吆喝聲，為了在武林江湖中能夠揚
名立萬，每一個人莫不辛勤的練習，然而場邊也有幾個累得滿身大
汗的弟子正坐在樹蔭下乘涼休息，不過看他們的神情似乎非常的緊
張，看來是怕被發現在偷懶吧。

LONG);
	setup();
	replace_program(ROOM);
}
