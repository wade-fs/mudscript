inherit ROOM;

void create()
{
  set ("short", "東櫓二樓");
  set ("long", @LONG
角落擺著城防時所需要的物品，守衛透過石狹間監視著下方廣場
來往的人群。房間正中央擺著關卡的地形模型，旁邊的辦公桌上還攤
開著許多書籍，上面還做了不少的註記。原來駐守此地的乃是副隊長
秋本明。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"j12.c",
  ]));
  setup();
}
