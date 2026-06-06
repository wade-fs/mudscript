// Room: /d/snow/mstreet1.c

inherit ROOM;

void create ()
{
  set ("short", "過去時空 雪亭鎮街道");
  set ("long", @LONG
你現在正走在雪亭鎮的街道上﹐東邊不遠處有一間高大的院子﹐門
口立著一根粗大的旗杆﹐旗子上寫著「淳風武館」﹐往南只聽得人聲鼎
沸﹐是個五十尺見方的廣場﹐人來人往相當熱鬧。往北可望見一座牌坊
﹐年代久遠﹐上面的字跡早已看不出是什麼字﹐出了牌坊就是鎮外。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"mstreet2",
  "south" : __DIR__"square",
  "west" : __DIR__"bank",
  "east" : __DIR__"school1",
]));
  set("outdoors", "snow");

  setup();
}
