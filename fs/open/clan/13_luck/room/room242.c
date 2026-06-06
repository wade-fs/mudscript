inherit ROOM;
void create() {
	set( "short", "南柯一夢樓" );
	set( "object", ([
		"amount5"  : 1,
		"file5"    : "/open/firedancer/npc/eq/r_cape",
		"amount8"  : 1,
		"file9"    : "/obj/gift/xisuidan",
		"file7"    : "/open/firedancer/npc/eq/r_belt",
		"file1"    : "/open/firedancer/npc/eq/r_head",
		"amount4"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/firedancer/npc/eq/r_boots",
		"amount6"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/firedancer/npc/eq/r_cloth",
		"file3"    : "/open/firedancer/npc/eq/r_finger",
		"amount9"  : 1,
		"file2"    : "/open/firedancer/npc/eq/r_hands",
		"amount2"  : 1,
		"file8"    : "/open/firedancer/npc/eq/r_armbands",
		"amount1"  : 1,
	]) );
	set( "build", 11631 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room243.c",
	]) );
	set( "long", @LONG

 M U D必竟是遊戲，生活也是要過，總有一天也是需要面對真正的人
生你的父母，你的老婆，你的女友，你的家庭，但我們還是不會忘記
我們曾經在FS上並肩作戰過，共同努力建立幫派過，在這成長過...
感謝幻想中有你 共同努力多感動  如今回想心安慰 上天安排這一切
一切總是有盡頭 夢醒時分是時後  幻想生活瞬眼過 南柯夢醒該振作
                          
                                           永遠的吉祥人

LONG);
	setup();
	replace_program(ROOM);
}
