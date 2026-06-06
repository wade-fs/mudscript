// Room: /open/capital/room/r31.c

inherit ROOM;

void create ()
{
  set ("short", "永安胡同");
  set ("long", @LONG
人多的地方就有乞丐，路邊就有幾個蹲在那兒討錢，偶爾會有幾個
官兵過來驅散，但過不了多久他們又會回來了，所以官兵們也懶得理，
只要不妨礙人們通行，大伙各自相安無事。北面有家小茶館，叫做紫藤
蘆。路邊有個牌坊寫著『南市』。
    這裡有禁衛軍四處的巡邏著，所以你還是不要在城內惹事的好。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/beggar" : 1,
]));
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"tea",
  "west" : __DIR__"r30",
  "east" : __DIR__"r33",
]));
  set("gopath", "west");
  set("gopath2", "west");

  setup();
}
