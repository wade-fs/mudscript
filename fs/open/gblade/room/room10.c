// Room: /u/m/moner/tree/room7.c
inherit ROOM;

void create ()
{
  set ("short", "薜荔蘿林");
  set ("long", @LONG

 越向南行，林木越密，鑽入鼻端的薜荔花香，使你的感覺越來越模糊，兩邊的飛樓
空，雕瓦繡欄， 漸漸隱於 山坳樹梢之間，四周的陽光漸漸消失，景物越來越昏暗，颼
颼的陰風輕輕的從你身後吹了過來,讓你感到微微的寒意,森林中不時傳出一些獅鳴獸吼, 

LONG);

  set("light_up", 1);
  set("outdoors", "wind");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room11.c",
  "west" : __DIR__"room10.c",
  "north" : __DIR__"room8.c",
  "east" : __DIR__"room9.c",
]));

  setup();
}
