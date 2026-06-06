inherit ROOM;
void create() {
	set( "short", "$HIM$≡冥魔邪盾Ⅱ≡$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount2"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 11872 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room367",
	]) );
	set( "long", @LONG
    邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾
冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾
冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾
冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾
冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾
冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾
冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾冥魔邪盾

LONG);
	setup();
	replace_program(ROOM);
}
