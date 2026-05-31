inherit ROOM;

void create ()
{
  set ("short", "[1;35m過去時空[0m 青石官道");
  set ("long", @LONG
    這是一條寬敞堅實的青石板大道﹐從這裡沿著山勢彎向西邊
﹐往西不遠處就是通往水煙閣的石階。

LONG);
  set("outdoors", "cele");
  set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/cele/sroad1",
  "west"  : "/d/cele/sroad3",
]));

  setup();
}
