inherit ROOM;
void create() {
	set( "short", "白虎堂口" );
	set( "owner", "mad" );
	set( "object", ([
		"amount10" : 1,
		"amount1"  : 1,
		"amount3"  : 1293,
		"amount9"  : 907,
		"file5"    : "/open/killer/headkill/obj/i_dag",
		"file3"    : "/open/doctor/pill/sky_pill",
		"file4"    : "/open/doctor/pill/gnd_pill",
		"file6"    : "/open/killer/obj/dagger",
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"file2"    : "/open/doctor/pill/human_pill",
		"amount6"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"amount7"  : 1,
		"amount2"  : 1463,
		"file9"    : "/open/doctor/pill/ice_pill",
		"amount8"  : 1,
		"amount4"  : 1525,
		"file10"   : "/open/killer/headkill/obj/w_dag",
		"file8"    : "/open/killer/headkill/obj/e_dag",
	]) );
	set( "build", 10248 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room13.c",
		"enter"     : "/open/clan/13_luck/room/room17",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    走到了都是喧嘩聲的地方，看看四周擠滿了人，往上看到白虎堂三
個大字，你問了一下周圍的人，原來他們都是來申請當十三吉祥士兵的
，有的是這裡的老百姓有的是遠從他地來到這裡的，看著每個人都說著
十三吉祥的過去種種事蹟，可見十三吉祥是聲名遠播的。

LONG);
	setup();
	replace_program(ROOM);
}
