inherit ROOM;

void create()
{
  set ("short", "北櫓二樓");
  set ("long", @LONG
角落擺著城防時所需要的物品，守衛透過石狹間監視著下方廣場
來往的人群。房間正中央大大的辦公桌上，放滿許多公文以及相關文
件，而後方書架上公文捲軸也整齊的放置。原來駐守此地的乃是隊長
石田忠義。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 1 */
    "westdown" : __DIR__"j15.c",
  ]));
  setup();
}
