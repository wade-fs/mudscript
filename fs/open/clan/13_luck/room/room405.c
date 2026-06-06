inherit ROOM;
void create() {
	set( "short", "十三殺道三" );
	set( "object", ([
		"amount5"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/mon/obj/ghost-helmet",
		"file1"    : "/open/mon/obj/ghost-helmet",
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount6"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount2"  : 1,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount1"  : 1,
	]) );
	set( "owner", "mwf" );
	set( "build", 11403 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room406",
	]) );
	set( "long", @LONG

    十三殺道的石階到此可說已經到了一個段落，再往上就到十三吉祥的
殿前大道了，而殿前大道的兩旁各是十三吉祥三殿中的幽冥殿及極火殿，
據說幽冥殿的殿主『幽冥王』和極火殿的殿主『烈陽神』在十三吉祥內的
聲望不輸給太歲，但他們卻認為太歲的能力可望成為日後武林的霸主，所
便跟隨太歲殺戮武林中自以為正派的人士。其旗下戰將更是殺人不眨眼的
殺手。

          .        .           .              ~~~~      ★.
      .               . ☆    .         .       ~~~~     .     .   .
          .      .             .          .   ~~~~   ~~~~        .
     ▁▂▃▄█▄▅▄▄▄▅▆█▆▃▅▆▆▅██▅▆▆▅█▆▅▄▄▃▃▂▂▁


LONG);
	setup();
	replace_program(ROOM);
}
