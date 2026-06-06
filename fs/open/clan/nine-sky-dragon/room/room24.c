inherit ROOM;
void create() {
	set( "short", "再一次也好" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"amount10" : 1,
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount6"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 11139 );
	set( "exits", ([
		"west"      : "/open/clan/nine-sky-dragon/room/room20",
	]) );
	set( "long", @LONG
忽然發現自己　已經醒了　回到現在的時空　呼吸活著 
又一個　平凡寂寞的長夜　沒有愛情的日子　過習慣了也就好 
反而遇見了新感情　會害怕被打擾  
經過愛情的人一定會知道　越想忘記的事越辦不到 
回憶總在　黑夜裡發酵 
陪你看過的書　走過的路　聽過的歌　闔眼就夢到  
不停在這裡的愛情啊　總是最美好 
幸福它遠的太縹緲　所以我常渴望的想要  
可以擁抱你　再一次也好 
讓我吻你　再一次也好　(我愛你　聽你再說一次也好) 
向每次爭執後的和好　當時我們多害怕彼此失去啊　緊緊擁抱 

LONG);
	setup();
	replace_program(ROOM);
}
