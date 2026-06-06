inherit ROOM;
void create() {
	set( "short", "三葉鼠的東房間" );
	set( "object", ([
		"amount6"  : 1,
		"amount10" : 1,
		"amount1"  : 5,
		"file3"    : "/open/gsword/obj/yuskirt",
		"file1"    : "/open/mon/obj/mon-pill",
		"file6"    : "/open/mon/obj/ghost-claw",
		"file10"   : "/open/dancer/obj/yuawaist",
		"amount3"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10163 );
	set( "owner", "nanahara" );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room643",
	]) );
	set( "long", @LONG
琴聲十六法》：「輕、松、脆、滑、高、潔、清、虛、幽、奇、古、淡、中、和、疾、徐。」「輕、松、脆、滑」講的是演奏時的形象之 美以及音樂旋律的流暢；「高、潔、清、虛、幽、奇、古、淡」講的是琴曲的風格、意境、韻味、氣質等概念。「中、和、疾、徐」則是 指高深的演奏技巧，另外甚至還提到了「按令入木，彈欲斷弦」的重彈指法
'.
LONG);
	setup();
	replace_program(ROOM);
}
