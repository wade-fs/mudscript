inherit ROOM;
void create() {
	set( "short", "美雪的惡夢" );
	set( "owner", "snowy" );
	set( "object", ([
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file3"    : "/obj/stone/suipian",
		"amount8"  : 1,
		"amount2"  : 987,
		"file6"    : "/open/ghost-hole/obj/light-spirit",
		"amount3"  : 111,
		"amount7"  : 1,
		"file7"    : "/open/capital/obj/4-3",
		"file4"    : "/open/ghost-hole/obj/dark-spirit",
		"file5"    : "/open/ghost-hole/obj/water-spirit",
		"amount1"  : 15,
		"file8"    : "/open/ghost-hole/obj/water-spirit",
		"file2"    : "/obj/stone/powder",
		"amount4"  : 1,
		"file1"    : "/obj/stone/jiao",
		"amount9"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/ghost-hole/obj/water-spirit",
		"amount10" : 1,
	]) );
	set( "build", 10029 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room769",
		"down"      : "/open/clan/ou-cloud-club/room/room740.c",
	]) );
	set( "long", @LONG
永無止境的詭異紫黑色籠罩著你的四周，你不確定這個地方到底有沒有
出口，呼號的風聲從甬道深處湧出，吹過你的身體時帶起一陣寒意，一些似
有似無的黯黑精靈體不時在身旁圍繞冷笑，整個甬道形成一個風洞，此處剛
好是風洞中間空間較大的地方，因此氣流迴旋的相當厲害。你看到旁邊斜斜
的倒著破碎的石碑，上面有些字樣似乎還可以辨認。
LONG);
	setup();
	replace_program(ROOM);
}
