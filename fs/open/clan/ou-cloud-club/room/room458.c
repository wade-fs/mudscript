inherit ROOM;
void create() {
	set( "short", "魔劍丹藥室1" );
	set( "owner", "mekyn" );
	set( "object", ([
		"amount5"  : 1,
		"amount7"  : 4,
		"amount10" : 1,
		"file5"    : "/open/gsword/obj1/bpball",
		"file10"   : "/obj/gift/xisuidan",
		"file2"    : "/obj/gift/shenliwan",
		"file7"    : "/obj/stone/powder",
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file4"    : "/open/gsword/obj1/bbladeball",
		"file9"    : "/obj/gift/unknowdan",
		"file8"    : "/obj/gift/hobowdan",
		"file3"    : "/obj/stone/jiao",
		"amount8"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file6"    : "/obj/stone/suipian",
		"amount4"  : 1,
		"amount6"  : 4,
		"amount2"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 10025 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room457",
		"east"      : "/open/clan/ou-cloud-club/room/room464",
	]) );
	set( "long", @LONG


    ∩︵∩    ∩︵∩    ∩︵∩    ∩︵∩    ∩︵∩    ∩︵∩    ∩︵∩
   （◎◎）  （○●）  （⊙⊙）  （☆★）  （◎★）  （⊕⊕）  （!  !）
     〉〈  │  〉〈  │  〉〈  │  〉〈  │  〉〈  │  〉〈  │  〉〈 
    ⊿ ˍ）╯ ⊿ ˍ）╯ ⊿ ˍ）╯ ⊿ ˍ）╯ ⊿ ˍ）╯ ⊿ ˍ）╯ ⊿ ˍ）


LONG);
	setup();
	replace_program(ROOM);
}
