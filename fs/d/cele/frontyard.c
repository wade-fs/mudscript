inherit ROOM;

void create ()
{
  set ("short", "[1;35m過去時空[0m 水煙閣前");
  set ("long", @LONG
    你現在正站在一座高大的樓閣﹐水煙閣前﹐琉璃色的屋瓦和白玉般
的白石磚使得水煙閣在崇山峻嶺中顯得十分搶眼﹐這座樓閣最早的主人
據說是有「武術之神」稱號的太陽神君「杞庸」﹐後來被當作歷代武林
盟主的居所﹐可說是學武之人的朝聖地﹐一條白石階梯沿著山腰往南而
下﹐水煙閣的大門就在你的北方。

LONG);

  set("outdoors", "cele");
  set("exits", ([ /* sizeof() == 1 */
  "north"  : "/d/cele/enter",
    "southdown": "/d/cele/stair3",
  "west"     : "/d/cele/path1",
]));


  setup();
}
