inherit ROOM;
void create() {
	set( "short", "armband" );
	set( "owner", "hild" );
	set( "object", ([
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount2"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount9"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount10" : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-armband",
	]) );
	set( "build", 10140 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room49",
		"west"      : "/open/clan/sky-wu-chi/room/room316.c",
	]) );
	set( "long", @LONG

     ▲=================================================================▲
     ▊▏                                                   ▉          ▊▏
     ▊▏ ▉▉▉▉▉▉▉                        ▉▉   ▉▉▉▉▉▉     ▊▏
     ▊▏    ▉       ▉                                 ▉     ▉      ▊▏
     ▊▏    ▉       ▉    ▉▉▉▉▉▉▉▉    ▉▉  ▉▉▉▉▉▉▉    ▊▏
     ▊▏   ▉        ▉                          ▉    ▉  ▉  ▉      ▊▏
     ▊▏   ▉        ▉                         ▉     ▉  ▉  ▉      ▊▏
     ▊▏   ▉  ▉▉▉▉                        ▉     ▉   ▉  ▉▉    ▊▏
     ▊▏                                                               ▊▏
  ╰██╯===========================================================╰██╯
     ●                                                                 ●
     ●                                                                 ●



LONG);
	setup();
	replace_program(ROOM);
}
