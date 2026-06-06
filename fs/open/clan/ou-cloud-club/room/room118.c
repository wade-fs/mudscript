inherit ROOM;
void create() {
	set( "short", "$HIC$傲$HIW$雲$HIY$閤$HIG$二樓$HIM$中庭$NOR$" );
	set( "item_desc", ([
		"dragon_axe" : @ITEM

正當你凝視這把戰斧的時候，三條龍紋化成無數的光點 ，
慢慢的在你的眼前凝聚成細小的文字 ...

東邊：遠古龍王巴哈姆特之龍王道
西邊：不死火鳥菲尼克斯之鳳凰路
南邊：冰雪帝王希瓦掌管之冰風谷
北邊：力量之神泰坦掌管之地震帶

ITEM,
	]) );
	set( "object", ([
		"amount1"  : 1,
		"file4"    : "/open/doctor/obj/feather",
		"amount7"  : 1,
		"file2"    : "/open/doctor/obj/feather",
		"amount8"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/doctor/obj/feather",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/doctor/obj/feather",
		"file9"    : "/open/doctor/obj/feather",
		"file6"    : "/open/doctor/obj/feather",
		"amount9"  : 1,
		"file3"    : "/open/doctor/obj/feather",
		"file1"    : "/open/doctor/obj/feather",
		"file5"    : "/open/doctor/obj/feather",
	]) );
	set( "build", 10959 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room448.c",
		"north"     : "/open/clan/ou-cloud-club/room/room122.c",
		"down"      : "/open/clan/ou-cloud-club/room/hall.c",
		"south"     : "/open/clan/ou-cloud-club/room/room14.c",
		"up"        : "/open/clan/ou-cloud-club/room/room203.c",
		"west"      : "/open/clan/ou-cloud-club/room/room442",
		"add"       : "/open/clan/ou-cloud-club/room/room356.c",
	]) );
	set( "long", @LONG
傲雲山莊的二樓，東西南北延伸過去都是寬大的走道，透露
著肅穆莊嚴的氣氛，令你不敢在此嘻鬧，因此正在休息的傲雲幫
眾們都能得到充分的休息，或許正是傲雲提供如此舒適的地方，
使得幫眾們練功事半功倍，也得以維持住幫派龍頭的地位。

在你正前方放著一把刻著三條龍形的冰龍戰斧(Dragon_axe)‧

LONG);
	setup();
	replace_program(ROOM);
}
