inherit ROOM;
void create() {
	set( "short", "虛空世界－九空劍聖界" );
	set( "owner", "cdrom" );
	set( "object", ([
		"amount2"  : 1,
		"file8"    : "/open/mogi/dragon/obj/dragon-head",
		"file3"    : "/obj/example/besttea",
		"amount4"  : 1,
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"amount5"  : 1,
		"file7"    : "/open/main/obj/m_cloak",
		"file5"    : "/open/ghost-hole/obj/fire-spirit",
		"file6"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file10"   : "/open/capital/obj/4-1",
		"amount7"  : 1,
		"amount6"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"file9"    : "/open/killer/obj/fire-knife",
		"file1"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount10" : 1,
		"file4"    : "/open/capital/obj/4-4",
	]) );
	set( "light_up", 1 );
	set( "build", 10161 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room296",
	]) );
	set( "long", @LONG
你眼前漸漸出現一個身影，手中的靈劍連陽似乎感應道什麼似的，發出炫麗的光芒照
亮四周身邊亦出現許多過往的影像，定睛一看似乎是百多年前仙魔大戰的景象，瞬間，七
道光芒劃過你眼前，你震了一下，難不成這就是傳說中的-仙劍連陽-
LONG);
	setup();
	replace_program(ROOM);
}
