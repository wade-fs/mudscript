inherit ROOM;
void create() {
	set( "short", "波--裝備室(2)" );
	set( "owner", "perth" );
	set( "object", ([
		"amount6"  : 1,
		"amount1"  : 90000,
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"file1"    : "/open/killer/obj/bellstar",
		"amount10" : 1,
		"file5"    : "/open/killer/obj/bellstar",
		"file2"    : "/open/killer/headkill/obj/f_dag",
		"file7"    : "/open/ghost-hole/obj/light-spirit",
		"amount7"  : 1,
		"amount2"  : 1,
		"file4"    : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"file9"    : "/obj/gift/unknowdan",
		"file3"    : "/open/mogi/castle/obj/blood-water",
		"amount8"  : 1,
		"file8"    : "/open/poison/obj/armband1",
		"amount9"  : 1,
		"amount3"  : 8,
		"file6"    : "/obj/gift/xiandan",
		"amount5"  : 8578,
	]) );
	set( "build", 10418 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room137.c",
		"west"      : "/open/clan/ou-cloud-club/room/room326",
		"east"      : "/open/clan/ou-cloud-club/room/room386",
		"north"     : "/open/clan/ou-cloud-club/room/room317.c",
	]) );
	set( "long", @LONG
波波收集到的裝備集中處，都是各地收集回來的寶物都是些未
曾見過的暗器、匕首、防具，有些還刻有名字，大概又是殺人搶回
來的吧對波的恐懼又加深了幾分，手裡拿著的劍，不自覺抖了起來
還是趕快離開這間房間吧，不然波回來可能又有危險了

裝備裝備裝備裝備裝備裝備裝備裝備裝備裝備裝備裝備裝備裝備裝

殺殺殺殺殺殺殺殺殺殺殺殺殺殺殺殺殺殺殺殺殺殺殺殺殺殺殺殺殺

LONG);
	setup();
	replace_program(ROOM);
}
