inherit ROOM;
void create() {
	set( "short", "gk'eq-armor" );
	set( "owner", "cong" );
	set( "object", ([
		"amount5"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/ghost-hole/obj/light-spirit",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount1"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armor",
	]) );
	set( "light_up", 1 );
	set( "build", 10059 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room217",
	]) );
	set( "long", @LONG

問世間。情是何物。直教生死相許。
天南地北雙飛客。老翅幾回寒暑。
歡樂趣。離別苦。就中更有痴兒女。
君應有語。渺萬里層雲。
千山暮雪。只影向誰去

橫汾路。寂寞當年蕭鼓。
荒煙依舊平楚。
招魂楚些何嗟及。
山鬼暗啼風雨。
天也妒。未信與。
鶯兒燕子俱黃土。
千愁萬古。為留待騷人。
狂歌痛飲。來訪雁丘處

LONG);
	setup();
	replace_program(ROOM);
}
