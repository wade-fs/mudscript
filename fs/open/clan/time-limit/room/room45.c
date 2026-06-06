inherit ROOM;
void create() {
	set( "short", "夜行巷" );
	set( "object", ([
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-ring",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount2"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount6"  : 1,
		"amount10" : 1,
	]) );
	set( "owner", "car" );
	set( "build", 10057 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room47",
	]) );
	set( "long", @LONG
夜行巷和斜角巷好像是兩個完全不同的世界,夜行巷
裡冷冷清清,幾個穿著破爛斗蓬的巫師坐在路旁盯著你看,
小巷子裡也有眼睛看著你,好像隨時會衝出來搶劫一樣,
路旁的商店所陳列的物品,也多半讓人覺得不太對勁,
比如說伯金與巴金斯門口就放著一隻萎縮的人手
一顆血淋淋的眼珠,還是早點離開這裡吧!

LONG);
	setup();
	replace_program(ROOM);
}
