inherit ROOM;
void create() {
	set( "short", "『棲霞崖』" );
	set( "owner", "poll" );
	set( "object", ([
		"file7"    : "/open/ping/obj/cloud",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/quests/snake/npc/obj/snake-3",
		"file4"    : "/open/magic-manor/obj/evil-kill-claw",
		"file5"    : "/open/magic-manor/obj/evil-kill-claw",
		"file3"    : "/open/magic-manor/obj/evil-kill-claw",
	]) );
	set( "build", 10117 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room461.c",
		"south"     : "/open/clan/13_luck/room/room459",
	]) );
	set( "long", @LONG
  
     這裡是有名的「棲霞崖」，山崖既名「棲霞」，當然少不了彩雲繚繞，
 霧隱奇峰的美景。而一天當中有兩個不同的時辰可以看到不同的美景。一個
 是凌晨的時辰，你所可以看到的是一大片霧，把整個山頭都覆蓋住了，讓這
 做山增添一種神秘感。而另一個時辰是黃昏日落時，一輪豔紅的夕陽，萬道
 霞光將山崖染成一片暈紅，此刻，山崖給你的感覺，就像一處與世無爭，出
 塵寧靜的人間仙境。

LONG);
	setup();
	replace_program(ROOM);
}
