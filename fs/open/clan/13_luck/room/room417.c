inherit ROOM;
void create() {
	set( "short", "滅殺之道一" );
	set( "object", ([
		"file8"    : "/open/center/obj/mechoufen-head",
		"amount10" : 1,
		"amount1"  : 1,
		"file5"    : "/open/fire-hole/obj/g-pill",
		"file1"    : "/obj/gift/shenliwan",
		"file3"    : "/open/center/obj/mechoufen-head",
		"file9"    : "/open/center/obj/mechoufen-head",
		"file7"    : "/open/center/obj/mechoufen-head",
		"amount7"  : 1,
		"amount5"  : 190,
		"amount3"  : 1,
		"file6"    : "/open/center/obj/mechoufen-head",
		"amount9"  : 1,
		"file4"    : "/open/fire-hole/obj/r-pill",
		"file10"   : "/open/center/obj/mechoufen-head",
		"amount8"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount4"  : 190,
	]) );
	set( "owner", "mwf" );
	set( "build", 12435 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room416",
		"out"       : "/open/clan/13_luck/room/room418",
	]) );
	set( "long", @LONG

    剛踏進十三吉祥的大門，四周圍靜的讓人毛骨聳然，空氣中充斥著一
股作人欲嘔的血腥味，但是路上卻沒有看到任何屍首或者打鬥過的痕跡，
你踏著腳步小心地往前走著，腳步聲和著心跳更添幾分恐怖的氣氛，不知
道有多少想闖入十三吉祥的武林人士被人擊斃在此，突然間!!左右兩旁好
像有黑影一閃!!!!


          .        .           .              ~~~~      ★.
      .               . ☆    .         .       ~~~~     .     .   .
          .      .             .          .   ~~~~   ~~~~        .     ▁▂▃▄█▄▅▄▄▄▅▆█▆▃▅▆▆▅██▅▆▆▅█▆▅▄▄▃▃▂▂▁


LONG);
	setup();
	replace_program(ROOM);
}
