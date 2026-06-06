inherit ROOM;
void create() {
	set( "short", "異世帝王行" );
	set( "light_up", 1 );
	set( "owner", "ctx" );
	set( "object", ([
		"amount10" : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file1"    : "/obj/gift/bingtang",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"file2"    : "/obj/gift/lingzhi",
		"file3"    : "/obj/gift/lingzhi",
		"file10"   : "/obj/gift/lingzhi",
		"amount1"  : 1,
		"file6"    : "/obj/gift/bingtang",
		"amount9"  : 1,
		"file9"    : "/obj/gift/lingzhi",
		"amount7"  : 1,
		"file8"    : "/obj/gift/bingtang",
		"file4"    : "/obj/gift/lingzhi",
		"file7"    : "/obj/gift/bingtang",
		"file5"    : "/obj/gift/lingzhi",
	]) );
	set( "build", 11203 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room511",
	]) );
	set( "long", @LONG
在無窮無盡的茫茫宇宙之中有著無數的星球, 無數的生命形
式，奧斯曼星球就是其中的一顆有著高級智慧生命體的美麗行星
在這星球上的天宇王國的王子奧斯曼‧昂斯拉沙克斯和神聖之日
帝國的繼承人薇拉莉絲公主的大婚典禮上，意外的遭受滅國之擊
僥倖逃出的王子和天宇王國國師的愛女依琳娜‧帕蘭, 意外的進
入空間魔法陣中來到古代的中國, 一場以復國為志的鍛鍊以及愛
情故事就此開始....

LONG);
	setup();
	replace_program(ROOM);
}
