inherit ROOM;
void create() {
	set( "short", "$CYN$ξ漩渦的西方ξ$NOR$" );
	set( "owner", "coling" );
	set( "object", ([
		"amount7"  : 1,
		"file2"    : "/open/gsword/obj1/kring",
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"file10"   : "/open/scholar/room/newplan/obj/s-shield",
		"amount10" : 1,
		"amount5"  : 1,
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"amount8"  : 1,
		"file1"    : "/open/killer/obj/atman_pill",
		"file8"    : "/open/gsword/obj1/karmor",
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/obj/magic-sign",
		"amount3"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/obj/magic-sign",
		"file3"    : "/open/magic-manor/obj/magic-sign",
		"amount1"  : 1367,
	]) );
	set( "build", 12341 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room454",
	]) );
	set( "long", @LONG
超巨大的漩渦！！把你捲向你要的反方向;看著$HIY$東方$NOR$正如你想要的方向
 這個時候你就只能的奮戰不懈的往你要的方向前進但覺得身上的體力一點
 一點的流失,心想這時候誰能給我一罐蠻牛就好了！！！！！！！！！！！

$HIM$ 碰～～～的一聲！！正如你想的的蠻牛掉在你面前$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
