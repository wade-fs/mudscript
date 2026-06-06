inherit ROOM;

void create()
{
  set ("short", "西櫓二樓");
  set ("long", @LONG
角落擺著城防時所需要的物品，守衛透過石狹間監視著下方廣場
來往的人群。房間正中央被清出一小塊空間當作訓練劍道的道場，而
刀架上整整齊齊的擺放了不少的武士刀，原來駐守此地的乃是副隊長
藤原祐司。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"j11.c",
  ]));
  setup();
}
