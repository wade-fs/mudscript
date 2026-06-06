inherit ROOM;
void create() {
	set( "short", "$HIY$九轉雄蛇丸$NOR$" );
	set( "object", ([
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"amount1"  : 1,
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"amount2"  : 1,
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"file4"    : "/open/sky/obj/lucky_grasslink",
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/sky/obj/lucky_grasslink",
	]) );
	set( "owner", "enter" );
	set( "build", 10454 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room783.c",
		"west"      : "/open/clan/ou-cloud-club/room/room785",
	]) );
	set( "long", @LONG
從你踏入此室時，一股淡淡清香撲鼻而來，只見地上
堆積著一堆堆的藥草，都是江湖上夢寐以求的藥草，而牆
邊壁櫥內更是放滿著各式各樣的藥丹，每一樣都是稀有難
求的，而此處竟堆積著如此多的丹藥，若非親眼看見還真
無法相信，可見傲雲山莊裡擁有太多的高手存在了。

逍遙派聖藥，具有神奇無比的療效，幾可起死回生。
與$HIR$生生照化丹$NOR$有異曲同工之妙。

LONG);
	setup();
	replace_program(ROOM);
}
