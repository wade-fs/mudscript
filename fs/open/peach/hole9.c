// Room: /u/w/whatup/peach/hole9
inherit ROOM;

void create ()
{
  set ("short", "桃花源入口");
  set ("long", @LONG
經過黑暗又漫長的山洞之後，你忽然發現前方有光線，興奮的往
光源處飛奔而去，終於走出山洞，重見天日，彷彿重生般，心裡浮現
的詩句「山窮水盡疑無路，柳暗花明又一村」真是一點也不錯，前方
就有個村子，趕緊去看看吧。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"virage1.c",
  "enter" : __DIR__"hole8",
]));

  setup();
}
