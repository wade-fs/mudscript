inherit ROOM;
void create() {
	set( "short", "滅殺之道二" );
	set( "object", ([
		"file5"    : "/open/center/obj/mechoufen-head",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/center/obj/mechoufen-head",
		"file8"    : "/open/center/obj/mechoufen-head",
		"amount6"  : 1,
		"file3"    : "/open/center/obj/mechoufen-head",
		"file9"    : "/open/center/obj/mechoufen-head",
		"amount2"  : 1,
		"amount10" : 1,
		"file2"    : "/open/center/obj/mechoufen-head",
		"file1"    : "/open/center/obj/mechoufen-head",
		"amount9"  : 1,
		"file6"    : "/open/center/obj/mechoufen-head",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/center/obj/mechoufen-head",
	]) );
	set( "owner", "mwf" );
	set( "build", 10122 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room415",
		"south"     : "/open/clan/13_luck/room/room417",
	]) );
	set( "long", @LONG

    剛逃過大門口的追殺，你卻發現好像已經沒有退回去的可能，門口那
兒不斷地擁出一波波的守衛，在不知不覺當中你已經身陷重圍了，正當你
在猶豫是否該往前衝殺之時，兩旁卻又跳出幾個不同裝扮的守衛，看來惡
戰是在所難免了!!前方似乎有座小橋，先衝上去再做打算吧!!!!


          .        .           .              ~~~~      ★.
      .               . ☆    .         .       ~~~~     .     .   .
          .      .             .          .   ~~~~   ~~~~        .
     ▁▂▃▄█▄▅▄▄▄▅▆█▆▃▅▆▆▅██▅▆▆▅█▆▅▄▄▃▃▂▂▁


LONG);
	setup();
	replace_program(ROOM);
}
