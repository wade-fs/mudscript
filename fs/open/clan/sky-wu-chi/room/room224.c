inherit ROOM;
void create() {
	set( "short", "$HIW$貓王座$NOR$" );
	set( "owner", "timekiller" );
	set( "light_up", 1 );
	set( "object", ([
		"amount3"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/mogi/castle/obj/lochagem",
		"file3"    : "/open/wind-rain/obj/sun_red_cloth",
		"file2"    : "/obj/gift/shenliwan",
		"file6"    : "/open/wu/obj/figring",
		"amount10" : 1,
		"amount5"  : 1,
		"file10"   : "/open/killer/headkill/obj/bluekill",
		"file5"    : "/obj/gift/unknowdan",
		"amount8"  : 1,
		"file7"    : "/open/mogi/castle/obj/leave",
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount2"  : 1,
	]) );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room242",
	]) );
	set( "build", 11295 );
	set( "long", @LONG
哈哈！！你來到這裡只是狂笑........
笑死倫！！.....就憑$HIC$霹靂貓$NOR$這小伙子，
也想在這天道無極幫裡，偷蓋個小王座....
奇怪的是，正想扁他時竟看不到霹靂貓本人，
切，原來他躲在王座後面睡覺，真$RED$豬$NOR$!!
嘿嘿，趕快 $HIW$ＳＭ$NOR$ 他吧!!  

LONG);
	setup();
	replace_program(ROOM);
}
