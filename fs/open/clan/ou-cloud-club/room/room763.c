inherit ROOM;
void create() {
	set( "short", "kid's room" );
	set( "owner", "kid" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room585",
	]) );
	set( "long", @LONG
強而有力的戰鼓聲讓你的精神大振，想要活動一下筋骨讓體
內沸騰的氣血舒緩，十八路長拳施展完畢後，你滿意的擦了擦額
頭上的汗珠，突然眼前出現了一位高大的巨人，身穿白金戰甲，
手持斬鐵巨劍，正是戰神$GRN$『奧丁』$NOR$，拍拍你的肩膀為你加油打氣
之後轉身又走進光圈之中‧

LONG);
	setup();
	replace_program(ROOM);
}
