inherit ROOM;
void create() {
	set( "short", "吉祥置物櫃戊" );
	set( "object", ([
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount10" : 1,
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10701 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room301",
	]) );
	set( "long", @LONG

    這裡是吉祥置物櫃戊，專門為還沒有房間的新進幫眾所設立的，此
環境優雅舒適，讓新進的幫眾有個可以去的地方跟休息的地方，使他們
快點成為十三吉祥的戰力，一起為幫派的未來而努力，一同打拼，萬丈
高樓平地起，蟠龍臥虎高山頂，希望能為天下第一大幫而邁進。

LONG);
	setup();
	replace_program(ROOM);
}
