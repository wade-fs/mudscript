inherit ROOM;
void create() {
	set( "short", "練氣室" );
	set( "object", ([
		"amount9"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/wind-rain/obj/sun_red_cloth",
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"amount6"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/mogi/castle/obj/lochagem",
		"file9"    : "/daemon/class/blademan/obj/shield",
		"amount3"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/wu/npc/obj/armband",
		"file6"    : "/open/tendo/obj/chaosbelt",
		"file2"    : "/daemon/class/fighter/figring",
	]) );
	set( "build", 10044 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room267",
	]) );
	set( "long", @LONG

    這裡是修練氣功的地方，非常的幽雅安靜，完全杜絕了外界干擾
擾，修練內功最忌就是受到干擾而走火入魔，四周陳設著各式的水晶
，聽說對於人體氣流有絕對的幫助，還有排列著一些的輔助防具，著
裝後來修練更是事半功倍的效果。


LONG);
	setup();
	replace_program(ROOM);
}
