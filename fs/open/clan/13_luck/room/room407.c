inherit ROOM;
void create() {
	set( "short", "十三殺道一" );
	set( "object", ([
		"amount5"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"file1"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount6"  : 1,
		"file6"    : "/open/mon/obj/ghost-cloak",
		"amount2"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount1"  : 1,
	]) );
	set( "owner", "mwf" );
	set( "build", 12924 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room406",
		"out"       : "/open/clan/13_luck/room/room413",
	]) );
	set( "long", @LONG

    這條階梯延伸出去的道路和前面的滅殺道感覺上並不相同，路面並不
窄小，石階更是以非常大塊的石板拼湊而成，顯示著一股威風八面的氣魄
路上更沒有安裝任何機關，看來建造者已經認同了能夠抵達這裡的人實力
，已經不再以小伎倆來取勝，代之以明刀明槍的對決，路旁的守衛看起來
也個個實力不弱。


          .        .           .              ~~~~      ★.
      .               . ☆    .         .       ~~~~     .     .   .
          .      .             .          .   ~~~~   ~~~~        .
     ▁▂▃▄█▄▅▄▄▄▅▆█▆▃▅▆▆▅██▅▆▆▅█▆▅▄▄▃▃▂▂▁


LONG);
	setup();
	replace_program(ROOM);
}
