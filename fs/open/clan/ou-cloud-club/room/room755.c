inherit ROOM;
void create() {
	set( "short", "$HIY$寶貝中心$NOR$" );
	set( "object", ([
		"amount6"  : 20,
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file7"    : "/open/fire-hole/obj/r-pill",
		"file6"    : "/open/fire-hole/obj/w-pill",
		"amount7"  : 20,
		"file1"    : "/obj/stone/jiao",
		"file10"   : "/obj/stone/powder",
		"amount4"  : 18,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 2,
		"amount9"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/mon/obj/thousand-nectar",
		"amount10" : 1,
		"file3"    : "/obj/stone/suipian",
		"file4"    : "/obj/stone/powder",
		"amount2"  : 1,
		"amount3"  : 5,
		"amount5"  : 63,
	]) );
	set( "build", 10131 );
	set( "owner", "kid" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room766",
		"east"      : "/open/clan/ou-cloud-club/room/room754",
		"down"      : "/open/clan/ou-cloud-club/room/room428.c",
		"north"     : "/open/clan/ou-cloud-club/room/room765.c",
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
