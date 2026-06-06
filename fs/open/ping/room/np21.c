#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "寢居");
  set ("long", @LONG
這裡是大師哥柳毅風的居所, 但此刻他卻不在房裡, 大概是有事外出
了吧, 你大概看了一下, 整間房間只有一張桌(table), 一把椅(chair),
和其他一些東西, 任何多餘的擺設多沒有。

LONG);

  set("item_desc", ([ /* sizeof() == 3 */
  "table" : "一張方方正正的桌子, 沒有特別的地方, 只是在桌子的正中央放了
一張字條(note)。
",
  "chair" : "粗糙的木頭製成的椅子, 不過摸起來卻很光滑。
",
  "note" : "                 ┌───────────┐
                 │ 有事, 至蜀中城將軍府 │
                 │  一趟, 代我向師父交代│
                 │                      │
                 │             柳毅風 筆│
                 └───────────┘
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"np16",
]));
  set("light_up", 1);

  setup();
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string str)
{
   object me = this_player();
if(me->query("family/family_name",1)=="段家" && me->query_skill("six-fingers",1)==100)
   me->move("open/ping/room/np31.c");
   return 1;
}

