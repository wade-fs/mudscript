inherit ROOM;
void create() {
	set( "short", "ξ天籟庭園ξ" );
	set( "owner", "oboe" );
	set( "object", ([
		"amount4"  : 15,
		"file7"    : "/obj/gift/unknowdan",
		"file1"    : "/obj/gift/xiandan",
		"amount3"  : 7,
		"file2"    : "/open/fire-hole/obj/p-pill",
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"amount1"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/fire-hole/obj/b-pill",
		"amount9"  : 1,
		"file4"    : "/open/fire-hole/obj/r-pill",
		"file10"   : "/open/magic-manor/obj/master_snake_head",
		"amount10" : 1,
		"file5"    : "/open/killer/obj/k_ring",
		"amount7"  : 1,
		"file6"    : "/open/fire-hole/obj/g-pill",
		"file9"    : "/open/fire-hole/obj/y-pill",
		"amount2"  : 14,
		"amount6"  : 10,
		"amount8"  : 1,
	]) );
	set( "build", 11395 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room453",
	]) );
	set( "long", @LONG
往北走出天音小築，你來到一個精緻的小庭園，庭園中的花草以一種自
然中隱含天道運行的規律生長著，你感到這裡的一切是那麼的寧靜而協調，
潺潺的小溪的流水聲，枝頭上小鳥清脆悅耳的叫聲，陣陣微風輕輕吹拂，地
上各式顏色不同卻散發著驚人能量的水晶，不僅提供了這些花草成長的能量
，更以一種自然到令你幾乎無法察覺的形式緩緩的加強你身上的能量，你感
覺你的身心似乎在這裡與大自然完全結合為一了。

LONG);
	setup();
	replace_program(ROOM);
}
