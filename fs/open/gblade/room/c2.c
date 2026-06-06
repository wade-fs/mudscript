inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG

地道陰暗又潮濕，真不是人待的地方，大概只有變態才會找人來開這樣的
一條地道，你開始在想是不是應該趁還能回頭的時候趁早回頭。
地道在這裡分成了兩個方向，往北的通道上滿是血跡，彷彿提醒你那是一
條危險的不歸路。你看到北邊的牆壁上寫著幾個字(words)。

LONG);
	set("item_desc",
	(["words" : "會往前走的 , 不是自信過了頭 , 就是愚昧到了家 !

					仙劍  鄭士欣 
",]));

  set("light_up",0);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"c2-1.c",
  "south" : __DIR__"c1.c",

]));

  setup();
}
