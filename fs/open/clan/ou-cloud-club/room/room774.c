inherit ROOM;
void create() {
	set( "short", "$HIY$九轉雄蛇丸$NOR$" );
	set( "object", ([
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount5"  : 800,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/open/mogi/castle/obj/sspill",
		"amount3"  : 800,
		"amount6"  : 800,
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"amount9"  : 800,
		"amount2"  : 800,
		"file6"    : "/open/mogi/castle/obj/sspill",
		"file8"    : "/open/mogi/castle/obj/sspill",
		"file1"    : "/open/mogi/castle/obj/sspill",
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"amount10" : 800,
		"amount7"  : 800,
		"amount8"  : 800,
		"amount1"  : 800,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"file9"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 800,
	]) );
	set( "owner", "enter" );
	set( "light_up", 1 );
	set( "build", 10555 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room775",
		"north"     : "/open/clan/ou-cloud-club/room/room601.c",
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
