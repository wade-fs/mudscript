inherit ROOM;
void create() {
	set( "short", "朵麗雅的秘密森林" );
	set( "owner", "snowy" );
	set( "object", ([
		"amount9"  : 1,
		"file7"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"amount5"  : 1,
		"amount10" : 1,
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/open/killer/obj/fire-knife",
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"file3"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount6"  : 1,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount2"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10020 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room83",
	]) );
	set( "long", @LONG
小道旁的樹木高聳參天，幾乎要將天空給掩蓋了。雖然在陰暗的樹蔭底
下行走，卻感不到一絲絲的寒冷或不安。或許是這森林有著特殊的魔法力量
吧，亦或許是處於這神聖之地—天界所致吧。可能是心情愉快的關係，連樹
上不知名的鳥兒的啼叫聲也變得如吟唱詩歌般，令人有身心舒暢之感。你注
意到這邊竟然如此幽靜，神秘感也隨之倍添。
LONG);
	setup();
	replace_program(ROOM);
}
