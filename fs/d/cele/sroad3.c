inherit ROOM;

void create ()
{
  set ("short", "過去時空 青石官道");
  set ("long", @LONG
    這是一條寬敞堅實的青石大道﹐大道沿著山腰往東向山下延伸﹐一
道長長的白石階梯從這裡往北邊上山﹐從這裡仰望階梯的盡頭有一座雄
偉的樓閣﹐那就是著名的「水煙閣」。

LONG);

  set("outdoors", "cele");
  set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/cele/sroad2",
  "northup"  : "/d/cele/stair1",
]));

        set("objects", ([
                "/d/cele/npc/guard": 2 ]) );

  setup();
}
