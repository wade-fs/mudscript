inherit ROOM;
void create() {
	set( "short", "ω冥魔寶盒ω" );
	set( "object", ([
		"amount5"  : 1,
		"file7"    : "/open/gsword/obj1/blosword",
		"file5"    : "/obj/gift/xiandan",
		"file10"   : "/open/gsword/obj1/blosword",
		"file1"    : "/obj/gift/xiandan",
		"amount6"  : 1,
		"amount8"  : 1,
		"file4"    : "/obj/gift/unknowdan",
		"file8"    : "/open/gsword/obj1/blosword",
		"amount1"  : 1,
		"file6"    : "/open/gsword/obj1/blosword",
		"file2"    : "/obj/gift/xiandan",
		"amount7"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"amount2"  : 1,
	]) );
	set( "owner", "enter" );
	set( "light_up", 1 );
	set( "build", 11379 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room333",
		"west"      : "/open/clan/ou-cloud-club/room/room146.c",
		"flyindance" : "/open/clan/ou-cloud-club/room/room196",
	]) );
	set( "long", @LONG
    ω冥魔腰帶ω
        ω冥魔邪盾ω
        ω冥魔指戒ω
        ω冥魔足環ω
        ω冥魔脛甲ω
        ω冥魔帝冠ω
        ω冥魔指套ω
        ω冥魔寶墜ω
        ω冥魔甲冑ω
        ω冥魔羽靴ω
        ω冥魔肩甲ω
        ω冥魔披風ω

LONG);
	setup();
	replace_program(ROOM);
}
