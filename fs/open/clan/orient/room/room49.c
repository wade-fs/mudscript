inherit ROOM;
void create() {
	set( "short", "$HIC$地獄入口$NOR$" );
	set( "owner", "spicy" );
	set( "object", ([
		"file6"    : "/open/quests/snake/npc/obj/snake-key-2",
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount6"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/gsword/obj1/kring",
		"amount2"  : 130,
		"amount7"  : 943,
		"amount5"  : 1,
		"file1"    : "/obj/gift/xisuidan",
		"file4"    : "/open/gsword/obj1/kring",
		"file7"    : "/open/mon/obj/thousand-nectar",
		"file8"    : "/open/gsword/obj1/kring",
	]) );
	set( "item_desc", ([
		"sign" : @ITEM
 放下屠刀   立地成佛
ITEM,
	]) );
	set( "build", 12297 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/orient/room/room47",
		"south"     : "/open/clan/orient/room/room43",
		"east"      : "/open/clan/orient/room/room48.c",
	]) );
	set( "long", @LONG
                     東    嶽    府
                   陰                      陽
                   司                      世
                   報                      奸
                   應                      雄
                   古                      違
                   往                      天
                   今                      害
                   來                      理
                   放                      皆
                   過                      由
                   誰                      己
          　　　　 ？　　　　　　　　　　　；
                                       
你正站在地獄入口，這裡有個標誌(sign)。
往下去就可進入地獄，但請你三思而行。
往南可以回到人陰陽界。

LONG);
	setup();
	replace_program(ROOM);
}
