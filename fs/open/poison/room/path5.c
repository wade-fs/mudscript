// Room: /open/poison/room/path5
inherit ROOM;

void create ()
{
  set ("short", "密道");
  set ("long", @LONG
來到這裡你發現兩旁牆壁留有碧血斑斑的舊痕跡，到處
劍痕累累，刀跡處處，似乎在此曾發生過一場大血戰。地上
躺著數具枯骨，極為陰森恐怖。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"path10",
  "east" : __DIR__"path4",
  "northwest" : __DIR__"path6",
]));

  setup();
}
