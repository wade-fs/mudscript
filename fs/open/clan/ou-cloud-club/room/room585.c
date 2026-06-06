inherit ROOM;
void create() {
	set( "short", "$HIY$寶貝中心$NOR$" );
	set( "object", ([
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"file7"    : "/obj/gift/shenliwan",
		"amount1"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file3"    : "/obj/gift/xisuidan",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-ring",
		"file6"    : "/open/ghost-hole/obj/light-spirit",
		"file5"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"file4"    : "/open/capital/obj/4-3",
		"file1"    : "/obj/gift/shenliwan",
		"amount9"  : 1,
	]) );
	set( "build", 10098 );
	set( "light_up", 1 );
	set( "owner", "kid" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room764",
		"up"        : "/open/clan/ou-cloud-club/room/room754",
		"west"      : "/open/clan/ou-cloud-club/room/room428.c",
		"north"     : "/open/clan/ou-cloud-club/room/room763.c",
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
