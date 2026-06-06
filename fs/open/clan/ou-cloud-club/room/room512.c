inherit ROOM;
void create() {
	set( "short", "風姿物語" );
	set( "owner", "ctx" );
	set( "light_up", 1 );
	set( "object", ([
		"file8"    : "/obj/gift/hobowdan",
		"amount3"  : 1,
		"amount2"  : 1,
		"file6"    : "/obj/gift/hobowdan",
		"amount5"  : 1,
		"file10"   : "/obj/gift/hobowdan",
		"amount4"  : 1,
		"amount10" : 1,
		"file5"    : "/obj/gift/hobowdan",
		"file1"    : "/obj/gift/hobowdan",
		"amount8"  : 1,
		"file2"    : "/obj/gift/hobowdan",
		"file7"    : "/obj/gift/hobowdan",
		"file9"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"file3"    : "/obj/gift/hobowdan",
		"file4"    : "/obj/gift/hobowdan",
	]) );
	set( "build", 10149 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room511",
	]) );
	set( "long", @LONG
暴風的前兆，即將撼動整個風之大陸！場內幕重重的婚禮，
引來各方人士覬覦, 令暹羅城成為七大宗門明爭暗鬥的角力場。
胸懷大志的蘭斯洛、劍術卓絕的花次郎、神秘多智的鴻五郎和混
水摸魚的天地有雪，乘著這股暗流，或有意，或無心，在因緣際
下齊聚暹羅，共同掀起衝擊風之大陸的滔天巨浪。被後世史家冠
上「我意王」尊稱的男子，蘭斯洛，在風之大陸史上留下無數豐
功偉業，他的王座在鮮血與火焰中閃爍生光。異世界奇幻冒險鉅
作，蘭斯洛王傳奇故事，正式從這裡展開！

LONG);
	setup();
	replace_program(ROOM);
}
