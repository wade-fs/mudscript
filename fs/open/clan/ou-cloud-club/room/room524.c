inherit ROOM;
void create() {
	set( "short", "夢幻空間" );
	set( "owner", "ctx" );
	set( "object", ([
		"amount8"  : 1,
		"file1"    : "/obj/gift/unknowdan",
		"file6"    : "/obj/gift/unknowdan",
		"file4"    : "/obj/gift/unknowdan",
		"amount1"  : 1,
		"file5"    : "/obj/gift/unknowdan",
		"amount2"  : 1,
		"file10"   : "/obj/gift/unknowdan",
		"amount5"  : 1,
		"amount6"  : 1,
		"file3"    : "/obj/gift/unknowdan",
		"file7"    : "/obj/gift/unknowdan",
		"amount3"  : 1,
		"amount9"  : 1,
		"file2"    : "/obj/gift/unknowdan",
		"file9"    : "/obj/gift/unknowdan",
		"amount10" : 1,
		"amount4"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10020 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room517",
	]) );
	set( "long", @LONG
偶然一次陰差陽錯,少年黃海華來到了繽紛奇麗的魔法世界
，他的無厘頭與天生王者風範,兩種極端卻又神奇混合一起的姿
態，讓神族與魔族的女神首領紛紛為他傾倒,也讓世間廣大民眾
仰賴他的救助,然而他卻也無意中成為邪惡勢力的目標。就在一
步步的磨練與冒險中，黃海華找到了他來到這個世界的使命,漸
漸成長起來，展開了通往王者寶座的道路.....

LONG);
	setup();
	replace_program(ROOM);
}
