inherit ROOM;

void create()
{
  set ("short", "南大路橋");
  set ("long", @LONG
寬闊的橋面，似乎可以同時容納四輛馬車並行。橋面上有不少商
旅來來往往。旁邊擺地攤的小販則叫賣著各自的商品，仔細挑選裡面
或許有不少來自異國的物品。往北則是入境的檢查哨。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"j02.c",
    "south" : __DIR__"island.c",
  ]));
  setup();
}
