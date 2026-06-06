// Room: /open/gsword/room/lake0.c

inherit ROOM;

void create ()
{
  set ("short", "昆明湖西");
  set ("long", @LONG
微微的風吹坲著岸邊的楊柳,凜凜的金光在水面上閃爍,幾隻蜻
蜓飛遊在湖上,細數著春光的斜陽,詩云: 
        
      西湖那有昆明好  四季如春景不息     於你心有戚戚焉...             
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/visitor1" : 1,
]));

  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 4 */
  "northeast" : "/open/gsword/room/lake1.c",
  "southeast" : "/open/gsword/room/lake3.c",
  "west" : "/open/gsword/room/mroom0.c",
  "east" : "/open/gsword/room/lakeroom0.c",
]));


  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

  setup();
}
