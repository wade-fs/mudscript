inherit ROOM;
void create() {
	set( "short", "世間浮華樓" );
	set( "object", ([
		"file2"    : "/open/firedancer/npc/eq/r_shield",
		"file1"    : "/open/firedancer/npc/eq/r_leg",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/firedancer/npc/eq/r_neck",
		"amount1"  : 1,
		"file3"    : "/open/gsword/obj/yuskirt",
	]) );
	set( "build", 10779 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room242.c",
		"south"     : "/open/clan/13_luck/room/room244.c",
	]) );
	set( "long", @LONG

    此間為了以前的樂透殺手所建立的...
碼不在多，六個就贏。簽不用早，有誠則靈。斯是夢境，唯吾不醒。
牌支算得準，一次六顆星。頭彩一中後，北銀抱獎金。
可以買別墅，堆黃金。無鬧鐘之亂耳，無加班之勞形。
晚晚酒店拼，天天自然醒。           
            吾自云：有中才行！

LONG);
	setup();
	replace_program(ROOM);
}
