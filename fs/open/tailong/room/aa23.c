inherit ROOM;

void create ()
{
  set ("short", "玄機房外");
  set ("long", @LONG
玄機房是天龍寺中最新建造的建築物, 這間房間是特別建造給段家的
武學奇人段譽夫婦所用作以隱居用的, 因為兩人想退出江湖而段譽又對天
龍寺有重大貢獻,因此本因方丈破例准予他們夫婦居住在天龍寺,又因為玄
機房內有重大秘密,因此這裡是天龍寺三禁地之二,門外有四大護衛在此把
守。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"aa22",
  "east" : __DIR__"aa24",
]));
  set("objects", ([ /* sizeof() == 4 */
"/open/tailong/npc/guard1.c":1,
"/open/tailong/npc/guard2.c":1,
"/open/tailong/npc/guard3.c":1,
"/open/tailong/npc/guard4.c":1,
]));

  setup();
  replace_program(ROOM);
}
