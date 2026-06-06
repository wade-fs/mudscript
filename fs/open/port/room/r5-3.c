// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
  set ("short", "海岸");
  set ("long", @LONG
這裡是楓林港的海岸 . 為免海水倒灌 , 或是有人遭到意外
 , 居名們在海岸旁加修了一道護堤 . 一條石子鋪成的小路向東
西方延伸 . 這一帶是楓林的舊區 , 住在這裡的居民大多以捕魚
為生 , 生活均十分困苦 . 北邊為一棟平常的漁戶 .

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/killer/island/npc/son.c" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"r5-5",
  "west" : __DIR__"r5-4",
  "east" : __DIR__"r5-2",
]));
  set("light_up", 1);
  set("outdoors", "/open/port");

  setup();
}

