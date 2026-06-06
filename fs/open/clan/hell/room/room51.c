inherit ROOM;
void create() {
	set( "short", "$RED$unplugged in new york$NOR$" );
	set( "object", ([
		"file1"    : "/open/tendo/obj/chaosbelt",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount4"  : 1,
		"file2"    : "/open/wind-rain/obj/sun_red_cloth",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount8"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file3"    : "/daemon/class/blademan/obj/shield",
		"amount6"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount3"  : 1,
		"file4"    : "/open/tendo/obj/lucloth",
	]) );
	set( "owner", "blur" );
	set( "build", 10565 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room63",
		"north"     : "/open/clan/hell/room/room46.c",
	]) );
	set( "long", @LONG
大四時....kalin已經在接觸blue跟jazz了...
但沒專心去研究..
在東引煩悶的日子裡....
kalin最愛在他的行政室放著billie holiday的CD...
他也沉迷在bill evans神乎其技的指法裡...
此時對kalin來說...music不在是情感的抒發..
也不再是叛逆的宣洩...
而是一個放鬆心靈的慰藉...

輕輕鬆鬆的音樂......殊舒服服的海風...
LONG);
	setup();
	replace_program(ROOM);
}
