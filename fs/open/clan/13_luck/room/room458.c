inherit ROOM;
void create() {
	set( "short", "『石板路』" );
	set( "owner", "poll" );
	set( "object", ([
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/quests/snake/npc/obj/snake-key-1",
		"amount7"  : 1,
		"amount4"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
		"file3"    : "/open/quests/snake/npc/obj/snake-key-1",
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file6"    : "/open/quests/snake/npc/obj/snake_gem",
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"file5"    : "/open/quests/snake/npc/obj/snake-key-1",
		"file10"   : "/open/quests/snake/npc/obj/snake_gem",
		"amount1"  : 1,
	]) );
	set( "build", 10098 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room459",
		"south"     : "/open/clan/13_luck/room/room457",
	]) );
	set( "long", @LONG
  
     你終於爬了上來，你的心裡有無法用言語形容的快樂。而往東邊再走過
 去的話，就會是墨子教的大門口了。從這裡往下面的山底下望過去，可以看
 到山底下的那個小城鎮，再往遠方的山麓看過去，可以看到一座小小的涼亭
 被建造在另外一座山頂上面，是提供給一些來這邊遊玩的遊客休憩的地方。
 你有空的時候，去那邊爬爬山，健身也是一件不錯的事情。

LONG);
	setup();
	replace_program(ROOM);
}
