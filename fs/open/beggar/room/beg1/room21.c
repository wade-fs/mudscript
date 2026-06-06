// Room: /u/g/guetenr/beggar/room/beg1/room21.c
inherit ROOM;

void create ()
{
  set ("short", "悅來客棧");
  set ("long", @LONG
客棧內散置著幾溜桌椅，每張桌上都預放著一組茶具，待賓客坐定小二
便會奉上茶水；東邊有扇紗窗，窗外點點飛花偶爾飄了進來添了幾許韻致，
窗下有張小几上置一壺茶與杯若干，乃客棧特置與人結緣之用，若有些口乾
舌燥不妨試飲。北邊便是掌櫃所在，西邊仍是客座，向南則是大街。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room20.c",
  "north" : __DIR__"room23.c",
  "west" : __DIR__"room22.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/boss.c" : 1,
]));

  setup();
}
