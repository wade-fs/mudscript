inherit ROOM;
void create ()
{
  set ("short", "黑牙聯門口");
  set ("long", @LONG

門楣上高高的懸著一塊水晶翠玉匾，龍飛鳳地寫著『黑牙聯』三個字剎是好看。
光線透過水晶翠玉折射出神秘的色彩，令人捨不得將眼睛移開。
銀白色的大門打開著，似乎敘述著『有種你就進來』的氣勢。
門上刻畫著兩對雄偉的飛龍，象徵著飛龍在天，所向無敵的感覺。
門旁的兩根龍柱，更是器與非凡，令人不禁多看兩眼。
如果你想對這些名器下手的話，你最好三思而行，因為門旁的侍衛可不是好惹的。

LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/killer/npc/guard_s.c" : 1,
]));
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"outr0.c",
  "enter" : __DIR__"r17.c",
]));

  setup();
}

 int valid_leave(object me, string dir)
 {
  if(dir=="enter"&&present("guard",environment(me)))
  {
    if(me->query("class")=="dancer")
      return notify_fail("心婷笑著說：想進去跳舞嗎？這裡可不是舞廳哦\n");
    if(me->query("class")=="blademan")
      return notify_fail("心婷生氣地說:不准進去，上次去金刀門居然要殺我\n");
   }
  return 1;
  }
