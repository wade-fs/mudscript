inherit ROOM;
void create() {
	set( "short", "童話森林" );
	set( "owner", "panhermes" );
	set( "object", ([
		"file2"    : "/open/mogi/dragon/obj/dragon-head",
		"file4"    : "/open/mogi/castle/obj/seven3-dark-head",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount5"  : 118,
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount1"  : 81,
		"file3"    : "/open/mon/obj/thousand-nectar",
		"amount3"  : 97,
	]) );
	set( "build", 11081 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room394",
	]) );
	set( "long", @LONG
你正處在一片一望無際的森林裡，放眼看去只見一片綠蔭，濃密的樹枝遮蓋了火
熱的太陽。你忽然聽到前方的草叢傳來蟋蟀的鳴叫聲，偶而你也可以聽到吱吱喳
喳的鳥叫聲，在寧靜的森林中顯得格外嘹亮。往北有一道高高的城墻阻擋著你的
去路，東邊便是白雪大道。
LONG);
	setup();
	replace_program(ROOM);
}
