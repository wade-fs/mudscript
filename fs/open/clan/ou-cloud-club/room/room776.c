inherit ROOM;
void create() {
	set( "short", "$HIY$九轉雄蛇丸$NOR$" );
	set( "object", ([
		"amount6"  : 800,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount4"  : 800,
		"file6"    : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 800,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount3"  : 800,
		"file5"    : "/open/mogi/castle/obj/sspill",
		"file1"    : "/open/mogi/castle/obj/sspill",
		"amount1"  : 800,
		"amount5"  : 800,
	]) );
	set( "owner", "enter" );
	set( "light_up", 1 );
	set( "build", 10032 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room775",
		"west"      : "/open/clan/ou-cloud-club/room/room777",
	]) );
	set( "long", @LONG

逍遙派聖藥，具有神奇無比的療效，幾可起死回生。
與$HIR$生生照化丹$NOR$有異曲同工之妙。

只見此房間襬放著滿滿的$HIY$九轉雄蛇丸$NOR$，讓你嘆為觀止。
逍遙派聖藥，具有神奇無比的療效，幾可起死回生。
逍遙派聖藥，具有神奇無比的療效，幾可起死回生。


LONG);
	setup();
	replace_program(ROOM);
}
