inherit ROOM;

void create()
{
  set ("short", "檢查哨");
  set ("long", @LONG
近年來，為了防止海賊的入侵，特別將原本的木製哨所的牆改用
土石搭造。窄小的通道門口，與南大橋的寬大有著天壤之別。守衛的
士兵正嚴格檢查通過的人群。避免有奸細混入其中。往北則會看到高
聳的石垣。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"j03.c",
    "south" : __DIR__"j01.c",
  ]));
  setup();
}
