inherit ROOM;
void create() {
	set( "short", "$HIY$寶貝中心$NOR$" );
	set( "object", ([
		"amount3"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file3"    : "/obj/gift/xiandan",
		"amount10" : 1,
		"file2"    : "/obj/gift/unknowdan",
		"amount2"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"file1"    : "/obj/gift/unknowdan",
		"amount1"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"file6"    : "/obj/gift/unknowdan",
		"file7"    : "/obj/gift/xiandan",
		"file4"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"file5"    : "/obj/gift/unknowdan",
		"file8"    : "/obj/gift/unknowdan",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "build", 10548 );
	set( "owner", "kid" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room768",
		"down"      : "/open/clan/ou-cloud-club/room/room585.c",
		"west"      : "/open/clan/ou-cloud-club/room/room755",
		"north"     : "/open/clan/ou-cloud-club/room/room767.c",
	]) );
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
