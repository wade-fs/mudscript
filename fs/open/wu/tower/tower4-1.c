// Room: /u/p/pokai/room/wu/tower4-1
inherit ROOM;

void create()
{
  set ("short", "武威七殺塔四樓--");
  set ("long", @LONG
來到這裡，你發覺打鬥的痕跡比方才少了許多，這裡的牆壁也是漆著深藍色，不
同的是這裡的空間比前幾層都小了些，不過這一層的挑高比前幾層都高，你想可能是
便於讓守關的武者施展輕功的因素。
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tower4-2",
  "down" : __DIR__"tower3-3",
]));
  setup();
}
