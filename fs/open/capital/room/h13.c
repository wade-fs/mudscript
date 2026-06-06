// Room: /open/capital/room/h13.c

inherit ROOM;

void create ()
{
  set ("short", "蘿蔔胡同");
  set ("long", @LONG
未建城之前這裡本來是一片的蘿蔔園，後來為了能夠順利的徵收此
塊土地，地主只好接受居民的要求，取名為蘿蔔胡同。
    雖然這裡已經沒有蘿蔔園了, 但是居民在自宅的院子裡還是自個架
個架子, 種幾根又白又嫩的大蘿蔔, 送禮自用兩相宜。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r70",
  "east" : __DIR__"h14",
]));
  set("outdoors", "/open/capital");

  setup();
}
