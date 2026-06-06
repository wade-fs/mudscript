inherit ROOM;
void create() {
	set( "short", "二樓north" );
	set( "object", ([
		"amount7"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/capital/obj/4-2",
		"file4"    : "/open/quests/snake/npc/obj/snake-key-1",
		"file1"    : "/obj/stone/jiao",
		"amount8"  : 1,
		"amount2"  : 6,
		"file3"    : "/obj/stone/powder",
		"file5"    : "/open/capital/obj/4-4",
		"amount6"  : 1,
		"file6"    : "/open/capital/obj/4-1",
		"amount3"  : 7,
		"file7"    : "/open/capital/obj/4-1",
		"amount1"  : 1,
		"file8"    : "/open/capital/obj/4-1",
		"file2"    : "/obj/stone/suipian",
	]) );
	set( "owner", "djlh" );
	set( "build", 10081 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room662.c",
		"east"      : "/open/clan/13_luck/room/room704",
		"west"      : "/open/clan/13_luck/room/room703.c",
	]) );
	set( "long", @LONG

 ╔═╦═╦═╦═╦═╦═╦═╦═════                           周蕙˙約定  
 ╠ ＞＜ ╬═╬═╬═╬═╬═   遠處的鐘聲迴盪在雨裡    我們在屋簷底下牽手聽    
  ◢██◣ ═╬═╬═╬═╬  幻想教堂裡頭那場婚禮     是為祝福 我倆 而舉行      
  █約  █ ═╬═╬═╬   一路從泥濘走到了美景      習慣在彼此眼中找勇氣        
  █ ˙ █ ═╬═╬═   累到無力總會想吻你        才能忘了情 路 艱 辛      ═╣ 
  █  定█ ═╬═╬   你我約定難過的往事不許提  也答應永遠都不讓對方擔心 ╬═╣ 
◢████◣        要做快樂的自己 照顧自己   就算某天一個人孤寂   ═╬═╬═╣ 
     ﹨           你我約定一爭吵很快要喊停  也說好沒有秘密彼此很透明 ╬═╬═╣ 
  ╭╮°        我會好好愛你 傻傻愛你     不去計較公平不公平   ═╬═╬═╬═╣ 
  ├╯romise                           ═════╩═╩═╩═╩═╩═╩═╩═╝ 

LONG);
	setup();
	replace_program(ROOM);
}
