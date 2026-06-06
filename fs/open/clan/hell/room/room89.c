inherit ROOM;
void create() {
	set( "short", "$HIC$聚靈武器封印區$HIY$(claw)$NOR$" );
	set( "owner", "blur" );
	set( "object", ([
		"amount6"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
		"file3"    : "/open/magic-manor/obj/evil-kill-claw",
		"file6"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
		"amount7"  : 1,
		"amount10" : 1,
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/obj/evil-kill-claw",
		"amount9"  : 1,
		"file5"    : "/open/magic-manor/obj/evil-kill-claw",
		"file4"    : "/open/magic-manor/obj/evil-kill-claw",
		"file7"    : "/open/magic-manor/obj/evil-kill-claw",
	]) );
	set( "light_up", 1 );
	set( "build", 11592 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room28",
	]) );
	set( "long", @LONG

(^^ ....轉承YYY)
先來討論一下藍龍好了...
ㄜ...反正就是不錯的pill..可以增加en force等級...
各位大哥哥大姐姐如果蹲完廁所的話...如果服用一顆藍龍精元..
你會有飄飄然的感覺...效果不錯.. hoho

吞雲吐霧心得PART2 
(百樂門)<--好玩的濾嘴...可以邊哈草邊玩搓搓樂..
(MORE)<--被禁止發售的美國菸...原因是至癌物過多..
(七星)<--學生群最愛...不錯的日本菸..還可玩對獎遊戲(A ~ E)
(Peace)<--香噴噴的日本菸...品質不錯...但有點難吸..

                        (^^ ...下文請閱PPP)

LONG);
	setup();
	replace_program(ROOM);
}
