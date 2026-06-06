// Room: /u/r/ranko/room/sh1.c
inherit ROOM;

void create ()
{
  set ("short", "麵店");
  set ("long", @LONG
此村一家口碑不錯的麵店，店裡賣著各式各樣的麵食，老闆不
時熟練地將麵條放入鍋中用沸水煮熟，並加上獨家的調味料，陣陣
的香味不時從鍋中飄出，令人聞了不覺食指大動。這裡已有不少村
民在此大快朵頤了，或許你該找張桌子坐下來加入他們。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"v2-1.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/mer1.c" : 1,
]));
  set("light_up", 1);

  setup();
}
