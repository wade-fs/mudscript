inherit ROOM;
void create() {
	set( "short", "十三殺道二" );
	set( "object", ([
		"amount5"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/mon/obj/ghost-legging",
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount6"  : 1,
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
	]) );
	set( "owner", "mwf" );
	set( "build", 10539 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room405",
		"south"     : "/open/clan/13_luck/room/room407.c",
	]) );
	set( "long", @LONG

    階梯雖然不長，但對你來說卻是步步艱難，路旁不斷地出現十三吉祥
所屬的刀堂，劍堂，戰堂和拳堂中所訓練出來的高手，他們個個冷血無情
，只以殺敗敵人為目的，只見他們一群群輪番上陣，讓你明瞭欲見太歲簡
直難如登天!!!!


          .        .           .              ~~~~      ★.
      .               . ☆    .         .       ~~~~     .     .   .
          .      .             .          .   ~~~~   ~~~~        .
     ▁▂▃▄█▄▅▄▄▄▅▆█▆▃▅▆▆▅██▅▆▆▅█▆▅▄▄▃▃▂▂▁


LONG);
	setup();
	replace_program(ROOM);
}
