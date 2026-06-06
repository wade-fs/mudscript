inherit ROOM;
void create() {
	set( "short", "『正氣堂』" );
	set( "owner", "mill" );
	set( "object", ([
		"amount9"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount10" : 1,
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "build", 10312 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room467",
		"south"     : "/open/clan/13_luck/room/room469",
	]) );
	set( "long", @LONG
  
     這裡是華山派的的正氣堂﹐是華山派掌門會見賓客之所﹐大門上掛
 了一個匾額(wood)﹐看來有些老舊﹐但識貨者一看便知是上等紫檀木所
 做﹐後面還有一個屏風﹐屏風後便是玄關了。
 華山劍派第七代掌門人『笑傲江湖』令狐沖(Master hu)

                         天  地  浩  然  正  氣

LONG);
	setup();
	replace_program(ROOM);
}
