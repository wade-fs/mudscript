inherit ROOM;
void create() {
	set( "short", "$HIW$$HBYEL$美短小窩$NOR$" );
	set( "object", ([
		"file9"    : "/obj/stone/powder",
		"amount3"  : 112,
		"amount1"  : 24,
		"file1"    : "/open/mogi/castle/obj/sspill",
		"file6"    : "/obj/stone/suipian",
		"file3"    : "/open/mon/obj/mon-pill",
		"amount9"  : 1,
		"amount2"  : 130,
		"file4"    : "/obj/stone/powder",
		"amount4"  : 7,
		"amount6"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/obj/stone/jiao",
	]) );
	set( "build", 10041 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room217",
	]) );
	set( "owner", "assist" );
	set( "long", @LONG
    強而有力的戰鼓聲讓你的精神大振，想要活動一下筋骨讓體
內沸騰的氣血舒緩，十八路長拳施展完畢後，你滿意的擦了擦額
手持斬鐵巨劍，正是戰神『奧丁』，拍拍你的肩膀為你加油打氣
之後轉身又走進光圈之中‧

           地上有隻可愛的小貓........
LONG);
	setup();
	replace_program(ROOM);
}
