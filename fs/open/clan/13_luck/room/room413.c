inherit ROOM;
void create() {
	set( "short", "斷魂橋尾" );
	set( "object", ([
		"amount2"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/mon/obj/ghost-claw",
		"file1"    : "/open/mon/obj/ghost-claw",
		"amount6"  : 1,
		"file2"    : "/open/mon/obj/ghost-claw",
		"file5"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/open/mon/obj/ghost-claw",
		"amount5"  : 1,
	]) );
	set( "owner", "mwf" );
	set( "build", 10062 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room407",
		"south"     : "/open/clan/13_luck/room/room414",
	]) );
	set( "long", @LONG

    好不容易衝到橋的尾端，人潮已經在漸漸退去，應該是要準備組下一
波的攻勢吧，或許又是已經認可你的實力了呢，恐怕只有見了十三吉祥之
主--太歲--才知道吧!!連接橋尾端的是一道長長的階梯，往上方延伸而去
，看來是特意營造若此，使人在徬徨之時對太歲更增敬畏之心。階梯旁好
像也有幾名守衛。


          .        .           .              ~~~~      ★.
      .               . ☆    .         .       ~~~~     .     .   .
          .      .             .          .   ~~~~   ~~~~        .
     ▁▂▃▄█▄▅▄▄▄▅▆█▆▃▅▆▆▅██▅▆▆▅█▆▅▄▄▃▃▂▂▁ 


LONG);
	setup();
	replace_program(ROOM);
}
