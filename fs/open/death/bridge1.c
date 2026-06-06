// Room: /open/death/bridge1.c

inherit ROOM;

void create ()
{
  set ("short", "奈何橋頭");
  set ("long", @LONG
再往前去就是奈何橋了，過了奈何橋就不能再回頭了，難道果真人生
沒有不死的傳說嗎！？只見一團團的鬼影往奈何橋上走去，似乎除了轉世
投胎之外，已經無路可走了。每個鬼同志的臉色又恐慌又匆忙，彷彿害怕
接受死後的審判，又怕太晚去輪迴找不到好位置，還是趕快上路吧！！
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"start",
  "north" : __DIR__"bridge2",
]));
  set("light_up", 1);
   set("no_auc",1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_transmit", 2);

  setup();
}
