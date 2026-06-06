inherit ROOM;
void create() {
	set( "short", "麗咪雅秘密花園" );
	set( "owner", "turtle" );
	set( "object", ([
		"amount8"  : 1,
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"amount4"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"amount9"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"amount5"  : 1,
		"amount10" : 1,
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "outdoors", "/open/clan/ou-cloud-club" );
	set( "light_up", 1 );
	set( "build", 10035 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room83",
	]) );
	set( "long", @LONG
燦爛的太陽在天空閃爍著，發出溫和的陽光照著你。道路上的黃土，在陽光的照
射下，呈現出金黃色，地面兩旁是翠綠的小草，小草上的水珠，被陽光一照，發出耀
眼的光芒。道路兩旁種植的是矮小的小樹，小樹長了許多的葉子，葉子也同樣的翠綠
無比。用力的吸一口氣，空氣中充滿著小草的草香，小樹的葉香，不只這樣，還有一
絲絲的水果香。
LONG);
	setup();
	replace_program(ROOM);
}
