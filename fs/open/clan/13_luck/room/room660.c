inherit ROOM;
void create() {
	set( "short", "四樓FF" );
	set( "owner", "zmud" );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armband",
	]) );
	set( "build", 10032 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room715.c",
		"down"      : "/open/clan/13_luck/room/room661.c",
		"north"     : "/open/clan/13_luck/room/room717",
		"west"      : "/open/clan/13_luck/room/room714.c",
		"east"      : "/open/clan/13_luck/room/room716.c",
	]) );
	set( "long", @LONG

╭═══╮╔═╗╔╗╔═══╗ ▂▃▂▄▅▃▂▄▄▂▃▄▃▄▂▅▂▃▅▂▂▅▃   
║      ║║  ║║║║   ★ ║ ▋反覆聽著妳的留言  分享妳的滿滿喜悅 真想替妳▌  
║    ╰╯║  ╚╝║║    ═╣ ▋向全世界 宣告妳有新的愛戀 曾被誰弄痛的心 但▌  
╭═╮  ║║  ╔╗║║    ═╣ ▋願它從今天 再不會受到虧欠 <S.H.E 幸福留言> ▌  
╰═══╯╚═╝╚╝╚═══╝ █▂▃▄▄▂▄▂▃▄▂▄▃▂▄▄▂▃▂▄▃▂█   
  ▂▃▂▄▅▃▂▄▂▅▃▄▄▂▄▂▃▄▂▄▃▂▄▂▃▄▃▄▄▂▃▂▄▃▂▃▄    
▋去實現要幸福的心願 很高興妳能領先 這次一定要直到永遠 去兌現要幸福的誓言   ▌  
▌祝我們都能如願 下次就換妳陪我陶醉  除了呵護新的情感 記得偶爾聊聊近況 愛讓 ▌  
▌人手忙腳亂  我當然能體諒  祝福妳甜蜜美滿 誰都有要幸福的心願 很高興有人實  ▌  
▌現 證明永遠並不會太遠 去兌現要幸福的誓言 祝我們都能如願 留給這世界幸福留言▌  
  
  
LONG);
	setup();
	replace_program(ROOM);
}
