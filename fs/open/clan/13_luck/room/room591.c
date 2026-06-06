inherit ROOM;
void create() {
	set( "short", "白色龍元" );
	set( "owner", "basaka" );
	set( "object", ([
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file10"   : "/open/magic-manor/obj/water-ball",
		"amount6"  : 1,
		"amount10" : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 12448 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room582.c",
		"north"     : "/open/clan/13_luck/room/room590.c",
	]) );
	set( "long", @LONG
傳說在崑崙山上有一個神秘的結界，只有當武功蓋世的人才有辦法
突破結界到達一個神秘的次元，在那神秘的次元有六色龍，各自擁有不
同的神奇功用，而在此間的丹藥，正是白龍的精華，可以暫時大幅提昇
自身的防禦力，變成不死怪物的驚人耐力，想要打變態級的怪物之前，
一定要先來一顆。

LONG);
	setup();
	replace_program(ROOM);
}
