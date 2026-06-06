inherit ROOM;
void create() {
	set( "short", "吉祥水道" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file8"    : "/open/ghost-hole/obj/light-spirit",
		"file4"    : "/open/gblade/obj/sa-head",
		"amount9"  : 1,
		"amount8"  : 1,
		"file2"    : "/open/ghost-hole/obj/light-spirit",
		"amount4"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "build", 10956 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room27.c",
		"east"      : "/open/clan/13_luck/room/room3.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    過了秋陽流你真正的發現到四周真的是火紅世界，尤其是四周的楓
樹上都有隨風搖曳的紅葉子，只要風稍微大點就有水中火燄的錯覺，微
風夾帶著秋天的氣氛，緩緩的吹來使你精神氣爽，讓你覺得這趟水之旅
擁有無數的回憶，有不虛此行的感覺。

LONG);
	setup();
	replace_program(ROOM);
}
