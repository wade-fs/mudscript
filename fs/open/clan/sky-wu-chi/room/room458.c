inherit ROOM;
void create() {
	set( "short", "$CYN$ξ漩渦的南方ξ$NOR$" );
	set( "owner", "coling" );
	set( "object", ([
		"file6"    : "/open/mogi/castle/obj/seven7-dark-head",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/mogi/castle/obj/seven6-dark-head",
		"file1"    : "/open/mogi/castle/obj/seven1-dark-head",
		"amount5"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/mogi/castle/obj/seven3-dark-head",
		"file2"    : "/open/ghost-hole/obj/death-butterfly",
		"amount9"  : 1,
		"file4"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file3"    : "/open/mogi/castle/obj/seven2-dark-head",
		"amount2"  : 1,
		"file10"   : "/open/mogi/castle/obj/seven6-dark-head",
		"amount3"  : 1,
		"amount10" : 1,
		"file8"    : "/open/magic-manor/obj/magic-sign",
		"file9"    : "/open/mogi/castle/obj/seven5-dark-head",
		"amount7"  : 1,
	]) );
	set( "build", 11064 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room454",
	]) );
	set( "long", @LONG
超巨大的漩渦！！把你捲向你要的反方向;看著$HIY$北方$NOR$正如你想要的方向
 這個時候你就只能的奮戰不懈的往你要的方向前進但覺得身上的體力一點
 一點的流失,心想這時候誰能給我一罐蠻牛就好了！！！！！！！！！！！

$HIM$ 碰～～～的一聲！！正如你想的的蠻牛掉在你面前$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
