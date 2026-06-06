// Room : /open/clan/demon_castle/room/hall.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIM$九$HIY$天$HIC$蒼$HIG$龍$NOR$" );
	set( "object", ([
		"amount4"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/ghost-hole/obj/light-spirit",
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"file9"    : "/open/ghost-hole/obj/fire-spirit",
		"amount9"  : 1,
		"file4"    : "/open/capital/obj/blade2",
	]) );

	set( "exits", ([ /* sizeof() == 5 */
		"up"        : "/open/clan/nine-sky-dragon/room/room10",
		"enter"     : "/open/clan/nine-sky-dragon/room/room2.c",
		"south"     : "/open/clan/nine-sky-dragon/room/room9",
	]) );
	set( "build", 10442 );
	set( "light_up", 1 );
	set( "no_transmit", 1 );
	set( "long", @LONG

    ╭═════════◥███◣  ◣        ◢　◢███◤═════════╮
　　║仗劍昂首千丘遠           ◥███◣  ◢███◤           獨吾嘯傲狂風間║
　　║堪尋敵手共論劍                 ◥||||||◤                 強絕高處不勝寒║
　　║昨日黃昏愁滿地                 ●▲▼▲●                 雲崖夜雨落葉時║
　　║西風獨颯誰共飲                  ╰▲▲╯                  約期未成秋華遲║
　　║忘心無我欲沉醉       ●╮       ╰▲▲╯       ╭●       情遊天涯笑蒼穹║
　　║潮浪不識劍中趣 ◢▆█◣╰──╮◢◎▼◎◣╭──╯◢█▆◣ 臥看濁世現雲蹤║
　　║龍氣狂絕覆雨風 〒〒〒█◣    ◥▲▼▲▼▲◤    ◢█〒〒〒 雲湧風起氣如虹║
　　║劍傲一方獨霸世 ╰╰╰∪█       ||||||||       █∪╯╯╯ 氣震雲驚動晴空║
　　╰════════╰╯ ◥◤ ◥■  九天蒼龍  ■◤ ◥◤╰╯ ════════╯

LONG);
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	setup();
	call_other( "/obj/board/nine-sky-dragon_b", "???" );
	}
