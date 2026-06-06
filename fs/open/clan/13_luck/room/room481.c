inherit ROOM;
void create() {
	set( "short", "郊外樹林" );
	set( "object", ([
		"amount8"  : 1,
		"file10"   : "/open/magic-manor/obj/lunar-heart",
		"file9"    : "/open/magic-manor/obj/lunar-heart",
		"amount1"  : 1,
		"file1"    : "/obj/gift/xisuidan",
		"amount6"  : 639,
		"file6"    : "/open/ping/obj/poison_pill",
		"amount10" : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "owner", "zmud" );
	set( "build", 10001 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room476",
		"east"      : "/open/clan/13_luck/room/room482",
	]) );
	set( "long", @LONG

　　這裡原來是一片相當安詳的樹林區，後來不知為啥原因，整座叢林
時常看到野山豬整群整群的遷移，由於野豬非常的怕人，所以幾乎很少
走出樹林。但是，因為常有一些不法的獵戶不聽勸解，私自入林宰殺野
山豬，藉此獲的龐大的暴利，使得山豬們對人類產生敵意，爾後見人就
咬，見人即戳的習性，故你走在這裡要特別格外的小心才行。

LONG);
	setup();
	replace_program(ROOM);
}
