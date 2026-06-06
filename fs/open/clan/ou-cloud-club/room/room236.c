inherit ROOM;
void create() {
	set( "short", "$HIG$戰神道$NOR$" );
	set( "object", ([
		"amount10" : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount7"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount6"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"amount8"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount9"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "light_up", 1 );
	set( "build", 10020 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room240",
		"east"      : "/open/clan/ou-cloud-club/room/room733",
		"south"     : "/open/clan/ou-cloud-club/room/room217.c",
		"north"     : "/open/clan/ou-cloud-club/room/room480",
	]) );
	set( "long", @LONG
強而有力的戰鼓聲讓你的精神大振，想要活動一下筋骨讓體
內沸騰的氣血舒緩，十八路長拳施展完畢後，你滿意的擦了擦額
頭上的汗珠，突然眼前出現了一位高大的巨人，身穿白金戰甲，
手持斬鐵巨劍，正是戰神$HIC$『奧丁』$NOR$，拍拍你的肩膀為你加油打氣
之後轉身又走進光圈之中‧

左邊現在是穎穎(sakira)的隱身小屋。

LONG);
	setup();
	replace_program(ROOM);
}
