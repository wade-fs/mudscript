inherit ROOM;
void create() {
	set( "short", "東長郎" );
	set( "object", ([
		"amount2"  : 1,
		"amount1"  : 1,
		"file1"    : "/obj/gift/shenliwan",
		"file2"    : "/open/sky/obj/lucky_grasslink",
	]) );
	set( "owner", "roarii" );
	set( "build", 2708 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room573",
		"west"      : "/open/clan/13_luck/room/room575",
	]) );
	set( "long", @LONG
這裡是東長廊的轉角，往北方走去可到招待遠客住宿的客房，
東練武場以及後花園。如果你感覺勞累可以先去招待遠客住宿的客
房休息一下，或是去瞧瞧後花園的美景，或是去練武場活動筋骨。
這裡是東長廊的轉角，往北方走去可到招待遠客住宿的客房，
東練武場以及後花園。如果你感覺勞累可以先去招待遠客住宿的客
房休息一下，或是去瞧瞧後花園的美景，或是去練武場活動筋骨。
LONG);
	setup();
	replace_program(ROOM);
}
