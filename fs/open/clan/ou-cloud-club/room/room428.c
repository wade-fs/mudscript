inherit ROOM;
void create() {
	set( "short", "$HIY$寶貝中心$NOR$" );
	set( "object", ([
		"amount6"  : 534,
		"file8"    : "/obj/gift/shenliwan",
		"file9"    : "/open/mon/obj/mon-pill",
		"file7"    : "/open/main/room/sp/stone",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 1,
		"file1"    : "/obj/gift/bingtang",
		"file10"   : "/open/killer/obj/atman_pill",
		"amount4"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 370,
		"file5"    : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"amount10" : 3621,
		"file4"    : "/open/mon/obj/flower-claw",
		"file3"    : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount2"  : 411,
	]) );
	set( "build", 10005 );
	set( "owner", "kid" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room762",
		"up"        : "/open/clan/ou-cloud-club/room/room755",
		"east"      : "/open/clan/ou-cloud-club/room/room585.c",
		"west"      : "/open/clan/ou-cloud-club/room/room211.c",
		"north"     : "/open/clan/ou-cloud-club/room/room761.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
強而有力的戰鼓聲讓你的精神大振，想要活動一下筋骨讓體
內沸騰的氣血舒緩，十八路長拳施展完畢後，你滿意的擦了擦額
頭上的汗珠，突然眼前出現了一位高大的巨人，身穿白金戰甲，
手持斬鐵巨劍，正是戰神$CYN$『奧丁』$NOR$，拍拍你的肩膀為你加油打氣
之後轉身又走進光圈之中‧

LONG);
	setup();
	replace_program(ROOM);
}
