// Room: /open/dancer/room/moon_ship
inherit ROOM;

void create ()
{
  set ("short", "彎月舫");
  set ("long", @LONG
雕飾著雲女玩月圖的彎月舫，船體是由千年神木所輮製而成，是
當今京城首富贈與雙月姊妹的禮物，只為能夠欣賞一次她們媲美天仙
的技藝。姊妹偶爾會乘著彎月舫遊湖賞景，但通常都是讓弟子們外出
購物用。

LONG);

  set("light_up", 1);
  set("no_magic", 1);
  set("outdoors", "/open/dancer");
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road_m",
]));
  set("no_fight", 1);

  setup();
}
