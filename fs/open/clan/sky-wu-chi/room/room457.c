inherit ROOM;
void create() {
	set( "short", "$CYN$ξ漩渦的北方ξ$NOR$" );
	set( "owner", "coling" );
	set( "object", ([
		"file7"    : "/open/mogi/castle/obj/seven4-dark-head",
		"amount5"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/mogi/castle/obj/seven2-dark-head",
		"file10"   : "/open/mogi/castle/obj/seven2-dark-head",
		"file8"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount6"  : 1,
		"file2"    : "/open/mogi/dragon/obj/dragon-head",
		"amount1"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"file4"    : "/open/mogi/dragon/obj/dragon-head",
		"amount2"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/mogi/castle/obj/seven1-dark-head",
		"file1"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file3"    : "/open/mogi/castle/obj/seven3-dark-head",
		"file5"    : "/open/mogi/castle/obj/seven1-dark-head",
		"amount7"  : 1,
	]) );
	set( "build", 31044 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room454",
	]) );
	set( "long", @LONG
超巨大的漩渦！！把你捲向你要的反方向;看著$HIY$南方$NOR$正如你想要的方向
 這個時候你就只能的奮戰不懈的往你要的方向前進但覺得身上的體力一點
 一點的流失,心想這時候誰能給我一罐蠻牛就好了！！！！！！！！！！！

$HIM$ 碰～～～的一聲！！正如你想的的蠻牛掉在你面前$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
