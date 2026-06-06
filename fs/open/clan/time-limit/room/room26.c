inherit ROOM;
void create() {
	set( "short", "$HIC$倫敦$HIY$車站$NOR$" );
	set( "owner", "firefan" );
	set( "object", ([
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"amount10" : 1,
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "build", 10136 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room53",
		"down"      : "/open/clan/time-limit/room/room27",
	]) );
	set( "long", @LONG
映入眼廉的是一棟雄偉的建築,這正是全英國最重要的交通中心'倫敦車站',
站牌上還掛著古老的大時鐘,車站內人來人往,有的人趕火車,有的人邊走邊吃,
眼睛還盯著時刻表,你一路走向第九月台,目標是九又四分之三月台,
但是在人潮眾多的月台要進入隱藏的通道而不被人發現還真是不容易,
尤其你鬼鬼祟祟的行徑已經引起幾位警察的注意了

LONG);
	setup();
	replace_program(ROOM);
}
