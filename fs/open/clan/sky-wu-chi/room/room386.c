inherit ROOM;
void create() {
	set( "short", "童話森林深處" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount10" : 1,
		"amount2"  : 15,
		"file3"    : "/open/gblade/obj/sa-head",
		"amount7"  : 1,
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"file10"   : "/open/gblade/obj/sa-head",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file8"    : "/open/gblade/obj/sa-head",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount1"  : 24,
		"file1"    : "/open/mon/obj/thousand-nectar",
		"amount9"  : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/gblade/obj/sa-head",
	]) );
	set( "light_up", 1 );
	set( "build", 10090 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room391.c",
	]) );
	set( "long", @LONG
你正處在一片一望無際的森林裡，放眼看去只見一片綠蔭，濃密的樹枝遮蓋了火
熱的太陽。你忽然聽到前方的草叢傳來蟋蟀的鳴叫聲，偶而你也可以聽到吱吱喳
喳的鳥叫聲，在寧靜的森林中顯得格外嘹亮。往北可以到達白雪大道。
一隻背著七色龜殼的小烏龜/pubertys/正縮頭縮腦的看著你。
一隻雪白的鶴/white crane/正站在這裡觀察四周。
LONG);
	setup();
	replace_program(ROOM);
}
